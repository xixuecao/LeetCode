// 15_3Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		
		for (int k = 0; k < (int)nums.size()-2; k++) // 需要加上int强制转换
		{
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue;
			int target = -nums[k], i = k + 1, j = (int)nums.size() - 1; // 需要加上int强制转换
			while (i < j)
			{
				if (nums[i] + nums[j] == target)
				{
					res.push_back({ nums[k],nums[i],nums[j] });
					while (i < j && nums[i] == nums[i + 1]) i++;
					while (i < j && nums[j] == nums[j - 1]) j--;
					i++; j--;
				}
				else if (nums[i] + nums[j] < target) i++;
				else j--;
			}
		}
		return res;

	}


};

int main()
{
	vector<int> nums{ 0, 0,0 };
	sort(nums.begin(), nums.end());
	for (auto i : nums) cout << i << " ";
	cout << endl;
	Solution s;
	vector<vector<int>> res;
	res = s.threeSum(nums);
	for (auto i : res) {
		for (auto j : i) cout << j << " ";
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
