// 117_Populating_Next_Right_Pointers_in_Each_Node_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		/*
		if (!root) return NULL;
		queue<Node*> q({ root });
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				Node* temp = q.front(); q.pop();
				if (i < size - 1) temp->next = q.front();
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
		}
		return root;
		*/
		if (!root) return NULL;
		Node* p = root->next;
		while (p)
		{
			if (p->left) {
				p = p->left; break;
			}
			if (p->right) {
				p = p->right; break;
			}
			p = p->next;
		}
		if (root->right) root->right->next = p;
		if (root->left) root->left->next = root->right ? root->right : p;
		connect(root->right);
		connect(root->left);
		return root;
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
