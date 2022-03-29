#include <bits/stdc++.h>

#define int int64_t 
#define fi first
#define se second

#define vii vector<int>
#define sz(s) int(s.size())

const long long mod = 998244353;
const long long inf = 1e18 - 1;
const int MaxN1 = 2e5 + 5;
const int MaxN2 = 1e6 + 5;

using namespace std;

int n, a[MaxN1], dd[MaxN2], ans = 0;
vii c = {1, 2, 3, 4, 5, 6, 7, 8, 9};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < 9; i++){
    	int x = c[i];
    	for(int j = 1; j <= 6; j++){
    		x = x * 10 + c[i];
    		c.push_back(x);
    	}
    }
    //for(int x : c) cout << x<< '\n';
    memset(dd, 0, sizeof dd);
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	for(int j = 0; j < sz(c); j++){
    		if(c[j] - a[i] >= 0 && c[j] - a[i] <= 1e6) ans += dd[c[j] - a[i]];
    	}
    	dd[a[i]]++;
    }
    cout << ans;
    
    return 0;
}
 
// tuntun
