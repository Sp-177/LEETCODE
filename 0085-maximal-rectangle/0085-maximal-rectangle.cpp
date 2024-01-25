class Solution {
public:
    int func(vector<int>&heights){
	 stack<int>dp;

        dp.push(0);
        int n=heights.size();
        int ans=0;
        for(int i=1;i<=n;i++){
            while(!dp.empty()){
                if(i!=n &&heights[i]==heights[dp.top()]){break;}
                if(i!=n && heights[i]>heights[dp.top()]){dp.push(i);break;}
                else{
                    int ci=dp.top();dp.pop();
                    int x;
                    if(dp.empty())x=i;
                    else x=i-dp.top()-1;
                    ans=max(ans,x*heights[ci]);
                }
            }
            dp.push(i);
        }
        return ans;
}

int maximalRectangle(vector<vector<char>> &matrix){
	int ans=0;
    int n=matrix.size();int m=matrix[0].size();
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(matrix[i][j]=='1')mat[i][j]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>=1 && mat[i][j]==1)mat[i][j]+=mat[i-1][j];
		}
		ans=max(ans,func(mat[i]));
	}
	return ans;
}
};