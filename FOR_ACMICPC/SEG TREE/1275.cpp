#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int a1[10][10];
int a2[10][10];
int dp[10][10];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++) {
			cin >> a1[i][f];
			dp[i][f] = INT_MAX;
		}
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m; f++)
			cin >> a2[i][f];

	for (int i = 0; i < m; i++)
		dp[0][i] = (a1[0][i] - a2[0][i]) * (a1[0][i] - a2[0][i]);
	for (int i = 0; i < n; i++)
		for (int f = 0; f < m-1; f++) {
			int tmp = (a1[i][f] - a2[i][f])* (a1[i][f] - a2[i][f]);
			if (f == 0) {
				dp[i][f] = min(dp[i][f], dp[i - 1][f] + tmp);
				dp[i][f] = min(dp[i][f], dp[i - 1][f+1] + tmp);
			}
			if (f == m - 1) {
				dp[i][f] = min(dp[i][f], dp[i - 1][f - 1] + tmp);
				dp[i][f] = min(dp[i][f], dp[i - 1][f] + tmp);
			}
			else {
				dp[i][f] = min(dp[i][f], dp[i - 1][f - 1] + tmp);
				dp[i][f] = min(dp[i][f], dp[i - 1][f] + tmp);
				dp[i][f] = min(dp[i][f], dp[i - 1][f + 1] + tmp);
			}
		}
	int min_ = INT_MAX;
	for (int i = 0; i < m; i++)
		if (min_ > dp[n - 1][i])
			min_ = dp[n - 1][i];
	cout << min_;
}