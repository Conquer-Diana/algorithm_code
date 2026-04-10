#define _CRT_SECURE_NO_WARNINGS


#include <vector>

using namespace std;

//ÕºœÒ‰÷»æŒ Ã‚£®dfs∞Ê£©
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(), n = image[0].size();
        dfs(image, sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return;

        int tmp = image[sr][sc];
        image[sr][sc] = color;
        for (int k = 0; k < 4; k++)
        {
            int x = sr + dx[k], y = sc + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == tmp)
                dfs(image, x, y, color);
        }
        return;
    }
};