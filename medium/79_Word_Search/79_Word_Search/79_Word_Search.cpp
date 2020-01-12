
// 79_Word_Search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty() || word.empty()) return false;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (dfssearch(board, word, i, j, 0)) return true; // can't use return derectly, need to use if to get cycle
		return false;

	}

	bool dfssearch(vector<vector<char>>& board, string word, int i, int j, int pos)
	{
		if (pos == word.size()) return true;
		int m = board.size(), n = board[0].size();
		if (i < 0 ||  j < 0 || i >= m || j >= n || board[i][j] == '#' || board[i][j] != word[pos]) return false;
		char temp = board[i][j];
		board[i][j] = '#';

		bool res = dfssearch(board, word, i - 1, j, pos + 1)
			|| dfssearch(board, word, i + 1, j, pos + 1)
			|| dfssearch(board, word, i, j - 1, pos + 1)
			|| dfssearch(board, word, i, j + 1, pos + 1);

		board[i][j] = temp;
		return res;
	}
};

int main()
{
	vector<vector<char>> board{{'a','b'}};
	Solution sol;
	string word = "ba";
	cout << sol.exist(board, word) << endl;

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
