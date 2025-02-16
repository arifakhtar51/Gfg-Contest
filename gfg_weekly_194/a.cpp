long long countPairs(vector<int>& arr) {
    // code here
   
    map<long long,long long>vis;
    long long ans=0;
    
    for(int i=0;i<arr.size();i++){
        // int comp=arr[i];
        string t=to_string(arr[i]);
        string comp=t;
        for(auto &c:t){
            c='9'-c+'0';
        }
        long long val=stoll(t);
       
        if(vis[val]){
            // cout<<arr[i]<<" ";
            ans+=vis[val];
        }
        vis[arr[i]]++;
    }
    return ans;
}