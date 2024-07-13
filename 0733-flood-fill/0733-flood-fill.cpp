class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int org,vector<vector<int>>&visit){
        // cout<<sr<<sc<<endl;
        if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size()||image[sr][sc]!=org||visit[sr][sc]){return ;}
        visit[sr][sc]=1;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,color,org,visit);
        dfs(image,sr,sc+1,color,org,visit);
        dfs(image,sr,sc-1,color,org,visit);
        dfs(image,sr-1,sc,color,org,visit);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>visit(image.size(),vector<int>(image[0].size(),0));
        dfs(image,sr,sc,color,image[sr][sc],visit);
        return image;
    }
};