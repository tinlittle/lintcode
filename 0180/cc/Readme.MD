# Problem statement
  convert a decimal number possibly with fractions (represented as numbers behind decimal points) into machine binary representation, if it exceeds 32 bit, return "ERROR"

# Solution
  Was not motivated to solve this problem because negative number is hard to deal with and also not specificially required. But need to finish this for completeness' sake

  The approach is to divide and concquer, separate the whole number before the decimal point and the fractions after the decimal point
  Parsing Edge cases:
    1   -> no decimal point     ==> result needs to be 1
    1.0 -> fraction is zero     ==> result needs to be 1
    0.1 -> whole number is zero ==> result needs to be 0.1
    .1  -> invalid input        ==> result needs to be ERROR
  Parsing normal case:
    1.5 -> has both normal whole number and fraction parts

  Apart parsing, there is the conversion to number part

  After the numbers are aquired, it is time to convert them to binary strings
  The whole number part is straight forward iteratively / and %
  The decimal part, represented in whoel number form (not float, double or fraction)
  Examples:
    .25 -> 25
      25 * 2 = 50, 50 < 100, "0.0", 50 * 2 = 100 100 >= 100, "0.01", 100 - 100 = 0, 0
    .675 -> 675
      675 * 2 = 1350, "1", 350 * 2 = 700, "10", 700 * 2 = 1400, "101", 400 * 2 = 800
      "1010", 800 * 2 = 1600, "10101", 600 * 2 = 1200, "101011", 200 * 2 infinit?
    .625 -> 625
      625 * 2 = 1250, "1", 250 * 2 = 500, "10", 500 * 2 = 1000, "101", 0
    .00005 -> ?
  Doesn't look like LintCode has the right solution or could have the right solution.
