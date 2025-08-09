class Solution {
public:
    int calcArea(vector<int>&h){
        int n=h.size();
        stack<int>s1,s2;
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++){
            while(s1.size()&& h[s1.top()]>=h[i])s1.pop();
            l[i]=(s1.size())?s1.top():-1;
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(s2.size()&& h[s2.top()]>=h[i])s2.pop();
            r[i]=(s2.size())?s2.top():n;
            s2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i-l[i];
            int right=r[i]-i;
            int area=(left+right-1)*h[i];
            ans=max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>vec(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')vec[j]=0;
                else vec[j]++;
            }
            ans=max(ans,calcArea(vec));
        }
        return ans;
    }
};