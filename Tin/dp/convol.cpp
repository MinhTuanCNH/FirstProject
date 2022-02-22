#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1005;

using namespace std;

ll n, a[10005], b[10005], f[5005][5005], ans = -inf;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		f[i][j] = max(a[i] * b[j], f[i - 1][j - 1] + a[i] * b[j]);
    		ans = max(ans, f[i][j]);
    	}
    }
    cout << ans;
    return 0;
}

// tuntun
