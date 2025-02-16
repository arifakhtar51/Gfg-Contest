int totalWays(int n) {
    // code here
    // return 2;
    if(n==0){
        return 1;
    }
    string str=bitset<32>(n).to_string();
    int cnt=0;
    for(auto c:str){
        if(c=='1')
        cnt+=1;
    }
    int j=-1;
    for(int i=0;i<32;i++){
        if(str[i]=='1'){
            j=i;break;
        }
    }
    if(cnt==31-j+1){
        return n+1;
    }
    int cnt2=0;
    for(int i=j+1;i<32;i++){
        if(str[i]=='0'){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<32;i++){
        if(str[i]=='1')
        cnt2+=1;
    }
   int pw=pow(2,cnt-1);
   int t1=pow(2,cnt2);
   int t2=pow(2,cnt-cnt2-1)-1;
   if(t2>0){
    //   cout<<"sad";
       return pw+t1*t2;
   }
   return pw;
}