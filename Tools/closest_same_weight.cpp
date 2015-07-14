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

    int num=atoi(argv[1]),i=0;
    while((num>>i) > 0){
        bool ith_bit_zero=!((1<<i)&num);
        bool i_plus_1th_bit_one=(1<<(i+1))&num;

        if(ith_bit_zero && i_plus_1th_bit_one) break;
        else if(!i_plus_1th_bit_one && !ith_bit_zero) break;
        else ++i;
    }

    Swap_Bits(num,i,i+1);
    std::cout<<"Num: "<<num<<std::endl;

    return 0;
}
