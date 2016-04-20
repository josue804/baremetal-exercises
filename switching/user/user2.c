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
  setWindow(13, 11, 47, 32);   // user process on right hand side
  cls();
  puts("in user2 code\n");
  for (i=0; i<4; i++) {
    kputs("hello, kernel console\n");
    puts("hello, user2 console\n");
  }
  puts("\n\nUser2 code does not return\n");
//  yield(); //calls user yield function
  puts("This user2 message won't appear!\n");
}
