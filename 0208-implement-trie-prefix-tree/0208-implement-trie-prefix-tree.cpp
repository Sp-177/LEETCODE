class Node{
public:
    bool isEnd;
    vector<Node*>child;
    Node(){
        isEnd=false;
        child.resize(26,NULL);
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(auto i:word){
            if(temp->child[i-'a']==NULL){
                temp->child[i-'a']=new Node();
            }
            temp=temp->child[i-'a'];
        }
        temp->isEnd=true;
        
    }
    
    bool search(string word) {
        Node* temp=root;
        for(auto i:word){
            if(temp->child[i-'a']==NULL){
                return false;
            }
            temp=temp->child[i-'a'];
        }
        return (temp->isEnd==true);
        
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(auto i:prefix){
            if(temp->child[i-'a']==NULL){
                return false;
            }
            temp=temp->child[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */