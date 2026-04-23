#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  if (argc != 2)  {
    printf("%s -h for usage.\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE *f = fopen(argv[1], "rb");
  if (f == NULL) {
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
  uint8_t buf[16]; // Declaration of array on the stack
                   //
  size_t offset = 0;
  size_t n;
  while ((n = fread(buf,1,16,f)) > 0) {
    /* HEX Printing */
    printf("%08zx ", offset);
    for (int i = 0; i < 16; i++) {
      if (i < n) {
      printf("%02x ", buf[i]);
      } else{
        printf("   ");
      }
    }
    /* ASCII Letter Printing */
    printf("|");
    for (int i = 0; i < n; i++) {
      if (buf[i] >= 32 && buf[i] <= 126) {
      printf("%c", buf[i]);
      } else{
        printf(".");
      }
    }
    printf("|");
    printf("\n");
    offset+=n;
  }
  printf("%08zx", offset);
  fclose(f);
  printf("\n");
}
