// 142_Linked_List_Cycle_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* last = head;
		while (fast && fast->next) {
			last = last->next;
			fast = fast->next->next;
			if (last == fast) break;
		}
		if (!fast || !fast->next) return NULL;
		last = head;
		while (last != fast)
		{
			last = last->next;
			fast = fast->next;
		}
		return fast;
		/*
		快指针每次走2，慢指针每次走1，快指针走的距离是慢指针的两倍。
		而快指针又比慢指针多走了一圈。所以 head 到环的起点+环的起点到他们相遇的点的距离
		与环一圈的距离相等。现在重新开始，head 运行到环起点和相遇点到环起点 
		的距离也是相等的，相当于他们同时减掉了环的起点到他们相遇的点的距离
		*/
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
