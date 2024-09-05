# Hack-Computer
This repository contains my implementation of the Hack computer as described in "The Elements of Computing Systems" by Noam Nisan and Shimon Schocken. The project includes the complete hardware architecture of the Hack platform, from the ALU and CPU to the assembler.

The Hack computer hardware consists of three core components.
- Instruction Memory (ROM)
- Date Memory (RAM)
- The Central Processing Unit (CPU)

![640px-Hack_Computer_Block_Diagram_2](https://github.com/user-attachments/assets/08b333db-e854-4882-a6da-1107779323c3)


### Instruction Memory
**ROM Module:** A linear array of sequential, 16-bit memory registers, starting at address 0 (0x0000). 

**Addressing:** Uses a 15-bit wide address bus, allowing access to 32,768 (2^15) individual memory words.
 
**Clock Signal:** The system clock signal is provided by both the simulation and computer emulator applications.

**Program Counter:** The current instruction address is supplied by the program counter register within the CPU.

**Instruction Fetching:** The instruction from the ROM register at the address on the instruction address bus is available as the "current" instruction at the beginning of the next cycle.

**Instruction Decoding:** There is no dedicated instruction register; instructions are directly decoded from the active ROM register in each clock cycle.

### Data Memory

**RAM Module:** A continuous linear array of sequential, read-write, 16-bit memory registers.

**Address Segments:**

**General-Purpose Data Storage:** Addresses 0 (0x0000) through 16383 (0x3FFF) contain conventional read-write registers for general program data.

**Screen I/O Subsystem:** Addresses 16384 (0x4000) through 24575 (0x5FFF) function like data RAM but also control output on the computer’s virtual 256 x 512 screen. If screen output is not needed, these registers can be used for general data.

**Keyboard Memory Map Register:** Address 24576 (0x6000) is a read-only register linked to the keyboard output of the host computer running the Hack emulator.

**Invalid Address Range:** Addresses 24577 (0x6001) through 32767 (0x7FFF) are invalid.

**System Clock Signal:** RAM state transitions are synchronized with the system clock signal.
