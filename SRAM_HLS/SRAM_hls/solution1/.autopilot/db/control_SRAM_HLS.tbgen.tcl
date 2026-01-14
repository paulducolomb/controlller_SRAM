set moduleName control_SRAM_HLS
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_none
set isOneStateSeq 1
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {control_SRAM_HLS}
set C_modelType { void 0 }
set C_modelArgList {
	{ addr_in int 19 regular  }
	{ data_in int 36 regular  }
	{ data_out int 36 regular {pointer 1}  }
	{ we uint 1 regular  }
	{ re uint 1 regular  }
	{ ready_r int 1 regular {pointer 1}  }
	{ Addr int 19 regular {pointer 1}  }
	{ Dq int 36 regular {pointer 2}  }
	{ Ce_n int 1 regular {pointer 1}  }
	{ Ce2 int 1 regular {pointer 1}  }
	{ Ce2_n int 1 regular {pointer 1}  }
	{ Oe_n int 1 regular {pointer 1}  }
	{ Rw_n int 1 regular {pointer 1}  }
	{ Ld_n int 1 regular {pointer 1}  }
	{ Cke_n int 1 regular {pointer 1}  }
	{ clk uint 1 unused  }
	{ reset uint 1 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "addr_in", "interface" : "wire", "bitwidth" : 19, "direction" : "READONLY"} , 
 	{ "Name" : "data_in", "interface" : "wire", "bitwidth" : 36, "direction" : "READONLY"} , 
 	{ "Name" : "data_out", "interface" : "wire", "bitwidth" : 36, "direction" : "WRITEONLY"} , 
 	{ "Name" : "we", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "re", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "ready_r", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Addr", "interface" : "wire", "bitwidth" : 19, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Dq", "interface" : "wire", "bitwidth" : 36, "direction" : "READWRITE"} , 
 	{ "Name" : "Ce_n", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Ce2", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Ce2_n", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Oe_n", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Rw_n", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Ld_n", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "Cke_n", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY"} , 
 	{ "Name" : "clk", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} , 
 	{ "Name" : "reset", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_local_block sc_out sc_logic 1 signal -1 } 
	{ ap_local_deadlock sc_out sc_logic 1 signal -1 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ addr_in sc_in sc_lv 19 signal 0 } 
	{ data_in sc_in sc_lv 36 signal 1 } 
	{ data_out sc_out sc_lv 36 signal 2 } 
	{ we sc_in sc_logic 1 signal 3 } 
	{ re sc_in sc_logic 1 signal 4 } 
	{ ready_r sc_out sc_logic 1 signal 5 } 
	{ Addr sc_out sc_lv 19 signal 6 } 
	{ Dq_i sc_in sc_lv 36 signal 7 } 
	{ Dq_o sc_out sc_lv 36 signal 7 } 
	{ Ce_n sc_out sc_logic 1 signal 8 } 
	{ Ce2 sc_out sc_logic 1 signal 9 } 
	{ Ce2_n sc_out sc_logic 1 signal 10 } 
	{ Oe_n sc_out sc_logic 1 signal 11 } 
	{ Rw_n sc_out sc_logic 1 signal 12 } 
	{ Ld_n sc_out sc_logic 1 signal 13 } 
	{ Cke_n sc_out sc_logic 1 signal 14 } 
	{ clk sc_in sc_logic 1 signal 15 } 
	{ reset sc_in sc_logic 1 signal 16 } 
}
set NewPortList {[ 
	{ "name": "ap_local_block", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_local_block", "role": "default" }} , 
 	{ "name": "ap_local_deadlock", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_local_deadlock", "role": "default" }} , 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "addr_in", "direction": "in", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "addr_in", "role": "default" }} , 
 	{ "name": "data_in", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "data_in", "role": "default" }} , 
 	{ "name": "data_out", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "data_out", "role": "default" }} , 
 	{ "name": "we", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "we", "role": "default" }} , 
 	{ "name": "re", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "re", "role": "default" }} , 
 	{ "name": "ready_r", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ready_r", "role": "default" }} , 
 	{ "name": "Addr", "direction": "out", "datatype": "sc_lv", "bitwidth":19, "type": "signal", "bundle":{"name": "Addr", "role": "default" }} , 
 	{ "name": "Dq_i", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "Dq", "role": "i" }} , 
 	{ "name": "Dq_o", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "Dq", "role": "o" }} , 
 	{ "name": "Ce_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Ce_n", "role": "default" }} , 
 	{ "name": "Ce2", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Ce2", "role": "default" }} , 
 	{ "name": "Ce2_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Ce2_n", "role": "default" }} , 
 	{ "name": "Oe_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Oe_n", "role": "default" }} , 
 	{ "name": "Rw_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Rw_n", "role": "default" }} , 
 	{ "name": "Ld_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Ld_n", "role": "default" }} , 
 	{ "name": "Cke_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "Cke_n", "role": "default" }} , 
 	{ "name": "clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "clk", "role": "default" }} , 
 	{ "name": "reset", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "reset", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "control_SRAM_HLS",
		"Protocol" : "ap_ctrl_none",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "addr_in", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_in", "Type" : "None", "Direction" : "I"},
			{"Name" : "data_out", "Type" : "None", "Direction" : "O"},
			{"Name" : "we", "Type" : "None", "Direction" : "I"},
			{"Name" : "re", "Type" : "None", "Direction" : "I"},
			{"Name" : "ready_r", "Type" : "None", "Direction" : "O"},
			{"Name" : "Addr", "Type" : "None", "Direction" : "O"},
			{"Name" : "Dq", "Type" : "None", "Direction" : "IO"},
			{"Name" : "Ce_n", "Type" : "None", "Direction" : "O"},
			{"Name" : "Ce2", "Type" : "None", "Direction" : "O"},
			{"Name" : "Ce2_n", "Type" : "None", "Direction" : "O"},
			{"Name" : "Oe_n", "Type" : "None", "Direction" : "O"},
			{"Name" : "Rw_n", "Type" : "None", "Direction" : "O"},
			{"Name" : "Ld_n", "Type" : "None", "Direction" : "O"},
			{"Name" : "Cke_n", "Type" : "None", "Direction" : "O"},
			{"Name" : "clk", "Type" : "None", "Direction" : "I"},
			{"Name" : "reset", "Type" : "None", "Direction" : "I"},
			{"Name" : "next_state", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "addr_reg_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "data_out_reg_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "dq_t", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "state", "Type" : "OVld", "Direction" : "IO"}]}]}


