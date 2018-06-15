#include "ContainerOps.h"
#include "Sorting.h"

#include <iostream>
#include <assert.h>

#include <random>
#include <algorithm>

#if 0
template <typename Iterator> void Sorting::quickSort(Iterator start, Iterator end) {
    int size = (end - start);
    if ( size <= 0 )
        return;     // Base case
    
    // Partition - in place partitioning that involves only swapping
    // https://class.coursera.org/algo/lecture/preview/22 - O(n) time with no extra memory++
    /*
        Assume pivot is first element of array
        Otherwise swap pivot with first element
        
        Idea: Array A is in this form
            pivot | < p | > p | unpartitioned/unseen
            
        Let i = index of the first item > p 
        Let j = index of the first item unpartitioned
        
        Let i = 1
        Let j = 1
        Let p = pivot value
        
        for j < size
            if A[i] < p
                swap A[j] with A[i]
                i++
        swap A[0] with A[i-1]
    */
    // Get pivot element
    int pivotIndex = (size + 1) / 2; // randomNumber(0, size);
    /*typename std::iterator_traits<Iterator>::value_type*/ auto pivot = *(start + pivotIndex);
    
    if (pivotIndex != 0)
        std::swap(*(start + pivotIndex), *start);
    
    int i = 1;
    for (int j = 1; j < size; j++){
        if ( *(start + j) < pivot ){
            std::swap( *(start+j), *(start+i));
            i++;
        }
    }
    
    std::swap(*start, *(start + i - 1));
    
    quickSort(start, start+i-1);
    quickSort(start+i, end);
}
#endif

using std::size_t;

template <typename T>
bool isSorted(T& list) {
  typename T::iterator i = list.begin();
  typename T::iterator j = i + 1;

  if (i == list.end())
    return true;
  if (j == list.end())
    return true;

  while (*i <= *j && j != list.end()) {
    i++; j++;
  }

  if (j == list.end())
    return true;
  
  return false;
}

template <typename T>
int quickselect(T& list, size_t first, size_t last, size_t target_index) {
  // given an array - list, a range indicated with index first and last inclusive, a target_index relative to first (zero based)
  // goal is the return the value at target_index where the range [first, last] is sorted
  // no requirement on the range [first, last] be actualy sorted
  // caution: target_index is relative, while first and last are absolute, this is a recursive funciton so the main logic
  // should be use only relative coordination, a function object should be created for the pure purpose of translating
  // from relative index to absolute index
  auto toABSIndex = [=] (const size_t rIndex) {
    assert(first + rIndex <= last);
    return first + rIndex;
  };
  auto pointerAt = [&] (const size_t rIndex) -> typename T::iterator {
    assert(first + rIndex <= last);
    return list.begin() + toABSIndex(rIndex);
  };

  auto valueAt = [=] (const size_t rIndex) {
    return *(pointerAt(rIndex));
  };

  size_t n = last - first + 1; //total number of items under evaluation

  // 1. start: do a partition on the last number
  // 2. check if pivot is the target, yes, return the value, no, next
  // 3. set up recursive call by select the range based on the value at pivot, set new parameters 
  // 4. call this this function recursively

  // #1. Partition and select random pivot position
  size_t pivot_index = n - 1;

  if (pivot_index == 0) {
    assert(target_index == 0);
    return valueAt(pivot_index);
  }
  /* std::random_device is too expensive, need to use poor man's method instead
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(0, n - 1);
  size_t random_index = dis(gen);
  */
  size_t random_index = rand() % (n - 1);
  if (random_index != pivot_index) {
    std::swap(*pointerAt(pivot_index), *pointerAt(random_index));
  }


  size_t low = 0, high = pivot_index - 1;
  int pivot = valueAt(pivot_index);

  while (low < high) {
    while (valueAt(low) <= pivot && low < pivot_index)
      ++low;
    while (valueAt(high) > pivot && high > low)
      --high;
    if ((high > low) && valueAt(low) > pivot && valueAt(high) <= pivot) {
      typename T::iterator lowPointer = pointerAt(low); 
      typename T::iterator highPointer = pointerAt(high);
      std::swap(*lowPointer, *highPointer);
    }
  }
  if (pivot < valueAt(high)) {
    std::swap(*pointerAt(pivot_index), *pointerAt(high));
    pivot_index = high;
  }

  // #2, step 2
  if (pivot_index == target_index)
    return valueAt(pivot_index);

  // #3, step 3, need new range and target index
  // range would be either before or after the pivot point, target index since it is relative to the range specified
  // needs to be calculated
  // if target_index is less than pivot_index, meaning select function wants a smaller integar, search in the left partition
  // and vice versa
  // the range should be either [first, pivot_index - 1], or [pivot_index + 1, last]
  if (target_index < pivot_index) {
    // setting up range on the left hand side
    // since we landed on the left hand side and the target is smaller than pivot, meaning
    // we narrowed our search but the target remains the same relative to first
    return quickselect(list, first, first + pivot_index - 1, target_index);
  }
  else {
    // setting up range and new relative target_index on the right hand side
    // since we landed on the right hand side, all items plus the pivot are smaller than target
    // to locate the next target, we shall adjust how deep we look by pivot_index + 1
 
    size_t new_first = first + pivot_index + 1;
    size_t new_target_index = target_index - pivot_index - 1;
    return quickselect(list, new_first, last, new_target_index);
  }
  
}

