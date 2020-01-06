// 73_Set_Matrix_Zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int> row(m), col(n);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				
				if (matrix[i][j] == 0) 
				{
					if (row[i] == 1 && col[j] == 1) continue;
					else if (row[i] == 1) col[j] = 1;
					else if (col[j] == 1) row[i] = 1;
					else row[i] = 1; col[j] = 1;
				}
			}
		}
		for (int i = 0; i < row.size(); i++)
		{
			if (row[i] == 1)
			{
				for (int j = 0; j < n; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < col.size(); i++)
		{
			if (col[i] == 1)
			{
				for (int j = 0; j < m; j++)
				{
					matrix[j][i] = 0;
				}
			}
		}
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
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
