class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         vector<int>ans(2);
    vector<vector<int>>v;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<nums[i].size();j++){
            v.push_back({nums[i][j],i});
        }
    }
    sort(v.begin(),v.end());
    // for(auto i:v)cout<<i[0]<<' '<<i[1]<<endl;
    unordered_map<int,int>s;
    
    int range=INT_MAX;
    int i=v[0][1],j=0;
    int first=0,end=0;
    while(j<v.size()){
        s[v[j][1]]++;
        end=j;
        if(s.size()==n){
            while(s.size()==n){
            int r=v[end][0]-v[first][0]+1;
            if(range>r){
                range=r;
                ans[0]=v[first][0];
                ans[1]=v[end][0];
            }
            i=v[first][1];
            s[i]--;
            first++;
            if(s[i]==0)s.erase(i);}
            
        }
        
        j++;
    }
    return ans;
    }
};