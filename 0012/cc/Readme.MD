# Problem statement
  Implement a stack with min function in addtion to top, pop, and push

# Solution
  The obvious (and alos correct) idea is to have two stacks. One for normal stack operations and another to keep track of current min value.

  The challenge is to keep the space and time cost of the separate min stack minimum.

  Notice, the requirement is a min stack, not a min queue or min vector. There is something special about stack, that is first in -- last out. The current min value will always be popped out before old min value is popped out.
  
# Lessons

# Todo
