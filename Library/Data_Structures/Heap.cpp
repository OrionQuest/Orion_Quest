//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Data_Structures/Heap.h>
#include <iostream>
#include <limits>
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Heap<T>::
Heap()
    :size(0)
{}
//#####################################################################
// Constructor
//#####################################################################
template<class T> Heap<T>::
Heap(const std::vector<T>& data_input)
    :data(data_input),size(data_input.size())
{}
//#####################################################################
// Insert
//#####################################################################
template<class T> void Heap<T>::
Insert(const T key)
{
    ++size;
    if(data.size()<size) data.resize(2*size);
    data[size-1]=-std::numeric_limits<T>::max();
    Increase_Key(size-1,key);
}
//#####################################################################
// Print
//#####################################################################
template<class T> void Heap<T>::
Print()
{
    for(int i=0;i<size;++i) std::cout<<" "<<data[i];
    std::cout<<std::endl;
}
//#####################################################################
// Increase_Key
//#####################################################################
template<class T> void Heap<T>::
Increase_Key(int i,const T key)
{
    if(key<data[i]){
        std::cerr<<"New key "<<key<<" is smaller than current key "<<data[i]<<std::endl;
        return;
    }

    data[i]=key;
    while(i>=0 && data[Parent(i)]<data[i]){
        T temp=data[Parent(i)];
        data[Parent(i)]=data[i];
        data[i]=temp;
        i=Parent(i);
    }
}
//#####################################################################
template class Heap<int>;
