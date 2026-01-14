#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
struct __cosim_s4__ { char data[4]; };
struct __cosim_s8__ { char data[8]; };
extern "C" void control_SRAM_HLS(__cosim_s4__, __cosim_s8__, volatile void *, char, char, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, char, char);
extern "C" void apatb_control_SRAM_HLS_hw(__cosim_s4__* __xlx_apatb_param_addr_in, __cosim_s8__* __xlx_apatb_param_data_in, volatile void * __xlx_apatb_param_data_out, char __xlx_apatb_param_we, char __xlx_apatb_param_re, volatile void * __xlx_apatb_param_ready_r, volatile void * __xlx_apatb_param_Addr, volatile void * __xlx_apatb_param_Dq, volatile void * __xlx_apatb_param_Ce_n, volatile void * __xlx_apatb_param_Ce2, volatile void * __xlx_apatb_param_Ce2_n, volatile void * __xlx_apatb_param_Oe_n, volatile void * __xlx_apatb_param_Rw_n, volatile void * __xlx_apatb_param_Ld_n, volatile void * __xlx_apatb_param_Cke_n, char __xlx_apatb_param_clk, char __xlx_apatb_param_reset) {
  // DUT call
  control_SRAM_HLS(*__xlx_apatb_param_addr_in, *__xlx_apatb_param_data_in, __xlx_apatb_param_data_out, __xlx_apatb_param_we, __xlx_apatb_param_re, __xlx_apatb_param_ready_r, __xlx_apatb_param_Addr, __xlx_apatb_param_Dq, __xlx_apatb_param_Ce_n, __xlx_apatb_param_Ce2, __xlx_apatb_param_Ce2_n, __xlx_apatb_param_Oe_n, __xlx_apatb_param_Rw_n, __xlx_apatb_param_Ld_n, __xlx_apatb_param_Cke_n, __xlx_apatb_param_clk, __xlx_apatb_param_reset);
}
