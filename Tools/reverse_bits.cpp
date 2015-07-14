#include <cstdlib>
#include <iostream>
#include <Utilities/Bit_Manipulation.h>
using namespace Orion_Quest;

int main(int argc,char** argv)
{
    if(argc!=2){
        std::cout<<"Usage: "<<argv[0]<<" <num>"<<std::endl;
        return 1;
    }

    int num=atoi(argv[1]);
    Reverse_Bits(num);

    std::cout<<"Num: "<<num<<std::endl;
}
