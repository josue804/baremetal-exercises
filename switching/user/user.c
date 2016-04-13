/* A simple program that we will run in user mode.
 */
#include "simpleio.h"

extern void kputc(unsigned);
extern void yield(void);	//prototype for user yield function in userlib.s

void kputs(char* s) {
  while (*s) {
    kputc(*s++);
  }
}

void cmain() {
  int i;
  setWindow(2, 22, 50, 30);   // user process on right hand side
  cls();
  puts("in user code\n");
  for (i=0; i<4; i++) {
    kputs("hello, kernel console\n");
    puts("hello, user console\n");
  }
  puts("\n\nUser code does not return\n");
  for (;;) { /* Don't return! */
    yield(); //calls user yield function
  }
  puts("This message won't appear!\n");
}
