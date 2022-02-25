#include <bits/stdc++.h>

#define int int64_t 
#define fi first
#define se second

#define vii vector<int>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1e6 + 5;

using namespace std;

int n, nt[MaxN];

int lcm(int a, int b){ 
	return (a * b) / __gcd(a, b); 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     
    
    cin >> n;
    if(n < 3) cout << n;
    else{
    	int res = 0;
    	for(int i = 3; i <= n; i++){
    		res = max(res, lcm(i - 1, lcm(i, i - 3)));
    		res = max(res, lcm(i - 1, lcm(i, i - 2)));
    	    if(i > 5) res = max(res, lcm(i - 1, lcm(i - 5, i - 3)));
    		res = max(res, lcm(i - 3, lcm(i - 2, i)));
    	}
    	cout << res;
    }
    
    return 0;
}
 
// tuntun
