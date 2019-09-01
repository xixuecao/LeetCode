// 26_Remove_Duplicates_from_Sorted_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		/*
		int res = 0;
		int len = nums.size();
		vector<int> temp = nums;
		if (nums.empty())
		{
			return 0;
		}
		for (int i = 0; i < len;)
		{
			auto res1 = find(nums.begin(), nums.end(), temp[i]);
			auto res2 = find(nums.rbegin(), nums.rend(), temp[i]);

			res += (res2 + 1).base() - res1;
			i += res2 .base() - res1;
			nums.erase(res1 + 1, res2.base());
		}
		return len - res;
		*/
		if (nums.empty()) return 0;
		int num = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[num])
			{
				num++;
				nums[num] = nums[i];
			}
		}
		return num + 1;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };

	cout << s.removeDuplicates(v) << endl;
	for (auto i : v)
	{
		cout << i << " ";
	}
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
