class AB
{
    AB(final int N_input,final int k_input)
    {
        N=N_input;
        k=k_input;
        f=new boolean[N+1][k+1][0];
        example=new String[N+1][k+1][0];

        for(int n=0;n<=N;++n) for(int t=0;t<=k;++t){
            f[n][t]=new boolean[n+1];
            example[n][t]=new String[n+1];
        }
    }

    String Create_String(final int n,final int t)
    {
        String result="";
        for(int r=1;r<N;++r) if(f[n][t][r])
            return example[n][t][r];
        return result;
    }

    void Initialize_Base_Cases()
    {
        for(int n=0;n<=N;++n) for(int r=0;r<=n;++r){
            f[n][0][r]=true;
            example[n][0][r]="";
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
                boolean found_A=false,found_B=false;
                int pos=-1,total=-1,count=-1;
                for(int j=1;j<=n;++j){      // search position for putting an A or a B

                    // put an A in position j
                    int max_Bs_ahead=Math.min(r,n-j),min_Bs_ahead=Math.max(0,r-j+1);
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
                }

                if(found_A || found_B) f[n][t][r]=true;
                if(found_A) example[n][t][r]=example[pos-1][t-total-count][r-count]+"A"+example[n-pos][total][count];
                if(found_B) example[n][t][r]=example[pos-1][total][pos-1-count]+"B"+example[n-pos][t-total-count][r-pos+count];
            }
        }
    }

    final int N;
    final int k;
    boolean f[][][];
    String example[][][];
}

class ABDemo
{
    public static void main(String args[])
    {
        if(args.length!=2){
            System.out.println("Usage: java ABDemo <N> <k>");
            return;
        }

        int N=Integer.parseInt(args[0]),k=Integer.parseInt(args[1]);

        AB ab=new AB(N,k);
        ab.Initialize_Base_Cases();
        ab.Iterate();

        System.out.println(ab.Create_String(N,k));
    }
}
