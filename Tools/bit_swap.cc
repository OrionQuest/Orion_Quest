#include <cstdlib>
#include <iostream>
#include <Utilities/Bit_Manipulation.h>
using namespace Orion_Quest;

int main(int argc,char** argv)
{
    if(argc!=4){
        std::cout<<"Usage: "<<argv[0]<<" <num> <i> <j>"<<std::endl;
        return 1;
    }

    int num=atoi(argv[1]),i=atoi(argv[2]),j=atoi(argv[3]);
    Swap_Bits(num,i,j);

    std::cout<<"Num: "<<num<<std::endl;
    return 0;
}
