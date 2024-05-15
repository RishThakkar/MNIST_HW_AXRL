onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /testbench/clk
add wave -noupdate /testbench/rstn
add wave -noupdate /testbench/i
add wave -noupdate /testbench/go
add wave -noupdate /testbench/layer_index
add wave -noupdate /testbench/data_address
add wave -noupdate /testbench/data_size
add wave -noupdate /testbench/weight_address
add wave -noupdate /testbench/weight_size
add wave -noupdate /testbench/result_address
add wave -noupdate /testbench/done

add wave -noupdate /testbench/mode
add wave -noupdate /testbench/en
add wave -noupdate /testbench/init

add wave -noupdate -radix unsigned /testbench/cu_0/cs.counter1
add wave -noupdate -radix unsigned /testbench/cu_0/current_state
add wave -noupdate -radix unsigned /testbench/cu_0/cs.column
add wave -noupdate -radix unsigned /testbench/cu_0/cs.row


add wave -noupdate -radix unsigned /testbench/bias_en
add wave -noupdate -radix unsigned /testbench/data_idx
add wave -noupdate -radix unsigned /testbench/weight_idx
add wave -noupdate -radix unsigned /testbench/result_idx
add wave -noupdate -radix unsigned /testbench/write_enable



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


