#include "../Library/Matrices/Strassen_Multiply.hh"
using namespace Orion_Quest;

int main()
{
    typedef float T;
    Matrix<T> n=Matrix<T>::Identity(4);
    n*=(T)2.;
    Matrix<T> m=Matrix<T>::Identity(4);
    m*=(T)4.;
    Matrix<T> result=Strassen_Multiply(n,m);
    std::cout<<"m1: "<<std::endl<<n<<std::endl;
    std::cout<<"m2: "<<std::endl<<m<<std::endl;
    std::cout<<"result: "<<std::endl<<result<<std::endl;

    return 0;
}
