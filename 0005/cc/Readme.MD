# Problem statement
  Get the Kth largest number from a vector

# Solution
  Initial thought: populate a sorted deque? Not a good idea
  Second thought: reuse the beggining on the array and keep the largest to the Kth largest number there. Keep track of of the Kth largest number pointer (the smallest number in the reserved area), iterate through the rest of the array, if larger number is found, swap, and update the pointer
  If we keep the first k items sorted, swap only happens on the end, plus updating after swap becomes a simple logK insertion operation

  