//alias c='g++ 1.cpp -std=c++11'
#include <bits/stdc++.h>


using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
#define ll long long
using namespace std;

///////////////////////////////////////////

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

////////////////////////////////

void permute(set<char> cur,  vector<char> &chosen){
	////debug(cur);
	//debug(chosen);
	if(cur.size()==0){
		for(auto x : chosen) cout << x << ' ';
		cout << endl;
		return;
	}
	set<char> cp = cur;
	for(auto x : cur){
		// choose
			chosen.push_back(x);
			cp.erase(x);
		// explore 
			permute(cp, chosen);
		// unchoose
			chosen.pop_back();
			cp.insert(x);
	}
}
void permute(set<int> cur,  vector<int> &chosen){
	////debug(cur);
	//debug(chosen);
	if(cur.size()==0){
		for(auto x : chosen) cout << x << ' ';
		cout << endl;
		return;
	}
	set<int> cp = cur;
	for(auto x : cur){
		// choose
			chosen.push_back(x);
			cp.erase(x);
		// explore 
			permute(cp, chosen);
		// unchoose
			chosen.pop_back();
			cp.insert(x);
	}
}
void printSubsets(int n, vector<int> & chosen){
	if(n < 1){
		for(auto x : chosen) cout << x << ' ';
		cout << endl;
		return;
	}
	
	// choose
	chosen.push_back(n);
	//explore
	printSubsets(n-1, chosen);
	//unchose
	chosen.pop_back();
	printSubsets(n-1, chosen);
	
}
void solve(){
  //int n; cin >> n;
  //vector<int> sofar;
  //printSubsets(n, sofar);
 // set<int> st; for(int i = 1; i <= n; i++) st.insert(i);
    set<char> st; 
    string s = "ahfiod";
    for(auto x : s) st.insert(x);
    vector<char> v;
  permute(st, v);
}

int32_t main(){
	ll t = 1; //cin >> t;
	for(ll j = 1; j <= t; j++){
	   solve();
	}
  return 0;
}
