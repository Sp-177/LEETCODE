class Solution {
public:
    bool bfs(queue<int>&q,vector<vector<int>> &edges,vector<int>&colored,int n){
		while(!q.empty()){
		int node=q.front();
		q.pop();
		for(int i:edges[node]){
				if(colored[i]==abs(colored[node]-1)||colored[i]==-1){
					if(colored[i]==-1){
						colored[i]=abs(colored[node]-1);
						q.push(i);
					}
				}
				else return false;
			
		}
	}
	return true;
}
bool isBipartite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<int>colored(n,-1);
	
	bool ans=true;
        for (int i = 0; i < n; i++) {
		queue<int>q;
                if (colored[i] == -1) {
                        q.push(i);
                        colored[i] = 0;
                        ans &= bfs(q, edges, colored, n);
                }
                if (!ans)
                        return false;
        }

    return ans;
}
};