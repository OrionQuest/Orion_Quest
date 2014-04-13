// ***************************************************
// Matrix stores data in column major order.
// ***************************************************
#ifndef __MATRIX_HH__
#define __MATRIX_HH__

#include <vector>
#include <cassert>
#include <iostream>

namespace Orion_Quest
{
template<class T>
class Matrix
{
  public:
    int m;
    int n;
    std::vector<T> data;

    Matrix(const int m_input,const int n_input)
        :m(m_input),n(n_input),data(m*n,T())
    {}

    Matrix(const Matrix<T>& other)
        :m(other.Rows()),n(other.Cols()),data(other.data)
    {}

    const T& operator()(const int i,const int j) const
    {assert(i>=0 && i<m && j>=0 && j<n);
    return data[n*i+j];}

    T& operator()(const int i,const int j)
    {assert(i>=0 && i<m && j>=0 && j<n);
    return data[n*i+j];}

    void operator+=(const Matrix<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)+=other(i,j);}

    void operator-=(const Matrix<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)-=other(i,j);}

    Matrix<T> operator+(const Matrix<T>& other) const
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    Matrix<T> copy(*this);copy+=other;return copy;}

    Matrix<T> operator-(const Matrix<T>& other) const
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    Matrix<T> copy(*this);copy-=other;return copy;}

    void operator=(const Matrix<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)=other(i,j);}

    void operator*=(const T a)
    {for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)*=a;}

    Matrix<T> operator*(const Matrix<T>& other) const
    {assert(Cols()==other.Rows() && (other.Cols()==1 || Rows()==1));
    Matrix<T> ret(Rows(),other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) for(int k=0;k<other.Cols();++k)
        ret(i,k)+=this->operator()(i,j)*other(j,k);
    return ret;}

    int Rows() const
    {return m;}

    int Cols() const
    {return n;}

    static Matrix<T> Identity(const int rows)
    {Matrix<T> ret(rows,rows);for(int i=0;i<rows;++i) ret(i,i)=(T)1;return ret;}
};

template<class T> std::ostream& operator<<(std::ostream& output,const Matrix<T>& m)
{
    for(int i=0;i<m.Rows();++i){output<<m(i,0);
        for(int j=1;j<m.Cols();++j) output<<" "<<m(i,j);
        output<<std::endl;}
    return output;
}
}
#endif
