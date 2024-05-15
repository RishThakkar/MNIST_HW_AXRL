// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+161,"clk", false,-1);
        vcdp->declBit(c+169,"rstn", false,-1);
        vcdp->declBit(c+177,"go", false,-1);
        vcdp->declBus(c+185,"layer_index", false,-1, 2,0);
        vcdp->declBus(c+193,"data_address", false,-1, 31,0);
        vcdp->declBus(c+201,"data_size", false,-1, 31,0);
        vcdp->declBus(c+209,"weight_address", false,-1, 31,0);
        vcdp->declBus(c+217,"weight_size", false,-1, 31,0);
        vcdp->declBus(c+225,"result_address", false,-1, 31,0);
        vcdp->declBit(c+233,"done", false,-1);
        vcdp->declBus(c+241,"top data_width", false,-1, 31,0);
        vcdp->declBus(c+241,"top weight_width", false,-1, 31,0);
        vcdp->declBit(c+161,"top clk", false,-1);
        vcdp->declBit(c+169,"top rstn", false,-1);
        vcdp->declBit(c+177,"top go", false,-1);
        vcdp->declBus(c+185,"top layer_index", false,-1, 2,0);
        vcdp->declBus(c+193,"top data_address", false,-1, 31,0);
        vcdp->declBus(c+201,"top data_size", false,-1, 31,0);
        vcdp->declBus(c+209,"top weight_address", false,-1, 31,0);
        vcdp->declBus(c+217,"top weight_size", false,-1, 31,0);
        vcdp->declBus(c+225,"top result_address", false,-1, 31,0);
        vcdp->declBit(c+233,"top done", false,-1);
        vcdp->declBit(c+65,"top en", false,-1);
        vcdp->declBit(c+73,"top init", false,-1);
        vcdp->declBit(c+81,"top mode", false,-1);
        vcdp->declBit(c+89,"top bias_en", false,-1);
        vcdp->declBus(c+1,"top data_idx", false,-1, 31,0);
        vcdp->declBus(c+9,"top weight_idx", false,-1, 31,0);
        vcdp->declBus(c+17,"top result_idx", false,-1, 31,0);
        vcdp->declBit(c+97,"top write_enable", false,-1);
        vcdp->declBus(c+25,"top result", false,-1, 7,0);
        vcdp->declBus(c+105,"top data", false,-1, 7,0);
        vcdp->declBus(c+113,"top weight", false,-1, 7,0);
        vcdp->declBit(c+161,"top control_unit clk", false,-1);
        vcdp->declBit(c+169,"top control_unit rstn", false,-1);
        vcdp->declBit(c+177,"top control_unit go", false,-1);
        vcdp->declBus(c+185,"top control_unit layer_index", false,-1, 2,0);
        vcdp->declBus(c+193,"top control_unit data_address", false,-1, 31,0);
        vcdp->declBus(c+201,"top control_unit data_size", false,-1, 31,0);
        vcdp->declBus(c+209,"top control_unit weight_address", false,-1, 31,0);
        vcdp->declBus(c+217,"top control_unit weight_size", false,-1, 31,0);
        vcdp->declBus(c+225,"top control_unit result_address", false,-1, 31,0);
        vcdp->declBit(c+233,"top control_unit done", false,-1);
        vcdp->declBit(c+65,"top control_unit en", false,-1);
        vcdp->declBit(c+73,"top control_unit init", false,-1);
        vcdp->declBit(c+81,"top control_unit mode", false,-1);
        vcdp->declBit(c+89,"top control_unit bias_en", false,-1);
        vcdp->declBus(c+1,"top control_unit data_idx", false,-1, 31,0);
        vcdp->declBus(c+9,"top control_unit weight_idx", false,-1, 31,0);
        vcdp->declBus(c+17,"top control_unit result_idx", false,-1, 31,0);
        vcdp->declBit(c+97,"top control_unit write_enable", false,-1);
        vcdp->declBus(c+121,"top control_unit current_state", false,-1, 4,0);
        vcdp->declBus(c+57,"top control_unit next_state", false,-1, 4,0);
        vcdp->declBus(c+249,"top control_unit data_counter", false,-1, 5,0);
        vcdp->declBus(c+257,"top control_unit weight_counter", false,-1, 3,0);
        vcdp->declBus(c+265,"top control_unit S0", false,-1, 31,0);
        vcdp->declBus(c+273,"top control_unit S1", false,-1, 31,0);
        vcdp->declBus(c+281,"top control_unit S2", false,-1, 31,0);
        vcdp->declBus(c+289,"top control_unit S3", false,-1, 31,0);
        vcdp->declBus(c+297,"top control_unit S4", false,-1, 31,0);
        vcdp->declBus(c+305,"top control_unit S5", false,-1, 31,0);
        vcdp->declBus(c+313,"top control_unit S6", false,-1, 31,0);
        vcdp->declBus(c+321,"top control_unit S7", false,-1, 31,0);
        vcdp->declBus(c+241,"top control_unit S8", false,-1, 31,0);
        vcdp->declBus(c+329,"top control_unit S9", false,-1, 31,0);
        vcdp->declBus(c+337,"top control_unit S10", false,-1, 31,0);
        vcdp->declBus(c+345,"top control_unit S11", false,-1, 31,0);
        vcdp->declBus(c+353,"top control_unit S12", false,-1, 31,0);
        vcdp->declBus(c+361,"top control_unit S13", false,-1, 31,0);
        vcdp->declBus(c+369,"top control_unit S14", false,-1, 31,0);
        vcdp->declBus(c+377,"top control_unit S15", false,-1, 31,0);
        vcdp->declBus(c+385,"top control_unit S16", false,-1, 31,0);
        vcdp->declBus(c+393,"top control_unit S17", false,-1, 31,0);
        vcdp->declBus(c+401,"top control_unit S18", false,-1, 31,0);
        vcdp->declBus(c+409,"top control_unit S19", false,-1, 31,0);
        vcdp->declBus(c+417,"top control_unit S20", false,-1, 31,0);
        vcdp->declBus(c+425,"top control_unit S21", false,-1, 31,0);
        vcdp->declBus(c+241,"top kernel_unit data_width", false,-1, 31,0);
        vcdp->declBus(c+241,"top kernel_unit weight_width", false,-1, 31,0);
        vcdp->declBit(c+161,"top kernel_unit clk", false,-1);
        vcdp->declBit(c+65,"top kernel_unit en", false,-1);
        vcdp->declBit(c+73,"top kernel_unit init", false,-1);
        vcdp->declBit(c+81,"top kernel_unit mode", false,-1);
        vcdp->declBit(c+89,"top kernel_unit bias_en", false,-1);
        vcdp->declBus(c+105,"top kernel_unit data", false,-1, 7,0);
        vcdp->declBus(c+113,"top kernel_unit weight", false,-1, 7,0);
        vcdp->declBus(c+25,"top kernel_unit result", false,-1, 7,0);
        vcdp->declBus(c+129,"top kernel_unit mac_result", false,-1, 15,0);
        vcdp->declBus(c+137,"top kernel_unit mac_result_q", false,-1, 12,0);
        vcdp->declBus(c+33,"top kernel_unit relu_result", false,-1, 7,0);
        vcdp->declBus(c+145,"top kernel_unit comp_result", false,-1, 7,0);
        vcdp->declBit(c+41,"top kernel_unit overflow", false,-1);
        vcdp->declBit(c+433,"top kernel_unit carry", false,-1);
        vcdp->declBit(c+49,"top kernel_unit checkbit", false,-1);
        vcdp->declBus(c+153,"top kernel_unit tmp", false,-1, 1,0);
        vcdp->declBus(c+241,"top memory_unit data_width", false,-1, 31,0);
        vcdp->declBus(c+241,"top memory_unit weight_width", false,-1, 31,0);
        vcdp->declBit(c+161,"top memory_unit clk", false,-1);
        vcdp->declBit(c+169,"top memory_unit rstn", false,-1);
        vcdp->declBit(c+81,"top memory_unit mode", false,-1);
        vcdp->declBus(c+1,"top memory_unit data_idx", false,-1, 31,0);
        vcdp->declBus(c+9,"top memory_unit weight_idx", false,-1, 31,0);
        vcdp->declBus(c+17,"top memory_unit result_idx", false,-1, 31,0);
        vcdp->declBit(c+97,"top memory_unit write_enable", false,-1);
        vcdp->declBus(c+25,"top memory_unit result", false,-1, 7,0);
        vcdp->declBus(c+105,"top memory_unit data", false,-1, 7,0);
        vcdp->declBus(c+113,"top memory_unit weight", false,-1, 7,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->top__DOT__data_idx),32);
        vcdp->fullBus(c+9,(vlTOPp->top__DOT__weight_idx),32);
        vcdp->fullBus(c+17,(vlTOPp->top__DOT__result_idx),32);
        vcdp->fullBus(c+25,(vlTOPp->top__DOT__result),8);
        vcdp->fullBus(c+33,((0xffU & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__overflow)
                                       ? ((0x1000U 
                                           & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                           ? 0U : (0xffU 
                                                   & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                      >> 3U)))
                                       : ((0x800U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                           ? 0U : (0xffU 
                                                   & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                      >> 3U)))))),8);
        vcdp->fullBit(c+41,(vlTOPp->top__DOT__kernel_unit__DOT__overflow));
        vcdp->fullBit(c+49,((1U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__overflow)
                                    ? ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                       >> 0xcU) : ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                   >> 0xbU)))));
        vcdp->fullBus(c+57,(vlTOPp->top__DOT__control_unit__DOT__next_state),5);
        vcdp->fullBit(c+65,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                   >> 4U))));
        vcdp->fullBit(c+73,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                   >> 3U))));
        vcdp->fullBit(c+81,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                   >> 2U))));
        vcdp->fullBit(c+89,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                   >> 5U))));
        vcdp->fullBit(c+97,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                   >> 1U))));
        vcdp->fullBus(c+105,(vlTOPp->top__DOT__data),8);
        vcdp->fullBus(c+113,(vlTOPp->top__DOT__weight),8);
        vcdp->fullBus(c+121,(vlTOPp->top__DOT__control_unit__DOT__current_state),5);
        vcdp->fullBus(c+129,(vlTOPp->top__DOT__kernel_unit__DOT__mac_result),16);
        vcdp->fullBus(c+137,(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q),13);
        vcdp->fullBus(c+145,(vlTOPp->top__DOT__kernel_unit__DOT__comp_result),8);
        vcdp->fullBus(c+153,(vlTOPp->top__DOT__kernel_unit__DOT__tmp),2);
        vcdp->fullBit(c+161,(vlTOPp->clk));
        vcdp->fullBit(c+169,(vlTOPp->rstn));
        vcdp->fullBit(c+177,(vlTOPp->go));
        vcdp->fullBus(c+185,(vlTOPp->layer_index),3);
        vcdp->fullBus(c+193,(vlTOPp->data_address),32);
        vcdp->fullBus(c+201,(vlTOPp->data_size),32);
        vcdp->fullBus(c+209,(vlTOPp->weight_address),32);
        vcdp->fullBus(c+217,(vlTOPp->weight_size),32);
        vcdp->fullBus(c+225,(vlTOPp->result_address),32);
        vcdp->fullBit(c+233,(vlTOPp->done));
        vcdp->fullBus(c+241,(8U),32);
        vcdp->fullBus(c+249,(vlTOPp->top__DOT__control_unit__DOT__data_counter),6);
        vcdp->fullBus(c+257,(vlTOPp->top__DOT__control_unit__DOT__weight_counter),4);
        vcdp->fullBus(c+265,(0U),32);
        vcdp->fullBus(c+273,(1U),32);
        vcdp->fullBus(c+281,(2U),32);
        vcdp->fullBus(c+289,(3U),32);
        vcdp->fullBus(c+297,(4U),32);
        vcdp->fullBus(c+305,(5U),32);
        vcdp->fullBus(c+313,(6U),32);
        vcdp->fullBus(c+321,(7U),32);
        vcdp->fullBus(c+329,(9U),32);
        vcdp->fullBus(c+337,(0xaU),32);
        vcdp->fullBus(c+345,(0xbU),32);
        vcdp->fullBus(c+353,(0xcU),32);
        vcdp->fullBus(c+361,(0xdU),32);
        vcdp->fullBus(c+369,(0xeU),32);
        vcdp->fullBus(c+377,(0xfU),32);
        vcdp->fullBus(c+385,(0x10U),32);
        vcdp->fullBus(c+393,(0x11U),32);
        vcdp->fullBus(c+401,(0x12U),32);
        vcdp->fullBus(c+409,(0x13U),32);
        vcdp->fullBus(c+417,(0x14U),32);
        vcdp->fullBus(c+425,(0x15U),32);
        vcdp->fullBit(c+433,(vlTOPp->top__DOT__kernel_unit__DOT__carry));
    }
}
