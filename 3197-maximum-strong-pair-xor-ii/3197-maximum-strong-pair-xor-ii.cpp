class Node {
public:
    vector<Node*> child;
    Node() { child.resize(2, NULL); }
};

class Trie {
public:
    Node* root;
    
    Trie() { 
        root = new Node(); 
    }
    
    // Destructor to free all allocated memory
    ~Trie() {
        deleteNode(root);
    }
    
    // Helper function to recursively delete all nodes
    void deleteNode(Node* node) {
        if (node == NULL) return;
        
        for (int i = 0; i < 2; i++) {
            if (node->child[i] != NULL) {
                deleteNode(node->child[i]);
            }
        }
        
        delete node;
    }
    
    void insert(int num) {
        Node* temp = root;
        for(int i = 19; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(temp->child[bit] == NULL) temp->child[bit] = new Node();
            temp = temp->child[bit];
        }
    }
    
    bool Erase(Node* &node, int num, int ind) {
        if(node == NULL) return false;
        
        if(ind == -1) {
            return true;
        }
        
        int bit = (num >> ind) & 1;
        bool shouldDeleteChild = Erase(node->child[bit], num, ind - 1);
        
        if(shouldDeleteChild) {
            delete node->child[bit];
            node->child[bit] = NULL;
            
            // Check if this node can be deleted (both children are NULL)
            if(node != root && node->child[0] == NULL && node->child[1] == NULL) {
                // Free up all memory before returning
                delete node;
                node = NULL;
                return true;
            }
        }
        
        return false;
    }
    
    int maxXor(int num) {
        Node* temp = root;
        int res = 0;
        for(int i = 19; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(temp->child[bit ^ 1]) {
                res = (res << 1) | 1;
                temp = temp->child[bit ^ 1];
            }
            else {
                res = res << 1;
                temp = temp->child[bit];
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        Trie obj;
        int j = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int y = nums[i];
            
            // Insert all valid numbers for current y (nums[i])
            while(j < nums.size() && nums[j] <= 2 * y) {
                obj.insert(nums[j]);
                j++;
            }
            
            // Calculate max XOR for current y
            if(obj.root->child[0] != NULL || obj.root->child[1] != NULL) {
                ans = max(ans, obj.maxXor(y));
            }
            
            // Remove current number from trie before moving to next
            obj.Erase(obj.root, y, 19);
        }
        
        return ans;
    }
    
    ~Solution() {
        // Destructor is automatically called when the Solution object goes out of scope
    }
};