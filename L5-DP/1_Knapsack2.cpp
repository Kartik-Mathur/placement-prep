#include <bits/stdc++.h>
using namespace std;

#define 	ll long long int
#define 	new(a,n) ll*a = new ll[n]
#define 	new1(a,n,m) ll**a = new ll*[n]; for(ll i = 0 ; i < n ; i++) a[i] = new ll[m];
#define 	mp make_pair
#define 	pb push_back
#define 	fi first
#define 	pii pair<ll,ll>
#define 	si second
#define 	fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define 	F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define 	F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define 	P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define 	P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define 	NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define 	NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define 	PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define 	PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define 	init(a,n,v) for(int i = 0 ; i <n ; i++) a[i]=v;
#define 	init2(a,n,m,v) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){a[i][j]=v;}}
#define 	w(t) int t;cin>>t;while(t--)
#define 	f(n) for(int __i=0;__i<n;__i++)
#define 	AS 200001
#define 	mod 1000000007
#define		INF 1e18

vector<ll> price(101), weight(101);
ll capacity, n, total_profit=0;
vector< vector<ll> > dp(101, vector<ll> (100005, INF));

void solve(){
	cin >> n >> capacity;
	for(int i = 0; i < n ; i++){
		cin>>weight[i]>>price[i];
		total_profit += price[i];
	}

	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 0;
	}

	for (int N = 1; N <= n ; ++N)
	{
		for (int profit = 1; profit <= total_profit; ++profit)
		{
			ll op1 = INF, op2 = INF;
			if(price[N-1] <= profit){
				op1 = weight[N-1] + dp[N-1][profit - price[N-1]];
			}
			op2 = dp[N-1][profit];

			dp[N][profit] = min(op1, op2);
		}
	}

	ll ans = INF;
	for (int i = 1; i <= total_profit; ++i)
	{
		if(dp[n][i]<=capacity){
			ans = i;
		}
	}

	cout << ans << endl;
}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}











