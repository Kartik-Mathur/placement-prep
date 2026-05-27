#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif		

	int t;
	cin>>t;
	while(t--){
		int a[100000];
		int n;
		cin>>n;

		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}

		// Find prefix sum
		for (int i = 1; i < n; ++i)
		{
			a[i] += a[i-1];
		}

		// take mod with n
		for (int i = 0; i < n; ++i)
		{
			a[i] %= n;
			a[i] = (a[i]+n)%n;
		}

		// Find remainders count
		int rem[100000]= {};
		rem[0] = 1;

		for (int i = 0; i < n; ++i)
		{
			rem[a[i]]++;
		}

		// Find the answer
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans += (rem[i] * (rem[i] - 1))/2;
		}

		cout << ans << endl;
	}

	return 0;
}
















