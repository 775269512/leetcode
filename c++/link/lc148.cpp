/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	public:
		ListNode* sortList(ListNode* head) {
			return sortList(head, nullptr);
		}

		ListNode* sortList(ListNode* head, ListNode* tail) {
			if(head==tail) return head;
			if(head->next==tail) {
				head->next = nullptr;//��һ����next����nullptr�Ǳ���ģ�
				//��Ϊ����ںϲ���ʱ���Ǹ���nullptr�������ж����������ģ�
				//Ҫ�ǲ���nullptr�Ļ�����һֱ���������������ʼ�������������Ƿ��εõ�������������
				return head;
			}
			ListNode *f=head,*s=head;
			while(f!=tail) {
				f=f->next;
				s=s->next;
				if(f!=tail) f=f->next;
			}

			return merge(sortList(head, s), sortList(s, tail));
		}

		ListNode* merge(ListNode* head1, ListNode* head2) {
			ListNode* dummyHead = new ListNode(0);
			ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
			while (temp1 != nullptr && temp2 != nullptr) {
				if (temp1->val <= temp2->val) {
					temp->next = temp1;
					temp1 = temp1->next;
				} else {
					temp->next = temp2;
					temp2 = temp2->next;
				}
				temp = temp->next;
				if (temp1 != nullptr) {
					temp->next = temp1;
				} else if (temp2 != nullptr) {
					temp->next = temp2;
				}

			}
			return dummyHead->next;
		}
};