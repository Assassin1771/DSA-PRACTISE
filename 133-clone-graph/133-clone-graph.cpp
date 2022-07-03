/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return NULL;
        
        Node* clone =new Node(node->val,{});
        visited[node]=clone;
        
        queue<Node*> q;
        q.push(node);
        
        while(q.size())
        {
            Node* curr=q.front();
            q.pop();
            
            for(auto i:curr->neighbors)
            {
                if(visited.find(i)==visited.end())
                {
                    visited[i]=new Node(i->val,{});
                    q.push(i);
                }
                
                visited[curr]->neighbors.push_back(visited[i]);
            }
        }
        
        return clone;
        
    }
};