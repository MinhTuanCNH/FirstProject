#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1e7 + 5;
const int sum = 40000;

using namespace std;

ll t, n, x, a[222], d[222][44444];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
    	ll Min = 0, Max = 0;
    	memset(d, 0, sizeof d);
    	cin >> n >> x;
    	for(int i = 1; i <= n; i++){
    		cin >> a[i];
    		a[i] -= x;
    		if(a[i] > 0) Max += a[i];
    		else Min += a[i];
    	}
    	
    	for(int i = 1; i <= n; i++){
    		for(int j = Min; j <= Max; j++){
    			d[i][j + sum] = (d[i - 1][j + sum] + d[i - 1][j - a[i] + sum]) % mod;
    		}
    		d[i][a[i] + sum] = (d[i][a[i] + sum] + 1) % mod;
    	}
    	cout << d[n][sum] % mod << '\n';
    }
    
    return 0;
}

// tuntun
