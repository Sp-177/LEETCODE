class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums){m[i]++;}
        int next=m.begin()->first;
        for(auto i:m){
            if(next!=i.first){
                break;
            }
            next++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second>1){
                for(int j=0;j<i.second-1;j++){
                    // cout<<i.first<<' '<<next<<endl;
                    while(true){
                        // cout<<next<<endl;
                        if(m[next]==0&&next>i.first){
                            m[next]++;
                            ans+=next-i.first;
                            break;
                        }
                        next++;
                       
                    }
                }
            }
        }
        return ans;
    }
};