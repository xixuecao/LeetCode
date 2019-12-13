// 33_Search_in_Rotated_Sorted_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

// ******************************************************************
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/
// ******************************************************************

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (target == nums[mid]) return mid;
			if (nums[l] <= nums[mid])
			{
				if (nums[l] <= target && target <= nums[mid]) r = mid - 1;
				else l = mid + 1;
			}
			else
			{
				if (nums[mid] <= target && target <= nums[r]) l = mid + 1;
				else r = mid - 1;
			}
		}
		return -1;
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
