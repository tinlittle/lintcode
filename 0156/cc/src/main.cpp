#include "Intervals.cpp"

#include <iostream>

int main() {

  Solution s;
  //vector<Interval> intervals = {{2,4},{1,3},{5,7},{4,6}};
  vector<Interval> intervals = {{5,7},{4,6},{1,3}};

  vector<Interval> newIntervals = s.merge(intervals);

  return 0;
}