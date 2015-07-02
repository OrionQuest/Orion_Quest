//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
// Class Heap
//##################################################################### 
#ifndef __Heap__
#define __Heap__

#include <vector>

namespace Orion_Quest{
template<class T>
class Heap
{
    std::vector<T> data;
    int size;
  public:
    Heap();
    Heap(const std::vector<T>& data_input);

    inline int Parent(const int i)
    {return (i-1)>>1;}

    inline int Left(const int i)
    {return (i<<1)+1;}

    inline int Right(const int i)
    {return (i<<1)+2;}

    const int Size()
    {return size;}

//##################################################################### 
    void Insert(const T key);
    void Print();
    int Level(int i);
    void Heapify();
//##################################################################### 
  private:
    void Max_Heapify(const int i);
    void Increase_Key(const int i,const T key);
//##################################################################### 
};
}
#endif
