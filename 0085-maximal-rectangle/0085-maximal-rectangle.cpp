class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<int>row(m,0);
        auto func=[&]()->int{
            int area=0;
            // for(int i:row)cout<<i<<" ";
            // cout<<endl;
            stack<int>st;
            for(int i=0;i<=m;i++){
                int num=i==m?0:row[i];
                while(st.size() && row[st.top()]>=num){
                    int ind=st.top();
                    int h=ind==m?0:row[ind];
                    st.pop();
                    int  w=0;
                    if(st.size()==0)w=i;
                    else w=i-st.top()-1;
                    area=max(area,h*w);
                }
                st.push(i);
            }
            // cout<<area<<endl;
            return area;
        };
    
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')row[j]=0;
                else row[j]+=matrix[i][j]-'0';
            }
             ans=max(ans,func());
            
        }
        return ans;
    }
};