#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_addr_in "../tv/cdatafile/c.control_SRAM_HLS.autotvin_addr_in.dat"
#define AUTOTB_TVOUT_addr_in "../tv/cdatafile/c.control_SRAM_HLS.autotvout_addr_in.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_in "../tv/cdatafile/c.control_SRAM_HLS.autotvin_data_in.dat"
#define AUTOTB_TVOUT_data_in "../tv/cdatafile/c.control_SRAM_HLS.autotvout_data_in.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_out "../tv/cdatafile/c.control_SRAM_HLS.autotvin_data_out.dat"
#define AUTOTB_TVOUT_data_out "../tv/cdatafile/c.control_SRAM_HLS.autotvout_data_out.dat"
// wrapc file define:
#define AUTOTB_TVIN_we "../tv/cdatafile/c.control_SRAM_HLS.autotvin_we.dat"
#define AUTOTB_TVOUT_we "../tv/cdatafile/c.control_SRAM_HLS.autotvout_we.dat"
// wrapc file define:
#define AUTOTB_TVIN_re "../tv/cdatafile/c.control_SRAM_HLS.autotvin_re.dat"
#define AUTOTB_TVOUT_re "../tv/cdatafile/c.control_SRAM_HLS.autotvout_re.dat"
// wrapc file define:
#define AUTOTB_TVIN_ready_r "../tv/cdatafile/c.control_SRAM_HLS.autotvin_ready_r.dat"
#define AUTOTB_TVOUT_ready_r "../tv/cdatafile/c.control_SRAM_HLS.autotvout_ready_r.dat"
// wrapc file define:
#define AUTOTB_TVIN_Addr "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Addr.dat"
#define AUTOTB_TVOUT_Addr "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Addr.dat"
// wrapc file define:
#define AUTOTB_TVIN_Dq "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Dq.dat"
#define AUTOTB_TVOUT_Dq "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Dq.dat"
// wrapc file define:
#define AUTOTB_TVIN_Ce_n "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Ce_n.dat"
#define AUTOTB_TVOUT_Ce_n "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Ce_n.dat"
// wrapc file define:
#define AUTOTB_TVIN_Ce2 "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Ce2.dat"
#define AUTOTB_TVOUT_Ce2 "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Ce2.dat"
// wrapc file define:
#define AUTOTB_TVIN_Ce2_n "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Ce2_n.dat"
#define AUTOTB_TVOUT_Ce2_n "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Ce2_n.dat"
// wrapc file define:
#define AUTOTB_TVIN_Oe_n "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Oe_n.dat"
#define AUTOTB_TVOUT_Oe_n "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Oe_n.dat"
// wrapc file define:
#define AUTOTB_TVIN_Rw_n "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Rw_n.dat"
#define AUTOTB_TVOUT_Rw_n "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Rw_n.dat"
// wrapc file define:
#define AUTOTB_TVIN_Ld_n "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Ld_n.dat"
#define AUTOTB_TVOUT_Ld_n "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Ld_n.dat"
// wrapc file define:
#define AUTOTB_TVIN_Cke_n "../tv/cdatafile/c.control_SRAM_HLS.autotvin_Cke_n.dat"
#define AUTOTB_TVOUT_Cke_n "../tv/cdatafile/c.control_SRAM_HLS.autotvout_Cke_n.dat"
// wrapc file define:
#define AUTOTB_TVIN_clk "../tv/cdatafile/c.control_SRAM_HLS.autotvin_clk.dat"
#define AUTOTB_TVOUT_clk "../tv/cdatafile/c.control_SRAM_HLS.autotvout_clk.dat"
// wrapc file define:
#define AUTOTB_TVIN_reset "../tv/cdatafile/c.control_SRAM_HLS.autotvin_reset.dat"
#define AUTOTB_TVOUT_reset "../tv/cdatafile/c.control_SRAM_HLS.autotvout_reset.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_addr_in "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_addr_in.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_in "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_data_in.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_out "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_data_out.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_we "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_we.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_re "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_re.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_ready_r "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_ready_r.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Addr "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Addr.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Dq "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Dq.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Ce_n "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Ce_n.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Ce2 "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Ce2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Ce2_n "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Ce2_n.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Oe_n "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Oe_n.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Rw_n "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Rw_n.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Ld_n "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Ld_n.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_Cke_n "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_Cke_n.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_clk "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_clk.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_reset "../tv/rtldatafile/rtl.control_SRAM_HLS.autotvout_reset.dat"


