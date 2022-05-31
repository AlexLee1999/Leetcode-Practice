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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        queue<Node*> myQueue;
        unordered_map<Node*, Node*> myMap;
        myMap[node] = new Node(node->val); 
        myQueue.push(node);
        while (!myQueue.empty()) {
            Node* tmp = myQueue.front();
            myQueue.pop();
            vector<Node*> neighbors_list = tmp->neighbors;
            for (int i=0; i<neighbors_list.size(); ++i) {
                if (myMap.find(neighbors_list[i]) == myMap.end()) {
                    myQueue.push(neighbors_list[i]);
                    Node* new_neighbor = new Node(neighbors_list[i]->val, vector<Node*>());
                    myMap[neighbors_list[i]] = new_neighbor;
                }
                myMap[tmp]->neighbors.push_back(myMap[neighbors_list[i]]);
            }
        }
        return myMap[node];
    }
};