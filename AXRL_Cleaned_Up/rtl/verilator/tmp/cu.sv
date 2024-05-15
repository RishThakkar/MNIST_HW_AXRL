/* verilator lint_off UNPACKED */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */

typedef struct {


	logic [31 : 0] data_idx_tmp;	// Starting Address for DATA
	logic [31 : 0] weight_idx_tmp;	// Starting Address for WEIGHT
	logic [31 : 0] result_idx_tmp;	// Starting Address for RESULT

	//logic [ 5 : 0] max_count;
	logic [ 8 : 0] counter0;	// Kernel Offset (0, 1, 2, 42, 43, 44, 84, 85, 86)
	logic [ 3 : 0] counter1;	// Output image counter	(used for weight addressing)
	logic [12 : 0] counter2;	// Result Index (0 - 6400)
	logic [ 8 : 0] counter3;	// Convolution Iteration (0-8)
	logic [ 2 : 0] counter4;	// Input image counter (input map number - used for data addressing in Conv2)

	logic [12 : 0] data_offset;	// Kernel Starting Position
	logic [11 : 0] weight_offset;
	logic [10 : 0] input_offset_data;
	logic [ 3 : 0] input_offset_weight;
	logic [ 5 : 0] column;		// Column Counter
	logic [ 5 : 0] row;		// Row Counter

	logic	       flag_out_image;
	logic	       flag_out_index;		// Used to increase output index
	logic	       bias_data;

	logic	       k_en;		// Enable the Kernel
	logic	       k_init;		// Reset the Kernel
	logic	       k_mode;		// Kernel Mode (Convolution or Max Pooling)

	logic	       wen;		// Memory Write Enable
	logic	       done;		// Layer Completed
	

} reg_type;


