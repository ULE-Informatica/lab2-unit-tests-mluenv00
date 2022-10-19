#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

// INT30-C. Not ensure that unsigned integer operations do not wrap
//the resulting value may be used to allocate insufficient memory 
//for a subsequent operation or in some other manner that can lead 
//to an exploitable vulnerability.

/*unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = ui_a + ui_b;
  return usum;
}*/

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {

  unsigned int usum;

  if (UINT_MAX - ui_a < ui_b) //delete the possibility of unsigned wrap
  {
      fprintf(stderr, "Error, unsigned wrap\n");
       return -1;

  } 
  else {
      usum = ui_a + ui_b;
      return usum;
  }
}

// INT30-C. Not ensure that unsigned integer operations do not wrap

/*unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  umul *= ui_b;
  return umul;
}*/

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {

  unsigned umul;

if (UINT_MAX - ui_a < ui_b) //delete the possibility of unsigned wrap
  {
      fprintf(stderr, "ERROR, unsigned wrap\n");
      return -1;
  } 
  else 
  {
      umul = ui_a * ui_b;
      return umul;
  }
  
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  return uShift;
}
