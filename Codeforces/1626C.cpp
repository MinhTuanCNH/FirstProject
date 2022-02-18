#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define FOD(i,a,b) for(ll i=a; i>=b; i--)
#define For(x,m) for(auto x: m)
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
 
const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
 
using namespace std;

ll t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        ll n, k[118], h[118], ans = 0;
        unordered_map<ll,ll> mp;
        cin >> n;
        k[0] = h[0] = 0;
        FOR(i,1,n){cin >> k[i]; mp[k[i]] = 1;}
        FOR(i,1,n) cin >> h[i];
        FOD(i,n,1){
            if(mp[k[i]] == 1){
                if(k[i] - h[i] + 1 > k[i-1]){
                    ans += (h[i]*h[i] + h[i])/2;
                    //cout << "a ";
                }
                else{
                    //cout << "b ";
                    ll j = i - 1;
                    while(k[i] - h[i] + 1 <= k[j]){
                        h[i] = max(h[i], h[j] + k[i] - k[j]);
                        mp[k[j]] = 0;
                        j--;
                    }
                    ans += (h[i]*h[i] + h[i])/2;
                }
            }
            //cout << ans << ' ';
        }
        cout << ans << '\n';
    }
    return 0;
}
 
// tuntun
