// 8_String_to_Integer_(atoi).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int i = 0, res = 0, sign = 1;
		while (i < str.size() && str[i] == ' ') i++;
		if (i < str.size() && (str[i] == '+' || str[i] == '-'))
			sign = (str[i++] == '+') ? 1 : -1; // need to increace i
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && INT_MAX % 10 < (str[i] - '0'))) 
			{
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			res = 10 * res + (str[i++] - '0'); // need to increace i
		}
		return res * sign;

		/*
		if (str.empty()) return 0;
        int sign = 1, base = 0, i = 0, n = str.size();
        while (i < n && str[i] == ' ') ++i;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
		*/
	}
};

int main()
{
	Solution s;
	string str = " -42";
	cout << s.myAtoi(str) << endl;
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
