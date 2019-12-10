// 29_Divide_Two_Integers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
		if (m < n) return 0;
		while (m >= n) {
			long long t = n, p = 1;
			while (m > (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}
		if ((dividend < 0) ^ (divisor < 0)) res = -res;
		return res > INT_MAX ? INT_MAX : res;
	}

};

int main()
{
	int a = -1010369383;
	int b = -2147483648;
	Solution s;
	cout << s.divide(a, b) << endl;
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
