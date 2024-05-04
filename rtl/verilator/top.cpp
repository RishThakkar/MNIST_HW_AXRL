#include <iostream>
#include "Vtop.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <fstream>
#include <string>

int main(int argc, const char ** argv, const char ** env) {

	Verilated::commandArgs(argc, argv);
  	int exitcode = 0;

	Vtop * dut = new Vtop;	// Instantiate the top module

  	// Enable dumping a VCD file
  
  	Verilated::traceEverOn(true);
  	VerilatedVcdC * tfp = new VerilatedVcdC;
  	dut->trace(tfp, 99);
  	tfp->open("top.vcd");


	std::ifstream image_file, weight_file;
	image_file.open("binary_image.txt");
	weight_file.open("binary_weights_new.txt");
	
	std::string read_value;
	uint8_t int_value;
	char print_value;

	std::ofstream fd_conv1, fd_max1, fd_conv2, fd_max2, fd_dense;
	fd_conv1.open("ver_out_conv1.txt");
	fd_max1.open("ver_out_max1.txt");
	fd_conv2.open("ver_out_conv2.txt");
	fd_max2.open("ver_out_max2.txt");
	fd_dense.open("ver_out_dense.txt");

	std::ifstream fd_conv1_gold, fd_max1_gold, fd_conv2_gold, fd_max2_gold, fd_dense_gold;
	fd_conv1_gold.open("/user/stud/fall23/vp2518/EmbeddedSystems/Project/MNIST_HW_AXRL-main/C_Simulation/Binary_C_conv1_out.txt");
	fd_max1_gold.open("/user/stud/fall23/vp2518/EmbeddedSystems/Project/MNIST_HW_AXRL-main/C_Simulation/Binary_C_max1_out.txt");
	fd_conv2_gold.open("/user/stud/fall23/vp2518/EmbeddedSystems/Project/MNIST_HW_AXRL-main/C_Simulation/Binary_C_conv2_out.txt");
	fd_max2_gold.open("/user/stud/fall23/vp2518/EmbeddedSystems/Project/MNIST_HW_AXRL-main/C_Simulation/Binary_C_max2_out.txt");
	fd_dense_gold.open("/user/stud/fall23/vp2518/EmbeddedSystems/Project/MNIST_HW_AXRL-main/C_Simulation/Binary_C_dense_out.txt");

	int identical = 10;


	int counter = 0;
	if (image_file.is_open()) {
		while (std::getline(image_file, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			dut->top__DOT__memory_unit__DOT__memory_A0[counter] = int_value;
			counter++;
		}
		image_file.close();
	}	

	counter = 0;
	if (weight_file.is_open()) {
		while (std::getline(weight_file, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			dut->top__DOT__memory_unit__DOT__memory_B[counter] = int_value;
			counter++;
		}
		weight_file.close();
	}

	//for (int k = 0; k < 1764; k++) {
	//	std::cout << k << " " << (int) dut->top__DOT__memory_unit__DOT__memory_A0[k] << std::endl;
	//}

	unsigned int data_addresses[5] = {0, 0, 0, 0, 0};
	unsigned int data_sizes[5] = {1764, 6400, 1600, 1296, 324};
	unsigned int weight_addresses[5] = {0, 0, 40, 0, 188};
	unsigned int weight_sizes[5] = {40, 0, 148, 0, 3250};
	unsigned int result_addresses[5] = {0, 0, 0, 0, 0};
	unsigned int result_sizes[5] = {6400, 1600, 1296, 324, 10};
	
	uint8_t conv1_gold[result_sizes[0]];
	uint8_t max1_gold[result_sizes[1]];
	uint8_t conv2_gold[result_sizes[2]];
	uint8_t max2_gold[result_sizes[3]];
	uint8_t dense_gold[result_sizes[4]];

	counter = 0;
	if (fd_conv1_gold.is_open()) {
		while (std::getline(fd_conv1_gold, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			conv1_gold[counter] = int_value;
			//if (counter == 6394) printf("%d", conv1_gold[counter]);
			counter++;
		}
		fd_conv1_gold.close();
	}

	counter = 0;
	if (fd_max1_gold.is_open()) {
		while (std::getline(fd_max1_gold, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			max1_gold[counter] = int_value;
			counter++;
		}
		fd_max1_gold.close();
	}

	counter = 0;
	if (fd_conv2_gold.is_open()) {
		while (std::getline(fd_conv2_gold, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			conv2_gold[counter] = int_value;
			counter++;
		}
		fd_conv2_gold.close();
	}

	counter = 0;
	if (fd_max2_gold.is_open()) {
		while (std::getline(fd_max2_gold, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			max2_gold[counter] = int_value;
			counter++;
		}
		fd_max2_gold.close();
	}

	counter = 0;
	if (fd_dense_gold.is_open()) {
		while (std::getline(fd_dense_gold, read_value)) {
			int_value = std::stoi(read_value, nullptr, 2);
			dense_gold[counter] = int_value;
			counter++;
		}
		fd_dense_gold.close();
	}

  	bool last_clk = true;
  	int time = 0;
	int time_limit;
	int time_go = 0;

  	// Initial values
  
  	dut->go = 0;
	dut->rstn = 0;

	for (int k = 0 ; k < 8 ; k++, time += 10) {
    		dut->clk = ((time % 20) >= 10) ? 1 : 0;
 		if (time == 20) dut->rstn = 1; // Pulse "go" for 1 cycles		
		dut->eval();
      		tfp->dump(time);
  	}

 	for (int i = 0 ; i < 5 ; i++) {

		time_limit = time + 20000000;
		time_go = time;

		std::cout << "Layer " << i << " Start" << std::endl;

		dut->layer_index = i;
		dut->data_address = data_addresses[i];
		dut->data_size = data_sizes[i];
		dut->weight_address = weight_addresses[i];
		dut->weight_size = weight_sizes[i];
		dut->result_address = result_addresses[i];

		for (;time < time_limit ; time += 10) {
    			dut->clk = ((time % 20) >= 10) ? 1 : 0; // Simulate a 50 MHz clock	
			if (time == time_go + 20) dut->go = 1; // Pulse "go" for 1 cycles
    			if (time == time_go + 40) dut->go = 0;
		
			dut->eval();		// Run the simulation for a cycle
			tfp->dump(time); 	// Write the VCD file for this cycle
			
			//std::cout << "Hi " << (float) dut->top__DOT__data_idx << std::endl;

			if (dut->clk && !last_clk && !dut->go) {
      				if (dut->done) break; 	// Stop once "done" appears
    			}
			last_clk = dut->clk;
			//time += 10;
		}

		//std::cout << std::endl;
		
		// Once "done" is received, run a few more clock cycles

	  	for (int k = 0 ; k < 4 ; k++, time += 10) {
    			dut->clk = ((time % 20) >= 10) ? 1 : 0;
      			dut->eval();
      			tfp->dump(time);
  		}

		for (int k = 0; k < result_sizes[i]; k++) {
			
			if (i % 2 == 0)
				int_value = dut->top__DOT__memory_unit__DOT__memory_A1[k];
			else 
				int_value = dut->top__DOT__memory_unit__DOT__memory_A0[k];


			//std::cout << k+1 << " " << (int) int_value << std::endl;

			for (int l = 7; l >= 0; l--) {
				print_value = (int_value & (1 << l)) ? '1' : '0';

				if 	(i == 0) {
					fd_conv1 << print_value;
					if (int_value != conv1_gold[k]) {
						identical = 0;
						//if( k == 6394)
						//printf("%d %d %d\n", k+1, int_value, conv1_gold[k]);
					}
				}
				else if (i == 1) {
					fd_max1 << print_value;
					if (int_value != max1_gold[k]) identical = 1;
				}
				else if (i == 2) {
					fd_conv2 << print_value;
					if (int_value != conv2_gold[k]) identical = 2;
				}
				else if (i == 3) {
					fd_max2 << print_value;     
					if (int_value != max2_gold[k]) identical = 3;
				}
				else if (i == 4) {
					fd_dense << print_value;
					if (int_value != dense_gold[k]) identical = 4;
				}
			}
			if 	(i == 0) fd_conv1 << std::endl;
			else if (i == 1) fd_max1 << std::endl;
			else if (i == 2) fd_conv2 << std::endl;
			else if (i == 3) fd_max2 << std::endl;     
			else if (i == 4) fd_dense << std::endl;
		}

		if (identical == 10)
			std::cout << "Layer " << i << " Done: Correct" << std::endl;
		else {
			std::cout << "Layer " << identical << " Done: False" << std::endl;
			return(1);
		}

		std::cout << std::endl;
	}

	std::cout << "RTL Model " << " Done: Correct" << std::endl;
	
	
	
	

  	tfp->close(); // Stop dumping the VCD file
  	delete tfp;

  	dut->final(); // Stop the simulation
  	delete dut;

  	return 0;
}