inline void rev_endian(char* p, size_t nbytes)
{
  std::reverse(p, p+nbytes);
}

template<size_t bit_width>
struct transaction {
  typedef uint64_t depth_t;
  static const size_t wbytes = (bit_width+7)>>3;
  static const size_t dbytes = sizeof(depth_t);
  const depth_t depth;
  const size_t vbytes;
  const size_t tbytes;
  char * const p;
  typedef char (*p_dat)[wbytes];
  p_dat vp;

  void reorder() {
    rev_endian(p, dbytes);
    p_dat vp = (p_dat) (p+dbytes);
    for (depth_t i = 0; i < depth; ++i) {
      rev_endian(vp[i], wbytes);
    }
  }

  transaction(depth_t depth)
    : depth(depth), vbytes(wbytes*depth), tbytes(dbytes+vbytes),
      p(new char[tbytes]) {
    *(depth_t*)p = depth;
    vp = (p_dat) (p+dbytes);
  }

  template<size_t psize>
  void import(char* param, depth_t num, int64_t offset) {
    param -= offset*psize;
    for (depth_t i = 0; i < num; ++i) {
      memcpy(vp[i], param, wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[i], wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num, int64_t skip) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[skip+i], wbytes);
      param += psize;
    }
  }

  ~transaction() { if (p) { delete[] p; } }
};
      

inline const std::string begin_str(int num)
{
  return std::string("[[transaction]] ")
         .append(std::to_string(num))
         .append("\n");
}

inline const std::string end_str()
{
  return std::string("[[/transaction]] \n");
}
      
class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  addr_in_depth = 0;
  data_in_depth = 0;
  data_out_depth = 0;
  we_depth = 0;
  re_depth = 0;
  ready_r_depth = 0;
  Addr_depth = 0;
  Dq_depth = 0;
  Ce_n_depth = 0;
  Ce2_depth = 0;
  Ce2_n_depth = 0;
  Oe_n_depth = 0;
  Rw_n_depth = 0;
  Ld_n_depth = 0;
  Cke_n_depth = 0;
  clk_depth = 0;
  reset_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{addr_in " << addr_in_depth << "}\n";
  total_list << "{data_in " << data_in_depth << "}\n";
  total_list << "{data_out " << data_out_depth << "}\n";
  total_list << "{we " << we_depth << "}\n";
  total_list << "{re " << re_depth << "}\n";
  total_list << "{ready_r " << ready_r_depth << "}\n";
  total_list << "{Addr " << Addr_depth << "}\n";
  total_list << "{Dq " << Dq_depth << "}\n";
  total_list << "{Ce_n " << Ce_n_depth << "}\n";
  total_list << "{Ce2 " << Ce2_depth << "}\n";
  total_list << "{Ce2_n " << Ce2_n_depth << "}\n";
  total_list << "{Oe_n " << Oe_n_depth << "}\n";
  total_list << "{Rw_n " << Rw_n_depth << "}\n";
  total_list << "{Ld_n " << Ld_n_depth << "}\n";
  total_list << "{Cke_n " << Cke_n_depth << "}\n";
  total_list << "{clk " << clk_depth << "}\n";
  total_list << "{reset " << reset_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int addr_in_depth;
    int data_in_depth;
    int data_out_depth;
    int we_depth;
    int re_depth;
    int ready_r_depth;
    int Addr_depth;
    int Dq_depth;
    int Ce_n_depth;
    int Ce2_depth;
    int Ce2_n_depth;
    int Oe_n_depth;
    int Rw_n_depth;
    int Ld_n_depth;
    int Cke_n_depth;
    int clk_depth;
    int reset_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static bool RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool err = false;
  size_t x_found;

  // search and replace 'X' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('X', 0)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  // search and replace 'x' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('x', 2)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  return err;}
struct __cosim_s4__ { char data[4]; };
struct __cosim_s8__ { char data[8]; };
extern "C" void control_SRAM_HLS_hw_stub_wrapper(__cosim_s4__*, __cosim_s8__*, volatile void *, char, char, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, char, char);

