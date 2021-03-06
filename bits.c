#include <stdint.h>

/*
 * Modified CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Read the following instructions carefully.

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
  int pow2plus1(int x) {
      // exploit ability of shifts to compute powers of 2
      return (1 << x) + 1;
  }

  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
  int pow2plus4(int x) {
      // exploit ability of shifts to compute powers of 2
      int result = (1 << x);
      result += 4;
      return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any
arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  2. Use the btest test harness to check your functions for correctness.
  3. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
 */

/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x)
{
    int y = x >> 15;
    y = y >> 16;
    return (x ^ y) - y;
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000, 0x80000000) = 0,
 *            addOK(0x80000000, 0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
    int x_31 = x;
    x_31 = x_31 >> 15;
    x_31 = x_31 >> 16;
    int y_31 = y;
    y_31 = y_31 >> 15;
    y_31 = y_31 >> 16;
    int tmp = (x_31 ^ y_31) & 0x1;
    int num;
    num = x + y;
    num = num >> 15;
    num = num >> 16;
    num = num & 0x1;
    num = num ^ (y_31 & 0x1);
    return tmp | !num;
}

/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x)
{
    x = x & (x >> 16);
    x = x & (x >> 8);
    x = x & (x >> 4);
    x = x & (x >> 2);
    x = x & 0x1;
    return x;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    x = x & (x >> 16);
    x = x & (x >> 8);
    x = x & (x >> 4);
    x = x & (x >> 2);
    x = x & 0x2;
    x = x >> 1;
    return x;
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x)
{
    x = x | (x >> 16);
    x = x | (x >> 8);
    x = x | (x >> 4);
    x = x | (x >> 2);
    x = x & 0x1;
    return x;
}

/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x)
{
    x = x | (x >> 16);
    x = x | (x >> 8);
    x = x | (x >> 4);
    x = x | (x >> 2);
    x = x & 0x2;
    x = x >> 1;
    return x;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x)
{
    x = x | (x >> 16);
    x = x | (x >> 8);
    x = x | (x >> 4);
    x = x | (x >> 2);
    x = x | (x >> 1);
    x = ~x;
    x = x & 0x1;
    return x;
}

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
    x = ~(~x | ~y);
    return x;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
    int count, y, z;

    y = x & (0x55 << 24 | 0x55 << 16 | 0x55 << 8 | 0x55);
    z = (x >> 1) & (0x55 << 24 | 0x55 << 16 | 0x55 << 8 | 0x55);
    count = y + z;

    y = count & (0x33 << 24 | 0x33 << 16 | 0x33 << 8 | 0x33);
    z = (count >> 2) & (0x33 << 24 | 0x33 << 16 | 0x33 << 8 | 0x33);
    count = y + z;

    y = count & (0x0F << 24 | 0x0F << 16 | 0x0F << 8 | 0x0F);
    z = (count >> 4) & (0x0F << 24 | 0x0F << 16 | 0x0F << 8 | 0x0F);
    count = y + z;

    y = count & (0xFF << 16 | 0xFF);
    z = (count >> 8) & (0xFF << 16 | 0xFF);
    count = y + z;

    y = count & (0xFF << 8 | 0xFF);
    z = (count >> 16) & (0xFF << 8 | 0xFF);
    count = y + z;


    return count;
}

/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5, 3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit)
{
    int mask_h = (~0U) >> (31 + (~highbit + 1));
    int mask_l = (~0U) << lowbit;
    mask_h = mask_h & mask_l;
    return mask_h;
}

/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y)
{
    return ~(~(~x & ~y) & ~(x & y));
}

/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y)
{
    return ~x & ~y;
}

/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
    return ~(~x & ~y);
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x)
{
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 0x1;
}

