#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 8e3 + 5;
const int MaxN2 = 2e5 + 5;

using namespace std;

// idol h1euct

ll t, n;
ll a[MaxN], dd[MaxN];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
    	memset(dd, 0, sizeof dd);
    	cin >> n;
    	for(int i = 1; i <= n; i++) cin >> a[i], dd[a[i]]++;
    	ll res = 0;
    	for(int i = 1; i < n; i++){
    		ll sum = a[i];
    		for(int j = i + 1; j <= n; j++){
    			sum += a[j];
    			if(sum > n) break;
    			else if(dd[sum] > 0){
    				res += dd[sum];
    				dd[sum] = 0;
    			}
    		}
    	}
    	cout << res << '\n';
    }
    
    return 0;
}
 
// tuntun
