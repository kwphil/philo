# Data types
## Variables and Registers
### General Purpose Registers
General Purpose registers are meant to be used for various things, and so cannot be set for specific data types
Using the same names as ASM as in Philo
```ex: $al, $ah, $bx, $eax, $edi```
### Segment Registers
Segment registers are meant to be used for, segments in the stack. to indicate that these are stack registers,
they are grabbed slightly differently
```ex: S$ss, S$ds, S$cs```
These are set by using a general-purpose register, set at eax/ax (depending on the bit mode), if you want to use a specific register, do the following:
```S$ss = 0x54 : $bx;```
To assign a specific register to assign, use the colon (:) operator to signal to use a specific register

### Variables
Variables can be used off the stack or the heap, depending on the declaration
Declaring a variable:
```gen var : heap = 0x54;```
Using the colon operator signals whether it is a heap variable or a stack variable
The default type is heap, so if the colon operator is not included, it will start out as a heap

### Accessibility
There are two types of accessibility, private, and public.
These are not specifically required, but are useful for adding readablility to the code
- Public
- Private
If the private function is in a header file, it may only be used by the same dir
Any function or var not specified will default to if it is in the header or not, say if it is included in the function, it is public, and vice versa
