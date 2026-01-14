# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

set axilite_register_dict [dict create]
# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 1 \
    name addr_in \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_addr_in \
    op interface \
    ports { addr_in { I 19 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 2 \
    name data_in \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_data_in \
    op interface \
    ports { data_in { I 36 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 3 \
    name data_out \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_data_out \
    op interface \
    ports { data_out { O 36 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 4 \
    name we \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_we \
    op interface \
    ports { we { I 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 5 \
    name re \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_re \
    op interface \
    ports { re { I 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 6 \
    name ready_r \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_ready_r \
    op interface \
    ports { ready_r { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 7 \
    name Addr \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Addr \
    op interface \
    ports { Addr { O 19 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 8 \
    name Dq \
    type other \
    dir IO \
    reset_level 1 \
    sync_rst true \
    corename dc_Dq \
    op interface \
    ports { Dq_i { I 36 vector } Dq_o { O 36 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 9 \
    name Ce_n \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Ce_n \
    op interface \
    ports { Ce_n { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 10 \
    name Ce2 \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Ce2 \
    op interface \
    ports { Ce2 { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 11 \
    name Ce2_n \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Ce2_n \
    op interface \
    ports { Ce2_n { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 12 \
    name Oe_n \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Oe_n \
    op interface \
    ports { Oe_n { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 13 \
    name Rw_n \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Rw_n \
    op interface \
    ports { Rw_n { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 14 \
    name Ld_n \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Ld_n \
    op interface \
    ports { Ld_n { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 15 \
    name Cke_n \
    type other \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_Cke_n \
    op interface \
    ports { Cke_n { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 16 \
    name reset \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_reset \
    op interface \
    ports { reset { I 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -1 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


