// 56_Merge_Intervals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty()) return {};
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end());
		int beg = intervals[0][0], end = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++)
		{
			vector<int> temp = intervals[i];
			if (temp[1] <= end) continue;
			else if (temp[0] <= end) end = temp[1];
			else
			{
				res.push_back({ beg,end });
				beg = temp[0];
				end = temp[1];
			}
		}
		res.push_back({ beg,end });
		return res;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> intervals = { {1, 3},{0, 18} };
	vector<vector<int>> res = sol.merge(intervals);
	for (auto inter : res) {
		cout << "[ ";
		for (auto i : inter) cout << i<<" ";
		cout << "]" << endl;
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
