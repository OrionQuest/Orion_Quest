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

    std::vector<int> data;
    for(int i=1;i<argc;++i){
        data.push_back(atoi(argv[i]));
    }

    Heap<int> heap(data);
    //heap.Sort();

    //std::cout<<"Data:";
    //for(int i=0;i<data.size();++i) std::cout<<" "<<data[i];
    //std::cout<<std::endl;

    heap.Heapify();
    heap.Print();

    heap.Delete(3);
    heap.Print();

    //std::cout<<"Descending order: ";
    //while(!heap.Empty()){
    //    int max_value=heap.Extract_Max();
    //    std::cout<<" "<<max_value;
    //}
    //std::cout<<std::endl;

    return 0;
}
