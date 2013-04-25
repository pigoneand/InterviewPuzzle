/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
        if (!root || (!root->left && !root->right)) return;
        
        TreeLinkNode *nextRoot, *tailLeaf, *nextLevel;
        while (root) {
            
            // Get nextLevel and tailLeaf
            if (root->left) {
                nextLevel = root->left;
                root->left->next = root->right;
                tailLeaf = root->left;
                
                if (root->right) tailLeaf = root->right;
                
            } else if (root->right) {
                nextLevel = root->right;
                tailLeaf = root->right;
            } else {
                // When the current root node is a leaf, continue to find a nonLeaf root
                root = root->next;  
                continue;
            }
            
            // Connect the level
            nextRoot = root->next;
            
            while (nextRoot) {
                if (nextRoot->left) {
                    tailLeaf->next = nextRoot->left;
                    tailLeaf = tailLeaf->next;
                }
                
                if (nextRoot->right) {
                    tailLeaf->next = nextRoot->right;
                    tailLeaf = tailLeaf->next;
                }
                
                nextRoot = nextRoot->next;
            }
            
            // Goto next level
            root = nextLevel;
        }
    }
};