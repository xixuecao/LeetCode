// 93_Restore_IP_Addresses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
一是只要遇到字符串的子序列或配准问题首先考虑动态规划DP
二是只要遇到需要求出所有可能情况首先考虑用递归
*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string out;
		restorehelp(s, 0, out, res);
		return res;
	}
	void restorehelp(string s, int n, string out, vector<string>& res)
	{
		if (n == 4)
		{
			if (s.empty()) res.push_back(out);
		}
		else
		{
			for (int i = 1; i < 4; i++)
			{
				if (s.size() < i) break;
				int val = stoi(s.substr(0, i));
				if (val > 255 || i != to_string(val).size()) continue;
				restorehelp(s.substr(i), n + 1, out + s.substr(0, i) + (n == 3 ? "" : "."), res);
			}
		}
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
