// 155_Min_Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stk1.push(x);
		if (stk2.empty() || x < stk2.top()) stk2.push(x);
	}

	void pop() {
		if (stk1.top() == stk2.top()) stk2.pop();
		stk1.pop();
	}

	int top() {
		return stk1.top();
	}

	int getMin() {
		return stk2.top();
	}
private:
	stack<int> stk1;
	stack<int> stk2;
	
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
	MinStack* minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	minStack->getMin();
	minStack->pop();
	minStack->top();
	minStack->getMin();

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
