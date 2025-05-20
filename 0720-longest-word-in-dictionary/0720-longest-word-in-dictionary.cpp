class Node{
    public:
    bool isEnd;
    vector<Node*>child;
    Node(){
        isEnd=false;
        child.resize(26,0);
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node;
    }
    bool insert(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->child[word[i]-'a']==NULL){
                temp->child[word[i]-'a']=new Node();
            }
           
            temp=temp->child[word[i]-'a'];
            if(i!=word.size()-1){
                if(temp->isEnd==false)return false;
            }
        }
        temp->isEnd=true;
        return true;
    }
};
class Solution {
public:
    
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string ans="";
        Trie obj;
        for(auto str:words){
            if(obj.insert(str)){
                if(ans.size()<str.size())ans=str;
                else if(ans.size()==str.size())ans=min(ans,str);
            }
        }
        return ans;
    }
};