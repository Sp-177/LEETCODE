class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int P=0,M=0,G=0;
        for(int i=garbage.size()-1;i>=0;i--){
            P+=count(garbage[i].begin(),garbage[i].end(),'P');
            G+=count(garbage[i].begin(),garbage[i].end(),'G');
            M+=count(garbage[i].begin(),garbage[i].end(),'M');
            if(i>0 ){
                if(G>0){G+=travel[i-1];}
                if(P>0){P+=travel[i-1];}
                if(M>0){M+=travel[i-1];}
            }
            
            
        }
        return P+M+G;
    }
};