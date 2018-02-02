#include<stdlib.h>
#include <iostream>

/*
比较两棵 树 是否相等 

这种简单的 迭代还是写的出来的


判断条件 p和q都为null 返回 false
		p,q 有一个为null 返回 false
		两个树相等的条件 节点值相等， 左子树 相等， 右子树相等

*/


/*
  Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL )return true;
        if(p==NULL||q==NULL)    return false;
        return p->val == q->val && isSameTree(p->right, q->right)&&isSameTree(p->left, q->left);
    }
};