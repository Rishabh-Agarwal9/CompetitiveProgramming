#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vi;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
//mmi
ll inv(ll a) {
  return a <= 1 ? a : mod - (ll)(mod/a) * inv(mod % a) % mod;
}

//make a fact vect filled to maxN you want to query.
long long binomial_coefficient(ll n, ll k, vector<ll> &fact) {
    if(k>n) return 0;
    return fact[n] * inv(fact[k] * fact[n - k] % mod) % mod;
}

void print(vi &a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << "\n";
}
pair<int,int> get_path_end(int c , vector<int> & edge) {
		int len = 0;
		int cur = c;
		while (edge[cur] != -1)
			len++, cur = edge[cur];
		return make_pair(cur, len);
};
void solve(){
    ll n;
    cin>>n;
    string t;
    cin>>t;
    vector<int> edge(26, -1);
	vector<int> redge(26, -1);
	
	vector<int> vec;
	for (auto c : t)
		vec.push_back(c - 'a');
	for (int i = 0; i < n; i++) {
		if (edge[vec[i]] == -1) {
			for (int c = 0; c < 26; c++)
				if (redge[c] == -1) {
					pair<int,int> pp= get_path_end(c,edge);

                    int clast = pp.first;
                    int len = pp.second;

					if (clast != vec[i] || len == 25) {
						edge[vec[i]] = c;
						redge[c] = vec[i];
						break;
					}
				}
		}
		vec[i] = edge[vec[i]];
	}
 
	for (int i = 0; i < n; i++)
		t[i] = vec[i] + 'a';
 
	cout << t << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--){
        solve();    
    }
    return 0;
}