/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x)
{
    int a, b;

    a = (x >> 16) & (0xFF << 8 | 0xFF);
    b = (x << 16) & (0xFF << 24 | 0xFF << 16);
    x = a | b;

    a = (x >> 8) & (0xFF << 16 | 0xFF);
    b = (x << 8) & (0xFF << 24 | 0xFF << 8);
    x = a | b;

    a = (x >> 4) & (0x0F << 24 | 0x0F << 16 | 0x0F << 8 | 0x0F);
    b = (x << 4) & (0x0F << 28 | 0x0F << 20 | 0x0F << 12 | 0x0F << 4);
    x = a | b;

    a = (x >> 2) & (0x33 << 24 | 0x33 << 16 | 0x33 << 8 | 0x33);
    b = (x << 2) & (0xCC << 24 | 0xCC << 16 | 0xCC << 8 | 0xCC);
    x = a | b;

    a = (x >> 1) & (0x55 << 24 | 0x55 << 16 | 0x55 << 8 | 0x55);
    b = (x << 1) & (0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA);
    x = a | b;

    return x;
}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    return ~(~(x & (~y)) & ~((~x) & y));
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m)
{
    n = n << 3;
    m = m << 3;
    int n_mask = 0xFF << n;
    int m_mask = 0xFF << m;
    int x_n = x & n_mask;
    int x_m = x & m_mask;
    x = (x & ~n_mask);
    x = (x & ~m_mask);
    x = x | (((x_n >> n) & 0xFF) << m) | (((x_m >> m) & 0xFF) << n);
    return x;
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    x = !x;
    x = x << 15 << 16;
    x = x >> 15 >> 16;
    return (~x & y) | (x & z);
}

/*
 * countLeadingZero - count the number of zero bits preceding the
 *                    most significant one bit
 *   Example: countLeadingZero(0x00000F00) = 20,
 *            countLeadingZero(0x00000001) = 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int countLeadingZero(int x)
{
    int leading16_check =
        !((x >> 16) ^ 0);  // If leading 16 zero, check31to16 will be 1
    int leading16 = leading16_check << 4;
    x = x << leading16;

    int leading8_check = !((x >> 24) ^ 0);
    int leading8 = leading8_check << 3;
    x = x << leading8;

    int leading4_check = !((x >> 28) ^ 0);
    int leading4 = leading4_check << 2;
    x = x << leading4;

    int leading2_check = !((x >> 30) ^ 0);
    int leading2 = leading2_check << 1;
    x = x << leading2;

    int leading1_check = !((x >> 31) ^ 0);
    x = x << leading1_check;

    int remain1_check = !((x >> 31) ^ 0);
    x = x << remain1_check;

    return leading16 + leading8 + leading4 + leading2 + leading1_check +
           remain1_check;
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x)
{
    x = x << 15 << 16;
    return x >> 15 >> 16;
}

/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
int distinctNegation(int x)
{
    x = x << 1;
    return !(!x);
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *                Round toward zero
 *   Examples: dividePower2(15, 1) = 7, dividePower2(-33, 4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n)
{
    return (x + ((x >> 31) & ((1 << n) + ~0))) >> n;
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void)
{
    int num;
    num = (0x55 << 24 | 0x55 << 16 | 0x55 << 8 | 0x55);
    return num;
}

/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *                  Should exactly duplicate effect of C expression (x*3/4),
 *                  including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x)
{
    x = x + x + x;
    return (x + ((x >> 15 >> 16) & ((1 << 2) + ~0))) >> 2;
}

/*
 * fitsBits - return 1 if x can be represented as an n-bit, two's complement
 *            integer.
 *            1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
    n = n + ~0;
    int a = (~0U << n);
    int b = a + ~x;
    int c = (a >> n) ^ (b >> n);
    int d = 0 ^ (x >> n);
    return !c ^ !d;
}

/*
 * fitsShort - return 1 if x can be represented as a 16-bit, two's complement
 *             integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    /*
    int x_copy = x;
    x = (x >> 16 << 16) | (x >> 16);
    return ((!x) & !(x_copy >> 15 & 1)) ^ ((!(x + 1)) & (x_copy >> 15 & 1));
    */
    int x_positive = x >> 15;
    int x_negative = x >> 15;
    x_positive = !(x_positive ^ (0));
    x_negative = !(x_negative ^ (~0));
    return x_positive ^ x_negative;
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf)
{
    int check = ((uf >> 23) & 0xFF) ^ 0xFF;
    check = !check;
    int m = (uf << 9) ^ 0;
    if (check && m) {
        return uf;
    }
    uf = uf & 0x7fffffff;
    return uf;
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *                  for floating point argument f.
 *                  Argument is passed as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point value.
 *                  Anything out of range (including NaN and infinity) should
 *                  return 0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    // 0________1011100110
    int exp = (uf >> 23) & 0xFF;
    int outofRange = !(exp ^ 0xFF);
    int diff = exp - 127;
    if (outofRange || diff > 31) {
        return 0x80000000U;
    }
    if (!(uf << 1)) {
        return 0;
    }
    if (diff < 0) {
        return 0;
    }
    int tail = uf & 0x7FFFFF;
    unsigned result;
    result = (0x80000000 | (tail << 8)) >> (31 - diff);
    if (uf >> 31) {
        result = ~result + 1;
    }
    return result;
}

