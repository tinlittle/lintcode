# Problem statement
  right rotating shift of a string

# Solution
  Use O(1) space, use an extra char to hold the char rotated out
  take a loop and an inner loop with 3 steps process
    repeat # of shifts specified
      low char copied to extra char
      all chars shift right by one
      extra char copied into high char 

# Lessons
  1. Forgot to check for empty string
  2. Forgot to do mod of the rotate #, and did /= instead of %= when first realized it

# Todo
  This can be further enhanced by cp characters in place instead of a loop