// 13_Roman_to_Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> r2i;
		r2i['I'] = 1;
		r2i['V'] = 5;
		r2i['X'] = 10;
		r2i['L'] = 50;
		r2i['C'] = 100;
		r2i['D'] = 500;
		r2i['M'] = 1000;

		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int val = r2i[s[i]];
			if (i == s.size() - 1 || r2i[s[i + 1]] <= r2i[s[i]]) res += val;
			else res -= val;
		}
		return res;

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
