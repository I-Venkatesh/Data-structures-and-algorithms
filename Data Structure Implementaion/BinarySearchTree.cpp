using namespace std;
#include <bits/stdc++.h>
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *createBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode();
    int mid = (start + end) / 2;
    root->val = arr[mid];
    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);
    return root;
}
void printInorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";

    printInorder(root->right);
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *root = createBST(arr, 0, 9);
    printInorder(root);
}