// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example,
* Given
* 
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* 
* The flattened tree should look like:
* 
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
* 
* 
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to 
* the next node of a pre-order traversal.
*
* * Solution - Non-Recursion, No Stack
* * We can also solve the problem even without a stack:
* * Each time when we prune a right subtree, we use while-loop to find the right-most leaf of the current left subtree, 
* * and append the subtree there.
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
    void flatten(TreeNode *root) {
        TreeNode cur = root;  
        while (cur != null) {  
            if (cur.left != null) {  
                if (cur.right != null) { // if we need to prune a right subtree
                    TreeNode next = cur.left;  
                    while (next.right != null) next = next.right;  
                    next.right = cur.right;  
                }
                cur.right = cur.left;  
                cur.left = null;  
            }  
            cur = cur.right;  
        }
    }
};
