struct Node{
    bool is_end;
    vector<Node*>child;
    Node(){
        is_end=false;
        child.resize(26);
    }
};
struct Trie{
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string str){
        Node* temp_root=root;
        for(auto i:str){
            if(temp_root->child[i-'a']==NULL){
                temp_root->child[i-'a']=new Node();
            }
            
            temp_root=temp_root->child[i-'a'];
            
            
        }
        
        temp_root->is_end=true;
        return ;
    }

};

class Solution {
public:
    Trie obj;
    set<string>st;
    vector<vector<int>>visit;
    void dfs(Node*root,int i,int j,int n,int m,vector<vector<char>>&board,string str){
        
        if(i<0||j<0||i>=n||j>=m|| visit[i][j]==1||(root->child[board[i][j]-'a']==NULL))return ;
        // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
        // cout<<str+board[i][j]<<endl;
        if(root->child[board[i][j]-'a']&&root->child[board[i][j]-'a']->is_end==true)st.insert(str+board[i][j]);
        visit[i][j]=1;
        dfs(root->child[board[i][j]-'a'],i+1,j,n,m,board,str+board[i][j]);
        dfs(root->child[board[i][j]-'a'],i-1,j,n,m,board,str+board[i][j]);
        dfs(root->child[board[i][j]-'a'],i,j+1,n,m,board,str+board[i][j]);
        dfs(root->child[board[i][j]-'a'],i,j-1,n,m,board,str+board[i][j]);
        visit[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto i:words)obj.insert(i);
        int n=board.size(),m=board[0].size();
        visit.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)dfs(obj.root,i,j,n,m,board,"");
        }
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};