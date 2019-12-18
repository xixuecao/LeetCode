﻿// 43_Multiply_Strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int m = num1.size(), n = num2.size();
		string res;
		vector<int> v(m + n);
		for (int i = m - 1; i >= 0; i--)
		{
			int a = num1[i] - '0';
			for (int j = n - 1; j >= 0; j--)
			{
				int b = num2[j] - '0';
				int p = i + j, q = i + j + 1, sum = (a * b + v[q]);
				v[p] += sum / 10;
				v[q] = sum % 10;
			}
		}
		for (auto i : v)
			if (!res.empty() || i != 0) res.push_back(i + '0');
		return res.empty() ? "0" : res;
	}
};

int main()
{
	Solution sol;
	string num1 = "123", num2 = "456";
	cout << sol.multiply(num1, num2) << endl;
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
