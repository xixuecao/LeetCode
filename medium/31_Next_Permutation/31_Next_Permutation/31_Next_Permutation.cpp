// 31_Next_Permutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.empty()) return;
		int n = nums.size();
		int i = n - 2, j = n - 1;
		while (i >= 0 && nums[i + 1] <= nums[i]) i--;
		if (i >= 0)
		{
			while (j >= 0 && nums[j] <= nums[i]) j--;
			int temp = nums[i];	nums[i] = nums[j]; nums[j] = temp;
		}
		reverse(nums.begin() + (i + 1), nums.end()); // 把i直接加在begin()后面会有bug

	}
};

int main()
{
	Solution s;
	vector<int> nums{ 2,3,3,1 };
	s.nextPermutation(nums);
	for (auto i : nums)
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
