//
// Created by xlu on 2023/4/8.
//
#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//前序遍历
void traversal(vector<int>& vector1,TreeNode* treeNode){
    if (treeNode == nullptr)
        return;
    vector1.push_back(treeNode->val);
    traversal(vector1,treeNode->left);
    traversal(vector1,treeNode->right);
}

//中序遍历
void traversal2(vector<int>& vector1,TreeNode* treeNode){
    if (treeNode == nullptr)
        return;
    traversal(vector1,treeNode->left);
    vector1.push_back(treeNode->val);
    traversal(vector1,treeNode->right);
}

//后序遍历
void traversal3(vector<int>& vector1,TreeNode* treeNode){
    if (treeNode == nullptr)
        return;
    traversal(vector1,treeNode->left);
    traversal(vector1,treeNode->right);
    vector1.push_back(treeNode->val);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vector1;
    traversal(vector1,root);
    return vector1;
}



//----------------------使用迭代实现----------------------

//前序遍历
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> vector1;
    if (root == nullptr)
        return vector1;
    stack<TreeNode*> stack1;
    stack1.push(root);
    while (!stack1.empty()){
        TreeNode* node = stack1.top();
        stack1.pop();
        vector1.push_back(node->val);

        //因为栈是FILO特性，先插入右节点
        if (node->right != nullptr)
            stack1.push(node->right);
        if (node->left != nullptr)
            stack1.push(node->left);

//        这里交换下顺序就是后序遍历
//        if (node->left != nullptr)
//            stack1.push(node->left);
//        if (node->right != nullptr)
//            stack1.push(node->right);

    }
    return vector1;
}

//中序遍历
vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> vector1;
    if (root == nullptr)
        return vector1;
    stack<TreeNode*> stack1;
    TreeNode* cur = root;
    while (cur != nullptr || !stack1.empty()){
        if (cur != nullptr){
            stack1.push(cur);
            cur = cur->left;
        } else {
            cur = stack1.top();
            stack1.pop();
            vector1.push_back(cur->val);    //中节点
            cur = cur->right;   //右
        }
    }
    return vector1;
}


//后序遍历
vector<int> postorderTraversal2(TreeNode* root) {
    vector<int> vector1;
    if (root == nullptr)
        return vector1;
    stack<TreeNode*> stack1;
    stack1.push(root);
    while (!stack1.empty()){
        TreeNode* node = stack1.top();
        stack1.pop();
        vector1.push_back(node->val);
        if (node->left != nullptr)
            stack1.push(node->left);
        if (node->right != nullptr)
            stack1.push(node->right);
    }
    return vector1;
}


//二叉树层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> que;
    if (root != nullptr)
        que.push(root);
    while (!que.empty()){
        //当前层数的数量
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            vec.push_back(node->val);
            que.pop();

            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        //新增一层
        result.push_back(vec);
        //result.insert(result.begin(),vec);
    }
    return result;
}

//二叉树翻转
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}