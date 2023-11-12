class Graph {
private:
    vector<vector<int>>grid;
    int V;
public:
    Graph(int n, vector<vector<int>>& edges) {
        grid.resize(n);
        V=n;
        for(int i=0;i<n;i++){
            vector<int>v(n,-1);
            grid[i]=v;
        }
        for(int i=0;i<edges.size();i++){
            addEdge(edges[i]);
        }
    }
    
    void addEdge(vector<int> edge) {
        grid[edge[0]][edge[1]]=edge[2];
    }
    
    int shortestPath(int node1, int node2) {
            vector<int>dist(V,INT_MAX);
            dist[node1]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pair<int,int>p;
            p.first=0;p.second=node1;
            pq.push(p);
            while(!pq.empty()){
                pair<int,int>tp=pq.top();
                pq.pop();
                
                for(int i=0;i<V;i++){
                    if(grid[tp.second][i]!=-1){
                        if(dist[i]>(grid[tp.second][i]+tp.first)){
                            pair<int,int>np;
                            np.first=grid[tp.second][i]+tp.first;
                            np.second=i;
                            pq.push(np);
                            dist[i]=grid[tp.second][i]+tp.first;
                        }
                    }
                }
            }
            for(int i=0;i<V;i++){
                if(i==node2){if(dist[i]!=INT_MAX){return dist[i];}
                return -1;}
            };
            return 0;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */