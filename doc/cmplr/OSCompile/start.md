# Program Start
With start(),
-
- Starts at the org set by the macro, if undefined, autos to org 0x7c00
- Bootloader is not loaded quite yet
- Would be used for more eperienced programmers

With main(),
-
- Starts at the sector defined by the bootloader with macro
```
#define MAIN_SET_START <int:<bitNum> bits>
```