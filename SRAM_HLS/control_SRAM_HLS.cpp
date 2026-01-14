#include <ap_int.h>

enum State {IDLE, INIT, WRITE_DATA, READ_CAPTURE, BURST_WRITE, BURST_READ};

void control_SRAM_HLS(
    ap_uint<19> addr_in,
    ap_uint<36> data_in,
    ap_uint<36> &data_out,
    bool we,
    bool re,
    bool &ready,
    // SRAM signals
    ap_uint<19> &Addr,
    ap_uint<36> &Dq,
    bool &Ce_n,
    bool &Ce2,
    bool &Ce2_n,
    bool &Oe_n,
    bool &Rw_n,
    bool &Ld_n,
    bool &Cke_n,
    bool clk,
    bool reset
)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=addr_in
#pragma HLS INTERFACE ap_none port=data_in
#pragma HLS INTERFACE ap_none port=data_out
#pragma HLS INTERFACE ap_none port=we
#pragma HLS INTERFACE ap_none port=re
#pragma HLS INTERFACE ap_none port=ready
#pragma HLS INTERFACE ap_none port=Addr
#pragma HLS INTERFACE ap_none port=Dq
#pragma HLS INTERFACE ap_none port=Ce_n
#pragma HLS INTERFACE ap_none port=Ce2
#pragma HLS INTERFACE ap_none port=Ce2_n
#pragma HLS INTERFACE ap_none port=Oe_n
#pragma HLS INTERFACE ap_none port=Rw_n
#pragma HLS INTERFACE ap_none port=Ld_n
#pragma HLS INTERFACE ap_none port=Cke_n

    static State state = INIT;
    static State next_state = IDLE;
    static ap_uint<19> addr_reg = 0;
    static ap_uint<36> data_out_reg = 0;
    static ap_uint<36> dq_out_late = 0;
    static bool dq_t = 1;

    if(reset){
        state = INIT;
        next_state = IDLE;
        addr_reg = 0;
        data_out_reg = 0;
        dq_t = 1;
        ready = 0;
    } else {
        // FSM transition
        switch(state){
            case INIT:       next_state = IDLE; break;
            case IDLE:       next_state = (we ? WRITE_DATA : (re ? READ_CAPTURE : IDLE)); break;
            case WRITE_DATA: next_state = (we ? BURST_WRITE : (re ? READ_CAPTURE : IDLE)); break;
            case READ_CAPTURE: next_state = (we ? WRITE_DATA : (re ? BURST_READ : IDLE)); break;
            case BURST_WRITE: next_state = (we ? BURST_WRITE : (re ? READ_CAPTURE : IDLE)); break;
            case BURST_READ:  next_state = (we ? WRITE_DATA : (re ? BURST_READ : IDLE)); break;
        }

        // State outputs
        switch(state){
            case INIT:
                dq_t = 1; Ce_n=1; Ce2=0; Ce2_n=1; Cke_n=0; Ld_n=0; Rw_n=1; Oe_n=0; ready=0;
                break;
            case IDLE:
                ready = 1; dq_t=1; Ce_n=0; Ce2=1; Ce2_n=0; Rw_n=1; Ld_n=0;
                break;
            case WRITE_DATA:
                Ce_n=0; Ce2=1; Ce2_n=0; Rw_n=0; Ld_n=0; dq_t=0; ready=0;
                break;
            case BURST_WRITE:
                Ce_n=0; Ce2=1; Ce2_n=0; Cke_n=0; Rw_n=0; Ld_n=1; dq_t=0; ready=0;
                break;
            case BURST_READ:
                Ce_n=0; Ce2=1; Ce2_n=0; Cke_n=0; Rw_n=1; Ld_n=1; dq_t=1; ready=0;
                break;
            case READ_CAPTURE:
                Ce_n=0; Ce2=1; Ce2_n=0; Cke_n=0; Rw_n=1; Ld_n=0; dq_t=1; ready=0;
                break;
        }

        // Capture data
        if(state==READ_CAPTURE || state==BURST_READ){
            data_out_reg = Dq;
        }

        // Address latch
        if((next_state==BURST_WRITE && state!=BURST_WRITE) || 
           (state==WRITE_DATA && next_state==BURST_WRITE) ||
           (next_state==BURST_READ && state!=BURST_READ) ||
           (state==READ_CAPTURE && next_state==BURST_READ)){
            addr_reg = addr_in;
        }

        // Assign outputs
        Addr = addr_reg;
        data_out = data_out_reg;
        if(dq_t==0) Dq = data_in; // drive data bus
    }

    state = next_state;
}
