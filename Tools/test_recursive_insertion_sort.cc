//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Sorting/Recursive_Insertion_Sort.h>
#include <cstdlib>
#include <iostream>
using namespace Orion_Quest;

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        std::cout<<"Usage: "<<argv[0]<<" <num>"<<std::endl;
        return 1;
    }

    int num=atoi(argv[1]);
    std::vector<int> data;
    for(int i=0;i<num;++i) data.push_back(rand()%100+1);

    std::cout<<"Initial Data:";
    for(int i=0;i<data.size();++i) std::cout<<" "<<data[i];
    std::cout<<std::endl;

    Recursive_Insertion_Sort<int> ris(data);
    ris.Sort(0,data.size()-1);

    std::cout<<"Final Data:";
    for(int i=0;i<data.size();++i) std::cout<<" "<<data[i];
    std::cout<<std::endl;

    return 0;
}
