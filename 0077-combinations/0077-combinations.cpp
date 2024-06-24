class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        long loop=pow(2,n)-1;
        vector<vector<int>>ans;
        for(int i=0;i<=loop;i++){
           
            if(__builtin_popcount(i)==k){
                long index=1;
                vector<int>o;
                int j=i;
                while(j>0){
                    // cout<<index<<':'<<j<<endl;
                    if(j&1){o.push_back(index);}
                    index++;
                    j=j>>1;
                }
                ans.push_back(o);
            }
        }
        return ans;

    }
};