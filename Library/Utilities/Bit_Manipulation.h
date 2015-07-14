//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
// Routines for various bit manipulations
//#####################################################################
#ifndef __Bit_Manipulation__
#define __Bit_Manipulation__

namespace Orion_Quest{
//#####################################################################
// Swap the ith and jth bits
//#####################################################################
void Swap_Bits(int& num,const int i,const int j)
{
    if(((num>>i)&1)^((num>>j)&1)){
        num^=(1<<i);
        num^=(1<<j);
    }
}
//#####################################################################
// Reverse all bits
//#####################################################################
void Reverse_Bits(int& num)
{
    int number_of_bits=0,temp=num;
    while(temp>0){
        temp/=2;
        ++number_of_bits;
    }

    for(int i=0;i<number_of_bits/2;++i)
        Swap_Bits(num,i,number_of_bits-i-1);
}
//#####################################################################
}
#endif
