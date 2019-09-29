// 58_Length_of_Last_Word.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution {
public:
	/*
	我们关心的主要是非空格的字符，
	那么我们实际上在遍历字符串的时候，
	如果遇到非空格的字符，我们只需要判
	断其前面一个位置的字符是否为空格，
	如果是的话，那么当前肯定是一个新词的
	开始，将计数器重置为1，如果不是的话，
	说明正在统计一个词的长度，计数器自增1
	即可。
	*/
	int lengthOfLastWord(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != ' ') {
				if (i != 0 && s[i - 1] == ' ') res = 1;
				else ++res;
			}
		}
		return res;

	}
};

int main()
{
	string s = "a ";
	Solution s1;
	std::cout << s1.lengthOfLastWord(s) << endl;
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
