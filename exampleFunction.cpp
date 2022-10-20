#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 
#include <stddef.h>
#include <inttypes.h>

// Extern Function definition for wrapFunctionShift
extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)

//INT30-C. Not ensure that unsigned integer operations do not wrap.

/*unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = ui_a + ui_b;
  return usum;
}*/

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {

  unsigned int usum;

  if (UINT_MAX - ui_a < ui_b) //delete the possibility of unsigned wrap
  {
      fprintf(stderr, "ERROR, unsigned in wrapping in wrapFunctionAdd\n");
      usum = -1;
  } 
  else {
      usum = ui_a + ui_b;
  }

  return usum;
}

// INT30-C. Not ensure that unsigned integer operations do not wrap
// INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors

/*unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  umul *= ui_b;
  return umul;
}*/

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {

  unsigned umul;

  if (ui_a != 0 || ui_b != 0 )
  {
    if (UINT_MAX / ui_b < ui_a) //delete the possibility of unsigned wrap
    {
        fprintf(stderr, "ERROR, unsigned int wrapping in wrapFunctionMul\n");
        umul = -1;
    } 
    else 
    {
        umul = ui_a * ui_b;
    }
  }
  else
  {
    fprintf(stderr, "ERROR, the ui value can not be 0\n");
    umul = -1;
  }
  return umul;
}

//INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand 

/*uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  return uShift;
}*/

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) 
{
  uint32_t uShift=0;

  //__builtin_popcount the number of ones in the binary representation of the integer
  // The comprobations ensures that both the left and right operands have nonnegative values
  if (ui_a < 0 || ui_b < 0 || ui_b >= __builtin_popcount(UINT_MAX) || ui_a > (UINT_MAX >> ui_b)) 
  {
    fprintf(stderr, "ERROR, unsigned int wrapping in wrapFunctionShift\n");
    uShift = -1;
  } 
  else 
  {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b);
  }

  return uShift;
}


