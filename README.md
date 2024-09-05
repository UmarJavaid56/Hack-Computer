# Hack-Computer
This repository contains my implementation of the Hack computer as described in "The Elements of Computing Systems" by Noam Nisan and Shimon Schocken. The project includes the complete hardware architecture of the Hack platform, from the ALU and CPU to the assembler.

The Hack computer hardware consists of three core components.
- Instruction Memory (ROM)
- Date Memory (RAM)
- The Central Processing Unit (CPU)


### Instruction Memory
**ROM Module:** A linear array of sequential, 16-bit memory registers, starting at address 0 (0x0000). 

**Addressing:** Uses a 15-bit wide address bus, allowing access to 32,768 (2^15) individual memory words.
 
**Clock Signal:** The system clock signal is provided by both the simulation and computer emulator applications.

**Program Counter:** The current instruction address is supplied by the program counter register within the CPU.

**Instruction Fetching:** The instruction from the ROM register at the address on the instruction address bus is available as the "current" instruction at the beginning of the next cycle.

**Instruction Decoding:** There is no dedicated instruction register; instructions are directly decoded from the active ROM register in each clock cycle.
