// 81_Search_in_Rotated_Sorted_Array_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int beg = 0, end = nums.size() - 1;
		while (beg <= end)
		{
			int mid = beg + (end - beg) / 2;
			if (nums[mid] == target) return true;
			if (nums[end] < nums[mid])
			{
				if (target >= nums[beg] && nums[mid] > target) end = mid - 1;
				else beg = mid + 1;
			}
			else if(nums[end] > nums[mid])
			{
				if (target > nums[mid] && nums[end] >= target) beg = mid + 1;
				else end = mid - 1;
			}
			else
				end--;
			// 由于这一题有重复数值，所以需要判断右边值与中间值大小
			// 例如1，1，3，1
			// nums[mid] = 1, nums[end] = 1;
		}
		return false;
	}
};

int main()
{
    std::cout << "Hello World!\n";
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
