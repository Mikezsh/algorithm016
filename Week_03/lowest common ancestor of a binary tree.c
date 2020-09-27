/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == p || root == q || root  == NULL)
        return root;
    struct TreeNode *left = lowestCommonAncestor(root -> left,p,q);
    struct TreeNode *right = lowestCommonAncestor(root -> right,p,q);
    
    if(NULL != left && NULL != right)     //left and right both have one
        return root;
    
    return NULL == left ? right:left;
    
        
}