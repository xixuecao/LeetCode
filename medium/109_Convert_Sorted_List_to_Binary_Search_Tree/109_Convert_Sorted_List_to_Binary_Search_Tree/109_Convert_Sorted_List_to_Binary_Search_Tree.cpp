// 109_Convert_Sorted_List_to_Binary_Search_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		vector<int> vi;
		while (head)
		{
			vi.push_back(head->val);
			head = head->next;
		}
		return sortedListToBST(vi, 0, vi.size());
	}
	TreeNode* sortedListToBST(vector<int> vi, int beg, int end) {
		while (beg >= end) return NULL;
		int mid = beg + (end - beg) / 2;
		TreeNode* res = new TreeNode(vi[mid]);
		res->left = sortedListToBST(vi, beg, mid);
		res->right = sortedListToBST(vi, mid+1, end);
		return res;
	}
};

int main()
{

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
