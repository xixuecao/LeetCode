// 216_Combination_Sum_III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSum3DFS(res, out, k, n, 1);
        return res;
    }
    void combinationSum3DFS(vector<vector<int>>& res, vector<int>& out, int k, int n, int num) {
        if (n < 0) return;
        if (n == 0 && out.size() == k) res.push_back(out);
        for (int i = num; i < 10; i++)
        {
            out.push_back(i);
            combinationSum3DFS(res, out, k, n - i, i + 1);
            out.pop_back();
        }
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
