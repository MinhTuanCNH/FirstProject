#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 2e5 + 5;
const int sum = 40000;

using namespace std;

ll n, l, r, ans = -inf;
ll a[MaxN], st[MaxN * 4], f[MaxN];

void build(ll id, ll l, ll r){
    if(l == r){
        st[id] = f[l];
        return;
    }
    ll m = (l+r)/2;
    build(id*2, l, m);
    build(id*2 + 1, m+1, r);
    st[id] = max(st[id*2], st[id*2 + 1]);
}

ll getmax(ll id, ll l, ll r, ll u, ll v){
    if(u > r || v < l) return -inf;
    if(u <= l && r <= v) return st[id];
    ll m = (l+r)/2;
    return max(getmax(id*2, l, m, u, v), getmax(id*2 + 1, m+1, r, u, v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> n >> l >> r;
    f[0] = 0;
    memset(st, 0, sizeof st);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	f[i] = f[i - 1] + a[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
    	ll res = getmax(1, 1, n, i + l - 1, i + r - 1);
    	ans = max(res - f[i - 1], ans);
    }
    cout << ans;
    
    return 0;
}

// tuntun
