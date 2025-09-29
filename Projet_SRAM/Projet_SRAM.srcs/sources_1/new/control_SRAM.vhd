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


-- synopsys translate_on
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
    we       : in  std_logic;  
    re       : in  std_logic;  
    ready    : out std_logic;  

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
  type state_t is (IDLE, INIT, WRITE_DATA, READ_CAPTURE);
  signal state, next_state : state_t := IDLE;

  signal addr_reg : std_logic_vector(18 downto 0);
  signal data_out_reg : std_logic_vector(35 downto 0);
  signal dq_out : std_logic_vector(35 downto 0);
  signal dq_t   : std_logic := '1';  -- tri-state

begin

process(state, we, re)
  begin
    case state is

      when INIT => 
        next_state <= IDLE;

      when IDLE =>
        if we = '1' then
          next_state <= WRITE_DATA;
        elsif re = '1' then
          next_state <= READ_CAPTURE;
        else
          next_state <= IDLE;
        end if;

      when WRITE_DATA =>
      if we = '1' then
          next_state <= WRITE_DATA;
        elsif re = '1' then
          next_state <= READ_CAPTURE;
        else
          next_state <= IDLE;
        end if;

      when READ_CAPTURE =>
      if we = '1' then
          next_state <= WRITE_DATA;
        elsif re = '1' then
          next_state <= READ_CAPTURE;
        else
          next_state <= IDLE;
        end if;

    end case;
end process;


process(clk, reset)
  begin
    if reset = '1' then

      state        <= IDLE;
      addr_reg     <= (others => '0');
      data_out_reg <= (others => '0');
      dq_out       <= (others => '0');
      dq_t         <= '1';

    elsif falling_edge(clk) then
     
      state <= next_state;
      --valeur par défaut 
      Ce_n  <= '1';
      Ce2   <= '0';
      Ce2_n <= '1';
      Cke_n <= '1';
      Ld_n  <= '1';
      Rw_n  <= '1';
      Oe_n  <= '1';
      dq_t  <= '1';   
      ready <= '0';

      case state is
        when IDLE =>
        ready <= '1';
        --rien pour le moment 

        when INIT =>
        Ce_n  <= '1'; 
        Ce2 <= '1'; 
        Ce2_n <= '1';
        Cke_n <= '1'; 
        Ld_n <= '1';
        Rw_n  <= '1'; 
        Oe_n <= '1';
        dq_t  <= '1';
        ready  <= '1';


        when WRITE_DATA =>
        Ce_n  <= '0'; 
        Ce2 <= '1'; 
        Ce2_n <= '0';
        Cke_n <= '0'; 
        Rw_n <= '0'; 
        Ld_n <= '1';
        dq_out <= data_in;
        Addr   <= addr_in;
        dq_t   <= '0'; 
        ready  <= '0';

        when READ_CAPTURE =>
        Ce_n  <= '0'; 
        Ce2 <= '1'; 
        Ce2_n <= '0';
        Cke_n <= '0'; 
        Rw_n <= '1'; 
        Ld_n <= '1';
        Oe_n  <= '0';
        dq_t   <= '1';
        data_out_reg <= Dq;
        ready  <= '0';

      end case;
    end if;
  end process;

  data_out <= data_out_reg;

  -- bus
  Dq <= dq_out when dq_t = '0' else (others => 'Z');

end Behavioral;
