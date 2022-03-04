#include <bits/stdc++.h>

#define int int64_t 
#define fi first
#define se second

#define vii vector<int>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1e5 + 5;

using namespace std;

int n, a[MaxN], k, ans = inf;
int t[MaxN], f[MaxN], g[MaxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    t[0] = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	t[i] = t[i - 1] + a[i];
    }	
    memset(f, -inf, sizeof f);
    memset(g, -inf, sizeof g);
    for(int i = 1; i <= n; i++){
    	if(i >= k){
    		f[i] = max(f[i - 1], t[i] - t[i - k]);
    	}
    }
    for(int i = n; i >= 1; i--){
    	if(i <= n - k + 1){
    		g[i] = max(g[i + 1], t[i + k - 1] - t[i - 1]);
    	}
    }
    //for(int i = 1; i <= n; i++) cout << f[i] << ' ' << g[i] << '\n';
    for(int i = k; i <= n - k + 1; i++){
    	ans = min(ans, max(f[i - k], g[i + 1]));
    }
    cout << ans;
    
    return 0;
}
 
// tuntun
