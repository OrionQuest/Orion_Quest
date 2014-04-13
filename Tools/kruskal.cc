#include "../Library/Graphs/Disjoint_Set_Union.h"
#include <vector>
using namespace Orion_Quest;

int main()
{

    std::vector<std::pair<int,int> > edges;
    edges.push_back(std::pair<int,int>(0,1));
    edges.push_back(std::pair<int,int>(1,2));
    edges.push_back(std::pair<int,int>(2,0));
    edges.push_back(std::pair<int,int>(3,4));
    edges.push_back(std::pair<int,int>(3,5));

    Disjoint_Set_Union d(6);
    for(std::vector<std::pair<int,int> >::iterator it=edges.begin();it!=edges.end();++it){
        std::cout<<"Adding edge: ("<<it->first<<","<<it->second<<")"<<std::endl;
        d.Add_Edge(*it);}
    d.Print();
    return 0;
}
