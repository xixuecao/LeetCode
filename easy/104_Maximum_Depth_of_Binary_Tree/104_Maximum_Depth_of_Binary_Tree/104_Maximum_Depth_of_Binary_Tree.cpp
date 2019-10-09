﻿// 104_Maximum_Depth_of_Binary_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	int maxDepth(TreeNode* root) {
		/*
		if (!root) return 0;
		int res = 0;
		queue<TreeNode*> q{{root}};
		while (!q.empty())
		{
			res++;
			for (int i = q.size(); i > 0; i--)
			{
				TreeNode* t = q.front(); q.pop();
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);

			}
		}
		return res;
		*/
		if (!root) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
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
