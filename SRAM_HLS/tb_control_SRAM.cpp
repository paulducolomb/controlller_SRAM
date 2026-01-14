#include <ap_int.h>
#include "control_SRAM_HLS.cpp"

int main() {

    // ----------------------------
    // Déclaration des signaux
    // ----------------------------
    ap_uint<19> addr_in = 0;
    ap_uint<36> data_in = 0;
    ap_uint<36> data_out;
    bool we = 0, re = 0, ready = 0;

    ap_uint<19> Addr;
    ap_uint<36> Dq = 0;
    bool Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n;

    const int clk_cycles = 1;  // 1 appel = 1 cycle simulé
    bool reset = 1;

    // ----------------------------
    // RESET
    // ----------------------------
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    reset = 0;
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    // ----------------------------
    // WRITE SIMPLE 1
    // ----------------------------
    addr_in = 1;
    data_in = 0x123456789;
    we = 1; re = 0;

    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    we = 0;  // Fin write
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    // ----------------------------
    // WRITE SIMPLE 2
    // ----------------------------
    addr_in = 2;
    data_in = 0x444456789;
    we = 1; re = 0;
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);
    we = 0;
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    // ----------------------------
    // READ SIMPLE
    // ----------------------------
    addr_in = 1;
    re = 1; we = 0;
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);
    re = 0;
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    // ----------------------------
    // BURST WRITE (4 cycles)
    // ----------------------------
    addr_in = 1;
    ap_uint<36> burst_data[4] = {0xAAAAAAAAB, 0xAAAAAAAAC, 0xAAAAAAAAD, 0xAAAAAAAAE};
    for(int i=0; i<4; i++){
        data_in = burst_data[i];
        we = 1; re = 0;
        control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                         Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                         0, reset);
    }
    we = 0;  // fin burst
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    // ----------------------------
    // BURST READ (4 cycles)
    // ----------------------------
    addr_in = 1;
    re = 1; we = 0;
    for(int i=0; i<4; i++){
        control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                         Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                         0, reset);
    }
    re = 0;
    control_SRAM_HLS(addr_in, data_in, data_out, we, re, ready,
                     Addr, Dq, Ce_n, Ce2, Ce2_n, Oe_n, Rw_n, Ld_n, Cke_n,
                     0, reset);

    return 0;
}
