// 125_Valid_Palindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		int beg = 0, end = s.size()-1;
		while (beg <= end)
		{
			if (str.find(s[beg])!=string::npos)
			{
				if (s[beg] >= 'A' && s[beg] <= 'Z') s[beg] -= 'A' - 'a';
			}
			else
			{
				beg++;
				continue;
			}
			if (str.find(s[end]) != string::npos)
			{
				if (s[end] >= 'A' && s[end] <= 'Z') s[end] -= 'A' - 'a';
			}
			else
			{
				end--;
				continue;
			}
			if (s[beg] != s[end]) {
				return false;
			}
			beg++; end--;
		}
		return true;
	}
};
int main()
{
	Solution s;
	string str = "aa";
	cout << s.isPalindrome(str) << endl;
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
