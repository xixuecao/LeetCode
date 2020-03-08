// 165_Compare_Version_Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1, v2;
		string s1 = "", s2 = "";
		for (int i = 0; i < version1.size(); i++)
		{
	
			if (version1[i] != '.')
			{
				s1 += version1[i];
			}
			else
			{
				
				v1.push_back(stoi(s1));
				s1 = "";
			}
		}
		if (s1 != "." && s1 != "") v1.push_back(stoi(s1));
		for (int i = 0; i < version2.size(); i++)
		{

			if (version2[i] != '.')
			{
				s2 += version2[i];
			}
			else
			{
				
				v2.push_back(stoi(s2));
				s2 = "";
			}
		}
		if (s2 != "." && s2 != "") v2.push_back(stoi(s2));
		for (int i = 0; i < v1.size() || i < v2.size(); i++)
		{
			int a = 0, b = 0;
			if (i < v1.size()) a = v1[i];
			if (i < v2.size()) b = v2[i];
			if (a < b) return -1;
			else if (a > b) return 1;
			else continue;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	string s1 = "7.0";
	string s2 = "7.";
	//int a = s.compareVersion(s1, s2);
	cout << s.compareVersion(s1, s2) << endl;
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
