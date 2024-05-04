module top
#( 
	parameter data_width 	= 8,
	parameter weight_width 	= 8
) (	
	input logic clk,
	input logic rstn,

	// Software
	input logic	      go,
	input logic  [ 2 : 0] layer_index,
	input logic  [31 : 0] data_address,
	input logic  [31 : 0] data_size,
	input logic  [31 : 0] weight_address,
	input logic  [31 : 0] weight_size,
	input logic  [31 : 0] result_address,
	output logic 	      done
);

	// Control Unit -> Kernel
	logic	      en;
	logic 	      init;
	logic	      mode;
	logic	      bias_en;

	// Control Unit -> Memories
	logic [31 : 0] data_idx;
	logic [31 : 0] weight_idx;
	logic [31 : 0] result_idx;
	logic	       write_enable;

	// Memories -> Kernel
	logic [  data_width-1 : 0] result;
	logic [  data_width-1 : 0] data;
	logic [weight_width-1 : 0] weight;

	
	cu 	 control_unit (.*);
	kernel   kernel_unit  (.*);
	memory   memory_unit  (.*);

endmodule
	
