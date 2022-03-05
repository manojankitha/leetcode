class LRUCache {
    public:
        class Node {
            public:
                int key;
                int val;
                Node * prev;
                Node * next;
                
                // constructor
            Node(int _key,int _val) {
                key=_key;
                val=_val;
            }
        };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int maxCap;
    unordered_map<int,Node*> cache;
    
    LRUCache(int capacity) {
        maxCap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void removeNode(Node* delNode) {
        Node* delNext = delNode->next;
        Node* delPrev = delNode->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    void addNode(Node* newNode) {
        Node * temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    int get(int key) {
        if (cache.find(key)!=cache.end()){
            // item present in cache
            Node *temp = cache[key];
            cache.erase(key);
            int res = temp->val;
            removeNode(temp);
            addNode(temp);
            cache[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key,int value) {
         if(cache.find(key)!=cache.end()){
             Node * temp =cache[key];
             cache.erase(key);
             removeNode(temp);
         }
        if(cache.size()==maxCap){
            // evict here
            Node * delNode = tail->prev;
            cache.erase(delNode->key);
            removeNode(delNode);
        }
        Node * newNode = new Node(key,value);
        addNode(newNode);
        cache[key]= head->next;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */