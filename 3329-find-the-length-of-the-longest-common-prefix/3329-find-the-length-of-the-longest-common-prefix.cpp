class Node{
    public:
    Node* arr[10];
    bool is=true;
    Node(){
        for(int i=0;i<10;i++)arr[i]=NULL;
    }
    
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int x){
        string s=to_string(x);
        Node*  node=root;
        for(int i=0;i<s.size();i++){
            if(node->arr[s[i]-'0']==NULL){
                Node* newnode=new Node();
                node->arr[s[i]-'0']=newnode;
            }
            node=node->arr[s[i]-'0'];
        }
    }
    int search(int x){
        string s=to_string(x);
        Node* node=root;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(node->arr[s[i]-'0']==NULL)return ans;
            node=node->arr[s[i]-'0'];
            ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie *obj=new Trie();
        for(int i:arr2){
            obj->insert(i);
        }
        int ans=0;
        for(int i:arr1){
            ans=max(ans,obj->search(i));
        }
        return ans;
    }
};