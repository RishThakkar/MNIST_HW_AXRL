// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->top__DOT__data_idx),32);
        vcdp->chgBus(c+9,(vlTOPp->top__DOT__weight_idx),32);
        vcdp->chgBus(c+17,(vlTOPp->top__DOT__result_idx),32);
        vcdp->chgBus(c+25,(vlTOPp->top__DOT__result),8);
        vcdp->chgBus(c+33,((0xffU & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__overflow)
                                      ? ((0x1000U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                          ? 0U : (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                     >> 3U)))
                                      : ((0x800U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                          ? 0U : (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                     >> 3U)))))),8);
        vcdp->chgBit(c+41,(vlTOPp->top__DOT__kernel_unit__DOT__overflow));
        vcdp->chgBit(c+49,((1U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__overflow)
                                   ? ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                      >> 0xcU) : ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                  >> 0xbU)))));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+57,(vlTOPp->top__DOT__control_unit__DOT__next_state),5);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+65,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                  >> 4U))));
        vcdp->chgBit(c+73,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                  >> 3U))));
        vcdp->chgBit(c+81,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                  >> 2U))));
        vcdp->chgBit(c+89,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                  >> 5U))));
        vcdp->chgBit(c+97,((1U & (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                  >> 1U))));
        vcdp->chgBus(c+105,(vlTOPp->top__DOT__data),8);
        vcdp->chgBus(c+113,(vlTOPp->top__DOT__weight),8);
        vcdp->chgBus(c+121,(vlTOPp->top__DOT__control_unit__DOT__current_state),5);
        vcdp->chgBus(c+129,(vlTOPp->top__DOT__kernel_unit__DOT__mac_result),16);
        vcdp->chgBus(c+137,(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q),13);
        vcdp->chgBus(c+145,(vlTOPp->top__DOT__kernel_unit__DOT__comp_result),8);
        vcdp->chgBus(c+153,(vlTOPp->top__DOT__kernel_unit__DOT__tmp),2);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+161,(vlTOPp->clk));
        vcdp->chgBit(c+169,(vlTOPp->rstn));
        vcdp->chgBit(c+177,(vlTOPp->go));
        vcdp->chgBus(c+185,(vlTOPp->layer_index),3);
        vcdp->chgBus(c+193,(vlTOPp->data_address),32);
        vcdp->chgBus(c+201,(vlTOPp->data_size),32);
        vcdp->chgBus(c+209,(vlTOPp->weight_address),32);
        vcdp->chgBus(c+217,(vlTOPp->weight_size),32);
        vcdp->chgBus(c+225,(vlTOPp->result_address),32);
        vcdp->chgBit(c+233,(vlTOPp->done));
    }
}
