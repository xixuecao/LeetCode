// 88_Merge_Sorted_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		// tooooooo much code
		/*
		int a = 0, b = 0, k = 0;
		vector<int> nums = nums1;
		while (a < m && b < n)
		{
			if (nums[a] <nums2[b])
			{
				nums1[k] = nums[a];
				a++;
			}
			else
			{
				nums1[k] = nums2[b];
				b++;
			}
			k++;
		}
		while (a < m)
		{
			nums1[k++] = nums[a++];
		}
		while (b < n)
		{
			nums1[k++] = nums2[b++];
		}
		*/
		// from back to front
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (j >= 0) {
			nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
