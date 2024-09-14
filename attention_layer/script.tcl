############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project TNN
set_top TNN
add_files softmax.h
add_files softmax.cpp
add_files self_attention.h
add_files self_attention.cpp
add_files score.h
add_files score.cpp
add_files pooler.c
add_files loadWq.h
add_files loadWq.cpp
add_files loadIn2.h
add_files loadIn2.cpp
add_files loadBq.h
add_files loadBq.cpp
add_files inputs.c
add_files init_data.cpp
add_files encoder9.c
add_files encoder8.c
add_files encoder7.c
add_files encoder6.c
add_files encoder5.c
add_files encoder4.c
add_files encoder3.c
add_files encoder2.c
add_files encoder11.c
add_files encoder10.c
add_files encoder1.c
add_files encoder0.c
add_files encode_layer9.cpp
add_files encode_layer8.cpp
add_files encode_layer7.cpp
add_files encode_layer6.cpp
add_files encode_layer5.cpp
add_files encode_layer4.cpp
add_files encode_layer3.cpp
add_files encode_layer2.cpp
add_files encode_layer12.cpp
add_files encode_layer11.cpp
add_files encode_layer10.cpp
add_files encode_layer1.cpp
add_files data.h
add_files classifier.c
add_files biasAdd.h
add_files biasAdd.cpp
add_files activation.h
add_files activation.cpp
add_files TNN_5_2.h
add_files TNN_5_2.cpp
add_files -tb TEST_TNN2.cpp -cflags "-Wno-unknown-pragmas"
open_solution "sol1_T64_e768_H8_fix8_u55c" -flow_target vivado
set_part {xcu55c-fsvh2892-2L-e}
create_clock -period 2.5 -name default
config_array_partition -complete_threshold 0
config_compile -pipeline_loops 1024
config_op -impl dsp mul
config_op -impl dsp add
config_op -impl dsp sub
source "./TNN/sol1_T64_e768_H8_fix8_u55c/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
