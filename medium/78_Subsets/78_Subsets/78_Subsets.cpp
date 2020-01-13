// 78_Subsets.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		/*
		vector<vector<int>> res(1);
		for (int i = 0; i < nums.size(); i++)
		{
			int len = res.size();
			for (int j = 0; j < len; j++)
			{
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
		*/
		vector<vector<int>> res;
		vector<int> out;
		dfs(nums, 0, res, out);
		return res;
	}
	void dfs(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& out)
	{
		res.push_back(out);
		for (int i = idx; i < nums.size(); i++)
		{
			out.push_back(nums[i]);
			dfs(nums, i + 1, res, out);
			out.pop_back();
		}
	}
};

int main()
{
	vector<int> nums{ 1,2,3 };
	Solution sol;
	vector<vector<int>> res = sol.subsets(nums);
	for (auto i : res) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
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
