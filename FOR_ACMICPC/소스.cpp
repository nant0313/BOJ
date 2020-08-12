﻿#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	queue<int>q;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();
		if (q.size() >= 1) cout << ", ";
		else cout << '>';
	}
}