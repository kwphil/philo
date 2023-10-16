Version 0.2

Philo is a system programming language that is meant to be used on system programming, and is meant to focus primarily on macros.

Here is an example of printing "Hello, World!" using straight BIOS:
```
#include <io>
#prgmfor "OS"
#bits 16

fn public int main() {
  print("Hello, World!");
}
```
If you want to learn how to use Philo in depth, check out the doc dir in the repository.
It will take you step-by-step to become a pro in the language.

If you feel like that the earlier example isn't enough, here is another example that shows more of what Philo can do that others can't:
```
#include <io>
#include <convert>
#include "txt/ex.txt"
#include "asm/b64/print.asm"
#prgmfor "OS"
#bits 64

private struct stExample {
  string[60] str;
  int num = 3;
}

fn public int main() {
  stExample obExample;

  print(sizeof(obExample)); //returns 63;

  for(int i = 0; i < MACRO_IN(bits, 0); i++ : r) {
    print(i.tostr()); //prints 1-64
  }

  \mov rbx, msg0
  \call print64
  \msg0 db "Hello, World!",0

  print(readFile("txt/ex.txt"))

  return 0;
}
```

Another great thing about Philo is the linking power. It can link:
- Other Philo files
- Assembly files
- C files
- Rust files
- Binary files
- Plain text files