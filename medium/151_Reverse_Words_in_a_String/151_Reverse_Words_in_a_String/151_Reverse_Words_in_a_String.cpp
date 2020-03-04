// 151_Reverse_Words_in_a_String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		/*
        istringstream is(s);
		string str, res = "";
		vector<string> vs;
		while (is >> str)
			vs.push_back(str);
		for (auto i = vs.rbegin(); i != vs.rend(); i++)
			res = res + *i + " ";
		return res.substr(0,res.size()-1);
		*/
		/*
		istringstream is(s);
		string str;
		is >> s;
		while (is >> str) s = str + " " + s;
		if (!s.empty() && s[0] == ' ') s = "";
		return s;
		*/
		int storeidx = 0, n = s.size();
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++)
		{
			if (s[i] != ' ') {
				if (storeidx != 0) s[storeidx++] = ' ';
				int j = i;
				while (j < n && s[j] != ' ') s[storeidx++] = s[j++];
				reverse(s.begin() + storeidx - (j - i), s.begin() + storeidx);
				i = j;
			}
		}
		s.resize(storeidx);
		return s;
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
