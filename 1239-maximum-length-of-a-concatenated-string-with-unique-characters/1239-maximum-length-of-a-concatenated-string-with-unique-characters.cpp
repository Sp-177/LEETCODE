class Solution {
public:
    int func(vector<string>&arr,int i,unordered_set<char>&s){
        if(i==arr.size())return s.size();
       // cout<<arr[i]<<endl;
                int ans_1=func(arr,i+1,s);

              
        for(int j=0;j<arr[i].size();j++){
            if(s.count(arr[i][j])!=0){
                for(int k=0;k<j;k++){
                    s.erase(arr[i][k]);
                }
                return ans_1;
            }
           // cout<<arr[i][j]<<endl;
           else s.insert(arr[i][j]);
        }
         int ans=s.size();

        for(int j=i+1;j<arr.size();j++){
            int x=func(arr,j,s);
            if(ans<x){ans=x;}
        }
        for(auto j:arr[i]){
            s.erase(j);
        }
        //cout<<ans<<ans_1<<endl;
        return max(ans,ans_1);

    }
    int maxLength(vector<string>& arr) {
        unordered_set<char>s;
        return func(arr,0,s);
    }
};