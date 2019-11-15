// 234_Palindrome_Linked_List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	bool isPalindrome(ListNode* head) {
		/*
		// wrong
		if (!head) return true;
		ListNode* fhead = head;
		ListNode* rhead = reverse(head);
		while (fhead)
		{
			if (fhead->val != rhead->val) return false;
			fhead = fhead->next;
			rhead = rhead->next;
		}
		return true;
		*/
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		// if fast != nullptr, list has old numbers
		if (fast) slow = slow->next;
		slow = reverse(slow);
		while (slow) {
			if (slow->val != head->val) return false;
			slow = slow->next;
			head = head->next;
		}
		return true;
	}
	ListNode* reverse(ListNode* head) {
		if (!head) return NULL;
		ListNode* res = NULL;
		ListNode* curr = head;
		while (curr)
		{
			ListNode* temp = curr->next;
			curr->next = res;
			res = curr;
			curr = temp;
		}
		return res;
	}
};

int main()
{
	ListNode* h1 = new ListNode(1);
	ListNode* h2 = new ListNode(1);
	ListNode* h3 = new ListNode(2);
	ListNode* h4 = new ListNode(1);

	h1->next = h2; h2->next = h3; h3->next = h4;

	Solution s;
	ListNode* res = s.reverse(h1);

	cout << "h1:" << endl;
	while (h1)
	{
		cout << h1->val << " ";
		h1 = h1->next;
	}
	cout << endl;

	cout << "res:" << endl;
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl << s.isPalindrome(h1);
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
