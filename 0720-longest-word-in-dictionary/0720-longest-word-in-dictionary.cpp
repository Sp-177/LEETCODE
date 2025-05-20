class Node{
    public:
    bool isEnd;
    vector<Node*>child;
    char ch;
    Node(){
        isEnd=false;
        ch=0;
        child.resize(26,0);
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node;
    }
    void insert(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child[word[i]-'a']==NULL){
                temp->child[word[i]-'a']=new Node();
            }
           
            temp=temp->child[word[i]-'a'];
            temp->ch=word[i];
        }
        temp->isEnd=true;
        
    }
};
class Solution {
public:
    string dfs(Node* node,string str){
      
        if(node->isEnd==false)return "";
        string ans=str;
        for(char i='a';i<='z';i++){
            if(node->child[i-'a']==NULL)continue;
            string returned=dfs(node->child[i-'a'],str+i);
            ans=(ans.size()<returned.size())?returned:(ans.size()==returned.size())?min(returned,ans):ans;
        }
       
        return ans;
    }
    string longestWord(vector<string>& words) {
        
        string ans="";
        Trie obj;
        for(auto str:words){
           obj.insert(str);
        }
        Node* node=obj.root;
        for(char i='a';i<='z';i++){
            if(node->child[i-'a']==NULL)continue;
            string returned=dfs(node->child[i-'a'],string(1,i));
            ans=(ans.size()<returned.size())?returned:(ans.size()==returned.size())?min(returned,ans):ans;
        }
        return ans;
    }
};