#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

void Generate_Power_Set_Helper(const std::vector<int>& S,const int index,std::vector<int>& res)
{
    if(!res.empty()){
        std::copy(res.begin(),res.end()-1,std::ostream_iterator<int>(std::cout,","));
        std::cout<<res.back();
    }
    std::cout<<std::endl;

    for(int i=index;i<S.size();++i){
        res.push_back(S[i]);
        Generate_Power_Set_Helper(S,i+1,res);
        res.pop_back();
    }
}

void Generate_Power_Set(const std::vector<int>& S)
{
    std::vector<int> res;
    Generate_Power_Set_Helper(S,0,res);
}

int main(int argc,char** argv)
{
    if(argc!=2){
        std::cout<<"Usage: "<<argv[0]<<" <num>"<<std::endl;
        return 1;
    }

    int num=atoi(argv[1]);
    std::vector<int> S;
    for(int i=1;i<=num;++i) S.push_back(i);

    Generate_Power_Set(S);
    
    return 0;
}
