// 146_LRU_Cache.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) return -1;
		l.splice(l.begin(), l, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it != m.end()) l.erase(it->second);
		l.push_front(make_pair(key, value));
		m[key] = l.begin();
		if (m.size() > cap) {
			int k = l.rbegin()->first;
			l.pop_back();
			m.erase(k);
		}
	}
private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};

int main()
{
	//LRUCache cache = new LRUCache(2 /* capacity */);

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