module cu
(
	input logic  	      clk,
	input logic 	      rstn,

	// Software
	input logic	      go,
	input logic  [ 2 : 0] layer_index,
	input logic  [31 : 0] data_address,
	input logic  [31 : 0] data_size,
	input logic  [31 : 0] weight_address,
	input logic  [31 : 0] weight_size,
	input logic  [31 : 0] result_address,
	output logic 	      done,
		
	// Kernel
	output logic	      en,
	output logic 	      init,
	output logic	      mode,	// Both Kernel and Memories
	output logic	      bias_en,

	// Memories
	output logic [31 : 0] data_idx,
	output logic [31 : 0] weight_idx,
	output logic [31 : 0] result_idx,
	output logic	      write_enable

);

	//logic [ 2 : 0] layer;
	//logic [31 : 0] max_count;
	//logic [31 : 0] data_idx_tmp;
	//logic [31 : 0] weight_idx_tmp;
	//logic [31 : 0] result_idx_tmp;
	
	logic [ 4 : 0] current_state, next_state;

	reg_type cs, ns;

	logic [ 5 : 0] data_counter;
	logic [ 3 : 0] weight_counter;

	
	parameter S0 = 0;

	// Layer 0: Conv
	parameter S1 = 1;
	parameter S2 = 2;
	parameter S3 = 3;
	parameter S4 = 4;
	parameter S5 = 5;

	// Layer 1: Max
	parameter S6 = 6;
	parameter S7 = 7;
	parameter S8 = 8;

	// Layer 2: Conv
	parameter S9 = 9;
	parameter S10 = 10;
	parameter S11 = 11;
	parameter S12 = 12;
	parameter S13 = 13;

	// Layer 3: Max
	parameter S14 = 14;
	parameter S15 = 15;
	parameter S16 = 16;

	// Layer 4: Dense
	parameter S17 = 17;
	parameter S18 = 18;
	parameter S19 = 19;
	parameter S20 = 20;
	parameter S21 = 21;

	always @(*) begin
		
		ns = cs;
		//en = 0;
		//init = 0;
		//mode = 0;
		
		case (current_state)

			S0: begin
				//ns.enable = 0;
				//ns.reset  = 0;
				//ns.mode   = 0;
				ns.wen  = 0;
				ns.done = 0;
				ns.k_init  = 1'b0;
				ns.counter0 = 0;
				ns.counter1 = 0;
				ns.counter2 = 0;
				ns.counter3 = 0;
				ns.weight_offset = 0;
				ns.data_offset = 0;
				
				if (go == 1'b1) begin
					ns.data_idx_tmp   = data_address;
					ns.weight_idx_tmp = weight_address;
					ns.result_idx_tmp = result_address;
					//ns.max_count	  = data_size - 2;

					ns.k_init  = 1'b1;
					if (layer_index == 3'b000) begin
						next_state = S1;
						ns.k_mode  = 1'b0;
					end
					else if (layer_index == 3'b001) begin
						next_state = S6;
						ns.k_mode  = 1'b1;
					end
					else if (layer_index == 3'b010) begin
						next_state = S9;
						ns.k_mode = 1'b0;
					end
					else if (layer_index == 3'b011) begin
						next_state = S14;
						ns.k_mode = 1'b1;
					end
					else if (layer_index == 3'b100) begin
						next_state = S17;
						ns.k_mode = 1'b0;
					end
				end
			end

			S1: begin
				ns.counter0 = cs.counter0 + 1;			// In-Kernel Offset
				ns.counter3 = cs.counter3 + 1;			// Convolution iteration
				ns.weight_offset = cs.weight_offset + 4;
				ns.wen = 1'b0;
				//ns.bias_data = 1'b0;

				if (cs.counter3 == 0) begin	// Address 0: Enable MAC
					ns.k_init = 1'b0;
					ns.k_en   = 1'b1;
					if (cs.flag_out_index == 1'b1) begin	// If not the first ever iteration: Increase output index
						ns.counter2 = cs.counter2 + 1;
						ns.flag_out_index = 1'b0;
					end					
				end
				

				else if (cs.counter3 == 2 || cs.counter3 == 5)	// Next row of kernel
					ns.counter0 = cs.counter0 + 40;

				else if (cs.counter3 == 8) begin
					next_state = S2;
					//ns.flag   = 1'b1;   
					//ns.k_init = 1'b1;
					//ns.k_en   = 1'b0;
					ns.counter0 = 0;	 		// Reset Iteration Counter
					ns.counter3 = 0;	 		// Reset Convolution Kernel
					//ns.weight_offset = 0;
					if (cs.column != 39) begin	// Move to next column (Update Data Offset + Column Counter)
						ns.data_offset = cs.data_offset + 1;
						ns.column = cs.column + 1;
					end else begin			// Move to next row
						ns.column = 0;
						if (cs.row != 39) begin	
							ns.data_offset = cs.data_offset + 3; // Update Data Offset (+3)
							ns.row = cs.row + 1;		     // Update Row
						end else begin			// Move to next output map
							ns.data_offset = 0;	// Reset Everything
							ns.row = 0;
							if (cs.counter1 != 3) begin	
								//ns.counter1 = cs.counter1 + 1;
								ns.flag_out_image = 1'b1;
							end else			// Layer END
								next_state = S4;
								
						end
					end
				end
			end

			S2: begin				// Bias Address Generated
				if (cs.flag_out_image == 1'b1) begin		// If output map finished update the weight index
					ns.counter1 = cs.counter1 + 1;
					ns.flag_out_image = 1'b0;
				end
				ns.weight_offset = 0;
				ns.bias_data = 1'b1;
				next_state = S3;
			end

			S3: begin				// Initialize MAC for next Convolution
				//ns.weight_offset = 0;
				ns.bias_data = 1'b0;
				ns.k_init = 1'b1;
				ns.k_en   = 1'b0;				
				ns.wen = 1'b1;			// Write Result to Memory
				ns.flag_out_index = 1'b1;
				next_state = S1;
			end
			
			S4: begin
				ns.k_en = 0;
				ns.bias_data = 1'b1;
				next_state = S5;
			end
			
			S5: begin
				ns.bias_data = 1'b0;
				ns.wen = 1;
				ns.done = 1;
				next_state = S0;
			end

			S6: begin

				ns.counter0 = cs.counter0 + 1;			// In-Kernel Offset
				ns.counter3 = cs.counter3 + 1;			// Convolution iteration
				ns.wen = 1'b0;

				if (cs.counter3 == 0) begin		// Address 0: Enable MAC
					ns.k_init = 1'b0;
					ns.k_en   = 1'b1;
					if (cs.flag_out_index == 1'b1) begin	// If not the first ever iteration: Increase output index
						ns.counter2 = cs.counter2 + 1;
						ns.flag_out_index = 1'b0;
					end					
				end
				

				else if (cs.counter3 == 1)		// Next row of kernel
					ns.counter0 = cs.counter0 + 39;

				else if (cs.counter3 == 3) begin
					next_state = S7;
					ns.counter0 = 0;	 		// Reset Iteration Counter
					ns.counter3 = 0;	 		// Reset Convolution Kernel

					if (cs.column != 38) begin	// Move to next column (Update Data Offset + Column Counter)
						ns.data_offset = cs.data_offset + 2;
						ns.column = cs.column + 2;
					end else begin			// Move to next row
						ns.column = 0;
						ns.data_offset = cs.data_offset + 42;
						if (cs.row != 38) begin	
							 // Update Data Offset (+3)
							ns.row = cs.row + 2;		     // Update Row
						end else begin			// Move to next output map
							//ns.data_offset = 0;	// Reset Everything
							ns.row = 0;
							if (cs.counter1 != 3) begin	
								ns.counter1 = cs.counter1 + 1;
							//	ns.flag_out_image = 1'b1;
							end else begin		// Layer END
								next_state = S8;
								ns.data_offset = 0;
							end
								
						end
					end
				end			
			end

			S7: begin		// Initialize Kernel for next MAX Pooling
				ns.k_init = 1'b1;
				ns.k_en   = 1'b0;				
				ns.wen = 1'b1;			// Write Result to Memory
				ns.flag_out_index = 1'b1;
				next_state = S6;
			end

			S8: begin
				ns.k_init = 1'b1;
				ns.k_en = 1'b0;
				ns.wen = 1;
				ns.done = 1;
				next_state = S0;
			end

			S9: begin
				ns.counter0 = cs.counter0 + 1;			// In-Kernel Offset
				ns.counter3 = cs.counter3 + 1;			// Convolution iteration
				ns.weight_offset = cs.weight_offset + 16;
				ns.wen = 1'b0;
				//ns.bias_data = 1'b0;

				if (cs.counter3 == 0) begin	// Address 0: Enable MAC
					ns.k_init = 1'b0;
					ns.k_en   = 1'b1;

					if (cs.flag_out_index == 1'b1) begin	// If not the first ever iteration: Increase output index
						ns.counter2 = cs.counter2 + 1;
						ns.flag_out_index = 1'b0;
					end					
				end
				

				else if (cs.counter3 == 2 || cs.counter3 == 5)	// Next row of kernel
					ns.counter0 = cs.counter0 + 18;

				else if (cs.counter3 == 8) begin

					ns.counter0 = 0;				// Reset Iteration Counter
					ns.counter3 = 0;				// Reset Convolution Kernel

					if (cs.counter4 != 3) begin
						ns.counter4 = cs.counter4 + 1;
						ns.input_offset_data = cs.input_offset_data + 400;
						ns.input_offset_weight = cs.input_offset_weight + 4;
						ns.weight_offset = 0;

					end else begin
						ns.counter4 = 0;
						ns.input_offset_data = 0;
						ns.input_offset_weight = 0;
						next_state = S10;
	 		
						if (cs.column != 17) begin	// Move to next column (Update Data Offset + Column Counter)
							ns.data_offset = cs.data_offset + 1;
							ns.column = cs.column + 1;
						end else begin			// Move to next row
							ns.column = 0;
							if (cs.row != 17) begin	
								ns.data_offset = cs.data_offset + 3; // Update Data Offset (+3)
								ns.row = cs.row + 1;		     // Update Row
							end else begin			// Move to next output map
								ns.data_offset = 0;	// Reset Everything
								ns.row = 0;
								if (cs.counter1 != 3) begin	
									//ns.counter1 = cs.counter1 + 1;
									ns.flag_out_image = 1'b1;
								end else			// Layer END
									next_state = S12;
								
							end
						end
					end
				end
			end

			S10: begin				// Bias Address Generated
				if (cs.flag_out_image == 1'b1) begin		// If output map finished update the weight index
					ns.counter1 = cs.counter1 + 1;
					ns.flag_out_image = 1'b0;
				end
				ns.weight_offset = 0;
				ns.bias_data = 1'b1;
				next_state = S11;
			end

			S11: begin				// Initialize MAC for next Convolution
				//ns.weight_offset = 0;
				ns.bias_data = 1'b0;
				ns.k_init = 1'b1;
				ns.k_en   = 1'b0;				
				ns.wen = 1'b1;			// Write Result to Memory
				ns.flag_out_index = 1'b1;
				next_state = S9;
			end

			S12: begin
				ns.k_en = 0;
				ns.bias_data = 1'b1;
				next_state = S13;
			end
			
			S13: begin
				ns.bias_data = 1'b0;
				ns.wen = 1;
				ns.done = 1;
				next_state = S0;
			end

			S14: begin

				ns.counter0 = cs.counter0 + 1;			// In-Kernel Offset
				ns.counter3 = cs.counter3 + 1;			// Convolution iteration
				ns.wen = 1'b0;

				if (cs.counter3 == 0) begin		// Address 0: Enable MAC
					ns.k_init = 1'b0;
					ns.k_en   = 1'b1;
					if (cs.flag_out_index == 1'b1) begin	// If not the first ever iteration: Increase output index
						ns.counter2 = cs.counter2 + 1;
						ns.flag_out_index = 1'b0;
					end					
				end
				

				else if (cs.counter3 == 1)		// Next row of kernel
					ns.counter0 = cs.counter0 + 17;

				else if (cs.counter3 == 3) begin
					next_state = S15;
					ns.counter0 = 0;	 		// Reset Iteration Counter
					ns.counter3 = 0;	 		// Reset Convolution Kernel

					if (cs.column != 16) begin	// Move to next column (Update Data Offset + Column Counter)
						ns.data_offset = cs.data_offset + 2;
						ns.column = cs.column + 2;
					end else begin			// Move to next row
						ns.column = 0;
						ns.data_offset = cs.data_offset + 20;
						if (cs.row != 16) begin	
							ns.row = cs.row + 2;		     // Update Row
						end else begin			// Move to next output map
							ns.row = 0;
							if (cs.counter1 != 3) begin	
								ns.counter1 = cs.counter1 + 1;
							//	ns.flag_out_image = 1'b1;
							end else begin		// Layer END
								next_state = S16;
							end
								
						end
					end
				end			
			end

			S15: begin				// Initialize Kernel for next MAX Pooling
				ns.k_init = 1'b1;
				ns.k_en   = 1'b0;				
				ns.wen = 1'b1;			// Write Result to Memory
				ns.flag_out_index = 1'b1;
				next_state = S14;
			end

			S16: begin
				ns.k_init = 1'b1;
				ns.k_en = 1'b0;
				ns.wen = 1;
				ns.done = 1;
				next_state = S0;
			end

			S17: begin
				ns.counter0 = cs.counter0 + 1;			// In-Kernel Offset
				ns.counter3 = cs.counter3 + 1;			// Convolution iteration
				ns.weight_offset = cs.weight_offset + 10;
				ns.wen = 1'b0;
				//ns.bias_data = 1'b0;

				if (cs.counter3 == 0) begin	// Address 0: Enable MAC
					ns.k_init = 1'b0;
					ns.k_en   = 1'b1;
					if (cs.flag_out_index == 1'b1) begin	// If not the first ever iteration: Increase output index
						ns.counter2 = cs.counter2 + 1;
						ns.flag_out_index = 1'b0;
					end					
				end
				
				else if (cs.counter3 == 323) begin
					next_state = S18;
					ns.counter0 = 0;	 		// Reset Iteration Counter
					ns.counter3 = 0;	 		// Reset Convolution Kernel
					//ns.weight_offset = 0;
					if (cs.counter1 != 9) begin
						ns.flag_out_image = 1'b1;
					end else			// Layer END
						next_state = S20;
				end
			end

			S18: begin				// Bias Address Generated
				if (cs.flag_out_image == 1'b1) begin		// If output map finished update the weight index
					ns.counter1 = cs.counter1 + 1;
					ns.flag_out_image = 1'b0;
				end
				ns.weight_offset = 0;
				ns.bias_data = 1'b1;
				next_state = S19;
			end

			S19: begin				// Initialize MAC for next Convolution
				//ns.weight_offset = 0;
				ns.bias_data = 1'b0;
				ns.k_init = 1'b1;
				ns.k_en   = 1'b0;				
				ns.wen = 1'b1;			// Write Result to Memory
				ns.flag_out_index = 1'b1;
				next_state = S17;
			end
			
			S20: begin
				ns.k_en = 0;
				ns.bias_data = 1'b1;
				next_state = S21;
			end
			
			S21: begin
				ns.bias_data = 1'b0;
				ns.wen = 1;
				ns.done = 1;
				next_state = S0;
			end
		endcase
	end

	assign data_idx   = cs.data_idx_tmp   + cs.counter0 + cs.data_offset + cs.input_offset_data;
	assign weight_idx = cs.weight_idx_tmp + cs.counter1 + cs.weight_offset + cs.input_offset_weight;
	assign result_idx = cs.result_idx_tmp + cs.counter2;

	assign en	    = cs.k_en;
	assign init	    = cs.k_init;
	assign mode         = cs.k_mode;
	assign write_enable = cs.wen;
	assign bias_en	    = cs.bias_data;
	assign done	    = cs.done;


	always @(posedge clk) begin
		if (!rstn) begin
			current_state <= S0;
			//next_state    <= S0;
			cs.k_init     <= 1'b0;
			cs.k_en       <= 1'b0;
			cs.k_mode     <= 1'b0;
			cs.done       <= 1'b0;
			cs.wen	      <= 1'b0;
			cs.counter0 <= 0;
			cs.counter1 <= 0;
			cs.counter2 <= 0;
			cs.counter3 <= 0;
			cs.counter4 <= 0;
			cs.data_offset <= 0;
			cs.weight_offset <= 0;
			cs.input_offset_data <= 0;
			cs.input_offset_weight <= 0;
			cs.column <= 0;
			cs.row    <= 0;
			cs.flag_out_image   <= 0;
			cs.flag_out_index   <= 0;
			cs.bias_data <= 0;

		end else begin
			current_state <= next_state;
			cs <= ns;
		end
	end
 
endmodule 
