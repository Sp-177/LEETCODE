class Solution {
public:
    long long sol(int n,int m,int rooks,vector<vector<int>>&board, vector<vector<pair<int,int>>>&b,unordered_map<int,int>&m_r,unordered_map<int,int>&m_c,int row){
        
        if(rooks==0)return 0;
        long long ans=INT_MIN;
        for(int i=row;i<=n-rooks;i++){
            for(int j=0;j<m;j++){
                int x=b[i][j].first;
                int y=b[i][j].second;
                if(m_r[x]==0&&m_c[y]==0){
                    m_r[x]=1;
                    m_c[y]=1;
                    // cout<<x<<y<<endl;
                ans=max(ans,board[x][y]+sol(n,m,rooks-1,board,b,m_r,m_c,row+1));
                m_r[x]=0;
                    m_c[y]=0;
                
                }
            }
        }
        return ans;    }
    long long maximumValueSum(vector<vector<int>>& board) {
         vector<vector<pair<int,int>>>b(board.size());
        for(int i=0;i<board.size();i++){
            priority_queue<pair<int,pair<int,int>>>pq;
            for(int j=0;j<board[0].size();j++){
                pq.push({board[i][j],{i,j}});
            }
            for(int j=0;j<3;j++){
                // cout<<pq.top().first<<endl;
                b[i].push_back(pq.top().second);
                pq.pop();
            }
            
        }
        
        int n=b.size();
        int m=b[0].size();
        unordered_map<int,int>m_r,m_c;
        long long ans=LLONG_MIN;
        for(int i=0;i<n-2;i++){
            for(int r1=0;r1<3;r1++){
            for(int j=i+1;j<n-1;j++){
                for(int r2=0;r2<3;r2++){
                for(int k=j+1;k<n;k++){
                    for(int r3=0;r3<3;r3++){
                        int y1=b[i][r1].second,y2=b[j][r2].second,y3=b[k][r3].second;
                        if(y1!=y2&&y2!=y3&&y3!=y1){
                            long long sum=1LL*board[i][y1]+1LL*board[j][y2]+1LL*board[k][y3];
                            ans=max(ans,sum);
                        }
                    }
                }}
            }
            }
        }
        return ans;
    }
};