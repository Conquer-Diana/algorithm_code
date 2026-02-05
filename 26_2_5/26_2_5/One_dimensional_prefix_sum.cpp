#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//一维前缀和
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1,0);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    //先预处理出来一个前缀和数组
    //dp[i]表示[1,i]区间内所有元素的和
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
        dp[i] = dp[i - 1] + arr[i];

    int l = 0, r = 0;

    while (m--)
    {
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }

    return 0;
}