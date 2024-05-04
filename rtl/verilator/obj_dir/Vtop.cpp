// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/user/stud/fall23/vp2518/EmbeddedSystems/Project/src/top.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/user/stud/fall23/vp2518/EmbeddedSystems/Project/src/top.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__top__DOT__kernel_unit__DOT__comp_result;
    CData/*7:0*/ __Vdlyvval__top__DOT__memory_unit__DOT__memory_A0__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__memory_unit__DOT__memory_A0__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__memory_unit__DOT__memory_A1__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__memory_unit__DOT__memory_A1__v0;
    SData/*15:0*/ __Vdly__top__DOT__kernel_unit__DOT__mac_result;
    SData/*12:0*/ __Vdlyvdim0__top__DOT__memory_unit__DOT__memory_A0__v0;
    SData/*12:0*/ __Vdlyvdim0__top__DOT__memory_unit__DOT__memory_A1__v0;
    // Body
    __Vdlyvset__top__DOT__memory_unit__DOT__memory_A1__v0 = 0U;
    __Vdlyvset__top__DOT__memory_unit__DOT__memory_A0__v0 = 0U;
    __Vdly__top__DOT__kernel_unit__DOT__comp_result 
        = vlTOPp->top__DOT__kernel_unit__DOT__comp_result;
    __Vdly__top__DOT__kernel_unit__DOT__mac_result 
        = vlTOPp->top__DOT__kernel_unit__DOT__mac_result;
    vlTOPp->top__DOT__control_unit__DOT__current_state 
        = ((IData)(vlTOPp->rstn) ? (IData)(vlTOPp->top__DOT__control_unit__DOT__next_state)
            : 0U);
    if ((1U & (~ (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                  >> 2U)))) {
        if ((2U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
            vlTOPp->top__DOT__memory_unit__DOT____Vlvbound2 
                = vlTOPp->top__DOT__result;
            if ((0x18ffU >= (0x1fffU & vlTOPp->top__DOT__result_idx))) {
                __Vdlyvval__top__DOT__memory_unit__DOT__memory_A1__v0 
                    = vlTOPp->top__DOT__memory_unit__DOT____Vlvbound2;
                __Vdlyvset__top__DOT__memory_unit__DOT__memory_A1__v0 = 1U;
                __Vdlyvdim0__top__DOT__memory_unit__DOT__memory_A1__v0 
                    = (0x1fffU & vlTOPp->top__DOT__result_idx);
            }
        }
    }
    if ((4U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
        if ((2U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
            vlTOPp->top__DOT__memory_unit__DOT____Vlvbound1 
                = vlTOPp->top__DOT__result;
            if ((0x18ffU >= (0x1fffU & vlTOPp->top__DOT__result_idx))) {
                __Vdlyvval__top__DOT__memory_unit__DOT__memory_A0__v0 
                    = vlTOPp->top__DOT__memory_unit__DOT____Vlvbound1;
                __Vdlyvset__top__DOT__memory_unit__DOT__memory_A0__v0 = 1U;
                __Vdlyvdim0__top__DOT__memory_unit__DOT__memory_A0__v0 
                    = (0x1fffU & vlTOPp->top__DOT__result_idx);
            }
        }
    }
    if ((8U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
        __Vdly__top__DOT__kernel_unit__DOT__comp_result = 0U;
    } else {
        if ((0x10U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
            __Vdly__top__DOT__kernel_unit__DOT__comp_result 
                = (((IData)(vlTOPp->top__DOT__data) 
                    > (IData)(vlTOPp->top__DOT__kernel_unit__DOT__comp_result))
                    ? (IData)(vlTOPp->top__DOT__data)
                    : (IData)(vlTOPp->top__DOT__kernel_unit__DOT__comp_result));
        }
    }
    if ((8U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
        __Vdly__top__DOT__kernel_unit__DOT__mac_result = 0U;
    } else {
        if ((0x10U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
            if ((0x20U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q 
                    = (0x1fffU & ((0xfffU & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result) 
                                             >> 4U)) 
                                  + ((0xf00U & (VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->top__DOT__weight) 
                                                                        >> 7U)))) 
                                                << 8U)) 
                                     | (IData)(vlTOPp->top__DOT__weight))));
                vlTOPp->top__DOT__kernel_unit__DOT__tmp 
                    = ((2U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__tmp)) 
                       | (1U & (((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result) 
                                 >> 0xfU) ^ ((IData)(vlTOPp->top__DOT__weight) 
                                             >> 7U))));
                vlTOPp->top__DOT__kernel_unit__DOT__tmp 
                    = ((1U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__tmp)) 
                       | (2U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result) 
                                >> 0xeU)));
            } else {
                __Vdly__top__DOT__kernel_unit__DOT__mac_result 
                    = (0xffffU & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result) 
                                  + (((0xff00U & (VL_NEGATE_I((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->top__DOT__data) 
                                                                          >> 7U)))) 
                                                  << 8U)) 
                                      | (IData)(vlTOPp->top__DOT__data)) 
                                     * ((0xff00U & 
                                         (VL_NEGATE_I((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->top__DOT__weight) 
                                                                  >> 7U)))) 
                                          << 8U)) | (IData)(vlTOPp->top__DOT__weight)))));
            }
        }
    }
    vlTOPp->top__DOT__kernel_unit__DOT__comp_result 
        = __Vdly__top__DOT__kernel_unit__DOT__comp_result;
    vlTOPp->top__DOT__kernel_unit__DOT__mac_result 
        = __Vdly__top__DOT__kernel_unit__DOT__mac_result;
    vlTOPp->top__DOT__weight = ((0x18ffU >= (0x1fffU 
                                             & vlTOPp->top__DOT__weight_idx))
                                 ? vlTOPp->top__DOT__memory_unit__DOT__memory_B
                                [(0x1fffU & vlTOPp->top__DOT__weight_idx)]
                                 : 0U);
    vlTOPp->top__DOT__kernel_unit__DOT__overflow = 
        ((1U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__tmp))
          ? 0U : (1U & ((1U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                               >> 0xbU)) ^ (1U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__tmp) 
                                                  >> 1U)))));
    vlTOPp->top__DOT__data = ((4U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])
                               ? ((0x18ffU >= (0x1fffU 
                                               & vlTOPp->top__DOT__data_idx))
                                   ? vlTOPp->top__DOT__memory_unit__DOT__memory_A1
                                  [(0x1fffU & vlTOPp->top__DOT__data_idx)]
                                   : 0U) : ((0x18ffU 
                                             >= (0x1fffU 
                                                 & vlTOPp->top__DOT__data_idx))
                                             ? vlTOPp->top__DOT__memory_unit__DOT__memory_A0
                                            [(0x1fffU 
                                              & vlTOPp->top__DOT__data_idx)]
                                             : 0U));
    if (__Vdlyvset__top__DOT__memory_unit__DOT__memory_A1__v0) {
        vlTOPp->top__DOT__memory_unit__DOT__memory_A1[__Vdlyvdim0__top__DOT__memory_unit__DOT__memory_A1__v0] 
            = __Vdlyvval__top__DOT__memory_unit__DOT__memory_A1__v0;
    }
    if (__Vdlyvset__top__DOT__memory_unit__DOT__memory_A0__v0) {
        vlTOPp->top__DOT__memory_unit__DOT__memory_A0[__Vdlyvdim0__top__DOT__memory_unit__DOT__memory_A0__v0] 
            = __Vdlyvval__top__DOT__memory_unit__DOT__memory_A0__v0;
    }
    if (vlTOPp->rstn) {
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[0U];
        vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[1U];
        vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[2U];
        vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[3U];
        vlTOPp->top__DOT__control_unit__DOT__cs[4U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[4U];
        vlTOPp->top__DOT__control_unit__DOT__cs[5U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[5U];
        vlTOPp->top__DOT__control_unit__DOT__cs[6U] 
            = vlTOPp->top__DOT__control_unit__DOT__ns[6U];
    } else {
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xfffffffbU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xfffffffeU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
            = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__cs[2U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
            = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__cs[3U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
            = (0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__cs[2U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
            = (0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__cs[2U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
            = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__cs[1U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
            = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__cs[2U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
            = (0x8fffffffU & vlTOPp->top__DOT__control_unit__DOT__cs[1U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
            = (0xf0007fffU & vlTOPp->top__DOT__control_unit__DOT__cs[1U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
            = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__cs[1U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xffffffU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
            = (0xfffffff8U & vlTOPp->top__DOT__control_unit__DOT__cs[1U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xff0fffffU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xfff03fffU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xffffc0ffU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
        vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
            = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
    }
    vlTOPp->top__DOT__data_idx = (((((vlTOPp->top__DOT__control_unit__DOT__cs[6U] 
                                      << 0x1eU) | (
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[5U] 
                                                   >> 2U)) 
                                    + (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                  << 7U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    >> 0x19U)))) 
                                   + (0x1fffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0xfU)))) 
                                  + (0x7ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                << 8U) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                  >> 0x18U))));
    vlTOPp->top__DOT__weight_idx = (((((vlTOPp->top__DOT__control_unit__DOT__cs[5U] 
                                        << 0x1eU) | 
                                       (vlTOPp->top__DOT__control_unit__DOT__cs[4U] 
                                        >> 2U)) + (0xfU 
                                                   & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                       << 0xbU) 
                                                      | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                         >> 0x15U)))) 
                                     + (0xfffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 0x1dU) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 3U)))) 
                                    + (0xfU & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                << 0xcU) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                  >> 0x14U))));
    vlTOPp->top__DOT__result_idx = (((vlTOPp->top__DOT__control_unit__DOT__cs[4U] 
                                      << 0x1eU) | (
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                   >> 2U)) 
                                    + (0x1fffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                     >> 8U))));
    vlTOPp->done = (1U & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
    vlTOPp->top__DOT__result = (0xffU & ((4U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])
                                          ? (IData)(vlTOPp->top__DOT__kernel_unit__DOT__comp_result)
                                          : ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__overflow)
                                              ? ((0x1000U 
                                                  & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                     >> 3U)))
                                              : ((0x800U 
                                                  & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                     >> 3U))))));
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__kernel_unit__DOT__overflow = 
        ((1U & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__tmp))
          ? 0U : (1U & ((1U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                               >> 0xbU)) ^ (1U & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__tmp) 
                                                  >> 1U)))));
    vlTOPp->top__DOT__data_idx = (((((vlTOPp->top__DOT__control_unit__DOT__cs[6U] 
                                      << 0x1eU) | (
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[5U] 
                                                   >> 2U)) 
                                    + (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                  << 7U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    >> 0x19U)))) 
                                   + (0x1fffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0xfU)))) 
                                  + (0x7ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                << 8U) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                  >> 0x18U))));
    vlTOPp->top__DOT__weight_idx = (((((vlTOPp->top__DOT__control_unit__DOT__cs[5U] 
                                        << 0x1eU) | 
                                       (vlTOPp->top__DOT__control_unit__DOT__cs[4U] 
                                        >> 2U)) + (0xfU 
                                                   & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                       << 0xbU) 
                                                      | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                         >> 0x15U)))) 
                                     + (0xfffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 0x1dU) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 3U)))) 
                                    + (0xfU & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                << 0xcU) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                  >> 0x14U))));
    vlTOPp->top__DOT__result_idx = (((vlTOPp->top__DOT__control_unit__DOT__cs[4U] 
                                      << 0x1eU) | (
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                   >> 2U)) 
                                    + (0x1fffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                     >> 8U))));
    vlTOPp->done = (1U & vlTOPp->top__DOT__control_unit__DOT__cs[0U]);
    if (((((((((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
               | (1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
            | (4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
           | (5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
          | (6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
         | (7U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
        if ((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
            if (vlTOPp->go) {
                if ((0U == (IData)(vlTOPp->layer_index))) {
                    vlTOPp->top__DOT__control_unit__DOT__next_state = 1U;
                } else {
                    if ((1U == (IData)(vlTOPp->layer_index))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 6U;
                    } else {
                        if ((2U == (IData)(vlTOPp->layer_index))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 9U;
                        } else {
                            if ((3U == (IData)(vlTOPp->layer_index))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0xeU;
                            } else {
                                if ((4U == (IData)(vlTOPp->layer_index))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0x11U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                if ((0U != (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                       << 1U) | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                    if ((1U & (~ ((2U == (0x1ffU & 
                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU)))) 
                                  | (5U == (0x1ffU 
                                            & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                << 1U) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                  >> 0x1fU)))))))) {
                        if ((8U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                               << 1U) 
                                              | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 2U;
                            if ((0x27U == (0x3fU & 
                                           ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                             << 0x12U) 
                                            | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                               >> 0xeU))))) {
                                if ((0x27U == (0x3fU 
                                               & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                     >> 8U))))) {
                                    if ((3U == (0xfU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 0xbU) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x15U))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__next_state = 4U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    vlTOPp->top__DOT__control_unit__DOT__next_state = 3U;
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 1U;
                    } else {
                        if ((4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 5U;
                        } else {
                            if ((5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
                            } else {
                                if ((6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    if ((0U != (0x1ffU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))))) {
                                        if ((1U != 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            if ((3U 
                                                 == 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__next_state = 7U;
                                                if (
                                                    (0x26U 
                                                     == 
                                                     (0x3fU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          << 0x12U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                            >> 0xeU))))) {
                                                    if (
                                                        (0x26U 
                                                         == 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 8U))))) {
                                                        if (
                                                            (3U 
                                                             == 
                                                             (0xfU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                  << 0xbU) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                    >> 0x15U))))) {
                                                            vlTOPp->top__DOT__control_unit__DOT__next_state = 8U;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 6U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (((((((((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
                   | (9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                  | (0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                 | (0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                | (0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
               | (0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (0xfU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
            if ((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
            } else {
                if ((9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    if ((0U != (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        if ((1U & (~ ((2U == (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU)))) 
                                      | (5U == (0x1ffU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU)))))))) {
                            if ((8U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                                if ((3U == (7U & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 4U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1cU))))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0xaU;
                                    if ((0x11U == (0x3fU 
                                                   & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                       << 0x12U) 
                                                      | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                         >> 0xeU))))) {
                                        if ((0x11U 
                                             == (0x3fU 
                                                 & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     << 0x18U) 
                                                    | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                       >> 8U))))) {
                                            if ((3U 
                                                 == 
                                                 (0xfU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0xbU) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 0x15U))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0xcU;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 0xbU;
                    } else {
                        if ((0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 9U;
                        } else {
                            if ((0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0xdU;
                            } else {
                                if ((0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
                                } else {
                                    if ((0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                        if ((0U != 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            if ((1U 
                                                 != 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                if (
                                                    (3U 
                                                     == 
                                                     (0x1ffU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          << 1U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                            >> 0x1fU))))) {
                                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0xfU;
                                                    if (
                                                        (0x10U 
                                                         == 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x12U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 0xeU))))) {
                                                        if (
                                                            (0x10U 
                                                             == 
                                                             (0x3fU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                  << 0x18U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                    >> 8U))))) {
                                                            if (
                                                                (3U 
                                                                 == 
                                                                 (0xfU 
                                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                      << 0xbU) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                        >> 0x15U))))) {
                                                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0x10U;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__control_unit__DOT__next_state = 0xeU;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
            } else {
                if ((0x11U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    if ((0U != (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        if ((0x143U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 0x12U;
                            if ((9U == (0xfU & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 0xbU) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x15U))))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0x14U;
                            }
                        }
                    }
                } else {
                    if ((0x12U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 0x13U;
                    } else {
                        if ((0x13U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 0x11U;
                        } else {
                            if ((0x14U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0x15U;
                            } else {
                                if ((0x15U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__control_unit__DOT__ns[0U] = vlTOPp->top__DOT__control_unit__DOT__cs[0U];
    vlTOPp->top__DOT__control_unit__DOT__ns[1U] = vlTOPp->top__DOT__control_unit__DOT__cs[1U];
    vlTOPp->top__DOT__control_unit__DOT__ns[2U] = vlTOPp->top__DOT__control_unit__DOT__cs[2U];
    vlTOPp->top__DOT__control_unit__DOT__ns[3U] = vlTOPp->top__DOT__control_unit__DOT__cs[3U];
    vlTOPp->top__DOT__control_unit__DOT__ns[4U] = vlTOPp->top__DOT__control_unit__DOT__cs[4U];
    vlTOPp->top__DOT__control_unit__DOT__ns[5U] = vlTOPp->top__DOT__control_unit__DOT__cs[5U];
    vlTOPp->top__DOT__control_unit__DOT__ns[6U] = vlTOPp->top__DOT__control_unit__DOT__cs[6U];
    if (((((((((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
               | (1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
            | (4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
           | (5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
          | (6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
         | (7U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
        if ((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                = (0xfffffffeU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                = (0xf0007fffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
            if (vlTOPp->go) {
                vlTOPp->top__DOT__control_unit__DOT__ns[5U] 
                    = ((3U & vlTOPp->top__DOT__control_unit__DOT__ns[5U]) 
                       | (0xfffffffcU & (vlTOPp->data_address 
                                         << 2U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[6U] 
                    = (3U & (vlTOPp->data_address >> 0x1eU));
                vlTOPp->top__DOT__control_unit__DOT__ns[4U] 
                    = ((3U & vlTOPp->top__DOT__control_unit__DOT__ns[4U]) 
                       | (0xfffffffcU & (vlTOPp->weight_address 
                                         << 2U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[5U] 
                    = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[5U]) 
                       | (3U & (vlTOPp->weight_address 
                                >> 0x1eU)));
                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                    = ((3U & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                       | (0xfffffffcU & (vlTOPp->result_address 
                                         << 2U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[4U] 
                    = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[4U]) 
                       | (3U & (vlTOPp->result_address 
                                >> 0x1eU)));
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                if ((0U == (IData)(vlTOPp->layer_index))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffffbU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                } else {
                    if ((1U == (IData)(vlTOPp->layer_index))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (4U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((2U == (IData)(vlTOPp->layer_index))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xfffffffbU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((3U == (IData)(vlTOPp->layer_index))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (4U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((4U == (IData)(vlTOPp->layer_index))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xfffffffbU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                    = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                       | (0xfe000000U & (((IData)(1U) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                              << 7U) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                >> 0x19U))) 
                                         << 0x19U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                    = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                       | (3U & (((IData)(1U) + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 7U) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x19U))) 
                                >> 7U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                    = ((0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                       | (0x80000000U & (((IData)(1U) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 1U) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 0x1fU))) 
                                         << 0x1fU)));
                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                    = ((0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                       | (0xffU & (((IData)(1U) + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))) 
                                   >> 1U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                    = ((0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                       | (0x7ff8U & (((IData)(4U) + 
                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                        << 0x1dU) | 
                                       (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                        >> 3U))) << 3U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                if ((0U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                       << 1U) | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0x10U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    if ((0x40U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                            = ((0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                               | (0x1fff00U & (((IData)(1U) 
                                                + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 8U))) 
                                               << 8U)));
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    }
                } else {
                    if (((2U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU)))) 
                         | (5U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 1U) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 0x1fU)))))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                            = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                               | (0xfe000000U & (((IData)(0x28U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 7U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x19U))) 
                                                 << 0x19U)));
                        vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                            = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                               | (3U & (((IData)(0x28U) 
                                         + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                             << 7U) 
                                            | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                               >> 0x19U))) 
                                        >> 7U)));
                    } else {
                        if ((8U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                               << 1U) 
                                              | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            if ((0x27U != (0x3fU & 
                                           ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                             << 0x12U) 
                                            | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                               >> 0xeU))))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                    = ((0xf0007fffU 
                                        & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                       | (0xfff8000U 
                                          & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0xfU))) 
                                             << 0xfU)));
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = ((0xfff03fffU 
                                        & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                       | (0xfc000U 
                                          & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                  << 0x12U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                    >> 0xeU))) 
                                             << 0xeU)));
                            } else {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xfff03fffU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                if ((0x27U != (0x3fU 
                                               & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                     >> 8U))))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0xf0007fffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (0xfff8000U 
                                              & (((IData)(3U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0xfU))) 
                                                 << 0xfU)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = ((0xffffc0ffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                           | (0x3f00U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 8U))) 
                                                 << 8U)));
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0xf0007fffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffc0ffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    if ((3U != (0xfU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 0xbU) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x15U))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0x80U 
                                               | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    if ((0x80U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                            = ((0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                               | (0x1e00000U & (((IData)(1U) 
                                                 + 
                                                 ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                   << 0xbU) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                     >> 0x15U))) 
                                                << 0x15U)));
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    }
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x40U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xffffffdfU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                        = ((0x1ffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                           | (0xfe000000U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 7U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x19U))) 
                                                 << 0x19U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                        = ((0xfffffffcU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                           | (3U & 
                                              (((IData)(1U) 
                                                + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 7U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x19U))) 
                                               >> 7U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0x7fffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (0x80000000U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))) 
                                                 << 0x1fU)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                        = ((0xffffff00U 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                           | (0xffU 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))) 
                                                 >> 1U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xfffffffdU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    if ((0U == (0x1ffU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xfffffff7U 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0x10U 
                                               | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        if ((0x40U 
                                             & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                = (
                                                   (0xffe000ffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                   | (0x1fff00U 
                                                      & (((IData)(1U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                            << 0x18U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                              >> 8U))) 
                                                         << 8U)));
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0xffffffbfU 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        }
                                    } else {
                                        if ((1U == 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                = (
                                                   (0x1ffffffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                   | (0xfe000000U 
                                                      & (((IData)(0x27U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                            << 7U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                              >> 0x19U))) 
                                                         << 0x19U)));
                                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                = (
                                                   (0xfffffffcU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                                   | (3U 
                                                      & (((IData)(0x27U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                            << 7U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                              >> 0x19U))) 
                                                         >> 7U)));
                                        } else {
                                            if ((3U 
                                                 == 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    (0x1ffffffU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                    = 
                                                    (0xfffffffcU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                                                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                    = 
                                                    (0x7fffffffU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    (0xffffff00U 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                if (
                                                    (0x26U 
                                                     != 
                                                     (0x3fU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          << 0x12U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                            >> 0xeU))))) {
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                        = 
                                                        ((0xf0007fffU 
                                                          & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                         | (0xfff8000U 
                                                            & (((IData)(2U) 
                                                                + 
                                                                ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                  << 0x11U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                    >> 0xfU))) 
                                                               << 0xfU)));
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                        = 
                                                        ((0xfff03fffU 
                                                          & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                         | (0xfc000U 
                                                            & (((IData)(2U) 
                                                                + 
                                                                ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                  << 0x12U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                    >> 0xeU))) 
                                                               << 0xeU)));
                                                } else {
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                        = 
                                                        (0xfff03fffU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                        = 
                                                        ((0xf0007fffU 
                                                          & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                         | (0xfff8000U 
                                                            & (((IData)(0x2aU) 
                                                                + 
                                                                ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                  << 0x11U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                    >> 0xfU))) 
                                                               << 0xfU)));
                                                    if (
                                                        (0x26U 
                                                         != 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 8U))))) {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            ((0xffffc0ffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                             | (0x3f00U 
                                                                & (((IData)(2U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                      << 0x18U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                        >> 8U))) 
                                                                   << 8U)));
                                                    } else {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            (0xffffc0ffU 
                                                             & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                        if (
                                                            (3U 
                                                             != 
                                                             (0xfU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                  << 0xbU) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                    >> 0x15U))))) {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                                = 
                                                                ((0xfe1fffffU 
                                                                  & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                                 | (0x1e00000U 
                                                                    & (((IData)(1U) 
                                                                        + 
                                                                        ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                          << 0xbU) 
                                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                            >> 0x15U))) 
                                                                       << 0x15U)));
                                                        } else {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                                = 
                                                                (0xf0007fffU 
                                                                 & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffefU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0x40U | 
                                           vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (((((((((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
                   | (9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                  | (0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                 | (0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                | (0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
               | (0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (0xfU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
            if ((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            } else {
                if ((9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xfe000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                  << 7U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    >> 0x19U))) 
                                             << 0x19U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                        = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                           | (3U & (((IData)(1U) + 
                                     ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                       << 7U) | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                 >> 0x19U))) 
                                    >> 7U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x80000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))) 
                                             << 0x1fU)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xffU & (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU))) 
                                       >> 1U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x7ff8U & (((IData)(0x10U) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 0x1dU) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 3U))) 
                                         << 3U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    if ((0U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x10U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        if ((0x40U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1fff00U & (
                                                   ((IData)(1U) 
                                                    + 
                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0x18U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 8U))) 
                                                   << 8U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                    } else {
                        if (((2U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                << 1U) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                  >> 0x1fU)))) 
                             | (5U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU)))))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0xfe000000U & 
                                      (((IData)(0x12U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                            << 7U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              >> 0x19U))) 
                                       << 0x19U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                   | (3U & (((IData)(0x12U) 
                                             + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 7U) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x19U))) 
                                            >> 7U)));
                        } else {
                            if ((8U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                    = (0x1ffffffU & 
                                       vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                    = (0xfffffffcU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                    = (0x7fffffffU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                    = (0xffffff00U 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                if ((3U != (7U & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 4U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1cU))))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0x8fffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (0x70000000U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 4U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1cU))) 
                                                 << 0x1cU)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = ((0xffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                           | (0xff000000U 
                                              & (((IData)(0x190U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 8U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 0x18U))) 
                                                 << 0x18U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0xfffffff8U 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (7U & 
                                              (((IData)(0x190U) 
                                                + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 8U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 0x18U))) 
                                               >> 8U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = ((0xff0fffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                           | (0xf00000U 
                                              & (((IData)(4U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 0x14U))) 
                                                 << 0x14U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0xffff8007U 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0x8fffffffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0xfffffff8U 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xff0fffffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    if ((0x11U != (0x3fU 
                                                   & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                       << 0x12U) 
                                                      | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                         >> 0xeU))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                            = ((0xf0007fffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                               | (0xfff8000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        << 0x11U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          >> 0xfU))) 
                                                     << 0xfU)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = ((0xfff03fffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                               | (0xfc000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        << 0x12U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                          >> 0xeU))) 
                                                     << 0xeU)));
                                    } else {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xfff03fffU 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        if ((0x11U 
                                             != (0x3fU 
                                                 & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     << 0x18U) 
                                                    | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                       >> 8U))))) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                = (
                                                   (0xf0007fffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                   | (0xfff8000U 
                                                      & (((IData)(3U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                            << 0x11U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              >> 0xfU))) 
                                                         << 0xfU)));
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (
                                                   (0xffffc0ffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                   | (0x3f00U 
                                                      & (((IData)(1U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                            << 0x18U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                              >> 8U))) 
                                                         << 8U)));
                                        } else {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                = (0xf0007fffU 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0xffffc0ffU 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            if ((3U 
                                                 != 
                                                 (0xfU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0xbU) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 0x15U))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                    = 
                                                    (0x80U 
                                                     | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        if ((0x80U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1e00000U & 
                                      (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                            << 0xbU) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              >> 0x15U))) 
                                       << 0x15U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                            = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0x40U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xffffffefU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffdfU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                } else {
                                    if ((0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                            = ((0x1ffffffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                               | (0xfe000000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                        << 7U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          >> 0x19U))) 
                                                     << 0x19U)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                            = ((0xfffffffcU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                               | (3U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                        << 7U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          >> 0x19U))) 
                                                     >> 7U)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                            = ((0x7fffffffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                               | (0x80000000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        << 1U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          >> 0x1fU))) 
                                                     << 0x1fU)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                            = ((0xffffff00U 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                               | (0xffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        << 1U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          >> 0x1fU))) 
                                                     >> 1U)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xfffffffdU 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        if ((0U == 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0xfffffff7U 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0x10U 
                                                   | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            if ((0x40U 
                                                 & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    ((0xffe000ffU 
                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                     | (0x1fff00U 
                                                        & (((IData)(1U) 
                                                            + 
                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                >> 8U))) 
                                                           << 8U)));
                                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                    = 
                                                    (0xffffffbfU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            }
                                        } else {
                                            if ((1U 
                                                 == 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    ((0x1ffffffU 
                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                     | (0xfe000000U 
                                                        & (((IData)(0x11U) 
                                                            + 
                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                              << 7U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                >> 0x19U))) 
                                                           << 0x19U)));
                                                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                    = 
                                                    ((0xfffffffcU 
                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                                     | (3U 
                                                        & (((IData)(0x11U) 
                                                            + 
                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                              << 7U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                >> 0x19U))) 
                                                           >> 7U)));
                                            } else {
                                                if (
                                                    (3U 
                                                     == 
                                                     (0x1ffU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          << 1U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                            >> 0x1fU))))) {
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                        = 
                                                        (0x1ffffffU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                        = 
                                                        (0xfffffffcU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                        = 
                                                        (0x7fffffffU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                        = 
                                                        (0xffffff00U 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                    if (
                                                        (0x10U 
                                                         != 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x12U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 0xeU))))) {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                            = 
                                                            ((0xf0007fffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                             | (0xfff8000U 
                                                                & (((IData)(2U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                      << 0x11U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                        >> 0xfU))) 
                                                                   << 0xfU)));
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            ((0xfff03fffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                             | (0xfc000U 
                                                                & (((IData)(2U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                      << 0x12U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                        >> 0xeU))) 
                                                                   << 0xeU)));
                                                    } else {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            (0xfff03fffU 
                                                             & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                            = 
                                                            ((0xf0007fffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                             | (0xfff8000U 
                                                                & (((IData)(0x14U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                      << 0x11U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                        >> 0xfU))) 
                                                                   << 0xfU)));
                                                        if (
                                                            (0x10U 
                                                             != 
                                                             (0x3fU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                  << 0x18U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                    >> 8U))))) {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                                = 
                                                                ((0xffffc0ffU 
                                                                  & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                                 | (0x3f00U 
                                                                    & (((IData)(2U) 
                                                                        + 
                                                                        ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                          << 0x18U) 
                                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                            >> 8U))) 
                                                                       << 8U)));
                                                        } else {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                                = 
                                                                (0xffffc0ffU 
                                                                 & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                            if (
                                                                (3U 
                                                                 != 
                                                                 (0xfU 
                                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                      << 0xbU) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                        >> 0x15U))))) {
                                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                                    = 
                                                                    ((0xfe1fffffU 
                                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                                     | (0x1e00000U 
                                                                        & (((IData)(1U) 
                                                                            + 
                                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                              << 0xbU) 
                                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                                >> 0x15U))) 
                                                                           << 0x15U)));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (8U | 
                                               vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xffffffefU 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (2U | 
                                               vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0x40U 
                                               | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            } else {
                if ((0x11U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xfe000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                  << 7U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    >> 0x19U))) 
                                             << 0x19U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                        = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                           | (3U & (((IData)(1U) + 
                                     ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                       << 7U) | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                 >> 0x19U))) 
                                    >> 7U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x80000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))) 
                                             << 0x1fU)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xffU & (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU))) 
                                       >> 1U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x7ff8U & (((IData)(0xaU) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 0x1dU) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 3U))) 
                                         << 3U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    if ((0U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x10U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        if ((0x40U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1fff00U & (
                                                   ((IData)(1U) 
                                                    + 
                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0x18U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 8U))) 
                                                   << 8U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                    } else {
                        if ((0x143U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            if ((9U != (0xfU & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 0xbU) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x15U))))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0x80U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            }
                        }
                    }
                } else {
                    if ((0x12U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        if ((0x80U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1e00000U & 
                                      (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                            << 0xbU) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              >> 0x15U))) 
                                       << 0x15U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                            = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((0x13U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0x40U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((0x14U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xffffffefU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((0x15U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffdfU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__result = (0xffU & ((4U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])
                                          ? (IData)(vlTOPp->top__DOT__kernel_unit__DOT__comp_result)
                                          : ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__overflow)
                                              ? ((0x1000U 
                                                  & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                     >> 3U)))
                                              : ((0x800U 
                                                  & (IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q))
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__kernel_unit__DOT__mac_result_q) 
                                                     >> 3U))))));
}

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((((((((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
               | (1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
            | (4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
           | (5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
          | (6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
         | (7U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
        if ((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
            if (vlTOPp->go) {
                if ((0U == (IData)(vlTOPp->layer_index))) {
                    vlTOPp->top__DOT__control_unit__DOT__next_state = 1U;
                } else {
                    if ((1U == (IData)(vlTOPp->layer_index))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 6U;
                    } else {
                        if ((2U == (IData)(vlTOPp->layer_index))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 9U;
                        } else {
                            if ((3U == (IData)(vlTOPp->layer_index))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0xeU;
                            } else {
                                if ((4U == (IData)(vlTOPp->layer_index))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0x11U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                if ((0U != (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                       << 1U) | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                    if ((1U & (~ ((2U == (0x1ffU & 
                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU)))) 
                                  | (5U == (0x1ffU 
                                            & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                << 1U) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                  >> 0x1fU)))))))) {
                        if ((8U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                               << 1U) 
                                              | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 2U;
                            if ((0x27U == (0x3fU & 
                                           ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                             << 0x12U) 
                                            | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                               >> 0xeU))))) {
                                if ((0x27U == (0x3fU 
                                               & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                     >> 8U))))) {
                                    if ((3U == (0xfU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 0xbU) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x15U))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__next_state = 4U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    vlTOPp->top__DOT__control_unit__DOT__next_state = 3U;
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 1U;
                    } else {
                        if ((4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 5U;
                        } else {
                            if ((5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
                            } else {
                                if ((6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    if ((0U != (0x1ffU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))))) {
                                        if ((1U != 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            if ((3U 
                                                 == 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__next_state = 7U;
                                                if (
                                                    (0x26U 
                                                     == 
                                                     (0x3fU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          << 0x12U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                            >> 0xeU))))) {
                                                    if (
                                                        (0x26U 
                                                         == 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 8U))))) {
                                                        if (
                                                            (3U 
                                                             == 
                                                             (0xfU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                  << 0xbU) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                    >> 0x15U))))) {
                                                            vlTOPp->top__DOT__control_unit__DOT__next_state = 8U;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 6U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (((((((((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
                   | (9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                  | (0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                 | (0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                | (0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
               | (0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (0xfU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
            if ((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
            } else {
                if ((9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    if ((0U != (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        if ((1U & (~ ((2U == (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU)))) 
                                      | (5U == (0x1ffU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU)))))))) {
                            if ((8U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                                if ((3U == (7U & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 4U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1cU))))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0xaU;
                                    if ((0x11U == (0x3fU 
                                                   & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                       << 0x12U) 
                                                      | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                         >> 0xeU))))) {
                                        if ((0x11U 
                                             == (0x3fU 
                                                 & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     << 0x18U) 
                                                    | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                       >> 8U))))) {
                                            if ((3U 
                                                 == 
                                                 (0xfU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0xbU) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 0x15U))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0xcU;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 0xbU;
                    } else {
                        if ((0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 9U;
                        } else {
                            if ((0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0xdU;
                            } else {
                                if ((0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
                                } else {
                                    if ((0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                        if ((0U != 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            if ((1U 
                                                 != 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                if (
                                                    (3U 
                                                     == 
                                                     (0x1ffU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          << 1U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                            >> 0x1fU))))) {
                                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0xfU;
                                                    if (
                                                        (0x10U 
                                                         == 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x12U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 0xeU))))) {
                                                        if (
                                                            (0x10U 
                                                             == 
                                                             (0x3fU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                  << 0x18U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                    >> 8U))))) {
                                                            if (
                                                                (3U 
                                                                 == 
                                                                 (0xfU 
                                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                      << 0xbU) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                        >> 0x15U))))) {
                                                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0x10U;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__control_unit__DOT__next_state = 0xeU;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
            } else {
                if ((0x11U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    if ((0U != (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        if ((0x143U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 0x12U;
                            if ((9U == (0xfU & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 0xbU) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x15U))))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0x14U;
                            }
                        }
                    }
                } else {
                    if ((0x12U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__next_state = 0x13U;
                    } else {
                        if ((0x13U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__next_state = 0x11U;
                        } else {
                            if ((0x14U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__next_state = 0x15U;
                            } else {
                                if ((0x15U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__next_state = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__control_unit__DOT__ns[0U] = vlTOPp->top__DOT__control_unit__DOT__cs[0U];
    vlTOPp->top__DOT__control_unit__DOT__ns[1U] = vlTOPp->top__DOT__control_unit__DOT__cs[1U];
    vlTOPp->top__DOT__control_unit__DOT__ns[2U] = vlTOPp->top__DOT__control_unit__DOT__cs[2U];
    vlTOPp->top__DOT__control_unit__DOT__ns[3U] = vlTOPp->top__DOT__control_unit__DOT__cs[3U];
    vlTOPp->top__DOT__control_unit__DOT__ns[4U] = vlTOPp->top__DOT__control_unit__DOT__cs[4U];
    vlTOPp->top__DOT__control_unit__DOT__ns[5U] = vlTOPp->top__DOT__control_unit__DOT__cs[5U];
    vlTOPp->top__DOT__control_unit__DOT__ns[6U] = vlTOPp->top__DOT__control_unit__DOT__cs[6U];
    if (((((((((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
               | (1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
            | (4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
           | (5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
          | (6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
         | (7U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
        if ((0U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                = (0xfffffffeU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                = (0xf0007fffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
            if (vlTOPp->go) {
                vlTOPp->top__DOT__control_unit__DOT__ns[5U] 
                    = ((3U & vlTOPp->top__DOT__control_unit__DOT__ns[5U]) 
                       | (0xfffffffcU & (vlTOPp->data_address 
                                         << 2U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[6U] 
                    = (3U & (vlTOPp->data_address >> 0x1eU));
                vlTOPp->top__DOT__control_unit__DOT__ns[4U] 
                    = ((3U & vlTOPp->top__DOT__control_unit__DOT__ns[4U]) 
                       | (0xfffffffcU & (vlTOPp->weight_address 
                                         << 2U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[5U] 
                    = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[5U]) 
                       | (3U & (vlTOPp->weight_address 
                                >> 0x1eU)));
                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                    = ((3U & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                       | (0xfffffffcU & (vlTOPp->result_address 
                                         << 2U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[4U] 
                    = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[4U]) 
                       | (3U & (vlTOPp->result_address 
                                >> 0x1eU)));
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                if ((0U == (IData)(vlTOPp->layer_index))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffffbU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                } else {
                    if ((1U == (IData)(vlTOPp->layer_index))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (4U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((2U == (IData)(vlTOPp->layer_index))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xfffffffbU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((3U == (IData)(vlTOPp->layer_index))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (4U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((4U == (IData)(vlTOPp->layer_index))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xfffffffbU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                    = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                       | (0xfe000000U & (((IData)(1U) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                              << 7U) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                >> 0x19U))) 
                                         << 0x19U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                    = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                       | (3U & (((IData)(1U) + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 7U) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x19U))) 
                                >> 7U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                    = ((0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                       | (0x80000000U & (((IData)(1U) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 1U) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 0x1fU))) 
                                         << 0x1fU)));
                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                    = ((0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                       | (0xffU & (((IData)(1U) + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))) 
                                   >> 1U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                    = ((0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                       | (0x7ff8U & (((IData)(4U) + 
                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                        << 0x1dU) | 
                                       (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                        >> 3U))) << 3U)));
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                if ((0U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                       << 1U) | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0x10U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    if ((0x40U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                            = ((0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                               | (0x1fff00U & (((IData)(1U) 
                                                + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 8U))) 
                                               << 8U)));
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    }
                } else {
                    if (((2U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU)))) 
                         | (5U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 1U) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 0x1fU)))))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                            = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                               | (0xfe000000U & (((IData)(0x28U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 7U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x19U))) 
                                                 << 0x19U)));
                        vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                            = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                               | (3U & (((IData)(0x28U) 
                                         + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                             << 7U) 
                                            | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                               >> 0x19U))) 
                                        >> 7U)));
                    } else {
                        if ((8U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                               << 1U) 
                                              | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                 >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            if ((0x27U != (0x3fU & 
                                           ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                             << 0x12U) 
                                            | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                               >> 0xeU))))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                    = ((0xf0007fffU 
                                        & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                       | (0xfff8000U 
                                          & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 0x11U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0xfU))) 
                                             << 0xfU)));
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = ((0xfff03fffU 
                                        & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                       | (0xfc000U 
                                          & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                  << 0x12U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                    >> 0xeU))) 
                                             << 0xeU)));
                            } else {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xfff03fffU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                if ((0x27U != (0x3fU 
                                               & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                     >> 8U))))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0xf0007fffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (0xfff8000U 
                                              & (((IData)(3U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 0x11U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0xfU))) 
                                                 << 0xfU)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = ((0xffffc0ffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                           | (0x3f00U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 8U))) 
                                                 << 8U)));
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0xf0007fffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffc0ffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    if ((3U != (0xfU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 0xbU) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x15U))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0x80U 
                                               | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    if ((0x80U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                            = ((0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                               | (0x1e00000U & (((IData)(1U) 
                                                 + 
                                                 ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                   << 0xbU) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                     >> 0x15U))) 
                                                << 0x15U)));
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    }
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x40U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((4U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((5U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xffffffdfU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((6U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                        = ((0x1ffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                           | (0xfe000000U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 7U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x19U))) 
                                                 << 0x19U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                        = ((0xfffffffcU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                           | (3U & 
                                              (((IData)(1U) 
                                                + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                    << 7U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      >> 0x19U))) 
                                               >> 7U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0x7fffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (0x80000000U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))) 
                                                 << 0x1fU)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                        = ((0xffffff00U 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                           | (0xffU 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))) 
                                                 >> 1U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xfffffffdU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    if ((0U == (0x1ffU 
                                                & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 1U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1fU))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xfffffff7U 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0x10U 
                                               | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        if ((0x40U 
                                             & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                = (
                                                   (0xffe000ffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                   | (0x1fff00U 
                                                      & (((IData)(1U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                            << 0x18U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                              >> 8U))) 
                                                         << 8U)));
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0xffffffbfU 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        }
                                    } else {
                                        if ((1U == 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                = (
                                                   (0x1ffffffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                   | (0xfe000000U 
                                                      & (((IData)(0x27U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                            << 7U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                              >> 0x19U))) 
                                                         << 0x19U)));
                                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                = (
                                                   (0xfffffffcU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                                   | (3U 
                                                      & (((IData)(0x27U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                            << 7U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                              >> 0x19U))) 
                                                         >> 7U)));
                                        } else {
                                            if ((3U 
                                                 == 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    (0x1ffffffU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                    = 
                                                    (0xfffffffcU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                                                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                    = 
                                                    (0x7fffffffU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    (0xffffff00U 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                if (
                                                    (0x26U 
                                                     != 
                                                     (0x3fU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          << 0x12U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                            >> 0xeU))))) {
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                        = 
                                                        ((0xf0007fffU 
                                                          & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                         | (0xfff8000U 
                                                            & (((IData)(2U) 
                                                                + 
                                                                ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                  << 0x11U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                    >> 0xfU))) 
                                                               << 0xfU)));
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                        = 
                                                        ((0xfff03fffU 
                                                          & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                         | (0xfc000U 
                                                            & (((IData)(2U) 
                                                                + 
                                                                ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                  << 0x12U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                    >> 0xeU))) 
                                                               << 0xeU)));
                                                } else {
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                        = 
                                                        (0xfff03fffU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                        = 
                                                        ((0xf0007fffU 
                                                          & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                         | (0xfff8000U 
                                                            & (((IData)(0x2aU) 
                                                                + 
                                                                ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                  << 0x11U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                    >> 0xfU))) 
                                                               << 0xfU)));
                                                    if (
                                                        (0x26U 
                                                         != 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 8U))))) {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            ((0xffffc0ffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                             | (0x3f00U 
                                                                & (((IData)(2U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                      << 0x18U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                        >> 8U))) 
                                                                   << 8U)));
                                                    } else {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            (0xffffc0ffU 
                                                             & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                        if (
                                                            (3U 
                                                             != 
                                                             (0xfU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                  << 0xbU) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                    >> 0x15U))))) {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                                = 
                                                                ((0xfe1fffffU 
                                                                  & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                                 | (0x1e00000U 
                                                                    & (((IData)(1U) 
                                                                        + 
                                                                        ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                          << 0xbU) 
                                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                            >> 0x15U))) 
                                                                       << 0x15U)));
                                                        } else {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                                = 
                                                                (0xf0007fffU 
                                                                 & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffefU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0x40U | 
                                           vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (((((((((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)) 
                   | (9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                  | (0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                 | (0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
                | (0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
               | (0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
              | (0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) 
             | (0xfU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state)))) {
            if ((8U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            } else {
                if ((9U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xfe000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                  << 7U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    >> 0x19U))) 
                                             << 0x19U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                        = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                           | (3U & (((IData)(1U) + 
                                     ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                       << 7U) | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                 >> 0x19U))) 
                                    >> 7U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x80000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))) 
                                             << 0x1fU)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xffU & (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU))) 
                                       >> 1U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x7ff8U & (((IData)(0x10U) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 0x1dU) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 3U))) 
                                         << 3U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    if ((0U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x10U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        if ((0x40U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1fff00U & (
                                                   ((IData)(1U) 
                                                    + 
                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0x18U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 8U))) 
                                                   << 8U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                    } else {
                        if (((2U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                << 1U) 
                                               | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                  >> 0x1fU)))) 
                             | (5U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU)))))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0xfe000000U & 
                                      (((IData)(0x12U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                            << 7U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              >> 0x19U))) 
                                       << 0x19U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                   | (3U & (((IData)(0x12U) 
                                             + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 7U) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x19U))) 
                                            >> 7U)));
                        } else {
                            if ((8U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                    = (0x1ffffffU & 
                                       vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                    = (0xfffffffcU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                    = (0x7fffffffU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                    = (0xffffff00U 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                if ((3U != (7U & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 4U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1cU))))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0x8fffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (0x70000000U 
                                              & (((IData)(1U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    << 4U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                      >> 0x1cU))) 
                                                 << 0x1cU)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = ((0xffffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                           | (0xff000000U 
                                              & (((IData)(0x190U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 8U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 0x18U))) 
                                                 << 0x18U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = ((0xfffffff8U 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                           | (7U & 
                                              (((IData)(0x190U) 
                                                + (
                                                   (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 8U) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 0x18U))) 
                                               >> 8U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = ((0xff0fffffU 
                                            & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                           | (0xf00000U 
                                              & (((IData)(4U) 
                                                  + 
                                                  ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    << 0xcU) 
                                                   | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                      >> 0x14U))) 
                                                 << 0x14U)));
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0xffff8007U 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                } else {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0x8fffffffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                        = (0xfffffff8U 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xff0fffffU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    if ((0x11U != (0x3fU 
                                                   & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                       << 0x12U) 
                                                      | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                         >> 0xeU))))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                            = ((0xf0007fffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                               | (0xfff8000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        << 0x11U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          >> 0xfU))) 
                                                     << 0xfU)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = ((0xfff03fffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                               | (0xfc000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        << 0x12U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                          >> 0xeU))) 
                                                     << 0xeU)));
                                    } else {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xfff03fffU 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        if ((0x11U 
                                             != (0x3fU 
                                                 & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     << 0x18U) 
                                                    | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                       >> 8U))))) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                = (
                                                   (0xf0007fffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                   | (0xfff8000U 
                                                      & (((IData)(3U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                            << 0x11U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              >> 0xfU))) 
                                                         << 0xfU)));
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (
                                                   (0xffffc0ffU 
                                                    & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                   | (0x3f00U 
                                                      & (((IData)(1U) 
                                                          + 
                                                          ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                            << 0x18U) 
                                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                              >> 8U))) 
                                                         << 8U)));
                                        } else {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                = (0xf0007fffU 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0xffffc0ffU 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            if ((3U 
                                                 != 
                                                 (0xfU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0xbU) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 0x15U))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                    = 
                                                    (0x80U 
                                                     | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0xaU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        if ((0x80U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1e00000U & 
                                      (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                            << 0xbU) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              >> 0x15U))) 
                                       << 0x15U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                            = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((0xbU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0x40U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((0xcU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xffffffefU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((0xdU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffdfU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                } else {
                                    if ((0xeU == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                            = ((0x1ffffffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                               | (0xfe000000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                        << 7U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          >> 0x19U))) 
                                                     << 0x19U)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                            = ((0xfffffffcU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                               | (3U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                        << 7U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          >> 0x19U))) 
                                                     >> 7U)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                            = ((0x7fffffffU 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                               | (0x80000000U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        << 1U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          >> 0x1fU))) 
                                                     << 0x1fU)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                            = ((0xffffff00U 
                                                & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                               | (0xffU 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        << 1U) 
                                                       | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                          >> 0x1fU))) 
                                                     >> 1U)));
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xfffffffdU 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        if ((0U == 
                                             (0x1ffU 
                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))))) {
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0xfffffff7U 
                                                   & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                = (0x10U 
                                                   | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            if ((0x40U 
                                                 & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    ((0xffe000ffU 
                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                     | (0x1fff00U 
                                                        & (((IData)(1U) 
                                                            + 
                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                >> 8U))) 
                                                           << 8U)));
                                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                    = 
                                                    (0xffffffbfU 
                                                     & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                            }
                                        } else {
                                            if ((1U 
                                                 == 
                                                 (0x1ffU 
                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                      << 1U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                        >> 0x1fU))))) {
                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                    = 
                                                    ((0x1ffffffU 
                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                     | (0xfe000000U 
                                                        & (((IData)(0x11U) 
                                                            + 
                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                              << 7U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                >> 0x19U))) 
                                                           << 0x19U)));
                                                vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                    = 
                                                    ((0xfffffffcU 
                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                                                     | (3U 
                                                        & (((IData)(0x11U) 
                                                            + 
                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                              << 7U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                >> 0x19U))) 
                                                           >> 7U)));
                                            } else {
                                                if (
                                                    (3U 
                                                     == 
                                                     (0x1ffU 
                                                      & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                          << 1U) 
                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                            >> 0x1fU))))) {
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                        = 
                                                        (0x1ffffffU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                                        = 
                                                        (0xfffffffcU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                        = 
                                                        (0x7fffffffU 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                                                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                        = 
                                                        (0xffffff00U 
                                                         & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                                                    if (
                                                        (0x10U 
                                                         != 
                                                         (0x3fU 
                                                          & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                              << 0x12U) 
                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                >> 0xeU))))) {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                            = 
                                                            ((0xf0007fffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                             | (0xfff8000U 
                                                                & (((IData)(2U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                      << 0x11U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                        >> 0xfU))) 
                                                                   << 0xfU)));
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            ((0xfff03fffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                             | (0xfc000U 
                                                                & (((IData)(2U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                      << 0x12U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                        >> 0xeU))) 
                                                                   << 0xeU)));
                                                    } else {
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                            = 
                                                            (0xfff03fffU 
                                                             & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                                            = 
                                                            ((0xf0007fffU 
                                                              & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                                                             | (0xfff8000U 
                                                                & (((IData)(0x14U) 
                                                                    + 
                                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                      << 0x11U) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                        >> 0xfU))) 
                                                                   << 0xfU)));
                                                        if (
                                                            (0x10U 
                                                             != 
                                                             (0x3fU 
                                                              & ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                  << 0x18U) 
                                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                    >> 8U))))) {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                                = 
                                                                ((0xffffc0ffU 
                                                                  & vlTOPp->top__DOT__control_unit__DOT__ns[0U]) 
                                                                 | (0x3f00U 
                                                                    & (((IData)(2U) 
                                                                        + 
                                                                        ((vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                                          << 0x18U) 
                                                                         | (vlTOPp->top__DOT__control_unit__DOT__cs[0U] 
                                                                            >> 8U))) 
                                                                       << 8U)));
                                                        } else {
                                                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                                                = 
                                                                (0xffffc0ffU 
                                                                 & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                                            if (
                                                                (3U 
                                                                 != 
                                                                 (0xfU 
                                                                  & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                      << 0xbU) 
                                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                        >> 0x15U))))) {
                                                                vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                                                    = 
                                                                    ((0xfe1fffffU 
                                                                      & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                                                     | (0x1e00000U 
                                                                        & (((IData)(1U) 
                                                                            + 
                                                                            ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                                              << 0xbU) 
                                                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                                                >> 0x15U))) 
                                                                           << 0x15U)));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (8U | 
                                               vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0xffffffefU 
                                               & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (2U | 
                                               vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                            = (0x40U 
                                               | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                    = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
            } else {
                if ((0x11U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xfe000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                  << 7U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                    >> 0x19U))) 
                                             << 0x19U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                        = ((0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]) 
                           | (3U & (((IData)(1U) + 
                                     ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                       << 7U) | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                 >> 0x19U))) 
                                    >> 7U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x80000000U & (((IData)(1U) 
                                              + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                  << 1U) 
                                                 | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                    >> 0x1fU))) 
                                             << 0x1fU)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                        = ((0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                           | (0xffU & (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                            << 1U) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                              >> 0x1fU))) 
                                       >> 1U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                        = ((0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]) 
                           | (0x7ff8U & (((IData)(0xaU) 
                                          + ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              << 0x1dU) 
                                             | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                >> 3U))) 
                                         << 3U)));
                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                        = (0xfffffffdU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    if ((0U == (0x1ffU & ((vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                           << 1U) | 
                                          (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                           >> 0x1fU))))) {
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0xfffffff7U & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x10U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        if ((0x40U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xffe000ffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1fff00U & (
                                                   ((IData)(1U) 
                                                    + 
                                                    ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                      << 0x18U) 
                                                     | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                        >> 8U))) 
                                                   << 8U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffbfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                    } else {
                        if ((0x143U == (0x1ffU & ((
                                                   vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   << 1U) 
                                                  | (vlTOPp->top__DOT__control_unit__DOT__cs[1U] 
                                                     >> 0x1fU))))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0x1ffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[3U] 
                                = (0xfffffffcU & vlTOPp->top__DOT__control_unit__DOT__ns[3U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                                = (0x7fffffffU & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = (0xffffff00U & vlTOPp->top__DOT__control_unit__DOT__ns[2U]);
                            if ((9U != (0xfU & ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                                 << 0xbU) 
                                                | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                                   >> 0x15U))))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0x80U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            }
                        }
                    }
                } else {
                    if ((0x12U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                        if ((0x80U & vlTOPp->top__DOT__control_unit__DOT__cs[0U])) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[2U] 
                                = ((0xfe1fffffU & vlTOPp->top__DOT__control_unit__DOT__ns[2U]) 
                                   | (0x1e00000U & 
                                      (((IData)(1U) 
                                        + ((vlTOPp->top__DOT__control_unit__DOT__cs[3U] 
                                            << 0xbU) 
                                           | (vlTOPp->top__DOT__control_unit__DOT__cs[2U] 
                                              >> 0x15U))) 
                                       << 0x15U)));
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffff7fU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        }
                        vlTOPp->top__DOT__control_unit__DOT__ns[1U] 
                            = (0xffff8007U & vlTOPp->top__DOT__control_unit__DOT__ns[1U]);
                        vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                            = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                    } else {
                        if ((0x13U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffdfU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (8U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0xffffffefU & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                = (0x40U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                        } else {
                            if ((0x14U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0xffffffefU 
                                       & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                    = (0x20U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                            } else {
                                if ((0x15U == (IData)(vlTOPp->top__DOT__control_unit__DOT__current_state))) {
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (0xffffffdfU 
                                           & vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (2U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                    vlTOPp->top__DOT__control_unit__DOT__ns[0U] 
                                        = (1U | vlTOPp->top__DOT__control_unit__DOT__ns[0U]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rstn & 0xfeU))) {
        Verilated::overWidthError("rstn");}
    if (VL_UNLIKELY((go & 0xfeU))) {
        Verilated::overWidthError("go");}
    if (VL_UNLIKELY((layer_index & 0xf8U))) {
        Verilated::overWidthError("layer_index");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rstn = VL_RAND_RESET_I(1);
    go = VL_RAND_RESET_I(1);
    layer_index = VL_RAND_RESET_I(3);
    data_address = VL_RAND_RESET_I(32);
    data_size = VL_RAND_RESET_I(32);
    weight_address = VL_RAND_RESET_I(32);
    weight_size = VL_RAND_RESET_I(32);
    result_address = VL_RAND_RESET_I(32);
    done = VL_RAND_RESET_I(1);
    top__DOT__data_idx = VL_RAND_RESET_I(32);
    top__DOT__weight_idx = VL_RAND_RESET_I(32);
    top__DOT__result_idx = VL_RAND_RESET_I(32);
    top__DOT__result = VL_RAND_RESET_I(8);
    top__DOT__data = VL_RAND_RESET_I(8);
    top__DOT__weight = VL_RAND_RESET_I(8);
    top__DOT__control_unit__DOT__current_state = VL_RAND_RESET_I(5);
    top__DOT__control_unit__DOT__next_state = VL_RAND_RESET_I(5);
    VL_ZERO_RESET_W(194, top__DOT__control_unit__DOT__cs);
    VL_ZERO_RESET_W(194, top__DOT__control_unit__DOT__ns);
    top__DOT__control_unit__DOT__data_counter = VL_RAND_RESET_I(6);
    top__DOT__control_unit__DOT__weight_counter = VL_RAND_RESET_I(4);
    top__DOT__kernel_unit__DOT__mac_result = VL_RAND_RESET_I(16);
    top__DOT__kernel_unit__DOT__mac_result_q = VL_RAND_RESET_I(13);
    top__DOT__kernel_unit__DOT__comp_result = VL_RAND_RESET_I(8);
    top__DOT__kernel_unit__DOT__overflow = VL_RAND_RESET_I(1);
    top__DOT__kernel_unit__DOT__carry = VL_RAND_RESET_I(1);
    top__DOT__kernel_unit__DOT__tmp = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<6400; ++__Vi0) {
            top__DOT__memory_unit__DOT__memory_A0[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<6400; ++__Vi0) {
            top__DOT__memory_unit__DOT__memory_A1[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<6400; ++__Vi0) {
            top__DOT__memory_unit__DOT__memory_B[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__memory_unit__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    top__DOT__memory_unit__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
