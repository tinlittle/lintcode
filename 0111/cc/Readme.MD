# Problem statement
  The many different ways of climbing stairs, to skip or not

# Solution
  One classical case for application of dynamic programming

  Let (S, c) denotes N flights of stairs, k is the # of permutation of climbing them in 1 or 2 steps. It is obvious we have those initial sets:

  c(S = 0) = 0
  c(S = 1) = 1
  c(S = 2) = 2
        3  = 3
        4  = 5
        5  = 8

  Let's look at the case of S = 3. Conceptually, Knowing c(S = 2) and c(S = 1),      "c(S=3) = c(S=2) + C(S=1)" because there is only one way to go from S = 2 to S = 3. While there are two ways to get from S = 1 to S = 3, one of the way is to stop at S = 2. Thus you are left with only one way. So this is basically another instances of fibonacci serie