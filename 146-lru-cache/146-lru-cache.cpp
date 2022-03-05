class LRUCache {
    public:
        class Node {
            public:
                int key;
                int val;
                Node *prev;
                Node *next;

                Node(int _key,int _val){
                    key=_key;
                    val=_val;
                }
        };
    
    //DLL
        Node *head=new Node(-1,-1);
        Node *tail=new Node(-1,-1);

        int maxCap;   // store max capacity of cache
        unordered_map<int,Node*> cache;  // store cache {key,Node address}
   
    

        LRUCache(int capacity) {
            maxCap = capacity;
            head->next=tail;
            tail->prev=head;  
        }

        void addNode(Node *newNode){
            Node * temp = head->next;
            head->next=newNode;
            newNode->prev = head;
            temp->prev = newNode;
            newNode->next = temp;


        }

        void removeNode(Node *delNode){
            Node* delNext = delNode->next;
            Node* delPrev = delNode->prev;
            delPrev->next = delNext;
            delNext->prev = delPrev;

        }

        int get(int key){
            if (cache.find(key)!=cache.end()) {
                // key present
                Node * temp = cache[key];

                int res = temp->val;
                
                cache.erase(key);
                removeNode(temp);
                addNode(temp);   
                cache[key]=head->next;
                return res;
            }  
            return -1;
        }

        void put(int key, int value){
            if(cache.find(key)!=cache.end()){
                // key already present, so delete it
                Node *delNode = cache[key];
                cache.erase(key);
                removeNode(delNode);

            }
            if (cache.size()==maxCap){
                 cache.erase(tail->prev->key);
                removeNode(tail->prev);
               
            }



            Node *newNode = new Node(key,value);

            addNode(newNode);
            cache[key] = head->next;




        }
};





/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */