#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *f = fopen(argv[1], "rb");
  long filelen;
  uint8_t *buf; // Declaration of array on the stack

  fseek(f, 0, SEEK_END); // Jump to the end of the file
  filelen = ftell(f); // Get current offset position in the File
  rewind(f); // Jump back to the beginning of the Filestream
             
  buf = (uint8_t *)malloc(filelen * sizeof(uint8_t)); // buf is now a pointer to an uint8_t array
  fread(buf, 1, filelen, f); // read file into buffer

  printf("%p - ", (void *)buf); // Print Initial Address workaround
  for (int i = 0; i < filelen; i+=2) {
    if (i != 0 && (i % 16) == 0){
      printf("\n");
      printf("%p - ", (void *)buf + i );
    }
    printf("%x%x ", buf[i],buf[i+1]);
  }
}
