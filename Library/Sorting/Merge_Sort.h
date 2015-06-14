//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
// Class Merge_Sort
//##################################################################### 
#ifndef __Merge_Sort__
#define __Merge_Sort__

#include <vector>

namespace Orion_Quest{
template<class T>
class Merge_Sort
{
  public:
    std::vector<T>& data;

    Merge_Sort(std::vector<T>& data_input);
    ~Merge_Sort() {}

//##################################################################### 
    void Sort(int start,int end);
    void Merge(int p,int q,int r);
//##################################################################### 
};
}
#endif
