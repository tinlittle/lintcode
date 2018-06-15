#include <type_traits>

namespace Sorting {
  template <typename _RandomAccessIterator>
  void QuickSort(_RandomAccessIterator __first, _RandomAccessIterator __last);
  template <typename Iterator> void quickSort(Iterator start, Iterator end);
  template <typename T> void hi(T t);
};
/*
template <typename Iterator> 
void 
quickSort(Iterator start, Iterator end);
*/

