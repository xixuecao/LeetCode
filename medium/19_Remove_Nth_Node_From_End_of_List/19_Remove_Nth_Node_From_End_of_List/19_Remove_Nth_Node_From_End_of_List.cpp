// 19_Remove_Nth_Node_From_End_of_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) return NULL;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		int length = 0;
		ListNode* first = head;
		while (first)
		{
			length++;
			first = first->next;
		}
		length -= n;
		first = dummy;
		for (int i = 0; i < length; i++)
			first = first->next;

		first->next = first->next->next;
		return dummy->next;
	}

};

int main()
{
	Solution s;
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);


	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	ListNode* res = s.removeNthFromEnd(l1,1);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}

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
