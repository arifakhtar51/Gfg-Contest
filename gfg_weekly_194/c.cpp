const int md=1e9+7;
  int solve(int n, int b, int c ){
      int len=2*b+1;
      vector<long long>prev(len+1,0LL);
      prev[b]=1;
      for(int s=1;s<=n;s++){
           vector<long long>curr(len+1,0LL);
           for(int k=0;k<len;k++){
               if(k-b==c||k-b==-c){
                   curr[k]=0;continue;
               }
               long long sm=0;
               if(k-1>=0){
                   sm=(sm+prev[k-1])%md;
               }
               if(k+1<len){
                   sm=(sm+prev[k+1])%md;
               }
               curr[k]=sm;
           }
           prev=curr;
      }
      return prev[b];
  }
  int solve2(int n,int b){
      int len=2*b+1;
      vector<long long>prev(len+1,0LL);
      prev[b]=1;
      for(int s=1;s<=n;s++){
           vector<long long>curr(len+1,0LL);
           for(int k=0;k<len;k++){
               if(k-1>=0){
                   curr[k]=(curr[k]+prev[k-1])%md;
               }
               if(k+1<len){
                   curr[k]=(curr[k]+prev[k+1])%md;
               }
           }
           prev=curr;
      }
      return prev[b];
  }
    int countWays(int n, int b, int c) {
        // code here
        if(n*2<c){
            return 0;
        }
        if( n%2!=0){
            return 0;
        }
        if(c>b)return 0;
        if(c==0){
            return solve2(n,b);
        }
        
        long x=solve2(n,b);
        long y=solve(n,b,c);
        long long ans=(x-y+md)%md;
        int md=1e9+7;
        return ans%md;
    }