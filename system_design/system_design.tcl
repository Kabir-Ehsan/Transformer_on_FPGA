
################################################################
# This is a generated script based on design: design_2
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

namespace eval _tcl {
proc get_script_folder {} {
   set script_path [file normalize [info script]]
   set script_folder [file dirname $script_path]
   return $script_folder
}
}
variable script_folder
set script_folder [_tcl::get_script_folder]

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2023.1
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   catch {common::send_gid_msg -ssname BD::TCL -id 2041 -severity "ERROR" "This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."}

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source design_2_script.tcl

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xcu55c-fsvh2892-2L-e
   set_property BOARD_PART xilinx.com:au55c:part0:1.0 [current_project]
}


# CHANGE DESIGN NAME HERE
variable design_name
set design_name design_2

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      common::send_gid_msg -ssname BD::TCL -id 2001 -severity "INFO" "Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   common::send_gid_msg -ssname BD::TCL -id 2002 -severity "INFO" "Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   common::send_gid_msg -ssname BD::TCL -id 2003 -severity "INFO" "Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   common::send_gid_msg -ssname BD::TCL -id 2004 -severity "INFO" "Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

common::send_gid_msg -ssname BD::TCL -id 2005 -severity "INFO" "Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   catch {common::send_gid_msg -ssname BD::TCL -id 2006 -severity "ERROR" $errMsg}
   return $nRet
}

set bCheckIPsPassed 1
##################################################################
# CHECK IPs
##################################################################
set bCheckIPs 1
if { $bCheckIPs == 1 } {
   set list_check_ips "\ 
xilinx.com:ip:proc_sys_reset:5.0\
xilinx.com:ip:smartconnect:1.0\
xilinx.com:ip:axi_timer:2.0\
xilinx.com:ip:axi_uartlite:2.0\
xilinx.com:ip:clk_wiz:6.0\
xilinx.com:ip:hbm:1.0\
xilinx.com:ip:mdm:3.2\
xilinx.com:ip:microblaze:11.0\
xilinx.com:ip:xdma:4.1\
xilinx.com:ip:util_ds_buf:2.2\
xilinx.com:hls:TNN:1.0\
xilinx.com:ip:lmb_v10:3.0\
xilinx.com:ip:lmb_bram_if_cntlr:4.0\
xilinx.com:ip:blk_mem_gen:8.4\
"

   set list_ips_missing ""
   common::send_gid_msg -ssname BD::TCL -id 2011 -severity "INFO" "Checking if the following IPs exist in the project's IP catalog: $list_check_ips ."

   foreach ip_vlnv $list_check_ips {
      set ip_obj [get_ipdefs -all $ip_vlnv]
      if { $ip_obj eq "" } {
         lappend list_ips_missing $ip_vlnv
      }
   }

   if { $list_ips_missing ne "" } {
      catch {common::send_gid_msg -ssname BD::TCL -id 2012 -severity "ERROR" "The following IPs are not found in the IP Catalog:\n  $list_ips_missing\n\nResolution: Please add the repository containing the IP(s) to the project." }
      set bCheckIPsPassed 0
   }

}

if { $bCheckIPsPassed != 1 } {
  common::send_gid_msg -ssname BD::TCL -id 2023 -severity "WARNING" "Will not continue with creation of design due to the error(s) above."
  return 3
}

##################################################################
# DESIGN PROCs
##################################################################


