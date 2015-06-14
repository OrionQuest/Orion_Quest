//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
// Class Recursive_Insertion_Sort
//##################################################################### 
#ifndef __Recursive_Insertion_Sort__
#define __Recursive_Insertion_Sort__

#include <vector>

namespace Orion_Quest{
template<class T>
class Recursive_Insertion_Sort
{
  public:
    std::vector<T>& data;

    Recursive_Insertion_Sort(std::vector<T>& data_input);
    ~Recursive_Insertion_Sort() {}

//##################################################################### 
    void Sort(int start,int end);
//##################################################################### 
};
}
#endif
