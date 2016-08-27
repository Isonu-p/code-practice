/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�����������ʱ��, ���ֻ������һ�Դ�С��ϵ����, �Ǿ�����Ի���
 //������������Դ���, �Ǿ��ǲ�����, �������ڵ㻥��
class Solution {
public:
TreeNode *p1, *p2;
void inorder(TreeNode *root, TreeNode *&previous) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, previous);
	if (previous != NULL &&previous->val >= root->val) {
		if (p1 == NULL) {
			p1 = previous;
			p2 = root;
		}else{
			p2 = root;
		}
	}
	previous = root;
	inorder(root->right, previous);
}
void recoverTree(TreeNode* root) {
	TreeNode* prev = NULL;
	inorder(root, prev);
	if (p1 != NULL&&p2 != NULL) {
		int tmp = p1->val;
		p1->val = p2->val;
		p2->val = tmp;
	}
}
};