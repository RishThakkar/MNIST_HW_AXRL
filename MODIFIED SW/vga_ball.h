#ifndef _VGA_BALL_H
#define _VGA_BALL_H

#include <linux/ioctl.h>

typedef struct{
	unsigned char val;
} vga_ball_read_t;

typedef struct {
	unsigned char red, green, blue;
} vga_ball_color_t;
  
typedef struct 
{
  unsigned int layer_index, data_address, data_size, weight_address, weight_size, result_address, result_size; 
} vga_values_t;

typedef struct {
    unsigned char go;
    unsigned char done;
} vga_ball_signals_t;

typedef struct {
        unsigned short h, v;
} vga_ball_hv_t;

typedef struct {
  vga_ball_color_t background;
  vga_ball_hv_t hv;
  vga_ball_read_t read_val;
  vga_values_t cnn_write;
  vga_ball_signals_t signals;
} vga_ball_arg_t;



#define VGA_BALL_MAGIC 'q'

/* ioctls and their arguments */
#define VGA_BALL_WRITE_BACKGROUND _IOW(VGA_BALL_MAGIC, 1, vga_ball_arg_t *)
#define VGA_BALL_READ_BACKGROUND  _IOR(VGA_BALL_MAGIC, 2, vga_ball_arg_t *)
#define VGA_BALL_WRITE_HV _IOW(VGA_BALL_MAGIC, 3, vga_ball_arg_t *)
#define VGA_BALL_READ_HV _IOR(VGA_BALL_MAGIC, 4, vga_ball_arg_t *)
#define VGA_BALL_READ_VAL _IOR(VGA_BALL_MAGIC, 5,vga_ball_arg_t *) 
#define VGA_BALL_CNN_WRITE _IOW(VGA_BALL_MAGIC, 6, vga_ball_arg_t *)
#define VGA_BALL_READ_SIGNALS _IOR(VGA_BALL_MAGIC, 7, vga_ball_arg_t *)
#endif