# Hierarchical cell: microblaze_0_local_memory
proc create_hier_cell_microblaze_0_local_memory { parentCell nameHier } {

  variable script_folder

  if { $parentCell eq "" || $nameHier eq "" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2092 -severity "ERROR" "create_hier_cell_microblaze_0_local_memory() - Empty argument(s)!"}
     return
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2090 -severity "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2091 -severity "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj

  # Create cell and set as current instance
  set hier_obj [create_bd_cell -type hier $nameHier]
  current_bd_instance $hier_obj

  # Create interface pins
  create_bd_intf_pin -mode MirroredMaster -vlnv xilinx.com:interface:lmb_rtl:1.0 DLMB

  create_bd_intf_pin -mode MirroredMaster -vlnv xilinx.com:interface:lmb_rtl:1.0 ILMB


  # Create pins
  create_bd_pin -dir I -type clk LMB_Clk
  create_bd_pin -dir I -type rst SYS_Rst

  # Create instance: dlmb_v10, and set properties
  set dlmb_v10 [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_v10:3.0 dlmb_v10 ]

  # Create instance: ilmb_v10, and set properties
  set ilmb_v10 [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_v10:3.0 ilmb_v10 ]

  # Create instance: dlmb_bram_if_cntlr, and set properties
  set dlmb_bram_if_cntlr [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_bram_if_cntlr:4.0 dlmb_bram_if_cntlr ]
  set_property CONFIG.C_ECC {0} $dlmb_bram_if_cntlr


  # Create instance: ilmb_bram_if_cntlr, and set properties
  set ilmb_bram_if_cntlr [ create_bd_cell -type ip -vlnv xilinx.com:ip:lmb_bram_if_cntlr:4.0 ilmb_bram_if_cntlr ]
  set_property CONFIG.C_ECC {0} $ilmb_bram_if_cntlr


  # Create instance: lmb_bram, and set properties
  set lmb_bram [ create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen:8.4 lmb_bram ]
  set_property -dict [list \
    CONFIG.Enable_B {Use_ENB_Pin} \
    CONFIG.Memory_Type {True_Dual_Port_RAM} \
    CONFIG.Port_B_Clock {100} \
    CONFIG.Port_B_Enable_Rate {100} \
    CONFIG.Port_B_Write_Rate {50} \
    CONFIG.Use_RSTB_Pin {true} \
    CONFIG.use_bram_block {BRAM_Controller} \
  ] $lmb_bram


  # Create interface connections
  connect_bd_intf_net -intf_net microblaze_0_dlmb [get_bd_intf_pins DLMB] [get_bd_intf_pins dlmb_v10/LMB_M]
  connect_bd_intf_net -intf_net microblaze_0_dlmb_bus [get_bd_intf_pins dlmb_v10/LMB_Sl_0] [get_bd_intf_pins dlmb_bram_if_cntlr/SLMB]
  connect_bd_intf_net -intf_net microblaze_0_dlmb_cntlr [get_bd_intf_pins dlmb_bram_if_cntlr/BRAM_PORT] [get_bd_intf_pins lmb_bram/BRAM_PORTA]
  connect_bd_intf_net -intf_net microblaze_0_ilmb [get_bd_intf_pins ILMB] [get_bd_intf_pins ilmb_v10/LMB_M]
  connect_bd_intf_net -intf_net microblaze_0_ilmb_bus [get_bd_intf_pins ilmb_v10/LMB_Sl_0] [get_bd_intf_pins ilmb_bram_if_cntlr/SLMB]
  connect_bd_intf_net -intf_net microblaze_0_ilmb_cntlr [get_bd_intf_pins ilmb_bram_if_cntlr/BRAM_PORT] [get_bd_intf_pins lmb_bram/BRAM_PORTB]

  # Create port connections
  connect_bd_net -net SYS_Rst_1 [get_bd_pins SYS_Rst] [get_bd_pins dlmb_v10/SYS_Rst] [get_bd_pins ilmb_v10/SYS_Rst] [get_bd_pins dlmb_bram_if_cntlr/LMB_Rst] [get_bd_pins ilmb_bram_if_cntlr/LMB_Rst]
  connect_bd_net -net microblaze_0_Clk [get_bd_pins LMB_Clk] [get_bd_pins dlmb_v10/LMB_Clk] [get_bd_pins ilmb_v10/LMB_Clk] [get_bd_pins dlmb_bram_if_cntlr/LMB_Clk] [get_bd_pins ilmb_bram_if_cntlr/LMB_Clk]

  # Restore current instance
  current_bd_instance $oldCurInst
}


# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  variable script_folder
  variable design_name

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2090 -severity "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_gid_msg -ssname BD::TCL -id 2091 -severity "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports
  set fpga_uart0 [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:uart_rtl:1.0 fpga_uart0 ]

  set pci_express_x4 [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:pcie_7x_mgt_rtl:1.0 pci_express_x4 ]

  set pcie_refclk [ create_bd_intf_port -mode Slave -vlnv xilinx.com:interface:diff_clock_rtl:1.0 pcie_refclk ]
  set_property -dict [ list \
   CONFIG.FREQ_HZ {100000000} \
   ] $pcie_refclk


  # Create ports
  set pcie_perstn [ create_bd_port -dir I -type rst pcie_perstn ]
  set_property -dict [ list \
   CONFIG.POLARITY {ACTIVE_LOW} \
 ] $pcie_perstn

  # Create instance: microblaze_0_local_memory
  create_hier_cell_microblaze_0_local_memory [current_bd_instance .] microblaze_0_local_memory

  # Create instance: rst_clk_wiz_1_100M, and set properties
  set rst_clk_wiz_1_100M [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 rst_clk_wiz_1_100M ]

  # Create instance: rst_clk_wiz_1_100M1, and set properties
  set rst_clk_wiz_1_100M1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 rst_clk_wiz_1_100M1 ]

  # Create instance: rst_clk_wiz_1_288M, and set properties
  set rst_clk_wiz_1_288M [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 rst_clk_wiz_1_288M ]

  # Create instance: axi_smc, and set properties
  set axi_smc [ create_bd_cell -type ip -vlnv xilinx.com:ip:smartconnect:1.0 axi_smc ]
  set_property -dict [list \
    CONFIG.NUM_CLKS {5} \
    CONFIG.NUM_MI {5} \
    CONFIG.NUM_SI {14} \
  ] $axi_smc


  # Create instance: axi_timer_0, and set properties
  set axi_timer_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_timer:2.0 axi_timer_0 ]

  # Create instance: axi_uartlite_0, and set properties
  set axi_uartlite_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_uartlite:2.0 axi_uartlite_0 ]
  set_property -dict [list \
    CONFIG.C_BAUDRATE {115200} \
    CONFIG.UARTLITE_BOARD_INTERFACE {fpga_uart0} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $axi_uartlite_0


  # Create instance: clk_wiz_1, and set properties
  set clk_wiz_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:clk_wiz:6.0 clk_wiz_1 ]
  set_property -dict [list \
    CONFIG.CLKIN1_JITTER_PS {80.0} \
    CONFIG.CLKOUT1_JITTER {232.290} \
    CONFIG.CLKOUT1_PHASE_ERROR {246.360} \
    CONFIG.CLKOUT1_REQUESTED_OUT_FREQ {100} \
    CONFIG.CLKOUT2_JITTER {210.569} \
    CONFIG.CLKOUT2_PHASE_ERROR {246.360} \
    CONFIG.CLKOUT2_REQUESTED_OUT_FREQ {185} \
    CONFIG.CLKOUT2_USED {true} \
    CONFIG.CLKOUT3_JITTER {210.569} \
    CONFIG.CLKOUT3_PHASE_ERROR {246.360} \
    CONFIG.CLKOUT3_REQUESTED_OUT_FREQ {185} \
    CONFIG.CLKOUT3_USED {true} \
    CONFIG.CLKOUT4_JITTER {210.569} \
    CONFIG.CLKOUT4_PHASE_ERROR {246.360} \
    CONFIG.CLKOUT4_REQUESTED_OUT_FREQ {185} \
    CONFIG.CLKOUT4_USED {true} \
    CONFIG.MMCM_CLKFBOUT_MULT_F {37.000} \
    CONFIG.MMCM_CLKIN1_PERIOD {8.000} \
    CONFIG.MMCM_CLKIN2_PERIOD {10.0} \
    CONFIG.MMCM_CLKOUT0_DIVIDE_F {9.250} \
    CONFIG.MMCM_CLKOUT1_DIVIDE {5} \
    CONFIG.MMCM_CLKOUT2_DIVIDE {5} \
    CONFIG.MMCM_CLKOUT3_DIVIDE {5} \
    CONFIG.MMCM_DIVCLK_DIVIDE {5} \
    CONFIG.NUM_OUT_CLKS {4} \
    CONFIG.PRIM_IN_FREQ {125.000} \
    CONFIG.PRIM_SOURCE {Global_buffer} \
    CONFIG.RESET_PORT {resetn} \
    CONFIG.RESET_TYPE {ACTIVE_LOW} \
  ] $clk_wiz_1


  # Create instance: hbm_0, and set properties
  set hbm_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:hbm:1.0 hbm_0 ]
  set_property -dict [list \
    CONFIG.USER_APB_EN {false} \
    CONFIG.USER_AXI_CLK_FREQ {400} \
    CONFIG.USER_AXI_INPUT_CLK_FREQ {100} \
    CONFIG.USER_AXI_INPUT_CLK_NS {10.000} \
    CONFIG.USER_AXI_INPUT_CLK_PS {10000} \
    CONFIG.USER_AXI_INPUT_CLK_XDC {10.000} \
    CONFIG.USER_CLK_SEL_LIST0 {AXI_00_ACLK} \
    CONFIG.USER_HBM_CP_0 {5} \
    CONFIG.USER_HBM_FBDIV_0 {32} \
    CONFIG.USER_HBM_HEX_CP_RES_0 {0x0000A500} \
    CONFIG.USER_HBM_HEX_FBDIV_CLKOUTDIV_0 {0x00000802} \
    CONFIG.USER_HBM_HEX_LOCK_FB_REF_DLY_0 {0x00001f1f} \
    CONFIG.USER_HBM_LOCK_FB_DLY_0 {31} \
    CONFIG.USER_HBM_LOCK_REF_DLY_0 {31} \
    CONFIG.USER_HBM_REF_CLK_0 {100} \
    CONFIG.USER_HBM_REF_CLK_PS_0 {5000.00} \
    CONFIG.USER_HBM_REF_CLK_XDC_0 {10.00} \
    CONFIG.USER_HBM_RES_0 {10} \
    CONFIG.USER_HBM_TCK_0 {400} \
    CONFIG.USER_MC0_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC10_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC11_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC12_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC13_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC14_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC15_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC1_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC2_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC3_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC4_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC5_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC6_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC7_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC8_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC9_Q_AGE_LIMIT {0x7F} \
    CONFIG.USER_MC_ENABLE_01 {FALSE} \
    CONFIG.USER_MC_ENABLE_02 {FALSE} \
    CONFIG.USER_MC_ENABLE_03 {FALSE} \
    CONFIG.USER_MC_ENABLE_04 {FALSE} \
    CONFIG.USER_MC_ENABLE_05 {FALSE} \
    CONFIG.USER_MC_ENABLE_06 {FALSE} \
    CONFIG.USER_MC_ENABLE_07 {FALSE} \
    CONFIG.USER_SAXI_01 {false} \
    CONFIG.USER_SAXI_02 {false} \
    CONFIG.USER_SAXI_03 {false} \
    CONFIG.USER_SAXI_04 {false} \
    CONFIG.USER_SAXI_05 {false} \
    CONFIG.USER_SAXI_06 {false} \
    CONFIG.USER_SAXI_07 {false} \
    CONFIG.USER_SAXI_08 {false} \
    CONFIG.USER_SAXI_09 {false} \
    CONFIG.USER_SAXI_10 {false} \
    CONFIG.USER_SAXI_11 {false} \
    CONFIG.USER_SAXI_12 {false} \
    CONFIG.USER_SAXI_13 {false} \
    CONFIG.USER_SAXI_14 {false} \
    CONFIG.USER_SAXI_15 {false} \
  ] $hbm_0


  # Create instance: mdm_1, and set properties
  set mdm_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:mdm:3.2 mdm_1 ]

  # Create instance: microblaze_0, and set properties
  set microblaze_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:microblaze:11.0 microblaze_0 ]
  set_property -dict [list \
    CONFIG.C_ADDR_TAG_BITS {17} \
    CONFIG.C_AREA_OPTIMIZED {2} \
    CONFIG.C_BRANCH_TARGET_CACHE_SIZE {1} \
    CONFIG.C_CACHE_BYTE_SIZE {4096} \
    CONFIG.C_DCACHE_ADDR_TAG {17} \
    CONFIG.C_DCACHE_BASEADDR {0x0000000020000000} \
    CONFIG.C_DCACHE_BYTE_SIZE {4096} \
    CONFIG.C_DCACHE_FORCE_TAG_LUTRAM {0} \
    CONFIG.C_DCACHE_HIGHADDR {0x000000003FFFFFFF} \
    CONFIG.C_DCACHE_LINE_LEN {4} \
    CONFIG.C_DEBUG_ENABLED {1} \
    CONFIG.C_D_AXI {1} \
    CONFIG.C_D_LMB {1} \
    CONFIG.C_FSL_LINKS {0} \
    CONFIG.C_ICACHE_BASEADDR {0x0000000020000000} \
    CONFIG.C_ICACHE_FORCE_TAG_LUTRAM {0} \
    CONFIG.C_ICACHE_HIGHADDR {0x000000003FFFFFFF} \
    CONFIG.C_ICACHE_LINE_LEN {4} \
    CONFIG.C_I_LMB {1} \
    CONFIG.C_MMU_DTLB_SIZE {4} \
    CONFIG.C_MMU_ITLB_SIZE {2} \
    CONFIG.C_MMU_ZONES {2} \
    CONFIG.C_USE_BRANCH_TARGET_CACHE {1} \
    CONFIG.C_USE_DCACHE {1} \
    CONFIG.C_USE_ICACHE {1} \
    CONFIG.C_USE_MMU {3} \
    CONFIG.G_TEMPLATE_LIST {3} \
  ] $microblaze_0


  # Create instance: xdma_0, and set properties
  set xdma_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:xdma:4.1 xdma_0 ]
  set_property -dict [list \
    CONFIG.PCIE_BOARD_INTERFACE {pci_express_x4} \
    CONFIG.PF0_DEVICE_ID_mqdma {9031} \
    CONFIG.PF2_DEVICE_ID_mqdma {9231} \
    CONFIG.PF3_DEVICE_ID_mqdma {9331} \
    CONFIG.SYS_RST_N_BOARD_INTERFACE {pcie_perstn} \
    CONFIG.axisten_freq {125} \
    CONFIG.cfg_mgmt_if {false} \
    CONFIG.pf0_device_id {9031} \
    CONFIG.pf0_link_status_slot_clock_config {true} \
    CONFIG.pf0_msi_enabled {false} \
    CONFIG.pl_link_cap_max_link_speed {8.0_GT/s} \
    CONFIG.plltype {QPLL1} \
    CONFIG.xdma_axi_intf_mm {AXI_Memory_Mapped} \
    CONFIG.xdma_pcie_64bit_en {true} \
    CONFIG.xdma_rnum_chnl {4} \
    CONFIG.xdma_wnum_chnl {4} \
  ] $xdma_0


  # Create instance: util_ds_buf_0, and set properties
  set util_ds_buf_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:util_ds_buf:2.2 util_ds_buf_0 ]
  set_property -dict [list \
    CONFIG.DIFF_CLK_IN_BOARD_INTERFACE {pcie_refclk} \
    CONFIG.USE_BOARD_FLOW {true} \
  ] $util_ds_buf_0


  # Create instance: rst_clk_wiz_1_400M, and set properties
  set rst_clk_wiz_1_400M [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 rst_clk_wiz_1_400M ]

  # Create instance: TNN_0, and set properties
  set TNN_0 [ create_bd_cell -type ip -vlnv xilinx.com:hls:TNN:1.0 TNN_0 ]

  # Create interface connections
  connect_bd_intf_net -intf_net TNN_0_m_axi_b1 [get_bd_intf_pins TNN_0/m_axi_b1] [get_bd_intf_pins axi_smc/S13_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_bK [get_bd_intf_pins TNN_0/m_axi_bK] [get_bd_intf_pins axi_smc/S09_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_bQ [get_bd_intf_pins TNN_0/m_axi_bQ] [get_bd_intf_pins axi_smc/S08_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_bV [get_bd_intf_pins TNN_0/m_axi_bV] [get_bd_intf_pins axi_smc/S10_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_gmem [get_bd_intf_pins TNN_0/m_axi_ins] [get_bd_intf_pins axi_smc/S04_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_outs [get_bd_intf_pins TNN_0/m_axi_outs] [get_bd_intf_pins axi_smc/S11_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_w1 [get_bd_intf_pins TNN_0/m_axi_w1] [get_bd_intf_pins axi_smc/S12_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_wK [get_bd_intf_pins TNN_0/m_axi_wK] [get_bd_intf_pins axi_smc/S06_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_wQ [get_bd_intf_pins TNN_0/m_axi_wQ] [get_bd_intf_pins axi_smc/S05_AXI]
  connect_bd_intf_net -intf_net TNN_0_m_axi_wV [get_bd_intf_pins TNN_0/m_axi_wV] [get_bd_intf_pins axi_smc/S07_AXI]
  connect_bd_intf_net -intf_net axi_smc_M00_AXI [get_bd_intf_pins axi_smc/M00_AXI] [get_bd_intf_pins axi_timer_0/S_AXI]
  connect_bd_intf_net -intf_net axi_smc_M01_AXI [get_bd_intf_pins axi_smc/M01_AXI] [get_bd_intf_pins hbm_0/SAXI_00_8HI]
  connect_bd_intf_net -intf_net axi_smc_M02_AXI [get_bd_intf_pins axi_uartlite_0/S_AXI] [get_bd_intf_pins axi_smc/M02_AXI]
  connect_bd_intf_net -intf_net axi_smc_M03_AXI [get_bd_intf_pins axi_smc/M03_AXI] [get_bd_intf_pins TNN_0/s_axi_bus_bundle]
  connect_bd_intf_net -intf_net axi_smc_M04_AXI [get_bd_intf_pins axi_smc/M04_AXI] [get_bd_intf_pins TNN_0/s_axi_control]
  connect_bd_intf_net -intf_net axi_uartlite_0_UART [get_bd_intf_ports fpga_uart0] [get_bd_intf_pins axi_uartlite_0/UART]
  connect_bd_intf_net -intf_net microblaze_0_M_AXI_DC [get_bd_intf_pins microblaze_0/M_AXI_DC] [get_bd_intf_pins axi_smc/S02_AXI]
  connect_bd_intf_net -intf_net microblaze_0_M_AXI_DP [get_bd_intf_pins microblaze_0/M_AXI_DP] [get_bd_intf_pins axi_smc/S00_AXI]
  connect_bd_intf_net -intf_net microblaze_0_M_AXI_IC [get_bd_intf_pins microblaze_0/M_AXI_IC] [get_bd_intf_pins axi_smc/S03_AXI]
  connect_bd_intf_net -intf_net microblaze_0_debug [get_bd_intf_pins mdm_1/MBDEBUG_0] [get_bd_intf_pins microblaze_0/DEBUG]
  connect_bd_intf_net -intf_net microblaze_0_dlmb_1 [get_bd_intf_pins microblaze_0/DLMB] [get_bd_intf_pins microblaze_0_local_memory/DLMB]
  connect_bd_intf_net -intf_net microblaze_0_ilmb_1 [get_bd_intf_pins microblaze_0/ILMB] [get_bd_intf_pins microblaze_0_local_memory/ILMB]
  connect_bd_intf_net -intf_net pcie_refclk_1 [get_bd_intf_ports pcie_refclk] [get_bd_intf_pins util_ds_buf_0/CLK_IN_D]
  connect_bd_intf_net -intf_net xdma_0_M_AXI [get_bd_intf_pins xdma_0/M_AXI] [get_bd_intf_pins axi_smc/S01_AXI]
  connect_bd_intf_net -intf_net xdma_0_pcie_mgt [get_bd_intf_ports pci_express_x4] [get_bd_intf_pins xdma_0/pcie_mgt]

  # Create port connections
  connect_bd_net -net clk_wiz_1_clk_out1 [get_bd_pins clk_wiz_1/clk_out1] [get_bd_pins rst_clk_wiz_1_100M1/slowest_sync_clk] [get_bd_pins axi_smc/aclk2] [get_bd_pins hbm_0/APB_0_PCLK]
  connect_bd_net -net clk_wiz_1_clk_out3 [get_bd_pins clk_wiz_1/clk_out3] [get_bd_pins rst_clk_wiz_1_288M/slowest_sync_clk] [get_bd_pins axi_smc/aclk3] [get_bd_pins axi_uartlite_0/s_axi_aclk]
  connect_bd_net -net clk_wiz_1_clk_out4 [get_bd_pins clk_wiz_1/clk_out4] [get_bd_pins hbm_0/HBM_REF_CLK_0] [get_bd_pins hbm_0/AXI_00_ACLK] [get_bd_pins rst_clk_wiz_1_400M/slowest_sync_clk] [get_bd_pins axi_smc/aclk]
  connect_bd_net -net clk_wiz_1_locked [get_bd_pins clk_wiz_1/locked] [get_bd_pins rst_clk_wiz_1_100M/dcm_locked]
  connect_bd_net -net mdm_1_debug_sys_rst [get_bd_pins mdm_1/Debug_SYS_Rst] [get_bd_pins rst_clk_wiz_1_100M/mb_debug_sys_rst]
  connect_bd_net -net microblaze_0_Clk [get_bd_pins clk_wiz_1/clk_out2] [get_bd_pins microblaze_0_local_memory/LMB_Clk] [get_bd_pins rst_clk_wiz_1_100M/slowest_sync_clk] [get_bd_pins axi_timer_0/s_axi_aclk] [get_bd_pins microblaze_0/Clk] [get_bd_pins axi_smc/aclk4] [get_bd_pins TNN_0/ap_clk]
  connect_bd_net -net pcie_perstn_1 [get_bd_ports pcie_perstn] [get_bd_pins rst_clk_wiz_1_100M/ext_reset_in] [get_bd_pins rst_clk_wiz_1_100M1/ext_reset_in] [get_bd_pins rst_clk_wiz_1_288M/ext_reset_in] [get_bd_pins xdma_0/sys_rst_n] [get_bd_pins rst_clk_wiz_1_400M/ext_reset_in]
  connect_bd_net -net rst_clk_wiz_1_100M1_peripheral_aresetn [get_bd_pins rst_clk_wiz_1_100M1/peripheral_aresetn] [get_bd_pins hbm_0/APB_0_PRESET_N]
  connect_bd_net -net rst_clk_wiz_1_100M2_peripheral_aresetn [get_bd_pins rst_clk_wiz_1_288M/peripheral_aresetn] [get_bd_pins axi_uartlite_0/s_axi_aresetn]
  connect_bd_net -net rst_clk_wiz_1_100M2_peripheral_aresetn1 [get_bd_pins rst_clk_wiz_1_400M/peripheral_aresetn] [get_bd_pins hbm_0/AXI_00_ARESET_N]
  connect_bd_net -net rst_clk_wiz_1_100M_bus_struct_reset [get_bd_pins rst_clk_wiz_1_100M/bus_struct_reset] [get_bd_pins microblaze_0_local_memory/SYS_Rst]
  connect_bd_net -net rst_clk_wiz_1_100M_mb_reset [get_bd_pins rst_clk_wiz_1_100M/mb_reset] [get_bd_pins microblaze_0/Reset]
  connect_bd_net -net rst_clk_wiz_1_100M_peripheral_aresetn [get_bd_pins rst_clk_wiz_1_100M/peripheral_aresetn] [get_bd_pins axi_smc/aresetn] [get_bd_pins axi_timer_0/s_axi_aresetn] [get_bd_pins TNN_0/ap_rst_n]
  connect_bd_net -net util_ds_buf_0_IBUF_DS_ODIV2 [get_bd_pins util_ds_buf_0/IBUF_DS_ODIV2] [get_bd_pins xdma_0/sys_clk]
  connect_bd_net -net util_ds_buf_0_IBUF_OUT [get_bd_pins util_ds_buf_0/IBUF_OUT] [get_bd_pins xdma_0/sys_clk_gt]
  connect_bd_net -net xdma_0_axi_aclk [get_bd_pins xdma_0/axi_aclk] [get_bd_pins axi_smc/aclk1] [get_bd_pins clk_wiz_1/clk_in1]
  connect_bd_net -net xdma_0_axi_aresetn [get_bd_pins xdma_0/axi_aresetn] [get_bd_pins clk_wiz_1/resetn]

  # Create address segments
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x00000000 -range 0x00002000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs microblaze_0_local_memory/dlmb_bram_if_cntlr/SLMB/Mem] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces microblaze_0/Data] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00000000 -range 0x00002000 -target_address_space [get_bd_addr_spaces microblaze_0/Instruction] [get_bd_addr_segs microblaze_0_local_memory/ilmb_bram_if_cntlr/SLMB/Mem] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces xdma_0/M_AXI] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces xdma_0/M_AXI] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces xdma_0/M_AXI] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces xdma_0/M_AXI] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces xdma_0/M_AXI] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces xdma_0/M_AXI] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_b1] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_b1] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_b1] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_b1] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_b1] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_b1] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bK] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bK] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bK] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bK] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bK] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bK] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bQ] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bQ] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bQ] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bQ] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bQ] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bQ] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bV] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bV] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bV] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bV] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bV] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_bV] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_ins] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_ins] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_ins] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_ins] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_ins] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_ins] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_outs] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_outs] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_outs] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_outs] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_outs] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_outs] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_w1] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_w1] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_w1] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_w1] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_w1] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_w1] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wK] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wK] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wK] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wK] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wK] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wK] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wQ] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wQ] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wQ] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wQ] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wQ] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wQ] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force
  assign_bd_address -offset 0x00010000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wV] [get_bd_addr_segs TNN_0/s_axi_bus_bundle/Reg] -force
  assign_bd_address -offset 0x00008000 -range 0x00008000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wV] [get_bd_addr_segs TNN_0/s_axi_control/Reg] -force
  assign_bd_address -offset 0x41C00000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wV] [get_bd_addr_segs axi_timer_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x40600000 -range 0x00010000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wV] [get_bd_addr_segs axi_uartlite_0/S_AXI/Reg] -force
  assign_bd_address -offset 0x10000000 -range 0x10000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wV] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM00] -force
  assign_bd_address -offset 0x20000000 -range 0x20000000 -target_address_space [get_bd_addr_spaces TNN_0/Data_m_axi_wV] [get_bd_addr_segs hbm_0/SAXI_00_8HI/HBM_MEM01] -force


  # Restore current instance
  current_bd_instance $oldCurInst

  validate_bd_design
  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""


