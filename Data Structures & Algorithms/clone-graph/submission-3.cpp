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
    Node* cloneGraph(Node* node) 
    {
        if(!node) return node;
        unordered_map<Node* , Node*> mp;
        queue<Node*> q; 
        Node* clone = new Node(node->val);
        mp[node] = clone;
        q.push(node);
        while(!q.empty())
        {
            int level = q.size();
            for(int i = 0 ; i < level ; i++)
            {
                Node* t1 = q.front(); // fix unnecessary Inner Loop traversal (first for loop) 
                q.pop();
                for(int j = 0 ; j < t1->neighbors.size() ; j++)
                {
                    if(!mp.contains(t1->neighbors[j])) 
                    {
                        q.push(t1->neighbors[j]);
                        Node* temp = new Node(t1->neighbors[j]->val);
                        mp[t1->neighbors[j]] = temp;
                    }
                    mp[t1]->neighbors.push_back(mp[t1->neighbors[j]]); // magic 
                }
            }
        }
        return clone;
    }
};
