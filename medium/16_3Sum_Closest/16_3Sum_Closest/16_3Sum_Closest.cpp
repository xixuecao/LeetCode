// 16_3Sum_Closest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = 0, min = INT_MAX;
		sort(nums.begin(), nums.end());

		for (int k = 0; k < (int)nums.size() - 2; k++)
		{
			int i = k + 1, j = (int)nums.size() - 1;
			while (i < j)
			{
				int sum = nums[k] + nums[i] + nums[j];
				int temp = abs(sum - target);
				if (temp < min)
				{
					min = temp;
					res = sum;
				}
				if (sum < target) i++;
				else j--;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> nums{ 0,2,1,-3 };
	Solution s;

	std::cout << s.threeSumClosest(nums, 1) << endl;;
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
