#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1e2 + 5;
const int sum = 40000;

using namespace std;

struct matrix{
	vector< vector<int> > res;
	
	auto & operator [] (int i) { 
		return res[i]; 
	}
	
	matrix(const vector <vector <int> > &d): res(d) { }
	
	int row() const {
		return res.size();
	}
	
	int col() const {
		return res[0].size();
	}
	
	matrix(int r, int c) : res(r, vector<int> (c)) {}
	
	
};

matrix multi(matrix a, matrix b){
	matrix c(a.row(), b.col());
	for(int i = 0; i < a.row(); i++){
		for(int j = 0; j < b.col(); j++){
			c[i][j] = 0;
			for(int k = 0; k < a.col(); k++){
				c[i][j] += (a[i][k] * b[k][j]) % mod;
			}
		}
	}
	return c;
}

matrix pow(matrix a, int n){
	if(n == 1) return a;
	matrix s = pow(a, n/2);
	if(n & 1) return multi(multi(s, s), a);
	return multi(s, s);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    matrix a({{1, 1}, {1, 0}});
    
    int n; cin >> n;
    matrix tun = pow(a, n + 2);
    cout << (tun[0][0] - 1) % mod;
    return 0;
}
