# MNIST_HW_AXRL
Hardware Accelerator for the MNIST dataset, Deployed on Terasic DE1-SoC Cyclone V FPGA.
Model developed in python with Tensorflow and keras, Weights and Biases saved in model_weights.h5 and txt files, with accuracy of 97% on Floating point weights and bias
C Simulator(FLmodel.c) built with the same weights and bias, gives in Weights and bias array's location, image location, starting indices for the same and layer index.
Quantized model Simulator(in progress-FP_model.c) with 4 bits for integer part(signed) and 4 bits for floating/fraction part, conversion based on 2's complement given in Converter.c