/*
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *                  Result is returned as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x)
{
    if (!x) {
        return 0;
    }
    if (x == 0x80000000) {
        return 0xcf000000;
    }
    unsigned sign = x & 0x80000000;
    int xChangToPositive = (x ^ (x >> 31)) + (sign >> 31);
    int LeftMostPos = 31;
    while (xChangToPositive > 0) {
        xChangToPositive = xChangToPositive << 1;
        LeftMostPos--;
    }
    int exp = (127 + LeftMostPos) << 23;
    int tail = (xChangToPositive >> 8) & 0x7FFFFF;
    if (LeftMostPos > 23) {  // Check for rounding to even
        int lastbit = (xChangToPositive & 0xFF);
        int shift8 = (xChangToPositive >> 8) & 1;
        int bias = (lastbit >= 0x80) && shift8;
        int bias_2 = (lastbit > 0x80) && !shift8;
        tail = tail + bias + bias_2;
    }
    return sign | (exp + tail);
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *                Both the arguments are passed as unsigned int's, but
 *                they are to be interpreted as the bit-level representations
 *                of single-precision floating point values.
 *                If either argument is NaN, return 0.
 *                +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug)
{
    int ufleft1 = uf << 1;
    int ugleft1 = ug << 1;
    if (ufleft1 > 0xFF000000 || ugleft1 > 0xFF000000) {
        return 0;
    }
    if (ufleft1 == ugleft1 && ufleft1 == 0) {
        return 1;
    }
    return uf == ug;
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *               Both the arguments are passed as unsigned int's, but
 *               they are to be interpreted as the bit-level representations
 *               of single-precision floating point values.
 *               If either argument is NaN, return 0.
 *               +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug)
{
    unsigned fIsNan = (uf << 1) > 0xFF000000;
    unsigned gIsNan = (ug << 1) > 0xFF000000;
    if (fIsNan || gIsNan) {
        return 0;
    }
    int fLeftShift1 = uf << 1;
    int gLeftShift1 = ug << 1;
    if (fLeftShift1 == gLeftShift1 && fLeftShift1 == 0) {
        return 0;
    }
    unsigned f_sign = uf >> 31;
    unsigned g_sign = ug >> 31;
    if (g_sign < f_sign) {
        return 1;
    }
    if (g_sign > f_sign) {
        return 0;
    }
    if (g_sign) {
        return ug < uf;
    }
    if (!g_sign) {
        return ug > uf;
    }
    return 0;
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf)
{
    unsigned nan = (((uf >> 23) & 0xFF) ^ 0xFF);
    if (!nan && (uf << 9)) {
        return uf;
    }
    return uf ^ 0x80000000;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *               (2.0 raised to the power x) for any 32-bit integer x.
 *
 *               The unsigned value that is returned should have the
 *               identical bit representation as the single-precision
 *               floating-point number 2.0^x.
 *               If the result is too small to be represented as a denorm,
 *               return 0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    if (x < -127) {
        return 0;
    }
    if (x > 128) {
        return 0x7f800000;
    }
    x += 127;
    x = x << 23;
    return x;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *                 floating point argument f.
 *                 Both the argument and result are passed as unsigned int's,
 *                 but they are to be interpreted as the bit-level
 *                 representation of single-precision floating point values.
 *                 When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf)
{
    int sign = uf & 0x80000000;
    unsigned fLeftShift1 = uf << 1;
    if (fLeftShift1 >= 0xFF000000) {
        return uf;
    }
    if (!(fLeftShift1 ^ 0)) {
        return (0 | sign);
    }
    int exp = (uf >> 23) & 0xFF;
    int tail = uf & 0x7FFFFF;
    if (exp < 2) {
        int tail_0 = tail & 1;
        int tail_1 = (tail >> 1) & 1;
        tail = tail >> 1;
        tail += tail_0 & tail_1;
        if (exp == 1) {
            tail += 0x400000;
            exp--;
        }
    } else {
        exp = exp - 1;
    }
    exp = exp << 23;
    return sign | exp | tail;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level representation
 *               of single-precision floating point values.
 *               When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
    unsigned nan = !((uf >> 23 << 24) ^ (0xFF << 24));
    if (nan) {
        return uf;
    }
    if (!(uf << 1)) {
        return uf;
    }
    if (!((uf >> 23 << 24) ^ 0)) {
        int mask_tail = ~0 << 23;
        int tail = uf & ~mask_tail;
        uf = uf & mask_tail;
        tail = tail << 1;
        return uf | tail;
    }
    return (uf + (1 << 23));
}

/*
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *                floating point argument f.
 *                Both the argument and result are passed as unsigned int's,
 *                but they are to be interpreted as the bit-level
 *                representation of single-precision floating point values.
 *                When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf)
{
    unsigned sign = uf & 0x80000000;
    unsigned fLeftShift1 = uf << 1;
    unsigned nan = fLeftShift1 >= 0xFF000000;
    if (nan) {
        return uf;
    }
    if (!fLeftShift1) {
        return uf;
    }
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned tail = uf & 0x7FFFFF;
    if (exp + 6 > 255) {
        return 0x7f800000 | sign;
    }
    if (!(uf & 0x7F800000)) {  // Denormalize
        int counter = 6;
        while (counter) {
            tail = tail << 1;
            if (tail > 0x7FFFFF) {
                break;
            }
            counter--;
        }
        exp = counter;
        tail = tail & 0x7FFFFF;
    } else {  // Normal case
        exp = exp + 6;
    }
    exp = exp << 23;

    return sign | exp | tail;
}

/*
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *                       Result is returned as unsigned int, but it is to be
 *                       interpreted as the bit-level representation of a
 *                       single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u)
{
    if (u == 0) {
        return 0;
    }
    if (u == 0x80000000) {
        return 0x4f000000;
    }
    int tmp = u;
    int counter = 31;
    while (tmp > 0) {
        tmp = tmp << 1;
        counter--;
    }
    int exp = (127 + counter) << 23;
    int tail;
    if (counter > 23) {
        /*
        if((tmp >> 8) & 1){
            unsigned bias = (1 << 7);
            tail = (((tmp + bias) >> 8) & 0x7FFFFF);
        } else {
            tail = ((tmp >> 8) & 0x7FFFFF);
        }
        */
        int bias = ((tmp & 0xFF) >= 0x80) && ((tmp >> 8) & 1);
        int bias_2 = ((tmp & 0xFF) > 0x80) && !((tmp >> 8) & 1);
        tail = (((tmp) >> 8) & 0x7FFFFF);
        tail = tail + bias + bias_2;
    } else {
        tail = ((tmp >> 8) & 0x7FFFFF);
    }
    return exp | tail;
}

