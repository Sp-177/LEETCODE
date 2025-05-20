class Node{
    public:
    vector<Node*>child;
    int num;
    Node(){child.resize(2,NULL);num=0;}
};
class Trie{
    public:
    Node* root;
    Trie(){root=new Node();}
    void insert(int number){
        // cout<<number<<endl;
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int mask=1<<i;
            int bit=(number&mask)!=0?1:0;
            // cout<<bit<<endl;
            if(temp->child[bit]==NULL){
                temp->child[bit]=new Node();
            }
            temp=temp->child[bit];
        }
        temp->num=number;
    }
    
} ;
class Solution {
public:
    int ans=0;
    void maxXor(Node*left,Node*right){
        if(left==NULL || right==NULL)return;
        if(left->child[0]==NULL&&left->child[1]==NULL){
            ans=max(ans,left->num^right->num);
            return;
        }
        if(left->child[1]&&right->child[0]||left->child[0]&&right->child[1]){
            maxXor(left->child[0],right->child[1]);
            maxXor(left->child[1],right->child[0]);
        return;
        }
         maxXor(left->child[0],right->child[0]);
          maxXor(left->child[1],right->child[1]);

        
    }
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        for(int i:nums)obj.insert(i);
        maxXor(obj.root,obj.root);
        return ans;
    }
};