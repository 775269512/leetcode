#include<bits/stdc++.h>
#include<string>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
����������������[left, right]�е�һ��i����Ҫ������iΪ���ڵ��BST���������¹��ɣ�

i��ߵ����п�����Ϊ��������㣬������ӿ����ж����������vector<TreeNode *> left_nodes = generate(left, i - 1);��
i�ұߵ����п�����Ϊ��������㣬ͬ��������vector<TreeNode *> right_nodes = generate(i + 1, right);��
�������Ե�ǰiΪ������BST���ӣ�����left_nodes.size() * right_nodes.size()��������ÿ�����������������iΪ���ڵ��BST���У�
Ȼ����forѭ��ʹ��[left, right]��ÿ����㶼�������������С�
**/

class Solution {
	public:
		vector<TreeNode *> generateTrees(int n) {
			if (n) return generate(1, n);
			else return vector<TreeNode *> {};
		}

		vector<TreeNode *> generate(int left, int right) {
			vector<TreeNode *> ans;
			if (left > right) {
				ans.push_back(nullptr);
				return ans;
			}
			for (int i = left; i <= right; i++) {
				vector<TreeNode *> left_nodes = generate(left, i - 1);
				vector<TreeNode *> right_nodes = generate(i + 1, right);
				for (TreeNode *left_node : left_nodes) {
					for (TreeNode *right_node : right_nodes) {
						TreeNode *t = new TreeNode(i);
						t->left = left_node;
						t->right = right_node;
						ans.push_back(t);
					}
				}
			}
			return ans;
		}
};

int main() {
	return 0;
}
