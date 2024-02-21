//
// Created by xlu on 2023/4/6.
//

#include "ListNode.h"


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* list = nullptr;
    ListNode* result = list;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val > list2->val){
            list->next = list2;
            list2 = list2->next;
        }
        else if (list2->val > list1->val){
            list->next = list1;
            list1 = list1->next;
        }
        list = list->next;
    }
    if(list1 != nullptr){
        list->next = list1;
    }
    if(list2 != nullptr){
        list->next = list2;
    }
    return result;
}