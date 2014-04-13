#ifndef __DISJOINT_SET_UNION_HH__
#define __DISJOINT_SET_UNION_HH__

#include <set>
#include <vector>
#include <cassert>
#include <utility>
#include <iostream>

namespace Orion_Quest
{
class Element
{
  public:
    const int index;
    int* count;
    int* last;
    Element* head;
    Element* next;

    Element(const int index_input)
        :index(index_input),count(new int(1)),last(new int(index)),head(this),next(0)
    {}
};

class Disjoint_Set_Union
{
  public:
    std::vector<Element*> nodes;

    Disjoint_Set_Union(const int n)
        :nodes(n)
    {for(int i=0;i<n;++i) nodes[i]=new Element(i);}

    void Assert(const int i) const
    {assert(i>=0 && i<nodes.size());}

    Element* Head(const int i) const
    {Assert(i);
    return nodes[i]->head;}

    Element* Get_Element(const int i)
    {Assert(i);
    return nodes[i];}

    void Set_Head(const int i,Element* head)
    {Assert(i);
    nodes[i]->head=head;}

    void Set_Count(Element* head,const int count)
    {assert(head->count);
    *(head->count)=count;}

    int Count(const int i) const
    {Assert(i);
    assert(Head(i)->count);
    return *(Head(i)->count);}

    void Merge(const int x,const int y)     // Merges y into x
    {
        int x_count=Count(x),y_count=Count(y);
        Element* head=Head(x);
        // change next pointer for last element of larger list
        Element* last=Get_Element(*(head->last));
        last->next=Head(y);
        // change count and last for larger list
        Set_Count(head,x_count+y_count);
        *(head->last)=*(Head(y)->last);
        // delete count and last for smaller list
        head=Head(y);
        delete head->count;head->count=0;
        delete head->last;head->last=0;
        // change head pointer for smaller list
        while(head){
            Set_Head(head->index,Head(x));
            head=head->next;}
    }

    void Add_Edge(const std::pair<int,int>& e)
    {
        int x=e.first,y=e.second,x_count=Count(x),y_count=Count(y);
        if(Head(x)!=Head(y)){
            if(x_count>y_count) Merge(x,y);
            else Merge(y,x);}
    }

    void Print()
    {
        std::set<int> index_set;
        for(int i=0;i<nodes.size();++i) if(index_set.count(i)==0){
            index_set.insert(i);
            Element* head=Head(i);
            std::cout<<"List :";
            while(head){
                std::cout<<" "<<head->index;
                if(index_set.count(head->index)==0) index_set.insert(head->index);
                head=head->next;}
            std::cout<<std::endl;}
    }
};
}
#endif
