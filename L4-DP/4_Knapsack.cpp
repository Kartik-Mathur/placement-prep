// Knapsack
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, capacity;
vector<int> weight(100000+1), price(100000+1);

int bottomUp() {
	int dp[2][100005] = {0};

	for (int n = 1 ; n <= N ; n++) {
		for (int c_cap = 1 ; c_cap <= capacity ; c_cap++) {
			int op1 = INT_MIN, op2 = INT_MIN;
			if (c_cap >= weight[n - 1]) {
				op1 = price[n - 1] + dp[0][c_cap - weight[n - 1]];
			}
			op2 = 0 + dp[0][c_cap];
			dp[1][c_cap] = max(op1, op2);
		}

		for (int i = 1; i <= capacity; ++i)
		{
			dp[0][i] = dp[1][i];
		}
	}

	return dp[1][capacity];
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin>>N >> capacity;
	
	for (int i = 0; i < N; ++i)
	{
		cin>>weight[i]>>price[i];
	}
	cout << bottomUp() << endl;

	return 0;
}
















