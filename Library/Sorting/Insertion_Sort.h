//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
// Class Insertion_Sort
//##################################################################### 
#ifndef __Insertion_Sort__
#define __Insertion_Sort__

#include <vector>

namespace Orion_Quest{
template<class T>
class Insertion_Sort
{
  public:
    std::vector<T>& data;

    Insertion_Sort(std::vector<T>& data_input);
    ~Insertion_Sort() {}

//##################################################################### 
    void Sort();
//##################################################################### 
};
}
#endif
