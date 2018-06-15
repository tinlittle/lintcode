# Problem statement
  bitwise gap between two integers

# Solution
  Obviously there is no different between the order of the two operands. It is not so much an algorithm question but rather a math question. Let's figure out a math solution with our simple 4 bit numbers
  0000 <-> 1111 = 1111 = 4
  1010 <-> 0101 = 1111 = 4
  1100 <-> 1100 = 0011 = 2

  The answer can only be from 0 to 4
  It can be viewed as counting the number of set bits (1) of x ^ y

  It just all comes down to a counting set bits problem. It could be solved by check high (or low) bit and then shift loop

  Obviously the check and shift method takes 32 operations no matter the input. There should be an clever faster way to do it

  Look at n and n-1 together, in a simple example:

  0000 vs 1111 & -> 0000

  0001 vs 0000 & -> 0000
  0010 vs 0001 & -> 0000
  0100 vs 0011 & -> 0000
  1000 vs 0111 & -> 0000

  0011 vs 0010 & -> 0010
  0101 vs 0100 & -> 0100
  0110 vs 0101 & -> 0100
  1001 vs 1000 & -> 1000
  1010 vs 1001 & -> 1000
  1100 vs 1010 & -> 1000

  0111 vs 0110 & -> 0110
  1011 vs 1010 & -> 1010
  1101 vs 1100 & -> 1100
  1110 vs 1101 & -> 1100

  1111 vs 1110 & -> 1110

  n & (n-1) always result into a number with one less 1s
  Implemented and resulted in much better performance

  Come to think about it in similar vein
  There could be utmost 4 bits to flip. Is there a reductive way?
  0000 and 1111 ^ -> 1111
  1010 and 0101 ^ -> 1111
    so looks like if xor result is maximum integer, number of bits is the size of integer
  0000 and 0000 ^ -> 0000
    if xor results is zero, number of bits to flip is 0, since two numbers are identical
  0000 and 0001 ^ -> 0001 & -> 0000 | -> 0001
  0000 and 0010 ^ -> 0010 & -> 0000 | -> 0010
  0000 and 0100 ^ -> 0100 & -> 0000 | -> 0100
  0000 and 1000 ^ -> 1000 & -> 0000 | -> 1000
  No obvious pattern here, giving up

  Similar problem of determining whether a number is power of 2:
  n    n-1
  0000 1111 & -> 0000
  0010 0001 & -> 0000
  0100 0011 & -> 0000
  1000 0111 & -> 0000
