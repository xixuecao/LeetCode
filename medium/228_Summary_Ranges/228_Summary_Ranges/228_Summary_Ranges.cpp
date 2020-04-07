// 228_Summary_Ranges.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int beg = 0, n = nums.size();
        while (beg < n)
        {
            int cnt = 1;
            while (beg + cnt < n && (long)nums[beg + cnt] - nums[beg] == cnt) cnt++;
            res.push_back((cnt == 1) ? to_string(nums[beg]) : to_string(nums[beg]) + "->" + to_string(nums[beg + cnt -1]));
            beg += cnt;
        }
        return res;
        /*
        vector<string> res;
        if (nums.size() == 0) return res;
        if (nums.size() == 1) return {to_string(nums[0])};
        string str;
        int l = 0, r = 0;
        for (int i = 1; i < nums.size();i++)
        {
            while (i < nums.size() && (long)nums[i] - nums[r] == 1) {
                i++;
                r++;
            }
            if (l == r) str = to_string(nums[l]);
            else str = to_string(nums[l]) + "->" + to_string(nums[r]);
            res.push_back(str);
            if (i == nums.size() - 1 && (long)nums[i] - nums[r] != 1) res.push_back(to_string(nums[i]));
            l = i; r = i;
        }
        return res;
        */
    }
};

int main()
{
    vector<int> nums{ 2 };
    Solution sol;
    vector<string> vs = sol.summaryRanges(nums);
    for (auto s:vs)
    {
        cout << s << endl;
    }
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
