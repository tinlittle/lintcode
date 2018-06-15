# Problem statement
  set a range of bits

# Solution
  let's break this down to a list of simpler problems
  1. how to set the last bit of a number to a specified value
      set the last bit to zero first and then do an | to the specified value
      with the 4 bit number case, examples:
      A number: 0101 to operate on, with value be either 1 or 0
      0101 set 1 = 0101, 0101 set 0 = 0100
      0101 & 1110 = 0100, 0100 | 0001 = 0101 and 0100 | 0000 = 0100
      so we need a constant 1110 to clear last bit of the number with & operation
      and we need derive to either 0000 or 0001 from specified value to set last bit
      with | operation, it may seem unnecessary for 0000, it is true for last bit but necessary for multiple bits operations
  2. How to set the last few bits of a number to a specified value
      follow the same logic as #1, the difference is 
        a. A different & constant, 1100 for example, if specified value has two digits
        b. maybe there is only one difference
  3. How to do the same, with a few bits to set, but start off from an offset relative to bit zero?
      what are the differences?
        a. Guess a dynamic mask is needed. 1001 if # of bits is 2 and start from bit 1
        b. The specified value just needs to be shifted by # starting bit times

# Observations
  Although classified by Lintcode as medium difficulty, this one looks more straight forward

