# Problem statement
  Get the nth ugly number

# Solution
  The idea is very novel. Insight, assuming we have a list of ordered ugly number, the next smallest ugly number would have to be a multiple of one of the existing ugly number on our list. If we have actively kept three separate lists of the 2x, 3x, and 5x of existing list, all we need to do to get the next smallest number is to pop off the smallest number on the top of the three queues. If we use priority queues for implementation, and since we only insert number that is bigger than all exiting queue items, there is not even a logN insertion penalty

  How to identify the vector that currently holds the smallest element? If you use min, you get the value

  you have sorted two vectors,
  vector<int> a; vector<int> b;
  and you want to identify which vector has the smallest item
  if you do std::min(a.front(), b.front()); you get the value
  but I want an operation to return a or b (so I could pop_front())
  how to write it elegantly in modern C++ style?


