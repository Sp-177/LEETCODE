class Solution {
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        sort(t.begin(),t.end());
        sort(w.begin(),w.end());
        int low=0,high=t.size();
        for(int i:t)cout<<i<<" ";
        cout<<endl;
        for(int i:w)cout<<i<<" ";
        cout<<endl;
        int m=w.size(),n=t.size();
        auto predicate_func=[&](int ans)->bool{
            int index=ans-1;
            int k=p;
            multiset<int>ms;
            for(int i=m-1;i>=max(0,m-ans);i--){
                ms.insert(w[i]);
            }
            for(int i=index;i>=0;i--){
                int req=t[i];
                auto it=ms.lower_bound(req);
                if(it !=ms.end()){
                    ms.erase(it);
                }
                else{
                    if(k<=0)return false;
                    auto it=ms.lower_bound(req-s);
                    if(it!=ms.end())ms.erase(it);
                    else return false;
                    k--;
                }
            }
            return true;
        };
        while(low<=high){
            int mid=(low+high)>>1;
            if(predicate_func(mid))low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};