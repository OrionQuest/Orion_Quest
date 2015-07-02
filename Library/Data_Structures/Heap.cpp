//#####################################################################
// Copyright (c) 2015, Mridul Aanjaneya.
//#####################################################################
#include <Data_Structures/Heap.h>
#include <cassert>
#include <iostream>
#include <limits>
using namespace Orion_Quest;
//#####################################################################
// Constructor
//#####################################################################
template<class T> Heap<T>::
Heap()
    :data(*(new std::vector<T>())),size(0)
{}
//#####################################################################
// Constructor
//#####################################################################
template<class T> Heap<T>::
Heap(std::vector<T>& data_input)
    :data(data_input),size(data_input.size())
{}
//#####################################################################
// Insert
//#####################################################################
template<class T> void Heap<T>::
Insert(const T key)
{
    ++size;
    if(data.size()<size) data.resize(2*size);
    data[size-1]=-std::numeric_limits<T>::max();
    Increase_Key(size-1,key);
}
//#####################################################################
// Level
//#####################################################################
template<class T> int Heap<T>::
Level(int i)
{
    int count=0;
    while(i>0){
        ++count;
        i=Parent(i);
    }
    return count;
}
//#####################################################################
// Print
//#####################################################################
template<class T> void Heap<T>::
Print()
{
    std::cout<<"Heap:";
    for(int i=0;i<size;++i) std::cout<<" "<<data[i];
    std::cout<<std::endl;

    for(int i=0;i<size;++i){
        std::cout<<"Level: "<<Level(i)<<", Data: "<<data[i];
        if(Left(i)<size) std::cout<<", Left: "<<data[Left(i)];
        if(Right(i)<size) std::cout<<", Right: "<<data[Right(i)];
        std::cout<<std::endl;
    }
}
//#####################################################################
// Increase_Key
//#####################################################################
template<class T> void Heap<T>::
Increase_Key(int i,const T key)
{
    if(key<data[i]){
        std::cerr<<"New key "<<key<<" is smaller than current key "<<data[i]<<std::endl;
        return;
    }

    data[i]=key;
    while(i>0 && data[Parent(i)]<data[i]){
        T temp=data[Parent(i)];
        data[Parent(i)]=data[i];
        data[i]=temp;
        i=Parent(i);
    }
}
//#####################################################################
// Heapify
//#####################################################################
template<class T> void Heap<T>::
Heapify()
{
    for(int i=size/2;i>=0;--i) Max_Heapify(i);
}
//#####################################################################
// Max_Heapify
//#####################################################################
template<class T> void Heap<T>::
Max_Heapify(const int i)
{
    int left=Left(i),right=Right(i),largest=i;
    if(left<size && data[left]>data[i]) largest=left;
    if(right<size && data[right]>data[largest]) largest=right;
    if(largest!=i){
        T temp=data[largest];
        data[largest]=data[i];
        data[i]=temp;
        Max_Heapify(largest);
    }
}
//#####################################################################
// Sort
//#####################################################################
template<class T> void Heap<T>::
Sort()
{
    Heapify();
    int i=size-1;
    do{
        i=size-1;
        T temp=data[i];
        data[i]=data[0];
        data[0]=temp;
        --size;
        Max_Heapify(0);
    }while(i>0);
}
//#####################################################################
// Extract_Max
//#####################################################################
template<class T> T Heap<T>::
Extract_Max()
{
    if(size<=0){
        std::cout<<"Heap underflow!"<<std::endl;
        return -std::numeric_limits<T>::max();
    }
    T value=data[0];
    data[0]=data[size-1];
    --size;
    Max_Heapify(0);
    return value;
}
//#####################################################################
// Delete
//#####################################################################
template<class T> void Heap<T>::
Delete(const int i)
{
    if(size<=0){
        std::cout<<"Heap underflow!"<<std::endl;
        return;
    }
    assert(i>=0 && i<size && size>0);
    std::cout<<"Deleting: "<<data[i]<<std::endl;
    data[i]=data[size-1];
    --size;
    Max_Heapify(i);
}
//#####################################################################
template class Heap<int>;
