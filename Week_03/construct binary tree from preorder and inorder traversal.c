/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int     i           = 0;
    int     iRootval    = 0;
    int     iLeftNum    = 0;
    int     iRightNum   = 0;
    struct TreeNode*     pTreeNode  = NULL;

    //1,结束条件
    if((0 == preorderSize) || (0 == inorderSize)) return NULL;

    //2,初始化
    pTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    iRootval = preorder[0];      //前序的第一个值是根节点

    //3,计算左支节点数，右支节点数
    for(i = 0; i < inorderSize; i++)
    {
        if(iRootval == inorder[i])  //中序是左->根->右
        {
            break;
        }
        iLeftNum += 1;
    }
    iRightNum = inorderSize - iLeftNum - 1;

    //4,递归处理左支、右支
    pTreeNode->val = iRootval;
    pTreeNode->left = buildTree(&preorder[1], iLeftNum, &inorder[0], iLeftNum);
    pTreeNode->right = buildTree(&preorder[1 + iLeftNum], iRightNum, &inorder[1 + iLeftNum], iRightNum);
    return pTreeNode;
}
