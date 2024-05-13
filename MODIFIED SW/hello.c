/*
 * Userspace program that communicates with the vga_ball device driver
 * through ioctls
 *
 * Stephen A. Edwards
 * Columbia University
 */

#include <stdio.h>
#include "vga_ball.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
int vga_ball_fd;

/* Read and print the background color */
void print_background_color() {
  vga_ball_arg_t vla;
  
  if (ioctl(vga_ball_fd, VGA_BALL_READ_BACKGROUND, &vla)) {
      perror("ioctl(VGA_BALL_READ_BACKGROUND) failed");
      return;
  }
  printf("%02x %02x %02x\n",
	 vla.background.red, vla.background.green, vla.background.blue);
}

/* Set the background color */
void set_background_color(const vga_ball_color_t *c)
{
  vga_ball_arg_t vla;
  vla.background = *c;
      if (ioctl(vga_ball_fd, VGA_BALL_WRITE_BACKGROUND, &vla)) {
      perror("ioctl(VGA_BALL_SET_BACKGROUND) failed");
      return;
  }
}
void set_cnn_values(const vga_values *c)
{
  vga_ball_arg_t vla;
  vla.cnn_write = *c;
    if(ioctl(vga_ball_fd, VGA_BALL_CNN_WRITE, &vla)){
    perror("ioctl(VGA_BALL_CNN_WRITE) failed");
    return;
  }
}
// void read_signals(vga_ball_signals_t *signals) {
//     vga_ball_arg_t vla;
//     if (ioctl(vga_ball_fd, VGA_BALL_READ_SIGNALS, &vla)) {
//         perror("ioctl(VGA_BALL_READ_SIGNALS) failed");
//         return;
//     }
//     *signals = vla.signals;
// }

//INITIAL LAYER INDEX AND OTHER VALUES
void send_initial_values() {
    vga_values_t initial_values = {0, 0, 1764, 0, 40, 0, 6400};
    set_cnn_values(&initial_values);
}
//FOLLOWING LAYERS VALUES
void send_next_values(int layer_index, int data_address , int data_size, int weight_address , int weight_size, int result_address, int result_size) {
    vga_values_t next_values = {layer_index, data_address, data_size, weight_address, weight_size, result_address, result_size};
    set_cnn_values(&next_values);
}
void set_hv(const vga_ball_hv_t *c)
{
  vga_ball_arg_t vla;
  vla.hv = *c;
  if (ioctl(vga_ball_fd, VGA_BALL_WRITE_HV, &vla)) {
      perror("ioctl(VGA_BALL_SET_HV) failed");
      return;
  }
}

static unsigned char read_val()
{
 vga_ball_arg_t vla;
 
 if (ioctl(vga_ball_fd, VGA_BALL_READ_VAL, &vla)) {
      perror("ioctl(VGA_BALL_READ) failed");
      return;
  }
 //printf("%c\n", vla.read_val.val);
 return vla.read_val.val; 
}

static unsigned char read_go()
{
 vga_ball_signals_t vla;
 
 if (ioctl(vga_ball_fd, VGA_BALL_READ_SIGNALS, &vla)) {
      perror("ioctl(VGA_BALL_READ) failed");
      return;
  }
 //printf("%c\n", vla.read_val.val);
 return vla.go; 
}

static unsigned char read_done()
{
 vga_ball_signals_t vla;
 
 if (ioctl(vga_ball_fd, VGA_BALL_READ_SIGNALS, &vla)) {
      perror("ioctl(VGA_BALL_READ) failed");
      return;
  }
 //printf("%c\n", vla.read_val.val);
 return vla.done;
}

int main()
{
  vga_ball_arg_t vla;
  int i;
  static const char filename[] = "/dev/vga_ball";

  vga_ball_hv_t hv_val = {0, 0};

  

  printf("VGA ball Userspace program started\n");

  if ( (vga_ball_fd = open(filename, O_RDWR)) == -1) {
    fprintf(stderr, "could not open %s\n", filename);
    return -1;
  }

  printf("initial state: ");
  send_initial_values();
  vga_ball_signals_t signals;
  int layer_index = 0;
  unsigned char incoming_go;
  unsigned char incoming_old_go = 0;
  unsigned char done;
    while (1) {
        read_signals(&signals);
        incoming_go = read_go();
        done = read_done();
        
        if (incoming_go != incoming_old_go) {
            if (done == 1) {
                printf("Done signal received, sending next values\n");
                layer_index++; // Increment layer_index after each done signal
                if (layer_index <= 4) {
                    if (layer_index == 1) {
                        send_next_values(1, 0, 6400, 0, 0, 0, 1600);
                    } else if (layer_index == 2) {
                        send_next_values(2, 0, 1600, 40, 148, 0, 1296);
                    } else if (layer_index == 3) {
                        send_next_values(3, 0, 1296, 0, 0, 0, 324);
                    } else if (layer_index == 4) {
                        send_next_values(4, 0, 324, 188, 3250, 0, 10);
                    }
                    printf("Waiting for done signal...\n");
                } else {
                    printf("All layers processed, terminating.\n");
                    break; // Exit loop if all layers are processed
                }
            } else {
                printf("Go signal received, waiting for done signal...\n");
            }
        } else {
            printf("Waiting for go signal...\n");
        }
        sleep(1); 
    }
 
  // unsigned char incoming;
  // unsigned char incoming_old = 0;
  // while(1) {
	// incoming = read_val();
  // 	printf("incoming old: %d\n", incoming_old);
	// printf("incoming: %d\n", incoming);

	// if(incoming != incoming_old){
	// 	printf("Button press");
	// 	incoming_old = incoming;
	// }
  // }

  printf("VGA BALL Userspace program terminating\n");
  return 0;
}
