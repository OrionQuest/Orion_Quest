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

    Heap<int> heap1;
    std::vector<int> data;
    for(int i=1;i<argc;++i){
        heap1.Insert(atoi(argv[i]));
        data.push_back(atoi(argv[i]));
    }

    heap1.Print();

    Heap<int> heap2(data);
    heap2.Heapify();
    heap2.Print();
    return 0;
}
