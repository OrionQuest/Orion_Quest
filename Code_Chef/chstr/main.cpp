#include <cstring>
#include <iostream>
#include <map>
#include <vector>

int choose(int n,int k)
{
    if(k==0) return 1;
    return (int)(n%(int)(1e9+7)*choose(n-1,k-1))/k;
}

int main()
{
    int number_of_test_cases=0;
    std::cin>>number_of_test_cases;

    for(int test=0;test<number_of_test_cases;++test){
        int N,Q;
        std::cin>>N>>Q;
        std::vector<int> q(Q,0);
        std::string query_string;
        std::cin>>query_string;
        for(int i=0;i<Q;++i) std::cin>>q[i];

        //std::cout<<"N: "<<N<<", Q: "<<Q<<std::endl;
        //std::cout<<"String: "<<query_string<<std::endl;
        //std::cout<<"Q:";
        //for(int i=0;i<Q;++i) std::cout<<" "<<q[i];
        //std::cout<<std::endl;

        // create data structure
        std::vector<std::map<std::string,int> > occurences(query_string.size()+1);
        for(int i=1;i<=query_string.size();++i){
            for(int j=0;j<=query_string.size()-i;++j){
                std::string key=query_string.substr(j,i);
                if(occurences[i].find(key)==occurences[i].end()) occurences[i][key]=1;
                else ++occurences[i][key];
            }
        }

        /*
        // output data structure
        std::cout<<"Occurences:"<<std::endl;
        for(int i=0;i<occurences.size();++i){
            std::cout<<i<<":";
            for(std::map<std::string,int>::iterator it=occurences[i].begin();it!=occurences[i].end();++it) std::cout<<" ("<<it->first<<","<<it->second<<")";
            std::cout<<std::endl;
        }
        */

        for(int t=0;t<Q;++t){int k=q[t],sum=0;
            for(int i=0;i<occurences.size();++i){
                for(std::map<std::string,int>::iterator it=occurences[i].begin();it!=occurences[i].end();++it){
                    if(it->second >= k) sum+=choose(it->second,k);
                }
            }
            std::cout<<sum<<std::endl;
        }
    }

    return 0;
}
