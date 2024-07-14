class Ds{
    public:
    vector<int>parent,size;
    Ds(int comp){
        parent.resize(comp);
        size.resize(comp,1);
        for(int i=0;i<comp;i++){parent[i]=i;}
    }
    int ultimate_par(int node){
        if(parent[node]==node){return node;}
        return parent[node]=ultimate_par(parent[node]);
    }
    void dsuS(int n1,int n2){
        int p1=ultimate_par(n1),p2=ultimate_par(n2);
        int s1=size[p1],s2=size[p2];
        if(p1!=p2){
            if(s1>=s2){
                size[p1]+=size[p2];
                parent[p2]=p1;
                parent[n2]=p1;
            }
            else{
                size[p2]+=size[p1];
                parent[p1]=p2;
                parent[n1]=p2;
            }
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int comp=n*m;
        vector<vector<int>>coord;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    coord.push_back({i,j});
                }
            }
        }
        Ds *obj=new Ds(comp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int n1=i*m+j;
                    if(i+1<n&&grid[i+1][j]){int n2=(i+1)*m+j;obj->dsuS(n1,n2);}
                    if(j+1<m&&grid[i][j+1]){int n2=(i)*m+j+1;obj->dsuS(n1,n2);}
                }
            }
        }
        
        int ans=0;
        // for(int i=0;i<comp;i++){
        //     cout<<obj->parent[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=0;i<comp;i++){
        //     cout<<obj->size[i]<<' ';
        // }
        for(auto i:obj->size){
            ans=max(ans,i);
        }
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto i:coord){
            int x=i[0],y=i[1];
            int sum=0;
            set<int>s;
            for(auto j:dir){
                int x1=x+j[0],y1=y+j[1];
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&grid[x1][y1]){
                    int par_node=obj->ultimate_par(x1*m+y1);
                    s.insert(par_node);
                }
            }
            for(auto j:s){
                // cout<<j<<endl;
                sum+=obj->size[j];
            }
            ans=max(ans,sum+1);
        }
        return ans;
    }
};