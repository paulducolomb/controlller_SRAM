; ModuleID = 'C:/Users/pauld/controlller_SRAM/SRAM_HLS/SRAM_hls/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_uint<19>" = type { %"struct.ap_int_base<19, false>" }
%"struct.ap_int_base<19, false>" = type { %"struct.ssdm_int<19, false>" }
%"struct.ssdm_int<19, false>" = type { i19 }
%"struct.ap_uint<36>" = type { %"struct.ap_int_base<36, false>" }
%"struct.ap_int_base<36, false>" = type { %"struct.ssdm_int<36, false>" }
%"struct.ssdm_int<36, false>" = type { i36 }

; Function Attrs: noinline
define void @apatb_control_SRAM_HLS_ir(%"struct.ap_uint<19>"* nocapture readonly %addr_in, %"struct.ap_uint<36>"* nocapture readonly %data_in, %"struct.ap_uint<36>"* %data_out, i1 %we, i1 %re, i1* %ready, %"struct.ap_uint<19>"* %Addr, %"struct.ap_uint<36>"* %Dq, i1* %Ce_n, i1* %Ce2, i1* %Ce2_n, i1* %Oe_n, i1* %Rw_n, i1* %Ld_n, i1* %Cke_n, i1 %clk, i1 %reset) local_unnamed_addr #0 {
entry:
  %data_out_copy = alloca i36, align 512
  %ready_copy = alloca i1, align 512
  %Addr_copy = alloca i19, align 512
  %Dq_copy = alloca i36, align 512
  %Ce_n_copy = alloca i1, align 512
  %Ce2_copy = alloca i1, align 512
  %Ce2_n_copy = alloca i1, align 512
  %Oe_n_copy = alloca i1, align 512
  %Rw_n_copy = alloca i1, align 512
  %Ld_n_copy = alloca i1, align 512
  %Cke_n_copy = alloca i1, align 512
  call fastcc void @copy_in(%"struct.ap_uint<36>"* %data_out, i36* nonnull align 512 %data_out_copy, i1* %ready, i1* nonnull align 512 %ready_copy, %"struct.ap_uint<19>"* %Addr, i19* nonnull align 512 %Addr_copy, %"struct.ap_uint<36>"* %Dq, i36* nonnull align 512 %Dq_copy, i1* %Ce_n, i1* nonnull align 512 %Ce_n_copy, i1* %Ce2, i1* nonnull align 512 %Ce2_copy, i1* %Ce2_n, i1* nonnull align 512 %Ce2_n_copy, i1* %Oe_n, i1* nonnull align 512 %Oe_n_copy, i1* %Rw_n, i1* nonnull align 512 %Rw_n_copy, i1* %Ld_n, i1* nonnull align 512 %Ld_n_copy, i1* %Cke_n, i1* nonnull align 512 %Cke_n_copy)
  call void @apatb_control_SRAM_HLS_hw(%"struct.ap_uint<19>"* %addr_in, %"struct.ap_uint<36>"* %data_in, i36* %data_out_copy, i1 %we, i1 %re, i1* %ready_copy, i19* %Addr_copy, i36* %Dq_copy, i1* %Ce_n_copy, i1* %Ce2_copy, i1* %Ce2_n_copy, i1* %Oe_n_copy, i1* %Rw_n_copy, i1* %Ld_n_copy, i1* %Cke_n_copy, i1 %clk, i1 %reset)
  call fastcc void @copy_out(%"struct.ap_uint<36>"* %data_out, i36* nonnull align 512 %data_out_copy, i1* %ready, i1* nonnull align 512 %ready_copy, %"struct.ap_uint<19>"* %Addr, i19* nonnull align 512 %Addr_copy, %"struct.ap_uint<36>"* %Dq, i36* nonnull align 512 %Dq_copy, i1* %Ce_n, i1* nonnull align 512 %Ce_n_copy, i1* %Ce2, i1* nonnull align 512 %Ce2_copy, i1* %Ce2_n, i1* nonnull align 512 %Ce2_n_copy, i1* %Oe_n, i1* nonnull align 512 %Oe_n_copy, i1* %Rw_n, i1* nonnull align 512 %Rw_n_copy, i1* %Ld_n, i1* nonnull align 512 %Ld_n_copy, i1* %Cke_n, i1* nonnull align 512 %Cke_n_copy)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_in(%"struct.ap_uint<36>"* readonly, i36* noalias align 512, i1* readonly, i1* noalias align 512, %"struct.ap_uint<19>"* readonly, i19* noalias align 512, %"struct.ap_uint<36>"* readonly, i36* noalias align 512, i1* readonly, i1* noalias align 512, i1* readonly, i1* noalias align 512, i1* readonly, i1* noalias align 512, i1* readonly, i1* noalias align 512, i1* readonly, i1* noalias align 512, i1* readonly, i1* noalias align 512, i1* readonly, i1* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<36>"(i36* align 512 %1, %"struct.ap_uint<36>"* %0)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %3, i1* %2)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<19>.19"(i19* align 512 %5, %"struct.ap_uint<19>"* %4)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<36>"(i36* align 512 %7, %"struct.ap_uint<36>"* %6)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %9, i1* %8)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %11, i1* %10)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %13, i1* %12)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %15, i1* %14)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %17, i1* %16)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %19, i1* %18)
  call fastcc void @onebyonecpy_hls.p0i1(i1* align 512 %21, i1* %20)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0i1(i1* noalias align 512, i1* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i1* %0, null
  %3 = icmp eq i1* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = bitcast i1* %1 to i8*
  %6 = load i8, i8* %5
  %7 = trunc i8 %6 to i1
  store i1 %7, i1* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<19>"(%"struct.ap_uint<19>"* noalias, i19* noalias readonly align 512) unnamed_addr #2 {
entry:
  %2 = icmp eq %"struct.ap_uint<19>"* %0, null
  %3 = icmp eq i19* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %.01.0.05 = getelementptr %"struct.ap_uint<19>", %"struct.ap_uint<19>"* %0, i32 0, i32 0, i32 0, i32 0
  %5 = bitcast i19* %1 to i24*
  %6 = load i24, i24* %5
  %7 = trunc i24 %6 to i19
  store i19 %7, i19* %.01.0.05, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_out(%"struct.ap_uint<36>"*, i36* noalias readonly align 512, i1*, i1* noalias readonly align 512, %"struct.ap_uint<19>"*, i19* noalias readonly align 512, %"struct.ap_uint<36>"*, i36* noalias readonly align 512, i1*, i1* noalias readonly align 512, i1*, i1* noalias readonly align 512, i1*, i1* noalias readonly align 512, i1*, i1* noalias readonly align 512, i1*, i1* noalias readonly align 512, i1*, i1* noalias readonly align 512, i1*, i1* noalias readonly align 512) unnamed_addr #3 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<36>.10"(%"struct.ap_uint<36>"* %0, i36* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %2, i1* align 512 %3)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<19>"(%"struct.ap_uint<19>"* %4, i19* align 512 %5)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<36>.10"(%"struct.ap_uint<36>"* %6, i36* align 512 %7)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %8, i1* align 512 %9)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %10, i1* align 512 %11)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %12, i1* align 512 %13)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %14, i1* align 512 %15)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %16, i1* align 512 %17)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %18, i1* align 512 %19)
  call fastcc void @onebyonecpy_hls.p0i1(i1* %20, i1* align 512 %21)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<36>.10"(%"struct.ap_uint<36>"* noalias, i36* noalias readonly align 512) unnamed_addr #2 {
entry:
  %2 = icmp eq %"struct.ap_uint<36>"* %0, null
  %3 = icmp eq i36* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %.01.0.05 = getelementptr %"struct.ap_uint<36>", %"struct.ap_uint<36>"* %0, i32 0, i32 0, i32 0, i32 0
  %5 = bitcast i36* %1 to i40*
  %6 = load i40, i40* %5
  %7 = trunc i40 %6 to i36
  store i36 %7, i36* %.01.0.05, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<36>"(i36* noalias align 512, %"struct.ap_uint<36>"* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i36* %0, null
  %3 = icmp eq %"struct.ap_uint<36>"* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %.0.0.04 = getelementptr %"struct.ap_uint<36>", %"struct.ap_uint<36>"* %1, i32 0, i32 0, i32 0, i32 0
  %5 = bitcast i36* %.0.0.04 to i40*
  %6 = load i40, i40* %5
  %7 = trunc i40 %6 to i36
  store i36 %7, i36* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<19>.19"(i19* noalias align 512, %"struct.ap_uint<19>"* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq i19* %0, null
  %3 = icmp eq %"struct.ap_uint<19>"* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %.0.0.04 = getelementptr %"struct.ap_uint<19>", %"struct.ap_uint<19>"* %1, i32 0, i32 0, i32 0, i32 0
  %5 = bitcast i19* %.0.0.04 to i24*
  %6 = load i24, i24* %5
  %7 = trunc i24 %6 to i19
  store i19 %7, i19* %0, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

declare void @apatb_control_SRAM_HLS_hw(%"struct.ap_uint<19>"*, %"struct.ap_uint<36>"*, i36*, i1, i1, i1*, i19*, i36*, i1*, i1*, i1*, i1*, i1*, i1*, i1*, i1, i1)

define void @control_SRAM_HLS_hw_stub_wrapper(%"struct.ap_uint<19>"*, %"struct.ap_uint<36>"*, i36*, i1, i1, i1*, i19*, i36*, i1*, i1*, i1*, i1*, i1*, i1*, i1*, i1, i1) #4 {
entry:
  %17 = alloca %"struct.ap_uint<36>"
  %18 = alloca %"struct.ap_uint<19>"
  %19 = alloca %"struct.ap_uint<36>"
  call void @copy_out(%"struct.ap_uint<36>"* %17, i36* %2, i1* null, i1* %5, %"struct.ap_uint<19>"* %18, i19* %6, %"struct.ap_uint<36>"* %19, i36* %7, i1* null, i1* %8, i1* null, i1* %9, i1* null, i1* %10, i1* null, i1* %11, i1* null, i1* %12, i1* null, i1* %13, i1* null, i1* %14)
  call void @control_SRAM_HLS_hw_stub(%"struct.ap_uint<19>"* %0, %"struct.ap_uint<36>"* %1, %"struct.ap_uint<36>"* %17, i1 %3, i1 %4, i1* %5, %"struct.ap_uint<19>"* %18, %"struct.ap_uint<36>"* %19, i1* %8, i1* %9, i1* %10, i1* %11, i1* %12, i1* %13, i1* %14, i1 %15, i1 %16)
  call void @copy_in(%"struct.ap_uint<36>"* %17, i36* %2, i1* null, i1* %5, %"struct.ap_uint<19>"* %18, i19* %6, %"struct.ap_uint<36>"* %19, i36* %7, i1* null, i1* %8, i1* null, i1* %9, i1* null, i1* %10, i1* null, i1* %11, i1* null, i1* %12, i1* null, i1* %13, i1* null, i1* %14)
  ret void
}

declare void @control_SRAM_HLS_hw_stub(%"struct.ap_uint<19>"*, %"struct.ap_uint<36>"*, %"struct.ap_uint<36>"*, i1, i1, i1*, %"struct.ap_uint<19>"*, %"struct.ap_uint<36>"*, i1*, i1*, i1*, i1*, i1*, i1*, i1*, i1, i1)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
