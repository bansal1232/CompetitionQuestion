#include<bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Node
{

    Node*next;
    Node*prev;
    int val;

    Node(int val):val(val), prev(NULL), next(NULL){    }
};

void inorder_iterative(TreeNode*node)
{
    if(node == NULL)
        return;
    stack<TreeNode*> st;
    st.push(node);
    while(!st.empty())
    {
        TreeNode* curr = st.top();
        while(curr->left)
        {
            st.push(curr->left);
            curr=curr->left;
        }
        while(!st.empty())
        {
            TreeNode*temp = st.top();
            cout << temp->val << " ";
            st.pop();
            if(temp->right)
            {
                st.push(temp->right);
                break;
            }
        }
    }
    cout<<"\n";
}


void pre_order_iterative(TreeNode*node)
{
    if(node == NULL)
        return;

    stack<TreeNode*> st;
    st.push(node);
    while(!st.empty())
    {
        TreeNode* curr = st.top();
        while(curr)
        {
            cout << curr->val << " ";
            if(curr->left == NULL)
                break;
            st.push(curr->left);
            curr=curr->left;
        }
        while(!st.empty())
        {
            TreeNode*temp = st.top();
            st.pop();
            if(temp->right)
            {
                st.push(temp->right);
                break;
            }
        }

    }
    cout<<"\n";
}

void post_order_iterative(TreeNode*node)
{
    if(node == NULL)
        return;

    stack<TreeNode*> st;
    do
    {
        while(node)
        {
            if(node->right)
                st.push(node->right);
            st.push(node);
            node=node->left;
        }

        node = st.top();
        st.pop();

        if(node->right && !st.empty() && node->right == st.top())
        {
            st.pop();
            st.push(node);
            node=node->right;
        }
        else
        {
            cout << node->val << " ";
            node = NULL;
        }
    } while(!st.empty());

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
    pre_order_iterative(root);
    inorder_iterative(root);
    post_order_iterative(root);
}
