/* verilator lint_off UNPACKED */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */

module memory 
#( 
	parameter data_width 	= 8,
	parameter weight_width 	= 8
) (	
	input logic clk,
	input logic rstn,
	
	input logic	     mode,
	input logic [31 : 0] data_idx,
	input logic [31 : 0] weight_idx,
	input logic [31 : 0] result_idx,
	input logic	     write_enable,

	input logic  [  data_width-1 : 0] result,
	output logic [  data_width-1 : 0] data,
	output logic [weight_width-1 : 0] weight
);



	logic [  data_width-1 : 0] memory_A0 [6400-1 : 0];
	logic [  data_width-1 : 0] memory_A1 [6400-1 : 0];
	logic [weight_width-1 : 0] memory_B  [6400-1 : 0];

	always_ff @(posedge clk) begin
		weight <= memory_B[weight_idx];  

		if (!mode) begin 
      			if (write_enable) memory_A1[result_idx] <= result;
		end else
      			if (write_enable) memory_A0[result_idx] <= result;

		data <= mode ? memory_A1[data_idx] : memory_A0[data_idx];
		
   	end

endmodule
