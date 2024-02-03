/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        TreeNode* pre = NULL;
        while(temp != NULL){
            if(key == temp->val){
                if(pre == NULL){
                    if(temp->left == NULL && temp->right == NULL)
                        return NULL;

                    if(temp->right != NULL){

                        root = temp->right;

                        if(temp->right->left != NULL){
                            TreeNode* leftNode = temp->right->left;
                            while(leftNode->left != NULL){
                                leftNode = leftNode->left;
                            }
                            leftNode->left = temp->left;
                        }else{
                            temp->right->left = temp->left;
                        }   
                    }else{
                        root = temp->left;
                    }    


                    return root;    
                }

                if(temp->right != NULL){
                    if(pre->val > temp->val){
                        pre->left = temp->right;
                        if(temp->right->left != NULL){
                            TreeNode* leftNode = temp->right->left;
                            while(leftNode->left != NULL){
                                leftNode = leftNode->left;
                            }
                            leftNode->left = temp->left;
                        }else{
                            temp->right->left = temp->left;
                        }
                    }else{
                        pre->right = temp->right;
                        if(temp->right->left != NULL){
                            TreeNode* leftNode = temp->right->left;
                            while(leftNode->left != NULL){
                                leftNode = leftNode->left;
                            }
                            leftNode->left = temp->left;
                        }else{
                            temp->right->left = temp->left;
                        }
                    }

                }else{
                    if(pre->val > temp->val){
                        pre->left = temp->left;
                    }else{
                        pre->right = temp->left;
                    }
                }
                return root;
            }

            if(key < temp->val){
                pre = temp;
                temp = temp->left;
            }
            else{
                pre = temp;
                temp = temp->right;
            }

        }

        return root;
    }
};