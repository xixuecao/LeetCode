// 119_Pascal's_Triangle_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		/*
		// Time Limit Exceeded
		if (rowIndex == 0) return { 1 };
		if (rowIndex == 1) return { 1,1 };
		vector<int> res;
		res.push_back(1);
		for (int i = 0; i < rowIndex-1; i++)
		{
			vector<int> t = getRow(rowIndex - 1);
			res.push_back(t[i] + t[i + 1]);
		}
		res.push_back(1);
		return res;
		*/
		if (rowIndex == 0) return { 1 };
		vector<vector<int>> nums;
		nums.push_back({1});
		nums.push_back({ 1,1 });
		for (int i = 2; i < rowIndex+1; i++)
		{
			vector<int> res;
			res.push_back(1);
			for (int j = 0; j < i - 1; j++)
			{
				vector<int> t = nums[i-1];
				res.push_back(t[j] + t[j + 1]);
			}
			res.push_back(1);
			nums.push_back(res);
		}
		return nums[nums.size()-1];

	}
	// 大佬写法
	vector<int> getRow2(int rowIndex) {
		vector<int> res(rowIndex + 1);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
			for (int j = i; j >= 1; j--)
				res[j] += res[j - 1];
		return res;
	}
};

int main()
{
	Solution s;
	
	vector<int> vi{0,1,2,3,4,5,6,7,8,9 };
	for (auto i : vi) {
		vector<int> res = s.getRow(i);
		for (auto j : res)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
	vector<int> vi2{ 0,1,2,3,4,5,6,7,8,9 };
	for (auto i2 : vi2) {
		vector<int> res2 = s.getRow2(i2);
		for (auto j2 : res2)
		{
			cout << j2 << " ";
		}
		cout << endl;
	}
	cout << endl;
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
