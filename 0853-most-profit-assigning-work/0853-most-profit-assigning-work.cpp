class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& profit, vector<int>& worker) {
       map<int,int>v;
       for(int i=0;i<profit.size();i++){
        v[dif[i]]=max(v[dif[i]],profit[i]);
       }
       sort(dif.begin(),dif.end());
        int ans=0;
        vector<int>pre(dif.size());
        pre[0]=v[dif[0]];
        for(int i=1;i<dif.size();i++){
            pre[i]=max(pre[i-1],v[dif[i]]);
        }
        for(int i:worker){
            cout<<i<<" : ";
            int index=upper_bound(dif.begin(),dif.end(),i)-dif.begin();
            cout<<index<<" : ";
            if(index>=dif.size()||dif[index]>i){
                ans+=index!=0?pre[index-1]:0;
            }
            else{ans+=pre[index];}
            cout<<ans<<endl;

        }
        return ans;
    }
};