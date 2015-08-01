//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Utilities/Substring_Search.h>
#include <cstring>
#include <iostream>
using namespace Orion_Quest;

int main(int argc,char** argv)
{
    if(argc!=2){
        std::cout<<"Usage: "<<argv[0]<<" <input string>"<<std::endl;
        return 1;
    }

    std::string input(argv[1]);
    std::vector<char> str;
    for(int i=0;i<input.size();++i) str.push_back(input[i]);

    Substring_Search<char> ss(str);

    return 0;
}
