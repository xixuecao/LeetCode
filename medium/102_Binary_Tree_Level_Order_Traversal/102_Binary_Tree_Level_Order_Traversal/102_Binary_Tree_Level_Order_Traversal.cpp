// 102_Binary_Tree_Level_Order_Traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		/*
		if (!root) return {  };
		vector<vector<int>> res;
		queue<TreeNode*> q{ {root} };
		while (!q.empty())
		{
			vector<int> t;
			// cause the size of q is changing, we need to define q.size() first
			for (int i = q.size(); i > 0; i--) 
			{
				TreeNode* temp = q.front(); q.pop();
				t.push_back(temp->val);
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
			res.push_back(t);
		}
		return res;
		*/
		vector<vector<int>> res;
		levelOrder(root, 0, res);
		return res;

	}
	void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
		if (!root) return;
		if (level == res.size()) res.push_back({});
		res[level].push_back(root->val);
		if (root->left) levelOrder(root->left, level + 1, res);
		if (root->right) levelOrder(root->right, level + 1, res);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
