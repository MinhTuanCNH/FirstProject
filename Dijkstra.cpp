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

struct Edge{
    pair<ll,ll> v;
    long long w;
};
struct Node{
    pair<ll,ll> u;
    long long Dist_u;
};
struct cmp{
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

ll n, m, a[222][222], ans = inf, d[222][222];
ll dx[] = {0, 0, -1, 1};
ll dy[] = {1, -1, 0, 0};
bool p[222][222];
pair<ll,ll> trace[222][222];
vector<Edge> E[222][222];

bool check(ll x, ll y){
    if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    FOR(i, 1, n){
        FOR(j, 1, m){
            FOR(k, 0, 3){
                ll x = i + dx[k], y = j + dy[k];
                if(check(x, y)) E[i][j].push_back({make_pair(x, y), a[x][y]});
            }
            p[i][j] = false; d[i][j] = inf;
        }
    }

    priority_queue<Node, vector<Node>, cmp> h;
    FOR(i, 1, n){
    	d[i][1] = a[i][1];
    	h.push({make_pair(i, 1), d[i][1]});
    }
    
    while(!h.empty()) {
        Node x = h.top();
        h.pop();
        
        if(p[x.u.fi][x.u.se] == true)
            continue;
        
        p[x.u.fi][x.u.se] = true;
        for(auto e : E[x.u.fi][x.u.se]) {
            ll i = e.v.fi, j = e.v.se,  w = e.w; 
            
            if(d[i][j] > d[x.u.fi][x.u.se] + w) {
                d[i][j] = d[x.u.fi][x.u.se] + w;
                h.push({make_pair(i, j), d[i][j]});
                trace[i][j] = make_pair(x.u.fi, x.u.se);
            }
        }
    }
    /*FOR(i,1,n){
    	FOR(j,1,m) cout << d[i][j] << ' ';
    	cout << '\n';
    }*/
    FOR(i, 1, n) ans = min(ans, d[i][m]);
    cout << ans;
    return 0;
}
 
// tuntun