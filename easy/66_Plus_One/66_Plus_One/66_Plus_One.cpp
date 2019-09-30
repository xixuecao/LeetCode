// 66_Plus_One.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		/*
		// sum is toooooo large!
		vector<int> res,temp;
		long long len = digits.size(), sum = 0;
		for (auto num:digits)
		{
			sum += num * pow(10, len - 1);
			len--;
		}
		sum++;
		while (sum != 0)
		{
			temp.push_back(sum % 10);
			sum = sum / 10;
		}
		for (int i = temp.size()-1; i >= 0 ; i--)
		{
			res.push_back(temp[i]);
		}
		return res;
		*/
		/*
		// too much code
		vector<int> res;
		int pos = 0;
		if (digits[digits.size() - 1] < 9)
		{
			digits[digits.size() - 1]++;
			return digits;
		}
		int arr = 1;
		for (int i = digits.size() - 1; i > -1 ; i--)
		{
			if (digits[i] + arr == 10)
			{
				digits[i] = 0;
				arr = 1;
			}
			else
			{
				digits[i] += arr;
				arr = 0;
			}
			res.push_back(digits[i]);
		}
		if (arr) res.push_back(arr);
		reverse(res.begin(), res.end());
		return res;
		*/
		for (int i = digits.size()-1; i > -1; i--)
		{
			if (digits[i] == 9) digits[i] = 0;
			else
			{
				digits[i]++;
				return digits;
			}
		}
		if (digits[0] == 0) digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3 };
	vector<int> res = s.plusOne(v);
	for (auto num : res)
	{
		cout << num << " ";
	}
	cout << endl;
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
