/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int max = 1;
    int maxDepth(Node* root, int depth = 1) {
        if(root == NULL){
            return 0;
        }
        if( root->children.size() == 0 ){
            return depth;
        }

        for(int i=0;i<root->children.size();i++){
            int d = maxDepth(root->children[i] , depth + 1);
            
            if(d  > max) max = d;
        }

        return max;
    }
};