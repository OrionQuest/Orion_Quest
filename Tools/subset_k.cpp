#include <cstdlib>
#include <iterator>
#include <iostream>
#include <vector>

void Generate_Subsets_Helper(const std::vector<int>& S,const int k,const int index,std::vector<int>& res)
{
    if(k==0){
        std::copy(res.begin(),res.end()-1,std::ostream_iterator<int>(std::cout,","));
        std::cout<<res.back()<<std::endl;
        return;
    }

    for(int i=index;i<S.size();++i){
        res.push_back(S[i]);
        Generate_Subsets_Helper(S,k-1,i+1,res);
        res.pop_back();
    }
}

void Generate_Subsets(const std::vector<int>& S,const int k)
{
    std::vector<int> res;
    Generate_Subsets_Helper(S,k,0,res);
}

int main(int argc,char** argv)
{
    if(argc!=3){
        std::cout<<"Usage: "<<argv[0]<<" <num> <k>"<<std::endl;
        return 1;
    }

    int num=atoi(argv[1]),k=atoi(argv[2]);
    std::vector<int> S;
    for(int i=1;i<=num;++i) S.push_back(i);

    Generate_Subsets(S,k);

    return 0;
}
