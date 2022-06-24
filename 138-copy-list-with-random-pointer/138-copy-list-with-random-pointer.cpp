/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
         return NULL;
        
        unordered_map<Node*, Node*> hm;
        
        Node* temp=head;
        while(temp)
        {
            hm[temp]=new Node(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        
        while(temp)
        {
            Node* clone=hm[temp];
            clone->next=hm[temp->next];
            clone->random=hm[temp->random];
            
            temp=temp->next;
        }
        
        return hm[head];
        
    }
};