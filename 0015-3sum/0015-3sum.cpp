class Solution {
    private:
    int count(int x,vector<int>&nums,int say,int limit){
        int l=x;
        int c=0;
        while(nums[l]==nums[x] ){
            c++;
            if(say==-1){x--;
            if(x<limit){break;}}
            else{x++;if(x>limit){break;}}
        }
        return c;
    }
    vector<vector<int>>pairSum(vector<int>&nums,int j,int k,int Sum,int a){
        vector<vector<int>>ans;
        while(j<k){
            vector<int>v(3);
            if(nums[j]+nums[k]==Sum){
                if(nums[j]==nums[k]){
                    v[0]=a;
                    v[1]=nums[j];
                    v[2]=nums[j];
                    ans.push_back(v);
                    break;
                }
                else{
                    int x=count(j,nums,1,k);
                    int y=count(k,nums,-1,j);
                    v[0]=a;
                    v[1]=nums[j];
                    v[2]=nums[k];
                    j=j+x;
                    k=k-y;
                    ans.push_back(v);
                }
            }
            else if(nums[j]+nums[k]>Sum){k--;}
            else{j++;}
        }return ans;
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int k=nums.size()-1;
        vector<vector<int>>ans;
        while(i<j &&i<k &&j<k){
           int n=count(i,nums,1,k);
            vector<vector<int>>temp=pairSum(nums,j,k,-1*nums[i],nums[i]);
            ans.insert(ans.end(),temp.begin(),temp.end());
            i=i+n;
            j=i+1;
        }
        return ans;
        
    }
};