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

If you feel like that the earlier example is enough, here is another example:
```
#include <io>
#include <convert>
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

  return 0;
}
```