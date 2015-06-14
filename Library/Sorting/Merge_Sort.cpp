//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Sorting/Merge_Sort.h>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Merge_Sort<T>::
Merge_Sort(std::vector<T>& data_input)
    :data(data_input)
{}
//#####################################################################
// Function Sort
//#####################################################################
template<class T> void Merge_Sort<T>::
Sort(int start,int end)
{
    if(start<end){
        int middle=floor((start+end)/2.);
        Sort(start,middle);
        Sort(middle+1,end);
        Merge(start,middle,end);}
}
//#####################################################################
// Function Merge
//#####################################################################
template<class T> void Merge_Sort<T>::
Merge(int p,int q,int r)
{
    std::vector<T> result;
    int i=p,j=q+1,k=0;

    while(i<=q && j<=r){
        if(data[i]<=data[j]) result.push_back(data[i++]);
        else result.push_back(data[j++]);
    }

    while(i<=q) result.push_back(data[i++]);

    while(j<=r) result.push_back(data[j++]);

    assert(result.size()==r-p+1);

    for(int k=p;k<=r;++k) data[k]=result[k-p];
}
//#####################################################################
template class Merge_Sort<int>;
template class Merge_Sort<float>;
template class Merge_Sort<double>;
