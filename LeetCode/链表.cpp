//
// Created by xlu on 2023/4/9.
//
#include <iostream>
#include <string>
#include "ListNode.h"

using namespace std;

/*------------------------------------------*/

//删除链表元素
ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val)
        head = head->next;

    if (head == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast){
        if (fast->val == val){
            slow->next = fast->next;
            fast = slow->next;
        } else {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return head;
}

ListNode* removeElements2(ListNode* head, int val){
    if (head == nullptr)
        return head;
    head->next = removeElements2(head->next,val);
    return head->val == val ? head->next : head;
}

/*------------------------------------------*/

/**
 * 递归翻转链表
 * @param head
 * @return
 */
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}


/**
 * 迭代翻转链表
 * @param head
 * @return
 */
ListNode* reverseList2(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

/*------------------------------------------*/

ListNode* findLastNode(ListNode* head,int n){
    ListNode* p1 = head;
    ListNode* p2 = head;

    for (int i = 0; i < n; ++i) {
        p1 = p1->next;
    }

    while (p1 != nullptr){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
//    ListNode* node(-1);
//    ListNode* node = new ListNode(-1);
//    node->next = head;
    ListNode* lastN = findLastNode(head,n+1);
    lastN->next = lastN->next->next;
    return head;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (p1 != p2){
        p1 = p1 == nullptr ? headB : p1->next;
        p2 = p2 == nullptr ? headA : p2->next;
    }
    return p1;
}

bool hasCycle(ListNode *head) {
    if (!head)
        return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}


void reverse(std::string& s,int l, int r) {
    int size = s.size();
    if (l > r || r > size)
        return;
    int i = l ;
    int j = r;
    for (; i < (r-l)/2; ++i,--j) {
        std::swap(s[i],s[j]);
    }
}

std::string reverseStr(std::string s, int k) {
    for (int i = 0; i < s.size()-1; ) {
        i += 2*k;
        reverse(s,i-k,i);
    }
    return s;
}


string addStrings(string num1, string num2) {
    int p1 = num1.size()-1;
    int p2 = num2.size()-1;
    string res = "";
    int i = 0;
    while (p1 >= 0 || p2 >= 0 || i != 0){
        int sum = i;
        if (p1 >= 0){
            sum += num1[p1]- '0';
            p1--;
        }
        if (p2 >= 0){
            sum += num2[p2]- '0';
            p2--;
        }
        i = sum / 10;
        res.insert(res.begin(),'0'+sum%10);
    }
    return res;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    int add = 0;
    ListNode* tmp = new ListNode(-1);
    ListNode* res = tmp;
    while (p1 || p2 || add != 0){
        int i = p1 ? p1->val : 0;
        int j = p2 ? p2->val : 0;
        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;

        int sum = i + j + add;
        add = sum / 10;
        tmp->next = new ListNode(sum%10);
        tmp = tmp->next;
    }
    return res->next;
}

int numDecodings(string s) {
    if (s.size() <= 1){
        return 1;
    }

}

int main(){
    string s1 = "123";
    string s2 = "123";
    cout << addStrings(s1,s2) << endl;
}