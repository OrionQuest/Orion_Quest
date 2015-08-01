//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#ifndef __Substring_Search__
#define __Substring_Search__

#include <vector>

namespace Orion_Quest{
template<class T>
class Substring_Search
{
    const std::vector<T>& str;
    std::vector<int> Z;

  public:
    Substring_Search(const std::vector<T>& str_input);

  private:
//#####################################################################
    void Compute_Z();
//#####################################################################
};
}
#endif
