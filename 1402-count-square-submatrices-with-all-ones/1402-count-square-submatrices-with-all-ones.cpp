class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>ps(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            ps[i][0]=matrix[i][0];
            for(int j=1;j<m;j++){
                ps[i][j]=ps[i][j-1]+matrix[i][j];
            }   
        }
        int ans=0;
        for(auto i:ps){for(int j:i)cout<<j<<" "; cout<<endl;}
        for(int i=1;i<=min(n,m);i++){
            int window=i;
            for(int k=window-1;k<m;k++){
               int cnt=0;
                for(int j=0;j<n;j++){
                    int sum=ps[j][k]-(((k-window)<0)?0:ps[j][k-window]);
                    if(sum>=window){
                        cnt++;
                        if(cnt>=window)ans++;
                    }
                    else cnt=0;
                }
                
            }
        }
        return ans;
    }
};