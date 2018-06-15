# Problem statement
  Count the # of k(s) (0 - 9) between 0 and N

# Solution
  First attempt of multi-dimension permutation

  First discover some patterns. Take a progression approach. Look at single, double, triple (...) digit number separately. Also simplify the question by removing the limit N and only look at the whole number space.

  0 is a special case, so look at 1 - 9 first

  Plan for first iteration: look at digit 1 - 9 in single, double, triple, (quadrupal optionally) digits corruances. The look at digit 0.

  For 1 to 9, in all single digit numbers, each occur exactly ONE (1) time.
  For 1 to 9, in all double digit numbers, each occur 10 + 9 = 19 times.

  Insight that triggers immediate reset. There is no single digit numbers when you look at 2 digit or 3 digit numbers. All numbers have the same digits when you look at them as a whole. We just need to treat digit 0 separately when it is a leading zero. Have a separate procedure to count the total number of leading zeros and remove them from the final tally.

  for numbers 0 to    9, each digit occurs    1 time
  for numbers 0 to   99, each digit occurs   20 times
  for numbers 0 to  999, each digit occurs  300 times

  So the formula is for numbers 0 to N, where N(m) is the biggest m digit number
    each digit occurs m * 10 to the mth power

  Now let's take a look at the leading zeros
    for single digit, no leading zero needs to be removed, or there is a leading zero but we choose not to remove it. Let's actually say there is one.
    for double digit numbers, 1 + 10 leading zeros need to be removed
    for triple digit numbers, 10 + 100
    for quadrupal digit numbers, 1 + 10 + 100 + 1000

  Now we solved the simplified problem. Time for the next step -- when we need to consider arbitrary number N instead of assuming it is 9...9
    Let's consider the most typical 2 digit number 55, let's lay out all number leading to 55,
    00 01 02 03 04 05 06 07 08 09
    10 11 12 13 14 15 16 17 18 19
    20 21 22 23 24 25 26 27 28 29
    30 31 32 33 34 35 36 37 38 39
    40 41 42 43 44 45 46 47 48 49
    50 51 52 53 54 55

    for k = 5, number of occurances = 5 + 5
    for k = 4, number of occurances = 5 + 10
    for k = 6, number of occurances = 4 

    on the other hand, let's look at 3 digit number 555,

    000 001 002 003 004 005 006 007 008 009
    010 011 012 013 014 015 016 017 018 019
    ...
    050                 055
    ...
    090 091 092 093 094 095 096 097 098 099
    100 101 102 103 104 105 106 107 108 109
    ...
    550 551 552 553 554 555 

    for k = 5, number of occurances = 55 + 5 * 10 + 

    use 555 and 2
      for 2 in d1
        020 to 029
        120
        220
        320
        420         
          a total of 5 * 10 
        520 to 529

    d₂d₁d₀ ->  for k on position 0
              1 (iff d₀ >= k) + d₁ + d₂ * 10¹ + d₃ * 10² + ...
            for k on position 1
              (d₀ + 1) (iff d₁ = k) + d₂ (+1 (iff d₂ > k)) * 10¹ + d₃ * 10² + ...
            for k on position 2
              100 (if a > k)
              (b * 10 + c) (if a == k)
              0 (if a < k)    

Am I making things too complicated? Take another perspective, for k occurances in digit 0, when number N goes up, O(k) at digit 0 increment once per N goes up by 10, it is like count by 10. For O(k) at digit 1, O(k) increment by 10 per N goes up by 100, for digit 2, O(k) goes up by 100 per N goes up by 1,000, for digit 3, O(k) goes up by 1,000 per N goes up by 10,000. This assumes of course the digit we are evaluating is not the MSD (most significatn digit). To fomularize this: the algorithm is roughly described as below:
For a given number N, let's figure out the number of digits, assuming there are m + 1 number of digits:
  dm,..d₂,d₁,d₀
O(0) = N / 10 + (1) (iff d₀ >= k)
O(1) = N / 100 * 10 + (d₀ + 1) (iff d₁ == k)
O(2) = N / 1000 * 100 + 

Or to think about it in yet another way, when we look at a particular digit position, we should look at if that position is the MSD position. If it is not, 



100 / 10 = 10, 99 / 10 = 9