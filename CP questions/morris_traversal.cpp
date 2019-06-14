#include<bits/stdc++.h>
using namespace std;

struct Node
{

    Node*next;
    Node*prev;
    int val;

    Node(int val):val(val), prev(NULL), next(NULL){    }
};

void morris_preoder_traversal(TreeNode*root)
{
	struct TreeNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {
        printf("%d ", current->val);

		if (current->left == NULL) {
                current = current->right;

		}
		else {

			pre = current->left;
			if(pre->right){
			while ((pre->right != NULL && pre->right != current->right) || pre->left)
            {
                if(pre->right)
                    pre=pre->right;
                else
                    pre=pre->left;
            }
			}
            if(pre->right == NULL)
            {
                pre->right = current->right;
                current=current->left;
            }
            else
            {
                pre->right = NULL;
                current=current->right;
            }


			}

		}

}
int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \      \
    4     5      6
         /      /
        7      8
       /
      9
*/
    TreeNode * root =new  TreeNode(1);
    root->left =new TreeNode(2);

    root->right = new TreeNode(3);
    root->left->left =new TreeNode(4);
    root->left->right =new TreeNode(5);
    root->left->right->left = new TreeNode(7);

    root->left->right->left->left = new TreeNode(9);
    root->right->right =new TreeNode(6);
    root->right->right->left =new TreeNode(8);
    morris_preoder_traversal(root);
}
