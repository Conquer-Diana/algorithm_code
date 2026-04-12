#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//机器人的运动范围
class Solution
{
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	int m, n, k;
	bool visit[101][101];
	int ret;

public:
	int movingCount(int _m, int _n, int _k)
	{
		m = _m, n = _n, k = _k;
		dfs(0, 0);
		return ret;
	}

	void dfs(int i, int j)
	{
		ret++;
		visit[i][j] = true;

		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y] && check(x, y))
				dfs(x, y);
		}
	}

	bool check(int x, int y)
	{
		int tmp = 0;
		while (x)
		{
			tmp += x % 10;
			x /= 10;
		}
		while (y)
		{
			tmp += y % 10;
			y /= 10;
		}
		return tmp <= k;
	}
};