// 34_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int beg = 0, end = 0, n = nums.size();
		int l = 0, r = n - 1;
		while (l <= r) 
		{
			int mid = l + (r - l) / 2;
			if (target == nums[mid])
			{
				beg = mid; end = mid;
				while (beg > 0 && nums[beg - 1] == nums[beg]) beg--;
				while (end < n - 1 && nums[end] == nums[end + 1]) end++;
				return { beg, end };
			}
			else if (target > nums[mid]) l = mid + 1;
			else r = mid - 1;
		}
		return { -1,-1 };
	}
};

int main()
{
	vector<int> nums{ 5, 7, 7, 8, 8, 10 };
	int target = 10;
	Solution s;
	vector<int> res = s.searchRange(nums, target);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
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
