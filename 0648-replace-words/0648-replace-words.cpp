class Node{
    public:
    vector<Node*>arr;
    bool isEnd;
    Node(){isEnd=false;arr.resize(26,NULL);}
    bool isthere(char c){
        return (arr[c-'a']==NULL?false:true);
    }
    Node* give(char c){
        if(isthere(c)){
            return arr[c-'a'];
        }
        return NULL;
    }
    void put(Node* node,char c){
        arr[c-'a']=node;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(node->isthere(c)){
                node=node->give(c);
            }
            else{
                Node* new_node=new Node();
                node->arr[c-'a']=new_node;
                node=new_node;
            }
        }
        node->isEnd=true;
    }
    string search(string s){
        Node* node=root;
        string ans="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(node->isthere(c)){
                node=node->give(c);
                ans+=c;
                if(node->isEnd){return ans;}
            }
            else{
              return s;
            }
        }
        return ans;

    }
};
class Solution {
public:
    string replaceWords(vector<string>& dic, string sen) {
        Trie* obj=new Trie();
        for(auto i:dic){
            obj->insert(i);
        }
        string ans="";
        vector<string>v;
        sen+=' ';
        string small="";
        for(auto i:sen){
            if(i==' '){
                v.push_back(small);
                small="";
                continue;
            }
            small+=i;
        }
        for(auto i:v){
            ans+=obj->search(i)+" ";
            
        }
        return ans.substr(0,ans.size()-1);
        
    }
};