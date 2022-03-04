#include <bits/stdc++.h>

#define int int64_t 
#define fi first
#define se second

#define vii vector<int>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN1 = 1e5 + 5;
const int MaxN2 = 5e3 + 5;

using namespace std;

int n, m, a[MaxN2], c[MaxN1];
int f[MaxN1], h[MaxN1];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }	
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= m; i++) cin >> c[i];
    int x = *min_element(c + 1, c + m + 1);
    h[m + 1] = inf;
    for(int i = m; i >= 1; i--){
    	if(c[i] < h[i + 1]) h[i] = c[i];
    	else h[i] = h[i + 1];
    }
    f[0] = 0, c[0] = 0;
    for(int i = 1; i <= n; i++){
    	//cout << "# " << a[i] << '\n';
    	f[i] = f[i - 1] + x;
    	for(int j = i; j >= 1; j--){
    		if(a[i] - a[j] + 1 <= m) f[i] = min(f[i] , f[j - 1] + h[a[i] - a[j] + 1]);
    		//cout << j << ' ' << f[j] + c[a[i] - a[j] + 1] << '\n';
    	}
    	//cout << f[i] << '\n';
    	//cout << '\n';
    }
    cout << f[n];
    
    return 0;
}
 
// tuntun
