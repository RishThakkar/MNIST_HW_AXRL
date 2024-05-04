`timescale 1ns/1ps
`define HALF_CLOCK_PERIOD #5.0

`define DATA_MEM0 	top_0.memory_unit.memory_A0
`define DATA_MEM1 	top_0.memory_unit.memory_A1
`define WEIGHT_MEM 	top_0.memory_unit.memory_B


module testbench();

	reg clk;
	reg rstn;

	reg	      go;
	reg  [ 2 : 0] layer_index;
	reg  [31 : 0] data_address;
	reg  [31 : 0] data_size;
	reg  [31 : 0] weight_address;
	reg  [31 : 0] weight_size;
	reg  [31 : 0] result_address;
	wire 	      done;  
		
	reg  [31 : 0] result_size;

	top top_0 (.*);

	integer i;
	integer fd_conv1_out, fd_max1_out, fd_conv2_out, fd_max2_out, fd_dense_out;
	

	always begin
		`HALF_CLOCK_PERIOD;
		clk = ~clk;
	end

	initial begin

		$readmemb("binary_weights_new.txt", `WEIGHT_MEM);
		$readmemb("binary_image.txt", `DATA_MEM0);

		// register setup
		clk = 0;
		rstn = 0;
		layer_index = 0;
		data_address = 0;
		data_size = 1764;
		weight_address = 0;
		weight_size = 40;
		result_address = 0;
		result_size = 6400;

		@(posedge clk);

		@(negedge clk);   // release resetn
		rstn = 1;    
		go = 1;
		
		@(posedge clk);
		go = 0;
		@(posedge clk);   // start the first cycle

		while (done != 1) begin
			@(posedge clk);  // next cycle
		end
		@(posedge clk);

		fd_conv1_out = $fopen("rtl_out_conv1.txt", "w");

		for (i = 0; i < result_size; i = i + 1) begin
			$fdisplayb(fd_conv1_out, top_0.memory_unit.memory_A1[i]);
		end

		@(posedge clk);
		@(posedge clk);

		/////////////////
		// MAX POOLING //
		/////////////////
		
		layer_index = 1;
		data_address = 0;
		data_size = 6400;
		weight_address = 0;
		weight_size = 0;
		result_address = 0;
		result_size = 1600;

		@(posedge clk);
		@(negedge clk);   // release resetn   
		go = 1;
		
		@(posedge clk);
		go = 0;		
		@(posedge clk);   // start the first cycle

		while (done != 1) begin
			@(posedge clk);  // next cycle
		end
		@(posedge clk);

		fd_max1_out = $fopen("rtl_out_max1.txt", "w");

		for (i = 0; i < result_size; i = i + 1) begin
			$fdisplayb(fd_max1_out, top_0.memory_unit.memory_A0[i]);
		end

		@(posedge clk);
		@(posedge clk);


		///////////////////
		/// CONV LAYER 2 //
		///////////////////

		layer_index = 2;
		data_address = 0;
		data_size = 1600;
		weight_address = 40;
		weight_size = 148;
		result_address = 0;
		result_size = 1296;

		@(posedge clk);
		@(negedge clk);   // release resetn
		go = 1;
		
		@(posedge clk);
		go = 0;
		@(posedge clk);   // start the first cycle

		while (done != 1) begin
			@(posedge clk);  // next cycle
		end
		@(posedge clk);

		fd_conv2_out = $fopen("rtl_out_conv2.txt", "w");

		for (i = 0; i < result_size; i = i + 1) begin
			$fdisplayb(fd_conv2_out, top_0.memory_unit.memory_A1[i]);
		end

		@(posedge clk);
		@(posedge clk);

		///////////////////
		// MAX POOLING 2 //
		///////////////////
		
		layer_index = 3;
		data_address = 0;
		data_size = 1296;
		weight_address = 0;
		weight_size = 0;
		result_address = 0;
		result_size = 324;

		@(posedge clk);
		@(negedge clk);   // release resetn   
		go = 1;
		
		@(posedge clk);
		go = 0;		
		@(posedge clk);   // start the first cycle

		while (done != 1) begin
			@(posedge clk);  // next cycle
		end
		@(posedge clk);

		fd_max2_out = $fopen("rtl_out_max2.txt", "w");

		for (i = 0; i < result_size; i = i + 1) begin
			$fdisplayb(fd_max2_out, top_0.memory_unit.memory_A0[i]);
		end

		@(posedge clk);
		@(posedge clk);


		///////////////
		///  DENSE  ///
		///////////////

		layer_index = 4;
		data_address = 0;
		data_size = 324;
		weight_address = 188;
		weight_size = 3250;
		result_address = 0;
		result_size = 10;

		@(posedge clk);
		@(negedge clk);   // release resetn
		go = 1;
		
		@(posedge clk);
		go = 0;
		@(posedge clk);   // start the first cycle

		while (done != 1) begin
			@(posedge clk);  // next cycle
		end
		@(posedge clk);

		fd_dense_out = $fopen("rtl_out_dense.txt", "w");

		for (i = 0; i < result_size; i = i + 1) begin
			$fdisplayb(fd_dense_out, top_0.memory_unit.memory_A1[i]);
		end

		@(posedge clk);
		@(posedge clk);

		$finish;
	end 

endmodule // testbench

