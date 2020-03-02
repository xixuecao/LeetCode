// 148_Sort_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* slow = head, * fast = head, * pre = head;
		while (fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
	}
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1), * cur = dummy;
		while (l1 && l2)
		{
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		return dummy->next;
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