extern "C" void apatb_control_SRAM_HLS_hw(__cosim_s4__* __xlx_apatb_param_addr_in, __cosim_s8__* __xlx_apatb_param_data_in, volatile void * __xlx_apatb_param_data_out, char __xlx_apatb_param_we, char __xlx_apatb_param_re, volatile void * __xlx_apatb_param_ready_r, volatile void * __xlx_apatb_param_Addr, volatile void * __xlx_apatb_param_Dq, volatile void * __xlx_apatb_param_Ce_n, volatile void * __xlx_apatb_param_Ce2, volatile void * __xlx_apatb_param_Ce2_n, volatile void * __xlx_apatb_param_Oe_n, volatile void * __xlx_apatb_param_Rw_n, volatile void * __xlx_apatb_param_Ld_n, volatile void * __xlx_apatb_param_Cke_n, char __xlx_apatb_param_clk, char __xlx_apatb_param_reset) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
static AESL_FILE_HANDLER aesl_fh;
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_data_out);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<36> > data_out_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "data_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              data_out_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "data_out" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_data_out)[0*5+0] = data_out_pc_buffer[0].range(7, 0).to_int64();
((char*)__xlx_apatb_param_data_out)[0*5+1] = data_out_pc_buffer[0].range(15, 8).to_int64();
((char*)__xlx_apatb_param_data_out)[0*5+2] = data_out_pc_buffer[0].range(23, 16).to_int64();
((char*)__xlx_apatb_param_data_out)[0*5+3] = data_out_pc_buffer[0].range(31, 24).to_int64();
((char*)__xlx_apatb_param_data_out)[0*5+4] = data_out_pc_buffer[0].range(35, 32).to_int64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_ready_r);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > ready_r_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "ready_r");
  
            // push token into output port buffer
            if (AESL_token != "") {
              ready_r_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "ready_r" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_ready_r)[0*1+0] = ready_r_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Addr);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<19> > Addr_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Addr");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Addr_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Addr" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Addr)[0*3+0] = Addr_pc_buffer[0].range(7, 0).to_int64();
((char*)__xlx_apatb_param_Addr)[0*3+1] = Addr_pc_buffer[0].range(15, 8).to_int64();
((char*)__xlx_apatb_param_Addr)[0*3+2] = Addr_pc_buffer[0].range(18, 16).to_int64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Dq);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<36> > Dq_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Dq");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Dq_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Dq" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Dq)[0*5+0] = Dq_pc_buffer[0].range(7, 0).to_int64();
((char*)__xlx_apatb_param_Dq)[0*5+1] = Dq_pc_buffer[0].range(15, 8).to_int64();
((char*)__xlx_apatb_param_Dq)[0*5+2] = Dq_pc_buffer[0].range(23, 16).to_int64();
((char*)__xlx_apatb_param_Dq)[0*5+3] = Dq_pc_buffer[0].range(31, 24).to_int64();
((char*)__xlx_apatb_param_Dq)[0*5+4] = Dq_pc_buffer[0].range(35, 32).to_int64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Ce_n);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Ce_n_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Ce_n");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Ce_n_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Ce_n" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Ce_n)[0*1+0] = Ce_n_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Ce2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Ce2_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Ce2");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Ce2_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Ce2" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Ce2)[0*1+0] = Ce2_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Ce2_n);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Ce2_n_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Ce2_n");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Ce2_n_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Ce2_n" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Ce2_n)[0*1+0] = Ce2_n_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Oe_n);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Oe_n_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Oe_n");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Oe_n_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Oe_n" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Oe_n)[0*1+0] = Oe_n_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Rw_n);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Rw_n_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Rw_n");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Rw_n_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Rw_n" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Rw_n)[0*1+0] = Rw_n_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Ld_n);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Ld_n_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Ld_n");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Ld_n_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Ld_n" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Ld_n)[0*1+0] = Ld_n_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_Cke_n);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<1> > Cke_n_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "Cke_n");
  
            // push token into output port buffer
            if (AESL_token != "") {
              Cke_n_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "Cke_n" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_Cke_n)[0*1+0] = Cke_n_pc_buffer[0].range(0, 0).to_uint64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
