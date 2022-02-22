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

ll n, m, a[300010], b[300010];
vll p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    cin >> m;
    FOR(i,1,m) cin >> b[i];
    ll i = 1, j = 1, resA = 0, resB = 0;
    while(i <= n && j <= m){
        resA += a[i];
        resB += b[j];
        a[i] = b[j] = 0;
        if(resA == resB){
            //cout << resA << ' ';
            p.push_back(resA);
            resA = resB = 0;
            i++; j++;
        }
        else if(resA > resB) j++;
        else i++;
    }
    //cout << i << ' ' << j << ' ';
    int k = p.size();
    if(i <= n || j <= m) cout << "-1";
    else cout << k;
    return 0;
}
