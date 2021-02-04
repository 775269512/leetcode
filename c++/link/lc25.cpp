s#include<string>
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
 ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // �鿴ʣ�ಿ�ֳ����Ƿ���ڵ��� k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // ������ C++17 ��д����Ҳ����д��
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // �����������½ӻ�ԭ����
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }

    
    // ��תһ�����������ҷ����µ�ͷ��β
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* pre = nullptr;
    	ListNode* now = head;
    	while(now!=nullptr){
    		ListNode* next = now->next;
    		now->next=pre;
    		pre = now;
    		now = next;
		}
        return {tail, head};
    }
};
