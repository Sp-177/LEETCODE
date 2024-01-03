class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,prev=-1,last=0;
        for(int i=bank.size()-1;i>=0;i--){
            int curr=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){curr++;}
            }
            if(curr!=0){ans+=last*curr;last=curr;}
            
        }
        return ans;
    }
};