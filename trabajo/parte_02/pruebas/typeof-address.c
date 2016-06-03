#include <stdio.h>

int main() {
  int a = 5;
  typeof(a) b;
  b = a;
  printf("%d", b);
  return 0;
}
