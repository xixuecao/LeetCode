// 219_Contains_Duplicate_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> ump;
		for (int i = 0; i < nums.size(); i++) {
			if (ump.count(nums[i]) == 0)
				ump[nums[i]] = i;
			else if (i - ump[nums[i]] <= k)
				return true;
			else ump[nums[i]] = i;
		}
		return false;
		/*
		//Pass
		unordered_map<int, int> ump;
		for (int i=0;i<nums.size();i++) {
			if (ump.count(nums[i]) == 0)
				ump[nums[i]] = i;
			else if (i - ump[nums[i]] <= k)
				return true;
			else ump[nums[i]] = i;
		}
		return false;
		// Pass
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.count(nums[i]) != 0 && i - m[nums[i]] <= k) return true;
			m[nums[i]] = i;
		}
		return false;
		// wrong
		if (nums.empty() || nums.size() == 1) return false;
		map<int, int> m;
		int max = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = m.find(nums[i]);
			if (iter != m.end()) max = i - iter->second < max ? max : i - iter->second;
			m[nums[i]] = i;
		}
		return max <= k;
		*/
	}
};

int main()
{
	vector<int> nums{ 1,2 };
	Solution s;
	cout << s.containsNearbyDuplicate(nums, 2) << endl;
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
