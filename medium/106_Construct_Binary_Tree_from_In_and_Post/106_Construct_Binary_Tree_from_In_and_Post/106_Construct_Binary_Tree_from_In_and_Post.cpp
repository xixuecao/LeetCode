// 106_Construct_Binary_Tree_from_In_and_Post.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	TreeNode* buildTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
		if (il > ir || pl > pr) return NULL;
		int i = 0;
		for ( i = il; i <= ir; i++)
			if (postorder[pr] == inorder[i]) break;
		TreeNode* cur = new TreeNode(postorder[pr]);
		cur->left = buildTree(inorder, il, i - 1, postorder, pl, pl + i - il - 1);
		cur->right = buildTree(inorder, i + 1, ir, postorder, pl + i - il, pr - 1);
		return cur;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
