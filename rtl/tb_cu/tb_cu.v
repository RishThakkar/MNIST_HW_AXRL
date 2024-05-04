`timescale 1ns/1ps
`define HALF_CLOCK_PERIOD #5.0


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
		
	// Kernel
	wire	      en;
	wire 	      init;
	wire	      mode;
	wire	      bias_en;	

	// Memories
	wire [31 : 0] data_idx;
	wire [31 : 0] weight_idx;
	wire [31 : 0] result_idx;
	wire	      write_enable;

	cu cu_0 (.*);

	integer i;

	always begin
		`HALF_CLOCK_PERIOD;
		clk = ~clk;
	end

	initial begin

		// register setup
		clk = 0;
		rstn = 0;
		layer_index = 0;
		data_address = 0;
		data_size = 0;
		weight_address = 0;
		weight_size = 0;
		result_address = 0;
		go = 0;

		layer_index = 1;
		//data_address = 0;
		//data_size = 0;
/*
		layer_index = 2;
		weight_address = 40;
		//data_address = 0;
		//data_size = 0;
		
		layer_index = 3;

		layer_index = 4;
		weight_address = 188;
*/
		@(posedge clk);
		@(negedge clk);   // release resetn
		rstn = 1;   
		
		@(posedge clk);
		@(posedge clk); 
		go = 1;
		
		@(posedge clk);
		go = 0;
		@(posedge clk);   // start the first cycle
		for (i=0 ; i<200000; i=i+1) begin 

			@(posedge clk);  // next cycle
		end
		  

		

		$finish;
	end 

endmodule // testbench

