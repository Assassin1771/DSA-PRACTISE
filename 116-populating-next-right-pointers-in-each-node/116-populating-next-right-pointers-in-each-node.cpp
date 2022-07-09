//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/1654181/C%2B%2BPythonJava-Simple-Solution-w-Images-and-Explanation-or-BFS-%2B-DFS-%2B-O(1)-Optimized-BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(q.size())
        {   
            Node* right=NULL;
            int count=q.size();
            
            for(int i=0;i<count;i++)
            {
                Node* curr=q.front();
                q.pop();
                
                curr->next=right;
                right=curr;
                
                if(curr->right)
                {
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }
        }
        
        return root;
        
    }
};