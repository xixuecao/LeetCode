﻿// 74_Search_a_2D_Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		vector<int> tv;
		for (int i = 0; i < m; i++)
		{
			if (target <= matrix[i][n - 1])
			{
				tv = matrix[i];
				break;
			}
		}

		if (tv.empty()) return false;
		int beg = 0, end = n;
		while (beg <= end)
		{
			int mid = beg + (end - beg) / 2;
			if (tv[mid] == target) return true;
			else if (tv[mid] < target) beg = mid + 1;
			else end = mid - 1;
		}

		return false;
	}
};

int main()
{
	vector<vector<int>> m = { {1} };
	Solution s;
	cout << s.searchMatrix(m, 2) << endl;
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