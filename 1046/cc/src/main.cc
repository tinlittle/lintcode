#include "bitsTable.cc"

#include <iostream>
#include <vector>
#include <algorithm>

#include <numeric>
//#include <experimental/filesystem>
//#include <execution>

#include <algorithm> 
#include <iterator> 
#include <utility> 
#include <memory>

#if 0
using namespace std;
template<class IterTag, class ValueType> 
struct remover { 
  template<class Container, class IterType, class Predicate> 
  static void do_remove_if(Container &c, IterType begin, IterType end, Predicate pred) { c.remove_if(pred); } 
};

template<class ValueType> 
struct remover<random_access_iterator_tag, ValueType> { 
  template<class Container, class IterType, class Predicate> 
  static void do_remove_if(Container &c, IterType begin, IterType end, Predicate pred) { 
    c.erase(remove_if(begin, end, pred), end); 
    } 
};

template<class IterTag, class Key, class Value> 
struct remover<IterTag, pair<Key, Value>> { 
  template<class Container, class IterType, class Predicate> 
  static void do_remove_if(Container &c, IterType begin, IterType end, Predicate pred) { 
    for(auto i = c.begin(); i != c.end();) { 
      if(pred(*i))
       c.erase(i++); 
      else 
        ++i; 
    }
  } 
}; 

template<class Container, class Predicate> 
void erase_if(Container &c, Predicate pred) {
   typedef iterator_traits<Container::iterator>::iterator_category iter_cat_t; 
   typedef remover<iter_cat_t, Container::value_type> remover_t; 
   remover_t::do_remove_if(c, c.begin(), c.end(), pred); 
} 
#endif

void foo(const std::shared_ptr<int>& sp) {
  std::cout << "lvalue shared_ptr: " << *sp << std::endl;
}


void foo(std::shared_ptr<int>&& sp ) {
  std::cout << "rvalue shared_ptr: " << *sp << std::endl;
}

template<typename T, typename V>
std::shared_ptr<T> factory(V v) {
  return std::shared_ptr<T> (new T(v));
}


std::shared_ptr<int> bar(std::shared_ptr<int> sp) {
  return sp;
}

int main () {
  Solution s;
  /*
  for (auto row : s.popTable) { 
    for (auto column : row)
      std::cout << column << " ";
    std::cout << std::endl;
  }
  */
 #if 0
  std::vector<std::filesystem:path> paths;
  std:filesystem::recursive_directory_iterator dirpos(std::string("."));
  for (auto dir : dirpos) 
    std::cout << dir << std::endl;
#endif
  std::shared_ptr<int> sp {new int{1949}};
  foo(sp);
  foo(bar(sp));

  std::unique_ptr<int> p {new int{1729}};

  std::cout << *p << std::endl;

  std::unique_ptr<int> p2{std::move(p)};

  std::cout << *p2 << std::endl;

  std::vector<int> v;
  for (auto i = 1; i <= 5; ++i)
    v.push_back(i * 11);
#if 0
  for (auto i = v.cbegin(); i != v.cend(); ++i)
    if (*i % 2 != 0) {
      v.erase(i);
      i = v.cbegin();
      continue;
    }
#endif
  auto iter = std::remove_if(v.begin(), v.end(), [](auto i) -> bool { return i % 2 != 0; });
  v.erase(iter, std::end(v));
  for (auto i : v)
    std::cout << i << " ";

  std::cout << std::endl;

  std::cout << "size of v: " << v.size() << " capacity: " << v.capacity() << std::endl;

#if 0
  for (auto column : s.popTable[20])
    std::cout << column << " ";
#endif
  
  return 0;
}