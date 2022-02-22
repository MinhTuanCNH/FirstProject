#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 100005;

using namespace std;

ll cs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll n, m;
ll a[10], dp[MaxN], tv[MaxN];

signed main(){
	memset(a, 0, sizeof a);
    cin >> n >> m;
    for(ll i = 1; i <= m; i++){
        ll x; cin >> x;
        a[x]++;
    }
    memset(tv, 0, sizeof tv);
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= 9 ; j++){
        	if(i == n && j == 0 && n != cs[0]) continue;
        	//cout << i << ' ' << j << ' ' << cs[j] << '\n';
            if(a[j] && i >= cs[j] && dp[i - cs[j]] > 0 && dp[i] <= dp[i - cs[j]] + 1){
            	//cout << 1 << '\n';
                dp[i] = dp[i-cs[j]] + 1;
                tv[i] = j;
            }
        }
    }
    vll ans;
    while(n > 0){
        cout << tv[n];
        ans.push_back(tv[n]);
        n -= cs[tv[n]];
    }
    //sort(ans.rbegin(), ans.rend());
    //for(auto ac : ans) cout << ac;
    return 0;
}

// tuntun
