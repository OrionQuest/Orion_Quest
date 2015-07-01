//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Data_Structures/Heap.h>
#include <cstdlib>
#include <iostream>
using namespace Orion_Quest;

int main(int argc,char** argv)
{
    if(argc<2){
        std::cout<<"Usage: "<<argv[0]<<" <num1> <num2> ..."<<std::endl;
        return 1;
    }

    Heap<int> heap;
    for(int i=1;i<argc;++i) heap.Insert(atoi(argv[i]));

    std::cout<<"Heap: ";
    heap.Print();
    return 0;
}
