
// 54_Spiral_Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return {};

		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = n - 1, u = 0, d = m - 1, k = 0;
		vector<int> res(m * n);
		while (true)
		{
			for (int i = l; i <= r; i++) res[k++] = matrix[u][i];
			if (++u > d) break;
			for (int i = u; i <= d; i++) res[k++] = matrix[i][r];
			if (--r < l) break;
			for (int i = r; i >= l; i--) res[k++] = matrix[d][i];
			if (--d < u) break;
			for (int i = d; i >= u; i--) res[k++] = matrix[i][l];
			if (++l > r) break;
		}
		return res;
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