CodeState = DUMP_INPUTS;
// print addr_in Transactions
{
aesl_fh.write(AUTOTB_TVIN_addr_in, begin_str(AESL_transaction));
{
    sc_bv<19> __xlx_tmp_lv = *((int*)__xlx_apatb_param_addr_in);
aesl_fh.write(AUTOTB_TVIN_addr_in, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.addr_in_depth);
aesl_fh.write(AUTOTB_TVIN_addr_in, end_str());
}

// print data_in Transactions
{
aesl_fh.write(AUTOTB_TVIN_data_in, begin_str(AESL_transaction));
{
    sc_bv<36> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_data_in);
aesl_fh.write(AUTOTB_TVIN_data_in, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.data_in_depth);
aesl_fh.write(AUTOTB_TVIN_data_in, end_str());
}

// print data_out Transactions
{
aesl_fh.write(AUTOTB_TVIN_data_out, begin_str(AESL_transaction));
{
    sc_bv<36> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_data_out);
aesl_fh.write(AUTOTB_TVIN_data_out, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.data_out_depth);
aesl_fh.write(AUTOTB_TVIN_data_out, end_str());
}

// print we Transactions
{
aesl_fh.write(AUTOTB_TVIN_we, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_we);
aesl_fh.write(AUTOTB_TVIN_we, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.we_depth);
aesl_fh.write(AUTOTB_TVIN_we, end_str());
}

// print re Transactions
{
aesl_fh.write(AUTOTB_TVIN_re, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_re);
aesl_fh.write(AUTOTB_TVIN_re, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.re_depth);
aesl_fh.write(AUTOTB_TVIN_re, end_str());
}

// print ready_r Transactions
{
aesl_fh.write(AUTOTB_TVIN_ready_r, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_ready_r);
aesl_fh.write(AUTOTB_TVIN_ready_r, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.ready_r_depth);
aesl_fh.write(AUTOTB_TVIN_ready_r, end_str());
}

// print Addr Transactions
{
aesl_fh.write(AUTOTB_TVIN_Addr, begin_str(AESL_transaction));
{
    sc_bv<19> __xlx_tmp_lv = *((int*)__xlx_apatb_param_Addr);
aesl_fh.write(AUTOTB_TVIN_Addr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Addr_depth);
aesl_fh.write(AUTOTB_TVIN_Addr, end_str());
}

// print Dq Transactions
{
aesl_fh.write(AUTOTB_TVIN_Dq, begin_str(AESL_transaction));
{
    sc_bv<36> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_Dq);
aesl_fh.write(AUTOTB_TVIN_Dq, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Dq_depth);
aesl_fh.write(AUTOTB_TVIN_Dq, end_str());
}

// print Ce_n Transactions
{
aesl_fh.write(AUTOTB_TVIN_Ce_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ce_n);
aesl_fh.write(AUTOTB_TVIN_Ce_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ce_n_depth);
aesl_fh.write(AUTOTB_TVIN_Ce_n, end_str());
}

// print Ce2 Transactions
{
aesl_fh.write(AUTOTB_TVIN_Ce2, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ce2);
aesl_fh.write(AUTOTB_TVIN_Ce2, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ce2_depth);
aesl_fh.write(AUTOTB_TVIN_Ce2, end_str());
}

// print Ce2_n Transactions
{
aesl_fh.write(AUTOTB_TVIN_Ce2_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ce2_n);
aesl_fh.write(AUTOTB_TVIN_Ce2_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ce2_n_depth);
aesl_fh.write(AUTOTB_TVIN_Ce2_n, end_str());
}

// print Oe_n Transactions
{
aesl_fh.write(AUTOTB_TVIN_Oe_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Oe_n);
aesl_fh.write(AUTOTB_TVIN_Oe_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Oe_n_depth);
aesl_fh.write(AUTOTB_TVIN_Oe_n, end_str());
}

// print Rw_n Transactions
{
aesl_fh.write(AUTOTB_TVIN_Rw_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Rw_n);
aesl_fh.write(AUTOTB_TVIN_Rw_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Rw_n_depth);
aesl_fh.write(AUTOTB_TVIN_Rw_n, end_str());
}

// print Ld_n Transactions
{
aesl_fh.write(AUTOTB_TVIN_Ld_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ld_n);
aesl_fh.write(AUTOTB_TVIN_Ld_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ld_n_depth);
aesl_fh.write(AUTOTB_TVIN_Ld_n, end_str());
}

// print Cke_n Transactions
{
aesl_fh.write(AUTOTB_TVIN_Cke_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Cke_n);
aesl_fh.write(AUTOTB_TVIN_Cke_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Cke_n_depth);
aesl_fh.write(AUTOTB_TVIN_Cke_n, end_str());
}

// print clk Transactions
{
aesl_fh.write(AUTOTB_TVIN_clk, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_clk);
aesl_fh.write(AUTOTB_TVIN_clk, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.clk_depth);
aesl_fh.write(AUTOTB_TVIN_clk, end_str());
}

// print reset Transactions
{
aesl_fh.write(AUTOTB_TVIN_reset, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_reset);
aesl_fh.write(AUTOTB_TVIN_reset, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.reset_depth);
aesl_fh.write(AUTOTB_TVIN_reset, end_str());
}

CodeState = CALL_C_DUT;
control_SRAM_HLS_hw_stub_wrapper(__xlx_apatb_param_addr_in, __xlx_apatb_param_data_in, __xlx_apatb_param_data_out, __xlx_apatb_param_we, __xlx_apatb_param_re, __xlx_apatb_param_ready_r, __xlx_apatb_param_Addr, __xlx_apatb_param_Dq, __xlx_apatb_param_Ce_n, __xlx_apatb_param_Ce2, __xlx_apatb_param_Ce2_n, __xlx_apatb_param_Oe_n, __xlx_apatb_param_Rw_n, __xlx_apatb_param_Ld_n, __xlx_apatb_param_Cke_n, __xlx_apatb_param_clk, __xlx_apatb_param_reset);
CodeState = DUMP_OUTPUTS;
// print data_out Transactions
{
aesl_fh.write(AUTOTB_TVOUT_data_out, begin_str(AESL_transaction));
{
    sc_bv<36> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_data_out);
aesl_fh.write(AUTOTB_TVOUT_data_out, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.data_out_depth);
aesl_fh.write(AUTOTB_TVOUT_data_out, end_str());
}

// print ready_r Transactions
{
aesl_fh.write(AUTOTB_TVOUT_ready_r, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_ready_r);
aesl_fh.write(AUTOTB_TVOUT_ready_r, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.ready_r_depth);
aesl_fh.write(AUTOTB_TVOUT_ready_r, end_str());
}

// print Addr Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Addr, begin_str(AESL_transaction));
{
    sc_bv<19> __xlx_tmp_lv = *((int*)__xlx_apatb_param_Addr);
aesl_fh.write(AUTOTB_TVOUT_Addr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Addr_depth);
aesl_fh.write(AUTOTB_TVOUT_Addr, end_str());
}

// print Dq Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Dq, begin_str(AESL_transaction));
{
    sc_bv<36> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_Dq);
aesl_fh.write(AUTOTB_TVOUT_Dq, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Dq_depth);
aesl_fh.write(AUTOTB_TVOUT_Dq, end_str());
}

// print Ce_n Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Ce_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ce_n);
aesl_fh.write(AUTOTB_TVOUT_Ce_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ce_n_depth);
aesl_fh.write(AUTOTB_TVOUT_Ce_n, end_str());
}

