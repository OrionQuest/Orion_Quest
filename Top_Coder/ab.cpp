#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc,char** argv)
{
    if(argc!=3){
        std::cout<<"Usage: "<<argv[0]<<" <N> <k>"<<std::endl;
        return 1;
    }

    int N=atoi(argv[1]),k=atoi(argv[2]);
    std::vector<std::vector<bool> > f(N+1,std::vector<bool>(k+1,false));

    // base cases
    for(int i=0;i<=N;++i) f[i][0]=true;
    f[2][1]=true;

    // iteration
    for(int n=3;n<=N;++n){
        for(int t=1;t<=k;++t) if(t<=n*(n-1)/2){
            bool found=false;
            for(int j=1;j<=n;++j){          // search position for putting an A or a B
                // put an A in position j
                for(int r=0;r<=n-j;++r){    // r is the number of B's in front of j
                    for(int sum=0;sum<=(n-j-r)*r;++sum)
                        if(f[n-j][sum] && f[j-1][t-sum-r]){
                            found=true;
                            break;
                        }
                    if(found) break;
                }

                if(found) break;

                // put a B in position j
                for(int r=0;r<=j-1;++r){    // r is the number of A's behind j
                    for(int sum=0;sum<=(j-1-r)*r;++sum)
                        if(f[j-1][sum] && f[n-j][t-sum-r]){
                            found=true;
                            break;
                        }
                    if(found) break;
                }

                if(found) break;
            }
            if(found) f[n][t]=true;
        }
    }

    std::cout<<"A string is possible: "<<f[N][k]<<std::endl;
    return 0;
}
