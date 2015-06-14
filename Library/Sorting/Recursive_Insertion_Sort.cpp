//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Sorting/Recursive_Insertion_Sort.h>
#include <cassert>
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Recursive_Insertion_Sort<T>::
Recursive_Insertion_Sort(std::vector<T>& data_input)
    :data(data_input)
{}
//#####################################################################
// Function Sort
//#####################################################################
template<class T> void Recursive_Insertion_Sort<T>::
Sort(int start,int end)
{
    if(start<end) Sort(start,end-1);
    int j=end;T key=data[j];
    while(key<data[j-1] && j>0){
        data[j]=data[j-1];
        --j;
    }
    assert(j>=0);
    data[j]=key;
}
//#####################################################################
template class Recursive_Insertion_Sort<int>;
template class Recursive_Insertion_Sort<float>;
template class Recursive_Insertion_Sort<double>;
