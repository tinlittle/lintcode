# Problem statement
  pop map, build an array of number of 1 bits from 0 to n

# Solutiony
  Looks like a perfect opportunity to utilize dynamic programming, specifically memoirization methods
  Binary Index    Pop   Formula
  0000      0      0      
  0001      1      1             <===
  0010      2      1     1 + 0
  0011      3      2     1 + 1   <===
  0100      4      1     1 + 0
  0101      5      2    
  0110      6      2
  0111      7      3     1 + 2   <===
  1000      8      1     1 + 0
  1001      9      2
  1010     10      2
  1011     11      3
  1100     12      2
  1101     13      3
  1110     14      3
  1111     15      4     1 + 3   <===

  The table can be built out iteratively. Start off by two items, add 1 to the value to all existing items and append to the array. Do this until the target number is reached.

  This is not a bit manipulation algorithm per se. Rather an observation of binary bits progression. 

# Afterthoughts
