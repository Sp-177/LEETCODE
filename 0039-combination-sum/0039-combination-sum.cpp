class Solution {
public:
    void func(vector<int>&candidates,int target,int index,vector<int>&output,vector<vector<int>>&ans){
        if(target==0){ans.push_back(output);return;}
        if(index>=candidates.size())return;
        if(candidates[index]<=target){
            output.push_back(candidates[index]);
            func(candidates,target-candidates[index],index,output,ans);
            output.pop_back();
        }
        func(candidates,target,index+1,output,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        func(candidates,target,0,output,ans);
        return ans;
    }
};