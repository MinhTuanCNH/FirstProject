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

int t, n, a[MaxN], sum = 0;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
    	bool check = false;
    	int sum = 0;
    	cin >> n >> a[1];
    	sum += a[1];
    	for(int i = 2; i <= n; i++){
    		cin >> a[i];
    		if(a[i] != a[i - 1]) check = true;
    		sum += a[i];
    	}	
    	if(!check){
    		cout << 0 << '\n';
    		continue;
    	}
    	int res = *max_element(a + 1, a + n + 1), ans = inf;
    	bool kk = 1;
    	for(int i = 1; i <= sqrt(sum); i++){
    		if(sum % i == 0){
    			bool k1 = 1, k2 = 1;
    			int tun = 0, cnt1 = 0, cnt2 = 0;
    			for(int j = 1; j <= n; j++){
    				if(tun < i) tun += a[j];
    				if(tun > i){
    					k1 = 0;
    					break;
    				}	
    				if(tun == i){
    					tun = 0;
    					cnt1++;
    				}	
    			}
    			tun = 0;
    			for(int j = 1; j <= n; j++){
    				if(tun < sum/i) tun += a[j];
    				if(tun > sum/i){
    					k2 = 0;
    					break;
    				}	
    				if(tun == sum/i){
    					tun = 0;
    					cnt2++;
    				}	
    			}
    			if(k1){
    				ans = min(n - cnt1, ans);
    				kk = 0;
    			}
    			if(k2){
    				ans = min(n - cnt2, ans);
    				kk = 0;
    			}
    		}
    	}
    	if(!kk) cout << ans << '\n';
    	else cout << n - 1 << '\n';
    }
    
    return 0;
}
 
// tuntun
