﻿// 133_Clone_Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	/*
	Node* cloneGraph(Node* node) {
		unordered_map<Node*, Node*> m;
		return helper(node, m);
	}
	Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
		if (!node) return NULL;
		if (m.count(node)) return m[node];
		Node* clone = new Node(node->val);
		m[node] = clone;
		for (Node* neighbor:node->neighbors)
		{
			clone->neighbors.push_back(helper(neighbor, m));
		}
		return clone;
	}
	*/
	Node* cloneGraph(Node* node) {
		if (!node) return NULL;
		unordered_map<Node*, Node*> m;
		queue<Node*> q{ {node} };
		Node* clone = new Node(node->val);
		m[node] = clone;
		while (!q.empty())
		{
			Node* temp = q.front(); q.pop();
			for (Node* neighbor : temp->neighbors)
			{
				if (!m.count(neighbor)) {
					m[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}
				m[temp]->neighbors.push_back(m[neighbor]);
			}
		}
		return clone;
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
