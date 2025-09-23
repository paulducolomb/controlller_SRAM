----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.09.2025 11:04:59
-- Design Name: 
-- Module Name: control_SRAM - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity control_SRAM is
 Port (
    -- Interface utilisateur
    clk      : in  std_logic;
    reset    : in  std_logic;
    addr_in  : in  std_logic_vector(18 downto 0);
    data_in  : in  std_logic_vector(35 downto 0);
    data_out : out std_logic_vector(35 downto 0);
    we       : in  std_logic;  -- 1 = demande écriture
    re       : in  std_logic;  -- 1 = demande lecture
    ready    : out std_logic;  -- 1 = opération terminée

    -- Interface SRAM
    Addr     : out std_logic_vector(18 downto 0);
    Dq       : inout std_logic_vector(35 downto 0);
    Ce_n     : out std_logic;
    Ce2      : out std_logic;
    Ce2_n    : out std_logic;
    Oe_n     : out std_logic;
    Rw_n     : out std_logic;
    Ld_n     : out std_logic;
    Cke_n    : out std_logic
  );end control_SRAM;

architecture Behavioral of control_SRAM is
  type state_t is (IDLE, ADDR_LOAD, WRITE_DATA, READ_CAPTURE, DESELECT);
  signal state, next_state : state_t := IDLE;

  signal addr_reg : std_logic_vector(18 downto 0);
  signal data_out_reg : std_logic_vector(35 downto 0);
  signal dq_out : std_logic_vector(35 downto 0);
  signal dq_t   : std_logic := '1';  -- tri-state control ('1' = Z, '0' = drive)

begin











end Behavioral;
