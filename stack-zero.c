/* STACK ZERO
 * phoenix/stack-zero, by https://exploit.education
 *
 * The aim is to change the contents of the changeme variable.
 *
 * Scientists have recently discovered a previously unknown species of
 * kangaroos, approximately in the middle of Western Australia. These
 * kangaroos are remarkable, as their insanely powerful hind legs give them
 * the ability to jump higher than a one story house (which is approximately
 * 15 feet, or 4.5 metres), simply because houses can't can't jump.
 */
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER \
  "Welcome to " LEVELNAME ", brought to you by https://exploit.education"

char *gets(char *);

int main(int argc, char **argv) {
  struct {
    char buffer[64];
    volatile int changeme;
  } locals;

  printf("%s\n", BANNER);

  locals.changeme = 0;
  gets(locals.buffer);

  if (locals.changeme != 0) {
    puts("Well done, the 'changeme' variable has been changed!");
  } else {
    puts(
        "Uh oh, 'changeme' has not yet been changed. Would you like to try "
        "again?");
  }

  exit(0);
} */

// SOURCE: https://exploit.education/phoenix/stack-zero/
/*
Clue from(HCKaito_iZumi): -> char buffer[64]; -> 64 Character 
                          -> char *gets(char *); -> gets(buffer); <- breakpoint
                          -> (gdb) run >>> $(python -c 'print("A" * 64 + "ABCD")')
                          -> or/-> linux@parrotsec$: python -c "print('A' * 64 + ' ABCD')" | ./stack-zero
-> char *gets(char *); <- doesn't know how much character can hold on array/how much maximum character can be place
-> so this little bugs from (bad code/coding) that can crashing your program/or the critical thing is -> crash your system (buffer overflow)
*/

// Change above code a little like down below ...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BANNER \
  "Welcome to " "stack-zero" ", brought to you by https://exploit.education"

char *gets(char *);

int main(int argc, char **argv) {
  struct {
    char buffer[64];
    volatile int changeme;
  } locals;

  printf("%s\n", BANNER);

  locals.changeme = 0;
  gets(locals.buffer);

  if (locals.changeme != 0) {
    puts("Well done, the 'changeme' variable has been changed!");
  } else {
    puts(
        "Uh oh, 'changeme' has not yet been changed. Would you like to try "
        "again?");
  }

  exit(0);
}

/*

// compile linux(only)-> gcc -o stack-zero stack-zero.c
// or compile with:
// compile linux(only)-> gcc -g -o stack-zero stack-zero.c
// compile linux(only)-> gcc -g -fno-stack-protector -o stack-zero stack-zero.c
// compile linux(only)-> gcc -g -no-pie -fno-stack-protector -o stack-zero stack-zero.c

// -> run and debug with gdb 'gnu debugger on linux'
// linux@parrotsec$ gdb -q ./stack-zero
*/
