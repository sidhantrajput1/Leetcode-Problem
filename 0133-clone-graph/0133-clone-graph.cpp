class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node) {

        for (Node* n : node->neighbors) {
            if (mp.find(n) == mp.end()) {

                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(n, clone);

            }
            else {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        mp.clear();

        // clone the given node
        Node* clone_node = new Node(node->val);

        // Now, clone its neighbour and recursively their neighbour
        // but if node reappears, then we need to access the clon node 
        // So store them in a map <Node*, Node*>

        mp[node] = clone_node;

        DFS(node, clone_node);

        return clone_node;
    }
};