// 36_Valid_Sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		/*
		for (int i = 0; i < 9; i++)
		{
			unordered_set<char> col;
			unordered_set<char> row;
			
			for (int j = 0; j < 9; j++) {


				if (board[i][j] != '.' && row.find(board[i][j]) != row.end()) return false;
				else row.insert(board[i][j]);
				if (board[j][i] != '.' && col.find(board[j][i]) != col.end()) return false;
				else col.insert(board[j][i]);
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				unordered_set<char> box;
				int row1 = 3 * i, col1 = 3 * j;
				for (int k = row1; k < row1+ 3; k++)
					for (int l = col1; l < col1 + 3; l++)
						if (board[k][l] != '.' && box.find(board[k][l]) != box.end())
							return false;
						else box.insert(board[k][l]);
			}
		}
	
		return true;
		*/

		if (board.size() != 9 || board[0].size() != 9) return false;

		// check row
		for (int i = 0; i < 9; i++) {
			vector<bool> used(9, false);
			for (int j = 0; j < 9; j++) {
				if (!isdigit(board[i][j])) continue;
				int k = board[i][j] - '0';
				if (k == 0 || used[k - 1]) return false;
				used[k - 1] = true;
			}
		}

		//check col
		for (int j = 0; j < 9; j++) {
			vector<bool> used(9, false);
			for (int i = 0; i < 9; i++) {
				if (!isdigit(board[i][j])) continue;
				int k = board[i][j] - '0';
				if (k == 0 || used[k - 1]) return false;
				used[k - 1] = true;
			}
		}

		// check subbox
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int row = 3 * i;
				int col = 3 * j;
				vector<bool> used(9, false);
				for (int m = row; m < row + 3; m++) {
					for (int n = col; n < col + 3; n++) {
						if (!isdigit(board[m][n])) continue;
						int k = board[m][n] - '0';
						if (k == 0 || used[k - 1]) return false;
						used[k - 1] = true;
					}
				}
			}
		}

		return true;
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
