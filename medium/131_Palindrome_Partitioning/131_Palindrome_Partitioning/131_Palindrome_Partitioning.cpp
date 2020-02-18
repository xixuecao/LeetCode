// 131_Palindrome_Partitioning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> out;
		helper(s, 0, out, res);
		return res;
	}
	void helper(string s, int start, vector<string>& out, vector<vector<string>>& res) {
		if (start == s.size()) { res.push_back(out); return; }
		for (int i = start; i < s.size(); ++i) {
			if (!ispail(s, start, i)) continue;
			out.push_back(s.substr(start, i - start + 1));
			helper(s, i + 1, out, res);
			out.pop_back();
		}
	}
	bool ispail(string s, int beg, int end) {
		while (beg < end)
		{
			if (s[beg] != s[end]) return false;
			beg++; end--;
		}
		return true;
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
