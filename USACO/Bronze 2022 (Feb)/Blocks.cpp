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

int n;
map<char, vector<int> > mp;

bool kt(int a, int b, int c, int d){
	if(a == b || a == c || a == d || b == c || b == d || c == d) return 0;
	return 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < 4; i++){
    	string s; cin >> s;
    	sort(s.begin(), s.end());
    	mp[s[0]].push_back(i);
    	for(int j = 1; j < 6; j++){
    		if(s[j] != s[j - 1]){
    			mp[s[j]].push_back(i);
    		}
    	}
    }
    while(n--){
    	string s; cin >> s;
    	bool check = false;
    	for(int i0 = 0; i0 < sz(mp[s[0]]); i0++){
    		if(sz(s) > 1){
    			for(int i1 = 0; i1 < sz(mp[s[1]]); i1++){
    				if(mp[s[1]][i1] != mp[s[0]][i0]){
    					if(sz(s) > 2){
    						for(int i2 = 0; i2 < sz(mp[s[2]]); i2++){
    							if(mp[s[1]][i1] != mp[s[0]][i0] && mp[s[1]][i1] != mp[s[2]][i2] && mp[s[0]][i0] != mp[s[2]][i2]){
    								if(sz(s) > 3){
    									for(int i3 = 0; i3 < sz(mp[s[3]]); i3++){
    										if(kt(mp[s[0]][i0], mp[s[1]][i1], mp[s[2]][i2], mp[s[3]][i3])) check = true;
    									}
    								}
    								else check = true;
    							}
    						}
    					}
    					else check = true;
    				}
    			}
    		}
    		else check = true;
    	}
    	if(check) cout << "YES\n";
    	else cout << "NO\n";
    }
    
    
    return 0;
}
 
// tuntun
