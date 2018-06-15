# Problem statement
  Find all nodes within a specified range on a Binary Search Tree

# Solution
  v1
    Mirror the binary search algorithm. But instead of a precise match, for the lower bound, locate the node that is equal or just above the bound, meaning either we find the matching node spot on, or we need to find one node that is just below the bound, we shall call finding the node that is just below a match, but we need to do a reverse backtrack and locate the next smallest node, which could be either its parent (for left child) or great parent (for right child), since we don't have a pointer back to parent, we shall use stack for backtracking
  v2
    It is now evidently obvious to me that I was making it complicated in v1 thoughts. The simpliest way to approach this is to traverse and collect all nodes in ascending order. And then to cut off from both ends the nodes that fall off of the range specified.

    This approach could be later improved by modifying the traverse termination condition. 

    Unbounded traversal terminates on the low side when left pointer reaches nullptr. We shall treat value below the specified range the same as nullptr

    Unbounded traversal terminates on the high side when right pointer reaches nullptr. We shall treat value above the specified range the same as nullptr

    One special case would be that the root is out of range to begin with. In that case, we shall seek to find the new root by moving down until we are within range

    Another missing piece is how to do tree traversal using stack instead of recursion to make it look better

# Lessons

# Todo
