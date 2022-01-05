# SIMP Machine Language

A simple computer that runs programs written in the only language
it directly understands: SIMP Machine Language.

**Accumulator**: "special register" in which information is put before the Simpletron uses that information
in calculations or examines it in various ways. All information in Simpletron is handled in terms of _words_.
A word is a signed four-digit decimal number such as +3364, -1293, -0001, etc. Simpletron is equipped with a 100-word memory.

## Operation Code
First two digits of each SML instruction specifying the operation to be performed.

### Input/Output Operations
const int read{10}; Read a word from the keyboard into a specific location in memory.

const int write{11}; Write a word from a specific location in memory to the screen.

### Load/Store Operations
const int load{20}; Load a word from a specific location in memory into the accumulator.

const int store{21}; Store a word from the accumulator into a specific location in memory.

### Arithmetic Operations
const int add{30}; Add a word from a specific location in memory to the word in the accumulator 
(leave result in accumulator).

const int subtract{31}; Subtract a word from a specific location in memory from the word in the accumulator 
(leave result in accumulator).

const int divide{32}; Divide a word from a specific location in memory into the word in the accumulator
(leave result in accumulator).

const int multiply{33}; Multiply a word from a specific location in memory by the word in the accumulator
(leave result in accumulator).

### Transfer-of-control Operations
const int branch{40}; Branch into a specific location in memory.

const int branchneg{41}; Branch to a specific location in memory if the accumulator is negative.

const int branchzero{42}; Branch to a specific location in memory if the accumulator is zero.

const int halt{43}; Halt--the program has completed its task.

## SML Extensions
- [x] Extend the Simpletron Simulator’s memory to contain 1000 memory locations to enable the Simpletron to handle larger programs.
- [x] Allow the simulator to perform remainder calculations. This requires an additional Simpletron Machine Language instruction.
- [x] Allow the simulator to perform exponentiation calculations. This requires an additional Simpletron Machine Language instruction.
- [ ] Modify the simulator to use hexadecimal values rather than integer values to represent Simpletron Machine Language instructions. 
- [x] Modify the simulator to allow output of a newline. This requires an additional Simpletron Machine Language instruction. 
- [ ] Modify the simulator to process floating-point values in addition to integer values.
- [x] Modify the simulator to handle string input. [Each Simpletron word can be divided into two groups,each holding a two-digit integer. Each two-digit integer represents the ASCII decimal equivalent of a character. Add a machine-language instruction
that inputs a string and store the string beginning at a specific Simpletron memory location. The first half of the word at that location will be a count of the number of characters in the string (i.e., the length of the string). Each succeeding half-word contains
one ASCII character expressed as two decimal digits. The machine-language instruction
converts each character into its ASCII equivalent and assigns it to a half-word.]
- [ ] Modify the simulator to handle output of strings stored in the format of task above. 
[Add a machine-language instruction that will display a string beginning at a certain
Simpletron memory location. The first half of the word at that location is a count of the
number of characters in the string (i.e., the length of the string). Each succeeding halfword contains one ASCII character expressed as two decimal digits. The machine-language instruction checks the length and displays the string by translating each two-digit
number into its equivalent character.]
- [ ] Modify the simulator to include instruction SML_DEBUG that displays a memory dump
after each instruction executes. Give SML_DEBUG an operation code of 44. The word
+4401 turns on debug mode, and +4400 turns off debug mode.

