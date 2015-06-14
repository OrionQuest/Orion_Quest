//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
// Class Binary_Search
//##################################################################### 
#ifndef __Binary_Search__
#define __Binary_Search__

#include <vector>

namespace Orion_Quest{
template<class T>
class Binary_Search
{
  public:
    std::vector<T>& data;

    Binary_Search(std::vector<T>& data_input);
    ~Binary_Search() {}

//##################################################################### 
    int Search(const T key,const int start,const int end);
//##################################################################### 
};
}
#endif
