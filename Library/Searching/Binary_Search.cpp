//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Searching/Binary_Search.h>
#include <cmath>
#include <iostream>
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Binary_Search<T>::
Binary_Search(std::vector<T>& data_input)
    :data(data_input)
{}
//#####################################################################
// Function Search
//#####################################################################
template<class T> int Binary_Search<T>::
Search(const T key,const int start,const int end)
{
    if(start<=end){
        int middle=floor((start+end)/2.);
        if(data[middle]==key) return middle;

        if(data[middle]>key) return Search(key,start,middle-1);
        else return Search(key,middle+1,end);
    }
    return -1;
}
//#####################################################################
template class Binary_Search<int>;
template class Binary_Search<float>;
template class Binary_Search<double>;
