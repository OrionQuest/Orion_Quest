//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include "Insertion_Sort.h"
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Insertion_Sort<T>::
Insertion_Sort(std::vector<T>& data_input)
    :data(data_input)
{}
//#####################################################################
// Function Sort
//#####################################################################
template<class T> void Insertion_Sort<T>::
Sort()
{
    for(int j=1;j<data.size();++j)
    {
        T key=data[j];int i=j-1;
        while(i>=0 && data[i]>key)
        {
            data[i+1]=data[i];
            --i;
        }
        data[i+1]=key;
    }
}
//#####################################################################
template class Insertion_Sort<int>;
template class Insertion_Sort<float>;
template class Insertion_Sort<double>;
