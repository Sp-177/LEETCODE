class Node{
    public:
    vector<Node*>child;
    int prefixSum;
    bool isEnd;
    int value;
    Node(){
        isEnd=false;
        prefixSum=0;
        value=0;
        child.resize(26,NULL);
    }
};
class MapSum {
public:
    Node* root;
    MapSum() {
        root=new Node();
    }
    pair<bool,int> search(string key){
        Node* temp=root;
        for(char c:key){
            if(temp->child[c-'a']==NULL){
               return {0,0};
            }
            temp=temp->child[c-'a'];
            
        }
        return {1,temp->value};
    }
    void insert(string key, int val) {
        auto p=search(key);
        int val1=val;
        if(p.first==1){
            val1=val-p.second;
        }
        Node* temp=root;
        for(char c:key){
            if(temp->child[c-'a']==NULL){
                temp->child[c-'a']=new Node();
            }
            temp=temp->child[c-'a'];
            temp->prefixSum+=val1;
        }
        temp->value=val;
        temp->isEnd=true;
    }
    
    int sum(string prefix) {
         Node* temp=root;
        for(char c:prefix){
            if(temp->child[c-'a']==NULL){
               return 0;
            }
            temp=temp->child[c-'a'];
            
        }
        return temp->prefixSum;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */