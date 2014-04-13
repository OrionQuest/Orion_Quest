#include "../Library/Matrices/Matrix_View.hh"
using namespace Orion_Quest;

int main()
{
    typedef float T;

    Matrix<T> m(4,4);
    for(int i=0;i<4;++i) m(i,i)=1;
    m+=m;
    m+=m;
    std::cout<<m<<std::endl;
    Matrix<T> other=Matrix_View<T>::Get_Matrix(m,0,1,1,2);
    std::cout<<"Other: "<<std::endl<<other<<std::endl;

    Matrix<T> n(4,1);
    for(int i=0;i<4;++i) n(i,0)=i;
    std::cout<<"n: "<<std::endl<<n<<std::endl;
    std::cout<<"m*n: "<<std::endl<<m*n<<std::endl;

    Matrix<T> p(1,4);
    for(int i=0;i<4;++i) p(0,i)=i+2;
    std::cout<<"p: "<<std::endl<<p<<std::endl;
    std::cout<<"p*m: "<<std::endl<<p*m<<std::endl;

    return 0;
}
