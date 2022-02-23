#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 5e3 + 5;
const int MaxN2 = 2e5 + 5;

using namespace std;

ll t, n;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
    	cin >> n;
    	if(n <= 3) cout << -1;
    	else{
    		if(n % 2){
    			for(int i = 1; i <= n; i += 2) cout << i << ' ';
    			cout << n - 3 << ' ' << n - 1 << ' ';
    			for(int i = n - 5; i > 0; i -= 2) cout << i << ' ';
    		}
    		else{
    			for(int i = 2; i <= n; i += 2) cout << i << ' ';
    			cout << n - 3 << ' ' << n - 1 << ' ';
    			for(int i = n - 5; i >= 1; i -= 2) cout << i << ' ';
    		}
    	}
    	cout << '\n';
    }
    
    return 0;
}
 
// tuntun
