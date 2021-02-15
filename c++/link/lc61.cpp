//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *p = head;
        // ͳ�Ƴ���
        int len = 1;
        for(; p->next; p=p->next) len++;
        // ��β����
        p->next = head;
        // �ҵ��ϵ�
        k %= len;
        for(p = head; --len != k; p = p->next);
        // ������β
        head = p->next;
        p->next = NULL;
        return head;
    }
};
