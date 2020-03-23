﻿// 209_Minimum_Size_Subarray_Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = INT_MAX, sum = 0, l = 0, r = 0;
        while (l < nums.size())
        {
            while (sum < s)
            {
                if (r >= nums.size()) return res == INT_MAX ? 0 : res;
                else sum += nums[r++];
            }
            if (r - l < res) res = r - l;
            sum -= nums[l++];
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    vector<int> vi = { 1,2,3,4,5};
    int s = 11;
    Solution sol;
    cout << sol.minSubArrayLen(s, vi) << endl;
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