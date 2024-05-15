onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /testbench/clk
add wave -noupdate /testbench/rstn
add wave -noupdate /testbench/i
add wave -noupdate /testbench/go
add wave -noupdate /testbench/layer_index
add wave -noupdate -radix unsigned /testbench/data_address
add wave -noupdate -radix unsigned /testbench/data_size
add wave -noupdate -radix unsigned /testbench/weight_address
add wave -noupdate -radix unsigned /testbench/weight_size
add wave -noupdate -radix unsigned /testbench/result_address
add wave -noupdate /testbench/done

add wave -noupdate /testbench/top_0/mode
add wave -noupdate /testbench/top_0/en
add wave -noupdate /testbench/top_0/init

add wave -noupdate -radix unsigned /testbench/top_0/control_unit/cs.counter1
add wave -noupdate -radix unsigned /testbench/top_0/control_unit/current_state
add wave -noupdate -radix unsigned /testbench/top_0/control_unit/cs.column
add wave -noupdate -radix unsigned /testbench/top_0/control_unit/cs.row

add wave -noupdate /testbench/top_0/bias_en
add wave -noupdate -radix unsigned /testbench/top_0/data_idx
add wave -noupdate -radix unsigned /testbench/top_0/weight_idx
add wave -noupdate -radix unsigned /testbench/top_0/result_idx
add wave -noupdate /testbench/top_0/write_enable

add wave -noupdate -radix binary /testbench/top_0/data
add wave -noupdate -radix binary /testbench/top_0/weight

add wave -noupdate -radix binary /testbench/top_0/kernel_unit/overflow
add wave -noupdate -radix binary /testbench/top_0/kernel_unit/checkbit
add wave -noupdate -radix binary /testbench/top_0/kernel_unit/mac_result
add wave -noupdate -radix binary /testbench/top_0/kernel_unit/mac_result_q
add wave -noupdate -radix binary /testbench/top_0/kernel_unit/relu_result
add wave -noupdate -radix binary /testbench/top_0/kernel_unit/comp_result
add wave -noupdate -radix binary /testbench/top_0/result

add wave -noupdate /testbench/top_0/memory_unit/memory_A0
add wave -noupdate /testbench/top_0/memory_unit/memory_A1
add wave -noupdate /testbench/top_0/memory_unit/memory_B

TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {3 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 223
configure wave -valuecolwidth 89
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ns} {12 ns}


