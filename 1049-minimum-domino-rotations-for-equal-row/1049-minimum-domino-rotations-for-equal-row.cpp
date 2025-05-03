class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int ans=INT_MAX;
        int n=t.size();
        for(int i=1;i<=6;i++){
            int rot=0;
            bool did=true;
            for(int j=0;j<n;j++){
                if(t[j]!=i && b[j]!=i){did=false;break;}
                if(b[j]==i&&t[j]!=i)rot++;
            }
            if(did)ans=min(ans,rot);
            rot=0,did=true;
             for(int j=0;j<n;j++){
                if(t[j]!=i && b[j]!=i){did=false;break;}
                if(t[j]==i&&b[j]!=i)rot++;
            }
            if(did)ans=min(ans,rot);
        }
        return (ans==INT_MAX?-1:ans);
    }
};