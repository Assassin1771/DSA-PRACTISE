class Node {
public:
    int key, val;
    Node *prev;
    Node *next;
    Node (int k, int v) {
        key = k, val = v;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    
    unordered_map<int, Node*> keyToAddress;
    Node *head, *tail;
    int currSize, maxSize;
    
    LRUCache(int capacity) 
    {
        head = tail = NULL;
        maxSize = capacity;
        currSize = 0; 
    }
    
    void moveToTail(Node* node, int value) 
    {
        node->val = value; 
    
        if (node == tail) 
            return;
        
        if (node == head) {
            head = head->next;
            head->prev = NULL;
        } else { // node in b/w;
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } 
        node->prev = tail;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    
    int get(int key) 
    {
        auto it = keyToAddress.find(key);
        if (it == keyToAddress.end()) return -1;
        
        Node* node = keyToAddress[key];
        moveToTail(node, node->val);
        
        return node->val;
    }
    
    void deleteAtHead() 
    {
        Node* tmp = head;
        head = head->next;
    
        if (head) head->prev = NULL;
        
        else tail = head; // head = NULL;
        
        delete(tmp);
        currSize--;
    }
    
    Node* addToTail(int key, int value) 
    {
        Node* newNode = new Node(key, value);
        if (currSize == 0) 
        {
            head = tail = newNode;
        }
        
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        
        currSize++;
        return newNode; 
    }
    
    void put(int key, int value) 
    {
        auto it = keyToAddress.find(key);
        if (it != keyToAddress.end()) 
        {
            moveToTail(keyToAddress[key], value); 
        }
        
        else
        {
            if (currSize < maxSize) 
            {
                keyToAddress[key] = addToTail(key, value);
            }
            
            else
            {
                keyToAddress.erase(head->key); // key is used to delete from map;
                deleteAtHead();
                keyToAddress[key] = addToTail(key, value);
            }
        }
    }
};
 
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */