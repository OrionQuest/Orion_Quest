#ifndef __STRASSEN_MULTIPLY_HH__
#define __STRASSEN_MULTIPLY_HH__

#include "Matrix_View.hh"

namespace Orion_Quest
{
template<class T> Matrix<T> Strassen_Multiply(const Matrix<T>& m1,const Matrix<T>& m2)
{
    assert(m1.Cols()==m2.Rows());
    if(m1.Rows()==1 || m2.Cols()==1) return m1*m2;

    Matrix<T> A=Matrix_View<T>::Get_Matrix(m1,0,m1.Rows()/2-1,0,m1.Cols()/2-1);
    Matrix<T> B=Matrix_View<T>::Get_Matrix(m1,0,m1.Rows()/2-1,m1.Cols()/2,m1.Cols()-1);
    Matrix<T> C=Matrix_View<T>::Get_Matrix(m1,m1.Rows()/2,m1.Rows()-1,0,m1.Cols()/2-1);
    Matrix<T> D=Matrix_View<T>::Get_Matrix(m1,m1.Rows()/2,m1.Rows()-1,m1.Cols()/2,m1.Cols()-1);

    Matrix<T> E=Matrix_View<T>::Get_Matrix(m2,0,m2.Rows()/2-1,0,m2.Cols()/2-1);
    Matrix<T> F=Matrix_View<T>::Get_Matrix(m2,0,m2.Rows()/2-1,m2.Cols()/2,m2.Cols()-1);
    Matrix<T> G=Matrix_View<T>::Get_Matrix(m2,m2.Rows()/2,m2.Rows()-1,0,m2.Cols()/2-1);
    Matrix<T> H=Matrix_View<T>::Get_Matrix(m2,m2.Rows()/2,m2.Rows()-1,m2.Cols()/2,m2.Cols()-1);

    Matrix<T> S1=Strassen_Multiply(B-D,G+H);
    Matrix<T> S2=Strassen_Multiply(A+D,E+H);
    Matrix<T> S3=Strassen_Multiply(A-C,E+F);
    Matrix<T> S4=Strassen_Multiply(A+B,H);
    Matrix<T> S5=Strassen_Multiply(A,F-H);
    Matrix<T> S6=Strassen_Multiply(D,G-E);
    Matrix<T> S7=Strassen_Multiply(C+D,E);

    Matrix<T> result(m1.Rows(),m2.Cols());
    Matrix_View<T> r1(result,0,result.Rows()/2-1,0,result.Cols()/2-1);
    Matrix_View<T> r2(result,0,result.Rows()/2-1,result.Cols()/2,result.Cols()-1);
    Matrix_View<T> r3(result,result.Rows()/2,result.Rows()-1,0,result.Cols()/2-1);
    Matrix_View<T> r4(result,result.Rows()/2,result.Rows()-1,result.Cols()/2,result.Cols()-1);

    r1=S1+S2-S4+S6;
    r2=S4+S5;
    r3=S6+S7;
    r4=S2-S3+S5-S7;

    return result;
}
}
#endif