template <typename T>
void myquicksort(T& list, size_t first, size_t last) {
  // have my array, and the range that needs to be sorted
  if (first >= last)
    return;
  // first identify the pivot position and pivot

  int *pivot_point = &list[last];
  int pivot = list[last];

  // now let's partition
  int *front = &list[first];
  int *back = &list[last - 1];

  while (front < back) {
    while (*front <= pivot && front < pivot_point)
      ++front;
    while ((*back > pivot) && back > front)
      --back;
    if ((back > front) && (*front > pivot && *back <= pivot))
      std::swap(*front, *back);
  }

  // where front and back crossed, front is where pivot should be, unless front never moved
  if (*pivot_point < *back) {
    std::swap(*back, *pivot_point);
    pivot_point = back;
  }
  else 
    assert(back < pivot_point);
  
  size_t pivot_index = first + (pivot_point - &list[first]);
  myquicksort(list, first, std::min(last, pivot_index - 1));
  myquicksort(list, std::min(last, pivot_index + 1), last);

}
//template void Sorting::hi<int> (int);

int main() {
  std::array<int, 10> nums = {5, 3, 4, 6, 8, 9, 8, 0, 1, 2};
  std::array<int, 3> ints = {5, 3, 4};
  std::array<int, 5> ints5 {1, 6, 4, 5, 3};
  std::array<int, 6> ints6 {5, 6, 3, 1, 2, 4};

  int a = quickselect(nums, 0, 9, 10 - 3);

  Sorting::hi(nums[3]);

  myquicksort(ints, 0, 2);
  assert(isSorted(ints));
  myquicksort(ints5, 0, ints5.size() - 1);
  assert(isSorted(ints));
  int loops = 0;

  std::random_device rd;
  std::mt19937 g(rd());
  while (loops < 10000000) {
    std::shuffle(ints5.begin(), ints5.begin() + 5, g);
    myquicksort(ints5, 0, ints5.size() - 1);
    assert(isSorted(ints));
    loops++;
  }
  myquicksort(ints5, 0, ints5.size() - 1);
  assert(isSorted(ints));
  myquicksort(ints6, 0, ints6.size() - 1);
  assert(isSorted(ints));
  myquicksort(ints6, 0, ints6.size() - 1);
  assert(isSorted(ints));
  myquicksort(nums, 0, nums.size() - 1);
  assert(isSorted(ints));
  loops = 0;
  while (loops < 10000000) {
    std::shuffle(nums.begin(), nums.begin() + nums.size(), g);
    int index_5 = quickselect(nums, 0, 9, 5);
    int index_6 = quickselect(nums, 0, 9, 6);
    assert (index_5 == 5 && index_6 == 6);
    myquicksort(nums, 0, nums.size() - 1);
    assert(isSorted(nums));
    loops++;
  }
  


  Sorting::quickSort(ints.begin(), ints.end());
  Sorting::quickSort(nums.begin(), nums.end());
  int m = ContainerOps::kthLargestElement(3, nums);

  std::cout << m << std::endl;
  return 0;
}