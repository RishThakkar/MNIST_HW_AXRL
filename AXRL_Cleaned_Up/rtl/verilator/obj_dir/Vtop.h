// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rstn,0,0);
    VL_IN8(go,0,0);
    VL_IN8(layer_index,2,0);
    VL_OUT8(done,0,0);
    VL_IN(data_address,31,0);
    VL_IN(data_size,31,0);
    VL_IN(weight_address,31,0);
    VL_IN(weight_size,31,0);
    VL_IN(result_address,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ top__DOT__result;
    CData/*7:0*/ top__DOT__data;
    CData/*7:0*/ top__DOT__weight;
    CData/*4:0*/ top__DOT__control_unit__DOT__current_state;
    CData/*4:0*/ top__DOT__control_unit__DOT__next_state;
    CData/*5:0*/ top__DOT__control_unit__DOT__data_counter;
    CData/*3:0*/ top__DOT__control_unit__DOT__weight_counter;
    CData/*7:0*/ top__DOT__kernel_unit__DOT__comp_result;
    CData/*0:0*/ top__DOT__kernel_unit__DOT__overflow;
    CData/*0:0*/ top__DOT__kernel_unit__DOT__carry;
    CData/*1:0*/ top__DOT__kernel_unit__DOT__tmp;
    SData/*15:0*/ top__DOT__kernel_unit__DOT__mac_result;
    SData/*12:0*/ top__DOT__kernel_unit__DOT__mac_result_q;
    IData/*31:0*/ top__DOT__data_idx;
    IData/*31:0*/ top__DOT__weight_idx;
    IData/*31:0*/ top__DOT__result_idx;
    WData/*193:0*/ top__DOT__control_unit__DOT__cs[7];
    WData/*193:0*/ top__DOT__control_unit__DOT__ns[7];
    CData/*7:0*/ top__DOT__memory_unit__DOT__memory_A0[6400];
    CData/*7:0*/ top__DOT__memory_unit__DOT__memory_A1[6400];
    CData/*7:0*/ top__DOT__memory_unit__DOT__memory_B[6400];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ top__DOT__memory_unit__DOT____Vlvbound1;
    CData/*7:0*/ top__DOT__memory_unit__DOT____Vlvbound2;
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
