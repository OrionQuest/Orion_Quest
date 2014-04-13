// ***************************************************
// Matrix_View is a reference window within a Matrix.
// It does allow the modification of the data.
// ***************************************************
#ifndef __MATRIX_VIEW_HH__
#define __MATRIX_VIEW_HH__

#include "Matrix.hh"

namespace Orion_Quest
{
template<class T>
class Matrix_View
{
  private:
    int n;
  public:
    int m_start;
    int m_end;
    int n_start;
    int n_end;
    std::vector<T>& data;

    Matrix_View(Matrix<T>& other,const int m_start_input,const int m_end_input,const int n_start_input,const int n_end_input)
        :n(other.Cols()),m_start(m_start_input),m_end(m_end_input),n_start(n_start_input),n_end(n_end_input),data(other.data)
    {assert(m_start>=0 && m_end<other.Rows() && n_start>=0 && n_end<other.Cols());}

    const T& operator()(const int i,const int j) const
    {assert(i>=0 && i<Rows() && j>=0 && j<Cols());
    return data[n*(i+m_start)+j+n_start];}

    T& operator()(const int i,const int j)
    {assert(i>=0 && i<Rows() && j>=0 && j<Cols());
    return data[n*(i+m_start)+j+n_start];}

    void operator+=(const Matrix<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)+=other(i,j);}

    void operator-=(const Matrix<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)-=other(i,j);}

    void operator+=(const Matrix_View<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)+=other(i,j);}

    void operator-=(const Matrix_View<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)-=other(i,j);}

    void operator=(const Matrix<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)=other(i,j);}

    void operator=(const Matrix_View<T>& other)
    {assert(Rows()==other.Rows() && Cols()==other.Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) this->operator()(i,j)=other(i,j);}

    int Rows() const
    {return m_end-m_start+1;}

    int Cols() const
    {return n_end-n_start+1;}

    Matrix<T> Get_Matrix()
    {Matrix<T> m(Rows(),Cols());
    for(int i=0;i<Rows();++i) for(int j=0;j<Cols();++j) m(i,j)=this->operator()(i,j);
    return m;}

    static Matrix<T> Get_Matrix(const Matrix<T>& other,const int m_start,const int m_end,const int n_start,const int n_end)
    {Matrix<T> copy(other);
    Matrix_View<T> v(copy,m_start,m_end,n_start,n_end);
    return v.Get_Matrix();}
};

template<class T> std::ostream& operator<<(std::ostream& output,const Matrix_View<T>& m)
{
    for(int i=0;i<m.Rows();++i){output<<m(i,0);
        for(int j=1;j<m.Cols();++j) output<<" "<<m(i,j);
        output<<std::endl;}
    return output;
}
}
#endif
