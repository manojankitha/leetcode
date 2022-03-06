class MRUQueue {
public:
    
    class Node {
        public:
            int key;
            Node* prev;
            Node* next;
            Node(int _key){
                key = _key;
            }
      
    };
    
    int maxCap ;
    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    vector<Node*> indexNodeMap;

    MRUQueue(int n) {
        maxCap = n;
        head->next = tail;
        tail->prev = head;
        
        
        // MRUQueue initialize
        for(int i=1;i<=n;i++){
           
            addNode(i); 
            indexNodeMap.push_back(tail->prev);
        }
    }
    void removeNode(Node *delNode){
        Node *delNext = delNode->next;
        Node *delPrev = delNode->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        
    }
    
    void addNode(int key){
        // always add node to end
        Node * newNode = new Node(key);
        Node * temp = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;   
    }
    
    int fetch(int k) {
        int key = indexNodeMap[k-1]->key;   // k = 3, key = 3
        removeNode(indexNodeMap[k-1]);    // removes node at third position
        addNode(key);   // add a new node with the new key
        indexNodeMap.erase(indexNodeMap.begin()+(k-1));    // erase this element
        indexNodeMap.push_back(tail->prev);   // add new position of 
        
        return key;
        
        
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */