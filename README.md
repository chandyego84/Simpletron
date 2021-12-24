# Simpletron Machine Language

A simple computer that runs programs written in the only language
it directly understands: SML.

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