class Solution {
public:
    bool say(vector<int>&output,vector<vector<int>>&ans){
       for(auto i: ans){
            if(i.size()==output.size()){
                int x=0;
                for(int j=0;j<i.size();j++)if(output[j]==i[j])x++;

                if(x==i.size())return false;

            }
        }
        return true;
    }
    void func(vector<int>&candidates,int target,int index,vector<int>&output,vector<vector<int>>&ans){
        if(target==0){ans.push_back(output);return;}
        for(int j=index;j<candidates.size();j++){
                
                if(j>index&&candidates[j]==candidates[j-1])continue;
                if(candidates[j]>target)break;
                output.push_back(candidates[j]);
                func(candidates,target-candidates[j],j+1,output,ans);
                output.pop_back();
        
        }
      

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,output,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};