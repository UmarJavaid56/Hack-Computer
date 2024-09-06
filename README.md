# Hack-Computer
This repository contains my implementation of the Hack computer as described in "The Elements of Computing Systems" by Noam Nisan and Shimon Schocken. The project includes the complete hardware architecture of the Hack platform.

The Hack computer hardware consists of three core components.
- Instruction Memory (ROM)
- Date Memory (RAM)
- The Central Processing Unit (CPU)

![640px-Hack_Computer_Block_Diagram_2](https://github.com/user-attachments/assets/08b333db-e854-4882-a6da-1107779323c3)


### Instruction Memory
**ROM Module:** A linear array of sequential, 16-bit memory registers, starting at address 0x0000. 

**Addressing:** Uses a 15-bit wide address bus, allowing access to 32,768 individual memory words.
 
**Clock Signal:** The simulation and computer emulator applications provide the system clock signal.

**Program Counter:** The current instruction address is supplied by the program counter register within the CPU.

**Instruction Fetching:** The instruction from the ROM register at the address on the instruction address bus is available as the "current" instruction at the beginning of the next cycle.

**Instruction Decoding:** There is no dedicated instruction register; instructions are directly decoded from the active ROM register in each clock cycle.

### Data Memory

**RAM Module:** A continuous linear array of sequential, read-write, 16-bit memory registers.

**Address Segments:**

- **General-Purpose Data Storage:** Addresses 0 (0x0000) through 16383 (0x3FFF) contain conventional read-write registers for general program data.

- **Screen I/O Subsystem:** Addresses 16384 (0x4000) through 24575 (0x5FFF) function like data RAM but also control output on the computer’s virtual 256 x 512 screen. If screen output is not needed, these registers can be used for general data.

- **Keyboard Memory Map Register:** Address 24576 (0x6000) is a read-only register linked to the keyboard output of the host computer running the Hack emulator.

- **Invalid Address Range:** Addresses 24577 (0x6001) through 32767 (0x7FFF) are invalid.

**System Clock Signal:** RAM state transitions are synchronized with the system clock signal.

### The Central Processing Unit

The Hack CPU comprises an Arithmetic Logic Unit (ALU), a set of registers (including the D and A registers), a Program Counter (PC), and an instruction control unit that integrates these components to coordinate the execution of instructions.

![hack_cpu](https://github.com/user-attachments/assets/01bd7f15-5177-4717-842a-f7a4123e27c0)

#### Arithmetic Logic Unit (ALU)
- A combinational logic device with two 16-bit input operands and one 16-bit output.
- Operates based on six ordered, single-bit control inputs.
- Provides two status flags: zr (zero) and ng (negative) to indicate computation results.
  
![hack_alu](https://github.com/user-attachments/assets/e95a1d07-8cdb-4222-bf59-323d1ff8b409)

#### Registers
- D Register (Data): A 16-bit general-purpose register; that always supplies the x operand for the ALU, though its value can be ignored for some instructions.
- A Register (Address): Can provide its value as the y operand for the ALU; also used for data memory addressing and as a target for branching instructions.
- M Register (Pseudo-register): Represents the value stored in the RAM at the address specified by the A register; not physically implemented in hardware but used conceptually for accessing memory data indirectly through the A register's address.

#### Program Counter (PC)
- A 16-bit counter whose low 15 bits specify the address of the next instruction in memory.
- Automatically increments each clock cycle unless modified by a branching instruction.
- Includes a reset input that sets the PC to 0x0000 when toggled.

#### Instruction Control
- The CPU includes logic to alter instruction execution order via the PC but does not support hardware interrupts or function calls.

## Hack Machine Language

The Hack machine language has two types of instructions, each encoded in 16 binary digits:

#### 1. A-Instructions (Address Instructions)

Encoding:
- The most significant bit is 0.
- Bits b14 through b0 represent a 15-bit binary value corresponding to a non-negative integer between 0 and 32767.

Functionality:

- Loads the 15-bit value into the CPU's A-register.
- It enables the RAM register at the address specified by this value for read/write operations in the next clock cycle.

#### 2. C-Instructions (Computation Instructions)

Encoding:
- The most significant bit is 1.
- The next two bits are conventionally set to 1 and ignored by the CPU.
- Bit a specifies the source of the y operand for the ALU.
- Bits **c1** to **c6** control the operands and computation performed by the ALU.
- Bits **d1** to **d3** determine the destination(s) for the ALU output.
- Bits **j1** to **j3** specify a branching condition based on the most recent computation result, allowing for arithmetic-based branching, unconditional jumps, or no branching.

Format:
- dest=comp;jump
- Either dest or jump can be empty, leading to formats like dest=comp or comp;jump.
- dest specifies where to store the result.
- comp specifies the computation to perform.
- jump specifies the branching condition.

This encoding scheme allows the Hack CPU to perform basic computations, data manipulation, and control flow, making it a simple yet powerful instruction set for implementing basic programs and algorithms on the Hack platform.
