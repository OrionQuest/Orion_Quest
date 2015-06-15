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
template<class T> std::pair<bool,int> Binary_Search<T>::
Search(const T key,const int start,const int end)
{
    if(start==end){
        if(data[start]==key) return std::pair<bool,int>(true,start);
        else if(data[start]>key) return std::pair<bool,int>(false,start-1);
        else return std::pair<bool,int>(false,start+1);}

    int middle=floor((start+end)/2.);
    if(data[middle]==key) return std::pair<bool,int>(true,middle);

    if(data[middle]>key) return Search(key,start,middle-1);
    else return Search(key,middle+1,end);
}
//#####################################################################
template class Binary_Search<int>;
template class Binary_Search<float>;
template class Binary_Search<double>;
