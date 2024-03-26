/*
有N件物品和一个容量是V的背包。每件物品只能使用一次。第i件物品的体积是
vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i])
// 到第i个物品，背包的容量有j，最大价值。
int main(int argc, char const *argv[]) {
    int n, v;
    cin >> n >> v;
    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            if (j >= weight[i])
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][v] << endl;
    return 0;
}
