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
   
    int maxXor(int num,Node* node){
        int Xor=0;
        for(int i=31;i>=0;i--){
            int mask=1<<i;
            int bit=(num&mask)!=0?1:0;
            if(node->child[bit^1]){
                Xor<<=1;
                Xor++;
                node=node->child[bit^1];

            }else{
                Xor<<=1;
                node=node->child[bit];
            }
        }
        return Xor;
    }
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        for(int i:nums)obj.insert(i);
        int ans=0;
        for(int i:nums)ans=max(ans,maxXor(i,obj.root));
        return ans;

    }
};