#include "../Library/Matrices/Matrix_View.hh"
using namespace Orion_Quest;

int main()
{
    typedef float T;
    Matrix<T> m=Matrix<T>::Identity(4);
    Matrix_View<T> v(m,1,2,0,3);
    std::cout<<v<<std::endl;
    return 0;
}
