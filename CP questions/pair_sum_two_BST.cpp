/**
 * Find a pair with given sum in a two different Balanced BST
 * Time complexity - O(n + m)
 * Space complexity - O(n + m)
 * Link: https://www.youtube.com/watch?v=D1Tv5cCs1d8
 * */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};
struct Node {

    Node* next;
    Node* prev;
    int val;

    Node(int val)
        : val(val)
        , prev(NULL)
        , next(NULL)
    {
    }
};

bool flag;
unordered_map<int, bool> mp;

void recurse(struct TreeNode* node1, TreeNode* node2, int& sum)
{
    if (node1 == NULL || node2 == NULL || mp.count(node1->val) > 0 || mp.count(node2->val) > 0 || flag)
        return;

    recurse(node1->left, node2, sum);
    recurse(node1, node2->right, sum);

    int curr_sum = node1->val + node2->val;

    if (curr_sum == sum) {
        cout << node1->val << ", " << node2->val;
        flag = true;
    }
    else if (curr_sum < sum) {
        mp[node1->val] = 1;
        recurse(node1->right, node2, sum);
    }
    else {
        mp[node2->val] = 1;
        recurse(node1, node2->left, sum);
    }
};

int main()
{
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(17);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(11);
    root1->right->right = new TreeNode(19);

    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(13);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(7);

    int sum = 12;
    recurse(root1, root2, sum);
}
