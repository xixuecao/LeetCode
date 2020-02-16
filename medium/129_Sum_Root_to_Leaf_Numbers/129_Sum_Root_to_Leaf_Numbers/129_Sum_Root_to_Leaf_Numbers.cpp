// 129_Sum_Root_to_Leaf_Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		/*
		if (!root) return 0;
		stack<TreeNode*> stk({ root });
		int res = 0;
		while (!stk.empty())
		{
			TreeNode* temp = stk.top(); stk.pop();
			if (temp->right)
			{
				temp->right->val += temp->val * 10;
				stk.push(temp->right);
			}
			if (temp->left)
			{
				temp->left->val += temp->val * 10;
				stk.push(temp->left);
			}
			if (!temp->left && !temp->right) res += temp->val;
		}
		return res;
		*/
		return help(root, 0);
	}
	int help(TreeNode* root, int sum) {
		if (!root) return 0;
		sum = sum *10 + root->val;
		if (!root->left && !root->right) return sum;
		return help(root->left, sum) + help(root->right, sum);
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
