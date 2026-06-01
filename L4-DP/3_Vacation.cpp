#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005][3];
int dp[100005][4];

int solve(int day,int ac){
	if(day == n){
		return 0;
	}

	if(dp[day][ac+1] != -1){
		return dp[day][ac+1];
	}

	int ans = 0;
	for (int j = 0; j < 3; ++j)
	{
		// agar jth activity is equal to the prev 
		if(j == ac) continue;
		ans = max(ans, a[day][j] + solve(day+1, j));
	}

	return dp[day][ac+1] = ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif		
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin>>a[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout << solve(0,-1) << endl;

	return 0;
}
















