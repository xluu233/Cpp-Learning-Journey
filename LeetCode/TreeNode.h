//
// Created by xlu on 2023/4/8.
//

#ifndef CPPDEMO_TREENODE_H
#define CPPDEMO_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //CPPDEMO_TREENODE_H
