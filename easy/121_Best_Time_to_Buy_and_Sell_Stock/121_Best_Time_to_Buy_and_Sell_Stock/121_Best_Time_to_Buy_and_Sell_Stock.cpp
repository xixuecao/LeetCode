// 121_Best_Time_to_Buy_and_Sell_Stock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int max = 0, min = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] < min) min = prices[i];
			else if (max < prices[i] - min) max = prices[i] - min;
		}
		return max;
	}
};

int main()
{
	vector<int> v1{7,1,4,5,6,3};
	vector<int> v2{ 7,6,5,4,3,1 };
	Solution s;
	cout << s.maxProfit(v1) << " " << s.maxProfit(v2) << endl;
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
