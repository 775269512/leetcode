s#include<string>
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    }
    
    // ��תһ�����������ҷ����µ�ͷ��β
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }
};
