#include <bits/stdc++.h>

#define int int64_t 
#define fi first
#define se second

#define vii vector<int>
#define sz(s) int(s.size())

const long long mod = 998244353;
const long long inf = 1e18 - 1;
const int MaxN1 = 5e5 + 5;
const int MaxN2 = 2e6 + 5;

using namespace std;

int n, m, b, r, dd[MaxN1], robo[MaxN1], len[MaxN1];
vii adj[MaxN1];
deque<int> q;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dd, 0, sizeof dd);
    memset(len, 0, sizeof len);
    cin >> n >> m >> b >> r;
    for(int i = 1, x; i <= b; i++){
    	cin >> x;
    	dd[x] = 1;
    	len[x] = 0;
    	q.push_back(x);
    }
    for(int i = 1; i <= r; i++) cin >> robo[i];
    for(int i = 1, u, v; i <= m; i++){
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    while(!q.empty()){
    	int u = q.front();
    	q.pop_front();
    	
    	for(int v : adj[u]){
    		if(!dd[v]){
    			len[v] = len[u] + 1;
    			dd[v] = 1;
    			q.push_back(v);
    		}
    	}
    }
    for(int i = 1; i <= r; i++) cout << len[robo[i]] << ' ';
    
    return 0;
}
 
// tuntun
