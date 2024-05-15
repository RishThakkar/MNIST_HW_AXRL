/* verilator lint_off UNPACKED */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */

module kernel
	#(
		parameter data_width = 8,
		parameter weight_width = 8
	) (
		input logic 			  clk,
		input logic 			  en,
		input logic 			  init,
		input logic			  mode,
		input logic			  bias_en,
		input logic  [data_width-1   : 0] data,
		input logic  [weight_width-1 : 0] weight,
		output logic [data_width-1   : 0] result
	);

	logic [2*data_width-1 : 0] mac_result;
	logic [data_width+data_width/2   : 0] mac_result_q;
	logic [data_width-1   : 0] relu_result;
	logic [data_width-1   : 0] comp_result;	
	logic overflow, carry, checkbit;
	logic [1:0] tmp;



	always @(posedge clk) begin
		if (init) begin
			mac_result <= 0;
		end else begin
			if (en) begin
				if (bias_en == 1'b1) begin
					mac_result_q <= mac_result[15: 4] + {{4{weight[7]}}, weight};
					//carry <= mac_result[15] ^ weight[7];
					tmp[0] <= mac_result[15] ^ weight[7];
					tmp[1] <= mac_result[15];
				end else
					mac_result <= mac_result + {{8{data[7]}}, data} *  {{8{weight[7]}}, weight};
			end
		end
	end

	//assign overflow = carry ^ mac_result_q[12];

	assign overflow = tmp[0] ? 0 : (mac_result_q[11] ^ tmp[1]);

	assign checkbit = overflow ? mac_result_q[12] : mac_result_q[11];

	assign relu_result = overflow ? (mac_result_q[12] ? 0 : mac_result_q[10:3]) : (mac_result_q[11] ? 0 : mac_result_q[10:3]);

	always @(posedge clk) begin
		if (init) begin
			comp_result <= 0;
		end else begin
			if (en) begin
				comp_result <= (data > comp_result) ? data : comp_result;
			end
		end
	end

	assign result = (mode == 0) ? relu_result : comp_result;

endmodule

