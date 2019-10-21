// 136_Single_Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		/*
		//if (nums.empty()) return 0;
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]]++;
		}
		for (auto i:m)
		{
			if (i.second == 1)
				return i.first;
		}
		return 0;
		*/
		/*
		unordered_set<int> st;
		for (auto num : nums)
		{
			if (st.count(num)) st.erase(num);
			else st.insert(num);
		}
		return *st.begin();
		*/
		int res = 0;
		for (auto num : nums) res ^= num;
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> vi{ 2,2,1 };
	cout << s.singleNumber(vi) << endl;
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
