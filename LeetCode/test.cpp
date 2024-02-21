//
// Created by xlu on 2023/8/11.
//
#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <stack>

void travelTree(TreeNode* root, std::vector<int>& res)
{
    if (root == nullptr)
        return;
    res.push_back(root->val);
    travelTree(root->left,res);
    travelTree(root->right,res);
}


/**
 * 迭代遍历
 * @param root
 * @return
 */
std::vector<int> travelTree2(TreeNode* root)
{
    std::vector<int> res;
    if (root == nullptr)
        return res;
    std::stack<TreeNode*> stack1;
    stack1.push(root);
    while (!stack1.empty())
    {
        TreeNode* node = stack1.top();
        if (node)
        {
            res.push_back(node->val);
            stack1.pop();
        }

        //FILO特性
        if(node->right != nullptr)
        {
            stack1.push(node->right);
        }
        if (node->left != nullptr)
        {
            stack1.push(node->left);
        }
    }
    return res;
}