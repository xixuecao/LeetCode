// 167_Two_Sum_II-Input_array_is_sorted.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		/*
		// tooooooooooo long
		vector<int> res;
		if (numbers.empty()) return res;
		for (int i = 0; i < numbers.size()-1; i++)
		{
			for (int j = i+1; j < numbers.size(); j++)
			{
				if (numbers[j] == target - numbers[i])
				{
					res.push_back(i+1);
					res.push_back(j+1);
				}
			}
		}
		return res;
		*/
		vector<int> res;
		if (numbers.empty()) return res;
		int beg = 0, end = numbers.size() - 1;
		while (beg <= end)
		{
			if (numbers[beg] + numbers[end] == target)
			{
				res.push_back(beg + 1);
				res.push_back(end + 1);
				break;
			}
			if (numbers[beg] + numbers[end] > target) end--;
			else beg++;
		}
		return res;
	}
};

int main()
{
	vector<int> numbers = { 2, 7, 11, 15 };
	int target = 9;
	Solution s;
	vector<int> res = s.twoSum(numbers, target);
	for (auto i : res) {
		cout << i << " ";
	}
	return 0;
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
