# Structs
Structs are used like they are in C, but with one addition:
They can have funcs defined inside the struct, and they do not require a 'struct' keyword like in C
```
struct example {
    int:1 var1;
    char:1 var2;
    void:0 func1() = *func1();
    void:0 func2() = {
        //insert code here
    };
};
//All valid ways to use structs
```
Any definitions inside a struct must have a return type
