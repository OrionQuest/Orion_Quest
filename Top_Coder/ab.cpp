#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

class ABPairs
{
  public:
    ABPairs(const int N_input,const int k_input)
        :N(N_input),k(k_input),f(N+1,std::vector<std::vector<bool> >(k+1,std::vector<bool>())),
        example(N+1,std::vector<std::vector<std::string> >(k+1,std::vector<std::string>()))
    {
        for(int n=0;n<=N;++n) for(int t=0;t<=k;++t){
            f[n][t]=std::vector<bool>(n+1,false);
            example[n][t]=std::vector<std::string>(n+1,"");
        }
    }

    std::pair<bool,std::string> operator()(const int n,const int t,const int r)
    {
        assert(n>=0 && n<=N);
        assert(t>=0 && t<=k);
        assert(r>=0 && r<=n);
        return std::pair<bool,std::string>(f[n][t][r],example[n][t][r]);
    }

    void Initialize_Base_Cases()
    {
        for(int n=0;n<=N;++n) for(int r=0;r<=n;++r){
            f[n][0][r]=true;
            for(int s=0;s<r;++s) example[n][0][r]+="B";
            for(int s=r;s<n;++s) example[n][0][r]+="A";
        }

        if(k>=1){
            f[2][1][1]=true;example[2][1][1]="AB";
        }
    }

    void Iterate()
    {
        for(int n=3;n<=N;++n) for(int t=1;t<=k;++t) if(t<=n*n/4){
            for(int r=1;r<n;++r){           // only consider number of B's between 1 and n-1
                bool found_A=false,found_B=false;
                int pos=-1,total=-1,count=-1;
                for(int j=1;j<=n;++j){      // search position for putting an A or a B

                    // put an A in position j
                    int max_Bs_ahead=std::min(r,n-j),min_Bs_ahead=std::max(0,r-j+1);
                    for(int s=min_Bs_ahead;s<=max_Bs_ahead;++s){    // s is the number of B's in front of j
                        for(int sum=0;sum<=(n-j-s)*s;++sum) if(t>=sum+s)
                            if(f[n-j][sum][s] && f[j-1][t-sum-s][r-s]){
                                found_A=true;
                                pos=j;
                                count=s;
                                total=sum;
                                break;
                            }
                        if(found_A) break;
                    }
                    if(found_A) break;

                    /*
                    // put a B in position j
                    int max_As_behind=std::min(n-r,j-1),min_As_behind=std::max(r-j,0);
                    for(int s=min_As_behind;s<=max_As_behind;++s){
                        for(int sum=0;sum<=s*(j-1-s);++sum)
                            if(f[j-1][sum][j-1-s] && f[n-j][t-sum-s][r-j+s]){
                                found_B=true;
                                pos=j;
                                count=s;
                                total=sum;
                                break;
                            }
                        if(found_B) break;
                    }
                    if(found_B) break;
                    */
                }

                if(found_A || found_B) f[n][t][r]=true;
                if(found_A) example[n][t][r]=example[pos-1][t-total-count][r-count]+"A"+example[n-pos][total][count];
                if(found_B) example[n][t][r]=example[pos-1][total][pos-1-count]+"B"+example[n-pos][t-total-count][r-pos+count];
            }
        }
    }

    const int N;
    const int k;
    // first index is the number of characters
    // second index is the total number of AB pairs
    // third index is the number of B's present
    std::vector<std::vector<std::vector<bool> > > f;
    std::vector<std::vector<std::vector<std::string> > > example;
};

int main(int argc,char** argv)
{
    if(argc!=3){
        std::cout<<"Usage: "<<argv[0]<<" <N> <k>"<<std::endl;
        return 1;
    }

    int N=atoi(argv[1]),k=atoi(argv[2]);
    ABPairs ab_pairs(N,k);

    ab_pairs.Initialize_Base_Cases();
    ab_pairs.Iterate();

    int count=-1;
    std::pair<bool,std::string> outcome;
    for(int r=1;r<N;++r){
        outcome=ab_pairs(N,k,r);
        if(outcome.first){
            count=r;
            break;
        }
    }

    if(count!=-1) std::cout<<outcome.second<<std::endl;
    else std::cout<<""<<std::endl;

    return 0;
}
