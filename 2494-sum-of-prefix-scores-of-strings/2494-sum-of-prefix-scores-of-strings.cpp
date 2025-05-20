 class Node{
    public:
    unordered_map<int,Node*>child; 
    int Sum;
    Node(){
        Sum=0;
    }
 };

 class Trie{
     public:
     Node* root;
     Trie(){root=new Node();}
     void insert(string word){
        Node *temp=root;
        for(auto i:word){
            if(temp->child[i-'a']==NULL){
                temp->child[i-'a']=new Node();
            }
             temp=temp->child[i-'a'];
             temp->Sum+=1;
        }
     }
     int score(string word){
        Node *temp=root;
        int sum=0;
        for(auto i:word){
            if(temp->child[i-'a']==NULL){
                return sum;
            }
             temp=temp->child[i-'a'];
             sum+=temp->Sum;
        }
         return sum;
     }
 } ;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie obj;
        for(auto i:words)obj.insert(i);
        vector<int>ans;
        for(auto i:words)ans.push_back(obj.score(i));
        return ans;
    }
};