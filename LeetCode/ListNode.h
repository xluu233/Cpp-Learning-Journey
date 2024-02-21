//
// Created by xlu on 2023/4/6.
//

#ifndef CPPDEMO_LISTNODE_H
#define CPPDEMO_LISTNODE_H


/**
 * 链表节点
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



#endif //CPPDEMO_LISTNODE_H
