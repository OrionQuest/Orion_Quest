//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Utilities/Substring_Search.h>
#include <algorithm>
#include <iostream>
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Substring_Search<T>::
Substring_Search(const std::vector<T>& str_input)
    :str(str_input),Z(str.size())
{
    Compute_Z();
}
//#####################################################################
// Function Compute_Z
//#####################################################################
template<class T> void Substring_Search<T>::
Compute_Z()
{
    int k=1;
    while(str[k]==str[k-1]) ++k;
    Z[1]=k-1;
    int l=(Z[1]>0)?1:0;
    int r=(Z[1]>0)?Z[1]:0;

    for(k=2;k<str.size();++k){
        if(k>r){
            int r=k;
            while(str[r]==str[r-k]) ++r;
            if(r>k){
                Z[k]=r-k;
                l=k;
                --r;
            }
        }
        else{int p=k-l,beta=std::min(Z[p],r-k+1);
            if(Z[p]<beta) Z[k]=Z[p];
            else{int q=beta;
                while(str[r+1]==str[q+1]){
                    ++q;
                    ++r;
                }
                Z[k]=r-k;
                l=k;
            }
        }
    }
}
//#####################################################################
template class Substring_Search<char>;
template class Substring_Search<int>;
