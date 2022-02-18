#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define FOD(i,a,b) for(ll i=a; i>=b; i--)
#define For(x,m) for(auto x: m)
#define size(s) int(s.size())
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;

using namespace std;

ll n, q, a[100005], st[400040];

void build(ll id, ll l, ll r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    ll m = (l+r)/2;
    build(id*2, l, m);
    build(id*2 + 1, m+1, r);
    st[id] = st[id*2] + st[id*2 + 1];
}

void update(ll id, ll i, ll l, ll r, ll v){
    if(i < l || i > r) return;
    if(l == r){
        st[id] = v;
        return;
    }
    ll m = (l+r)/2;
    update(id*2, i, l, m, v);
    update(id*2 + 1, i, m+1, r, v);
    st[id] = st[id*2] + st[id*2 + 1];
}

ll getsum(ll id, ll l, ll r, ll u, ll v){
    if(u > r || v < l) return 0;
    if(u <= l && r <= v) return st[id];
    ll m = (l+r)/2;
    return getsum(id*2, l, m, u, v) + getsum(id*2 + 1, m+1, r, u, v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    FOR(i,1,n) cin >> a[i];
    build(1, 1, n);
    while(q--){
        ll k, b, c;
        cin >> k >> b >> c;
        if(k == 0){
            ll x = a[b], y = a[c];
            update(1, b, 1, n, y);
            update(1, c, 1, n, x);
            a[b] = y, a[c] = x;
        }
        if(k == 1){
            cout << getsum(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}

// tuntun
