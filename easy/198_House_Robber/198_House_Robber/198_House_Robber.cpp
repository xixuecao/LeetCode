// 198_House_Robber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> res;
		res.push_back(0);
		res.push_back(nums[0]);
		for (int i = 2; i <= nums.size(); i++)
		{
			if (nums[i - 1] + res[i - 2] > res[i - 1]) res.push_back(nums[i - 1] + res[i - 2]);
			else res.push_back(res[i - 1]);
		}
		return *(res.end()-1);

		/*
        if(nums.size()==0) return 0;
        int profit[nums.size()+1];
        profit[0] = 0;
        profit[1] = nums[0];
        for(int i=2;i<=nums.size();i++)
            profit[i] = max(profit[i-1],nums[i-1]+profit[i-2]);
        return profit[nums.size()];
		*/
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