set ArgLastReadFirstWriteLatency {
	control_SRAM_HLS {
		addr_in {Type I LastRead 0 FirstWrite -1}
		data_in {Type I LastRead 0 FirstWrite -1}
		data_out {Type O LastRead -1 FirstWrite 0}
		we {Type I LastRead 0 FirstWrite -1}
		re {Type I LastRead 0 FirstWrite -1}
		ready_r {Type O LastRead -1 FirstWrite 0}
		Addr {Type O LastRead -1 FirstWrite 0}
		Dq {Type IO LastRead 0 FirstWrite 0}
		Ce_n {Type O LastRead -1 FirstWrite 0}
		Ce2 {Type O LastRead -1 FirstWrite 0}
		Ce2_n {Type O LastRead -1 FirstWrite 0}
		Oe_n {Type O LastRead -1 FirstWrite 0}
		Rw_n {Type O LastRead -1 FirstWrite 0}
		Ld_n {Type O LastRead -1 FirstWrite 0}
		Cke_n {Type O LastRead -1 FirstWrite 0}
		clk {Type I LastRead -1 FirstWrite -1}
		reset {Type I LastRead 0 FirstWrite -1}
		next_state {Type IO LastRead -1 FirstWrite -1}
		addr_reg_V {Type IO LastRead -1 FirstWrite -1}
		data_out_reg_V {Type IO LastRead -1 FirstWrite -1}
		dq_t {Type IO LastRead -1 FirstWrite -1}
		state {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "0", "Max" : "0"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "1"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	addr_in { ap_none {  { addr_in in_data 0 19 } } }
	data_in { ap_none {  { data_in in_data 0 36 } } }
	data_out { ap_none {  { data_out out_data 1 36 } } }
	we { ap_none {  { we in_data 0 1 } } }
	re { ap_none {  { re in_data 0 1 } } }
	ready_r { ap_none {  { ready_r out_data 1 1 } } }
	Addr { ap_none {  { Addr out_data 1 19 } } }
	Dq { ap_none {  { Dq_i in_data 0 36 }  { Dq_o out_data 1 36 } } }
	Ce_n { ap_none {  { Ce_n out_data 1 1 } } }
	Ce2 { ap_none {  { Ce2 out_data 1 1 } } }
	Ce2_n { ap_none {  { Ce2_n out_data 1 1 } } }
	Oe_n { ap_none {  { Oe_n out_data 1 1 } } }
	Rw_n { ap_none {  { Rw_n out_data 1 1 } } }
	Ld_n { ap_none {  { Ld_n out_data 1 1 } } }
	Cke_n { ap_none {  { Cke_n out_data 1 1 } } }
	clk { ap_none {  { clk in_data 0 1 } } }
	reset { ap_none {  { reset in_data 0 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
