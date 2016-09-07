// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Hao Chen
// Date   : 2014-07-09

/********************************************************************************** 
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef vector<int>::iterator Iter;
TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
{
    if(istart == iend)return NULL;
    int rootval = *pstart;
    Iter iterroot = find(istart, iend, rootval);
    TreeNode *res = new TreeNode(rootval);
    res->left = buildTreeRecur(istart, iterroot, pstart+1, pstart+1+(iterroot-istart));
    res->right = buildTreeRecur(iterroot+1, iend, pstart+1+(iterroot-istart), pend);
    return res;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // write your code here
    return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
}

void printTree_pre_order(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%c ", root->val );

    printTree_pre_order(root->left);
    printTree_pre_order(root->right);
}

void printTree_in_order(TreeNode *root)
{
    if (root == NULL){
        printf("# ");
        return;
    }

    printTree_in_order(root->left);
    printf("%c ", root->val );
    printTree_in_order(root->right);
}


void printTree_level_order(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0){
        TreeNode* n = q.front();
        q.pop();
        if (n==NULL){
            printf("# ");
            continue;
        }
        printf("%c ", n->val);
        q.push(n->left);
        q.push(n->right);
    }
    printf("\n");
}


int main()
{
    int pre_order[]={'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H'};
    int  in_order[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    vector<int> preorder( pre_order, pre_order + 9 );
    vector<int>  inorder(  in_order,  in_order + 9 );

    TreeNode* tree = buildTree(preorder, inorder);

    printTree_level_order(tree);
    printTree_pre_order(tree);
    printf("\n");
    printTree_in_order(tree);
    printf("\n");
    
    return 0;
}
