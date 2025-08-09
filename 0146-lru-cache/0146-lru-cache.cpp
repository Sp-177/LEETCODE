class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int Max, Curr;
    unordered_map<int, Node*> keyNode;
    Node* Head;
    Node* Tail;

    void remove(int key) {
        Node* node = keyNode[key];
        Node* p = node->prev;
        Node* n = node->next;

        // Update neighbors before deleting node!
        if(!p && !n){
            Head=nullptr;
            Tail=nullptr;
        }
        else if (!p) {
            // node is Head
            Head = n;
            if (n) n->prev = nullptr;
        }
        else if (!n) {
            // node is Tail
            Tail = p;
            if (p) p->next = nullptr;
        }
        else {
            p->next = n;
            n->prev = p;
        }

        keyNode.erase(key);
        delete node;
        Curr--;
    }

    void addToFront(int key, int value) {
        if (keyNode.count(key)) {
            remove(key);
        }
        else if (Curr == Max && Tail) {
            remove(Tail->key);
        }

        Node* newHead = new Node(key, value);
        newHead->next = Head;
        newHead->prev = nullptr;
        if (Head) Head->prev = newHead;
        Head = newHead;

        if (!Tail) Tail = newHead; // empty list before

        keyNode[key] = newHead;
        Curr++;
    }

    LRUCache(int c) {
        Max = c;
        Curr = 0;
        Head = nullptr;
        Tail = nullptr;
    }

    int get(int key) {
        
        if (keyNode.count(key) == 0) return -1;
        int value = keyNode[key]->val;
        addToFront(key, value);
        return value;
    }

    void put(int key, int value) {
        
        addToFront(key, value);
    }
};
