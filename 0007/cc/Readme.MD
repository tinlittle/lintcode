# Problem statement
  Serialize and deserialize binary tree

# Solution
  Need to use deque and string
    For deque, leverage pop_front and push_back
    For string, need to leverge
      initialize a string std::string
      integer to ascii, std::to_string
      appending to the string, push_back() for character, += for string
      match simple patterns at the end, check back() 
      slice a string from a set location, pop_back()
    Additional string operations needed for deserialization:
      tokenization
        roll one myself by using find_first_not_of()
        find, and std::string:npos
      delimiter specification
        trivial
      string to number conversion
        std::stoi()
        remember to check '#'

  