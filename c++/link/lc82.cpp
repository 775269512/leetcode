class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			if (head==nullptr)
				return nullptr;
			ListNode* dummyNode = new ListNode(0,head);
			//���ظ�������ɾ�����൱�����ض�ֵ�Ľ�㣬��Ҫ��ǰ�����
			ListNode* pre = dummyNode;
			ListNode* cur = head;
			while(cur!=nullptr) {
				if(cur->next&&cur->val==cur->next->val) {
					pre->next=cur->next;
				} else {  //û�����ظ����
					pre = cur;   //ǰ���������ƶ�
				}
				cur = cur->next;  //������û�����ظ���㣬cur����һֱ��ǰ��
			}
			return dummyNode->next;
		}
};
