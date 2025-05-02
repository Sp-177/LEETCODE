class Solution {
public:
    string pushDominoes(string d) {
        vector<int>ind;
        ind.push_back(0);
        for(int i=0;i<d.size();i++){
            if(d[i]=='L'|| d[i]=='R')ind.push_back(i);
        }
        ind.push_back(d.size()-1);
        vector<char>ans(d.size(),'.');
        for(int i=0;i<ind.size()-1;i++){
            int ind1=ind[i],ind2=ind[i+1];
            ans[ind1]=d[ind1];
            ans[ind2]=d[ind2];
            
            if((d[ind1]=='.'&&d[ind2]=='L')||(d[ind1]==d[ind2])){
                for(int j=ind1;j<=ind2;j++)ans[j]=d[ind2];
            }
            else if((d[ind2]=='.'&&d[ind1]=='R')||(d[ind1]==d[ind2])){
                for(int j=ind1;j<=ind2;j++)ans[j]=d[ind1];
            }
            else if(d[ind1]=='R' && d[ind2]=='L'){
                int diff=(ind2-ind1+1)/2;
                int cnt1=diff,cnt2=diff;
                for(int j=ind1;cnt1>0;j++){ans[j]=d[ind1];cnt1--;}
                for(int j=ind2;cnt2>0;j--){ans[j]=d[ind2];cnt2--;}
                
                
            }

        }
        string str="";
        for(auto i:ans){
            str+=i;
        }
        return str;
    }
};