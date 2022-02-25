#include <bits/stdc++.h>

#define int int64_t 
#define fi first
#define se second

#define vi vector<int>
#define vii vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1e7 + 5;

using namespace std;

int t, nt[MaxN];
string s;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // sang nguyen to
    memset(nt, 0, sizeof nt);
    nt[0] = nt[1] = 1;
    for(int i = 2; i <= sqrt(1e7); i++){
    	if(!nt[i]){
    		for(int j = i * i; j <= 1e7; j += i) nt[j] = 1;
    	}
    }
    
    cin >> t;
    while(t--){
    	cin >> s;
    	vii a, h;
    	int ans = 1;
    	for(int i = 0; i < sz(s); i++){
    		a.push_back(s[i] - '0');
    	}	
    	sort(a.begin(), a.end());
    	do{
    		int res = 0;
    		for(int i = 0; i < sz(a); i++){
    			res = res * 10 + a[i];
    			if(!nt[res]) h.push_back(res);
    		}
    	} while(next_permutation(a.begin(), a.end()));
    	sort(h.begin(), h.end());
    	if(sz(h) == 0){
    		cout << 0 << '\n';
    		continue;
    	}
    	for(int i = 1; i < sz(h); i++) if(h[i] != h[i - 1]) ans++;
    	cout << ans << '\n';
    }
    return 0;
}
 
// tuntun
