#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 305;

using namespace std;

ll a[MaxN][MaxN];
ll m, n;
ll r[MaxN][MaxN], c[MaxN][MaxN], minn[MaxN][MaxN][MaxN], maxx[MaxN][MaxN];

ll cal(ll x1, ll y1, ll x2, ll y2){
	ll sum = (r[x1][y2] + r[x2][y2] + c[x2-1][y2] - c[x1][y2]) - (r[x1][y1-1] + r[x2][y1-1] + c[x1][y1] - c[x2-1][y1]);
	return sum;
}
ll test1(ll x1, ll y1, ll x2, ll y2){
	ll sum = r[x1][y2] + r[x2][y2] + c[x2-1][y2] - c[x1][y2];
	return sum;
} 
ll test2(ll x1,ll y1,ll x2,ll y2){
	ll sum = r[x1][y1-1] + r[x2][y1-1] + c[x1][y1] - c[x2-1][y1];
	return sum;
}

int main(){
	cin >> m >> n;
	for (ll i = 1;i<=m;i++) {
		for (ll j = 1;j<=n;j++) cin >> a[i][j];
	}
	for (ll i = 1;i<=m;i++) {
		for (ll j = 1;j<=n;j++) {
			r[i][j] = r[i][j-1] + a[i][j];
		} 
	}
	for (ll j = 1;j<=n;j++) {
		for (ll i = 1;i<=m;i++) {
			c[i][j] = c[i-1][j] + a[i][j];
		}
	}
	for (ll x1 = 1;x1<=m;x1++) {
		for (ll x2 = x1 + 1;x2<=m;x2++) {
			minn[x1][x2][1] = test2(x1,1,x2,0);
			for (ll y1 = 2;y1<=n;y1++) {
				minn[x1][x2][y1] = min(minn[x1][x2][y1-1],test2(x1,y1,x2,0));
			}
		}
	}
	ll res = -inf;

	for (ll x1 = 1;x1<=m;x1++) {
		for (ll x2 = x1 + 1;x2<=m;x2++) {
			//maxx[x1][x2] = -inf;
			for (ll y2 = 2;y2<=n;y2++) {
				res = max(res,test1(x1,0,x2,y2) - minn[x1][x2][y2-1]); 
			}
		}
	}

	cout << res;
	
    return 0;
}

// tuntun
