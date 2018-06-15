#include "Sorting.h"

template <typename Iterator> void Sorting::quickSort(Iterator start, Iterator end) {
    int size = (end - start);
    if ( size <= 0 )
        return;     
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

template void Sorting::quickSort<int *> (int*, int*);
template <typename _RandomAccessIterator>
void Sorting::QuickSort(_RandomAccessIterator __first, _RandomAccessIterator __last) {
  //typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
  //difference_type __d = __last - __first;
  _RandomAccessIterator pivot = prev(__last);

    
}  


template <typename T>
void Sorting::hi(T t) {
  // do nothing;
  t++;
}

template void Sorting::hi<int> (int);
//#if 0

//#endif