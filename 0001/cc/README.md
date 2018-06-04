# Problem statement:
  Add two integers without using arithmatic operators like +, -, *, etc
  Idea is to use bitwise operators

# Solution
  The solution revolves around the idea of electronic half adder
  For 1 bit number, a + b == a ^ b, a carry bit (detected by a & b) means overflow
  For 2 bit number, a + b == a ^ b + (a₀ & b₀) << 1, here is how:
    00 ^ 00 = 00 0 & 0 = 0, result = 00 + 00 = 00
    01 ^ 01 = 00 1 & 1 = 1, result = 00 + 10 = 10
    10 + 10 = 00 10 ^ 10 = 00, 0 & 0 

  Let's look at signed numbers though, especially negative numbers
  Assuming 8 bit signed integers for simplicity's sake
  -1 + -1 should be -2, it translates into hex and binary respectively:
  FE + FE = FD
  1111,1110 + 1111,1110 = 1111,1100
  FE ^ FE = 0
  FE & FE = 0, FE << 1 = FD, thus the algorithm works out with negative integers

  How would the algorithm work with integer overflow?
  Let's look at positive integer case and again 8 bits for simplicity, no actually, let's do it in 4 bits this time, here is the whole table:
  -8, -7, -6, -5, -4, -3, -2, -1, 00, 01, 02, 03, 04, 05, 06, 07
   8,  9,  A,  B,  C,  D,  E,  F, 00, 01, 02, 03, 04, 05, 06, 07 

  Let's see how positive overflow would work:
    7 + 1 = -8, 7 + 2 = 1, ..., 7 + 7 = 6
    7 + 1 = 0111 + 0001 = 0110 + 10 = 1000 = -8
    7 + 7 = 0111 + 0111 = 0 + 1110 = E = -2
    Looks like I need scrap all this signed integer overflow since it is undefined anyway

  Let's just look at unsigned operations
  With 4 digits, the range is 0 to 15 (0 to F) so overflow will look like:
  F plus (0 to F)
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
  results in
  F, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E
  Let's do some spot check here
  F + 2 = 1111 + 0010 = 1101 + 0100 = 0001 -- correct
  F + F = 1111 + 1111 = 0000 + 1110 = 1110 -- correct
  Extreme case: F + F, 15 + 15 = 30, 30 % 16 = 14 -- E
  Try 7 + 10 = 17 % 16 = 1
  7 + A = 0111 + 1010 = 1101 + 0100 = 0001 -- correct with shift first, and next
  7 + A = 0111 + 1010 = 1101 + 0010<<1 = 1101 + 0100 -- correct
  Copy F + F with shift first below:
  F + F = 1111 + 1111 = 0000 + 1110 = 1110 -- correct
  1111 + 1111 = 0000 + 1111<<1 = 0000 + 1110 = 1110 -- correct, guess it doesn't matter
  whether shift first or and first, for simplity's sake, let's and first
  Edge conditoin just for fun
  A + 0 = 0
  1010 + 0000 = 1010 + 0 = 1010, so when operandor b is zero, it still works, but need
  to terminate to prevent infiity loop
  Am I missing something? Try F + 1
  F + 1 = 1111 + 0001 = 1110 + 0010 = 0


