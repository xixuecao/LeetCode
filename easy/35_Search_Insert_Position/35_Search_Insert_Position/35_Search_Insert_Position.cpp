// 35_Search_Insert_Position.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		/*
		int num = 0;
		bool flag = false;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target) 
			{
				flag = true;
				num = i;
			}
		}
		if (!flag)
		{
			if (target < nums[0])
				return 0;
			else if (nums[nums.size() - 1] < target)
				return nums.size();
			for (int i = 1; i < nums.size(); i++)
				if (nums[i-1] < target && target < nums[i])
					num = i;
		}
		return num;
		*/
		if (nums.empty()) return 0;
		int beg = 0;
		int end = nums.size() - 1;
		while (beg <= end)
		{
			int mid = (beg + end) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < target)
				beg = mid + 1;
			else
				end = mid - 1;
		}
		return beg;
	}
};

int main()
{
	Solution s;

	vector<int> nums = { 1,3,5,6 };
	cout << s.searchInsert(nums,2) << endl;
    
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
