#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

void printInorder(Node *node)
{
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node *node)
{
    if (node == nullptr)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void levelOrderBfs(Node *node)
{
    if (node == nullptr)
        return;

    queue<Node *> q;
    vector<vector<int>> ans;

    q.push(node);
    int curLevel = 0;
    while (!q.empty())
    {
        int len = q.size();
        ans.push_back({}); // dynamically adding a 1d vector in which we'll insert now
        for (int i = 0; i < len; i++)
        {
            Node *node = q.front();
            q.pop();
            ans[curLevel].push_back(node->data);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        curLevel++;
    }
    for(auto v: ans){
        for(auto it:v){
            cout<<it<<" ";
        }cout<<endl;
    }

}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    printInorder(root);
    cout << endl;
    printPreorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;
    levelOrderBfs(root);

    return 0;
}