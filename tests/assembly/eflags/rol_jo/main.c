#include "common.h"
#include <unistd.h>

int main() {
  int n;
  read(0, &n, sizeof(n));
  __asm__ goto("rol $1, %0\n"
      "jo %l1\n"
      "jmp %l2\n"
      :
      : "r"(n)
      :
      : good, bad);
good:
  good();
  return 0;
bad:
  bad();
  return 0;
}