/*
 * getByte - Extract byte n from word x
 *           Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
    x = (x >> (n << 3)) & 0xFF;
    return x;
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *                  most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x)
{
    if (!x) {
        return 0;
    }
    int leading16_check =
        !((x >> 16) ^ 0);  // If leading 16 zero, check31to16 will be 1
    int leading16 = leading16_check << 4;
    x = x << leading16;

    int leading8_check = !((x >> 24) ^ 0);
    int leading8 = leading8_check << 3;
    x = x << leading8;

    int leading4_check = !((x >> 28) ^ 0);
    int leading4 = leading4_check << 2;
    x = x << leading4;

    int leading2_check = !((x >> 30) ^ 0);
    int leading2 = leading2_check << 1;
    x = x << leading2;

    int leading1_check = !((x >> 31) ^ 0);
    x = x << leading1_check;

    int remain1_check = !((x >> 31) ^ 0);
    x = x << remain1_check;

    int leadingZero = leading16 + leading8 + leading4 + leading2 +
                      leading1_check + remain1_check;
    int one_pos = 31 + ~leadingZero + 1;
    return 1 << one_pos;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *               two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    int xSign = x >> 31;
    x = x ^ (~0 & xSign);
    int leading16_check =
        !((x >> 16) ^ 0);  // If leading 16 zero, check31to16 will be 1
    int leading16 = leading16_check << 4;
    x = x << leading16;

    int leading8_check = !((x >> 24) ^ 0);
    int leading8 = leading8_check << 3;
    x = x << leading8;

    int leading4_check = !((x >> 28) ^ 0);
    int leading4 = leading4_check << 2;
    x = x << leading4;

    int leading2_check = !((x >> 30) ^ 0);
    int leading2 = leading2_check << 1;
    x = x << leading2;

    int leading1_check = !((x >> 31) ^ 0);
    x = x << leading1_check;

    int remain1_check = !((x >> 31) ^ 0);
    x = x << remain1_check;

    int leadingZero = leading16 + leading8 + leading4 + leading2 +
                      leading1_check + remain1_check;
    int TotalNeedBits = 32 + ~leadingZero + 2;
    return TotalNeedBits;
}

/*
 * implication - return x -> y in propositional logic - 0 for false,
 *               1 for true
 *   Example: implication(1, 1) = 1
 *            implication(1, 0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y)
{
    return (!(x ^ y)) | y;
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x)
{
    int leading16_check =
        !((x >> 16) ^ 0);  // If leading 16 zero, check31to16 will be 1
    int leading16 = leading16_check << 4;
    x = x << leading16;

    int leading8_check = !((x >> 24) ^ 0);
    int leading8 = leading8_check << 3;
    x = x << leading8;

    int leading4_check = !((x >> 28) ^ 0);
    int leading4 = leading4_check << 2;
    x = x << leading4;

    int leading2_check = !((x >> 30) ^ 0);
    int leading2 = leading2_check << 1;
    x = x << leading2;

    int leading1_check = !((x >> 31) ^ 0);
    x = x << leading1_check;

    int remain1_check = !((x >> 31) ^ 0);
    x = x << remain1_check;

    int leadingZero = leading16 + leading8 + leading4 + leading2 +
                      leading1_check + remain1_check;

    return 31 + ~leadingZero + 1;
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters
 *                '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
    int xminus0x30 = ((x + (~0x30 + 1)) >> 15 >> 16) & 1;
    int xminus0x39 = ((x + (~0x39)) >> 15 >> 16) & 1;

    return (!xminus0x30) & xminus0x39;
}

/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y)
{
    return !(x + ~y + 1);
}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
    int x_sign = (x >> 15 >> 16) & 1;
    int y_sign = (y >> 15 >> 16) & 1;
    int diff = x + (~y + 1);  // Might be zero
    int diff_sign = (diff >> 15 >> 16) & 1;
    return ((!diff_sign) & (!!diff) & !!(x_sign + ~y_sign)) |
           (!(y_sign + ~x_sign));
}

/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y)
{
    int x_sign = (x >> 15 >> 16) & 1;
    int y_sign = (y >> 15 >> 16) & 1;
    int diff = y + (~x + 1);  // Might be zero
    int diff_sign = (diff >> 15 >> 16) & 1;
    return ((!diff_sign) & (!!diff) & !!(y_sign + ~x_sign)) |
           (!(x_sign + ~y_sign));
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    int x_sign = (x >> 15 >> 16) & 1;
    int y_sign = (y >> 15 >> 16) & 1;
    int diff = y + (~x + 1);  // Might be zero
    int diff_sign = (diff >> 15 >> 16) & 1;
    return ((!diff_sign) & !!(y_sign + ~x_sign)) | (!(x_sign + ~y_sign));
}

/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x)
{
    return (x >> 15 >> 16) & 1;
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x)
{
    return !((x >> 15 >> 16) & 1);
}

/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x)
{
    return !!(x ^ 0);
}

/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y)
{
    return !!((x + ~y) + 1);
}

/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x)
{
    int x_16 = (x >> 16);
    int mask_ff = 0xFF;
    x_16 = ((x_16 & mask_ff) << 8) | ((x_16 & (mask_ff << 8)) >> 8);
    int mask_0f = (0x0F << 8) | 0x0F;
    x_16 = ((x_16 & mask_0f) << 4) | ((x_16 & (mask_0f << 4)) >> 4);
    int mask_33 = (0x33 << 8) | 0x33;
    x_16 = ((x_16 & mask_33) << 2) | ((x_16 & (mask_33 << 2)) >> 2);
    int mask_55 = (0x55 << 8) | 0x55;
    x_16 = ((x_16 & mask_55) << 1) | ((x_16 & (mask_55 << 1)) >> 1);
    return !((x ^ x_16) & (mask_ff | (mask_ff << 8)));
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x)
{
    int tmp = x;
    x = (x >> 15 >> 16) & 1;
    return (!x) & (!!tmp);
}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x)
{
    int sign = (x >> 15 >> 16) & 1;
    int x_nagetive = (~x + 1);
    int filter = (x & x_nagetive);
    return !(filter ^ x) & (!!x) & (!sign);
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    int tmax = (~0U) >> 1;
    return !(x ^ tmax);
}

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x)
{
    int tmin = ((~0U) >> 1) + 1;
    return !(x ^ tmin);
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x)
{
    return !x;
}

/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x)
{
    return x & (~x + 1);
}

/*
 * leftBitCount - returns count of number of consective 1's in
 *                left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x)
{
    x = ~x;
    int leading16_check =
        !((x >> 16) ^ 0);  // If leading 16 zero, check31to16 will be 1
    int leading16 = leading16_check << 4;
    x = x << leading16;

    int leading8_check = !((x >> 24) ^ 0);
    int leading8 = leading8_check << 3;
    x = x << leading8;

    int leading4_check = !((x >> 28) ^ 0);
    int leading4 = leading4_check << 2;
    x = x << leading4;

    int leading2_check = !((x >> 30) ^ 0);
    int leading2 = leading2_check << 1;
    x = x << leading2;

    int leading1_check = !((x >> 31) ^ 0);
    x = x << leading1_check;

    int remain1_check = !((x >> 31) ^ 0);
    x = x << remain1_check;

    return leading16 + leading8 + leading4 + leading2 + leading1_check +
           remain1_check;
}

/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
    return (~((~x + 1) | x) >> 31) & 1;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *                Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n)
{
    x = x >> n;
    x = x & ((0xFFU << 24 | 0xFFU << 16 | 0xFFU << 8 | 0xFFU) >> n);
    return x;
}

/*
 * maximumOfTwo - compute the maximum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int maximumOfTwo(int x, int y)
{
    int xSign = x >> 31;
    int ySign = y >> 31;
    int SignEqual =
        (xSign ^ ySign);  // If sign is equal, SignEqual will be 0x00000000
    int XminusY = (x + ~y) >> 31;
    int YminusX = (y + ~x) >> 31;
    return (x & ((~SignEqual & YminusX) | (SignEqual & ySign))) |
           (y & ((~SignEqual & XminusY) | (SignEqual & xSign)));
}

/*
 * minimumOfTwo - compute the minimum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int minimumOfTwo(int x, int y)
{
    int xSign = x >> 31;
    int ySign = y >> 31;
    int SignEqual =
        (xSign ^ ySign);  // If sign is equal, SignEqual will be 0x00000000
    int XminusY = (x + ~y) >> 31;
    int YminusX = (y + ~x) >> 31;
    return (x & ((~SignEqual & XminusY) | (SignEqual & xSign))) |
           (y & ((~SignEqual & YminusX) | (SignEqual & ySign)));
}

/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
    return ~0;
}

/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *                   Should exactly duplicate effect of C expression (x*5/8),
 *                   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x)
{
    x = x + x + x + x + x;
    x = (x + ((x >> 31) & ((1 << 3) + ~0))) >> 3;
    return x;
}

/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return ~x + 1;
}

/*
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void)
{
    return 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;
}

/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *                   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15, 2) = 3, remainderPower2(-35, 3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int remainderPower2(int x, int n)
{
    // positive num 整除  -> 0x00000000
    // positive num 不整除-> 0x000.....
    // negative num 整除  -> 0x00000000
    // negative num 不整除-> 0x1111....
    // if 整除 then fit = 0x00000000 else fit = 0xFFFFFFFF
    int remainder = x & ~(~0 << n);
    int fill = ((x >> 31)) << n;
    int fit = ~((!remainder) << 31 >> 31);
    return (fill | remainder) & fit;
}

/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *                      Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678, 1, 0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c)
{
    int mask = ~(0xFF << (n << 3));
    x = x & mask;
    x = x | (c << (n << 3));
    return x;
}

/*
 * rotateLeft - Rotate x to the left by n
 *              Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n)
{
    int diff = 32 + ~n + 1;
    int x_cpy = x >> diff;
    int mask = ~0U >> diff;
    x_cpy = x_cpy & mask;
    x = x << n;
    x = x | x_cpy;
    return x;
}

/*
 * rotateRight - Rotate x to the right by n
 *               Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321, 4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n)
{
    int diff = 32 + ~n + 1;
    int mask = ~0U >> n;
    int x_tail = x << diff;
    x = x >> n;
    x = x & mask;
    x = x | x_tail;
    return x;
}

/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000, 0x40000000) = 0x7fffffff
 *             satAdd(0x80000000, 0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
    int neg_min = 0x80 << 24;
    int pos_max = ~0 ^ neg_min;
    int result = x + y;
    int result_sign = (result >> 31) & 1;
    int x_31 = x >> 31;
    int y_31 = y >> 31;
    int pos_over = ((!(x_31 | y_31)) & result_sign) << 31 >> 31;
    int neg_over = ((!((x_31 & y_31) + 1)) & !result_sign) << 31 >> 31;
    return (result & ~(pos_over | neg_over)) | (pos_max & pos_over) |
           (neg_min & neg_over);
}

/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x80000001) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x)
{
    int max = ~0U >> 1;
    int min = 0x80 << 24;
    int sign = x >> 31;
    int x_1 = x >> 1;
    int new_x = (x_1 + x_1);
    new_x = (((new_x << 1) ^ new_x)) >> 31;
    return ((x + x) & ~(new_x)) | (max & new_x & (~sign)) |
           (min & new_x & sign);
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *   Examples: satMul3(0x10000000) = 0x30000000
 *             satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *             satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *              satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *             satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int satMul3(int x)
{
    int max = ~0U >> 1;
    int min = 0x80 << 24;
    int sign = x >> 31;
    int x_1 = x >> 1;
    int new_x = (x_1 + x_1 + x_1);
    new_x = (((new_x << 1) ^ new_x)) >> 31;
    return ((x + x + x) & ~(new_x)) | (max & new_x & (~sign)) |
           (min & new_x & sign);
}

/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *   Examples: sign(130) = 1
 *             sign(-23) = -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int sign(int x)
{
    return (x >> 15 >> 16) | (!!x);
}

/*
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *                    where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x)
{
    int min = 1 << 31;
    int sign = (x >> 31) + !(min ^ x);
    int pos_x = x & (~0U >> 1);
    int neg_x = ~pos_x + 1;
    return (pos_x & ~sign) | (neg_x & sign);
}

/*
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void)
{
    return ~0 ^ (0xD7 << 14);
}

/*
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000, 0x80000000) = 1,
 *            subtractionOK(0x80000000, 0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y)
{
    int x_sign = x >> 31;
    int y_sign = y >> 31;
    int diff = (x + ~y + 1) >> 31;
    return (~(x_sign ^ diff) & 1) | !(x_sign ^ y_sign);
}

/*
 * thirdBits - return word with every third bit (starting from the LSB)
 *             set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void)
{
    return 0x49 | 0x92 << 8 | 0x24 << 16 | 0x49 << 24;
}

/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
    return ~0U >> 1;
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    return (~0U >> 1) + 1;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *                   avoiding errors due to overflow
 *   Examples: trueFiveEighths(11) = 6
 *             trueFiveEighths(-9) = -5
 *             trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 4
 */
