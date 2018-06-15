#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    // First, we shall sort the vector by the value of the first element(start)
    // need to define a lambda for the comparison function
    auto interval_compare = [] (const Interval &left, const Interval &right) -> bool {
      return left.start < right.start;
    };
    std::sort(intervals.begin(), intervals.end(), interval_compare);
    auto print = [] (const Interval& i) {
      cout << "start: " << i.start << " end: " << i.end << endl;
    };
    //for_each(intervals.begin(), intervals.end(), print);

    // next, merge ajacent vector items, note the last item in a vetor is vector.back()
    vector<Interval> newIntervals;
    newIntervals.push_back(intervals.front());
    vector<Interval>::reverse_iterator left = newIntervals.rbegin();
    vector<Interval>::iterator right = intervals.begin() + 1;
    // idea is to merge from right to left, with sorting, we simplified things a bit since
    // we can assume left.start is equal or less than right.start
    // idea is that if there is any overlap, we aborbs the right item and move to right.next() -> right++
    // otherwise (no overlap), push right onto newInterval
    while(right != intervals.end()) {
      if (left->end >= right->start)
        left->end = std::max(left->end, right->end);
      else {
        newIntervals.push_back(*right);
        left = newIntervals.rbegin();
      }
      right++;
    }
    //for_each(newIntervals.begin(), newIntervals.end(), print);

    return newIntervals;
  }

};