// print Ce2 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Ce2, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ce2);
aesl_fh.write(AUTOTB_TVOUT_Ce2, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ce2_depth);
aesl_fh.write(AUTOTB_TVOUT_Ce2, end_str());
}

// print Ce2_n Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Ce2_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ce2_n);
aesl_fh.write(AUTOTB_TVOUT_Ce2_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ce2_n_depth);
aesl_fh.write(AUTOTB_TVOUT_Ce2_n, end_str());
}

// print Oe_n Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Oe_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Oe_n);
aesl_fh.write(AUTOTB_TVOUT_Oe_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Oe_n_depth);
aesl_fh.write(AUTOTB_TVOUT_Oe_n, end_str());
}

// print Rw_n Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Rw_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Rw_n);
aesl_fh.write(AUTOTB_TVOUT_Rw_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Rw_n_depth);
aesl_fh.write(AUTOTB_TVOUT_Rw_n, end_str());
}

// print Ld_n Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Ld_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Ld_n);
aesl_fh.write(AUTOTB_TVOUT_Ld_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Ld_n_depth);
aesl_fh.write(AUTOTB_TVOUT_Ld_n, end_str());
}

// print Cke_n Transactions
{
aesl_fh.write(AUTOTB_TVOUT_Cke_n, begin_str(AESL_transaction));
{
    sc_bv<1> __xlx_tmp_lv = *((char*)__xlx_apatb_param_Cke_n);
aesl_fh.write(AUTOTB_TVOUT_Cke_n, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.Cke_n_depth);
aesl_fh.write(AUTOTB_TVOUT_Cke_n, end_str());
}

CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