int trueFiveEighths(int x)
{
    int tail = x & 0x7;
    x = x >> 3;
    return (x << 2) + x + (((tail << 2) + tail + ((x >> 31) & 0x7)) >> 3);
}

/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *                    avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    /*
    int sign = x >> 31;
    int Allone = ~0;
    int xHalf = (x + (sign & ((1 << 1) + Allone))) >> 1;
    int xHalf_remain = x & 1;
    int xOneFourths = x >> 2;
    int xOneFourths_remain = x & 3;
    int bias = ((xHalf_remain << 1) + xOneFourths_remain) >> 2;
    return xHalf + xOneFourths + (bias & ~sign) + (xHalf_remain & sign);
    */
    int tail = x & 0x3;
    x = x >> 2;
    return (x << 1) + x + (((tail << 1) + tail + ((x >> 31) & 0x3)) >> 2);
}

/*
 * twosComp2SignMag - Convert from two's complement to sign-magnitude
 *                    where the MSB is the sign bit
 *                    You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x)
{
    // If x < 0 then return xConvert else return x
    int negMark = 1 << 31;
    int xConvert = (~x + 1) | negMark;
    int decision = x >> 31;
    return (x & ~decision) | (xConvert & decision);
}

/*
 * upperBits - pads n upper bits with 1's
 *             You may assume 0 <= n <= 32
 *   Example: upperBits(4) = 0xF0000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 1
 */
int upperBits(int n)
{
    int diff = 32 + (~n + 1);
    return (~0 << diff) + !n;
}
