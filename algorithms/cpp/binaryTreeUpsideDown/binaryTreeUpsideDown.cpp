// Source : https://oj.leetcode.com/problems/binary-tree-upside-down/
// Author : Hao Chen
// Date   : 2014-11-17

/********************************************************************************** 
* Given a binary tree where all the right nodes are either leaf nodes with 
* a sibling (a left node that shares the same parent node) or empty, 
* 
* Flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. 
* Return the new root.
* 
* For example:
* Given a binary tree {1,2,3,4,5},
*     1
*    / \
*   2   3
*  / \
* 4   5
* return the root of the binary tree [4,5,2,#,#,3,1].
*    4
*   / \
*  5   2
*     / \
*    3   1  
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ. 
* 
**********************************************************************************/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        //using a dummy node to help to store the new tree      
        TreeNode dummy(0);
        TreeNode *head =  &dummy, *left=NULL, *right=NULL;

        while ( root!=NULL ) {
            //find the right & left
            left = root->right;
            right = root;
            
            //move root the next
            root = root->left;
            
            //replace the right with current root
            right->left = head->left;
            right->right = head->right;
            
            //move the dummy to the root
            dummy.right = right;
            dummy.left = left;
            
            //reset the head to the root
            head = &dummy;
    
        }
        
        return head->right;
    }
};

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        TreeNode *temp, *newRoot = NULL;
        temp = buildUpsideDownBT(root, newRoot);
        return newRoot;
    }
    
    TreeNode *buildUpsideDownBT(TreeNode *root, TreeNode *&newRoot) {
        if(!root) return root;
        if(!root->left && !root->right) {
            newRoot = root;
            return root;
        }
        TreeNode *parent = buildUpsideDownBT(root->left, newRoot);
        parent->left = root->right;
        parent->right = root;
        root->left = root->right = NULL;
        return parent->right;
    }
};

总结：
1. 这个递归的核心是，每次建立好一个新的子树后，要返回新子树的最右节点（ln 89)，以便上层的节点可以接回到这个节点的下面。
2. 但如果只返回最右节点，则我们无法知道最后整个新树的根在哪里。所以再base case里必须给新根赋值(ln 82)
3. 每次需要reset最右节点的left/right node，否则最后一层递归，递归到例子中的1节点时，返回前1节点的left/right node仍然为原来的值，而并不为NULL。
