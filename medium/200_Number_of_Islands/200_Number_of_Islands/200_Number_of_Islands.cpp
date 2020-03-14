// 200_Number_of_Islands.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/*
Input:
11110
11010
11000
00000

Output: 1
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                helper(grid, visited, i, j);
                res++;
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n) {
        if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size() || grid[m][n] == '0' || visited[m][n]) return;
        visited[m][n] = true;
        helper(grid, visited, m - 1, n);
        helper(grid, visited, m + 1, n);
        helper(grid, visited, m, n - 1);
        helper(grid, visited, m, n + 1);
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
