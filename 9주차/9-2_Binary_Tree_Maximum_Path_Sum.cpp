/*
	DFS
	Runtime: 16 ms ~ 24 ms (82.94% ~ 28.59%)
	Memory: 27.9 MB ~ 28 MB (32.19% ~ 29.3%)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	//https://withhamit.tistory.com/60
	//https://www.algodale.com/problems/binary-tree-maximum-path-sum/
	int maxSum = 0;
	int DFS(TreeNode* root) {
		if (root == NULL) return 0;
		// ���� �ڽ� ���� �������� ����, ������ ���� X
		int leftMax = max(DFS(root->left), 0);
		// ������ �ڽ� ���� �������� ����, ������ ���� X
		int rightMax = max(DFS(root->right), 0);

		// ���� ���� �θ� ��带 �������� ����
		maxSum = max(root->val + leftMax + rightMax, maxSum);
		// �����̳� ���� �ڽ� Ʈ���� ������ ����
		return root->val + max(leftMax, rightMax);
	}

	int maxPathSum(TreeNode* root) {
		maxSum = root->val;
		DFS(root);
		return maxSum;
	}
};