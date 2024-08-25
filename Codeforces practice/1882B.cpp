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

void solve(){
    ll n;
    cin>>n;
    
    vector<set<int>> vs;
    set<int> total;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        set<int> st;
        for(int j=0;j<k;j++){
            int temp;
            cin>>temp;
            st.insert(temp);
            total.insert(temp);
        }
        vs.push_back(st);
    }
    int ans  =0;
    
    for(auto x: total){
        set<int> tempSet;
        for(int i=0;i<n;i++){
            if(vs[i].find(x)==vs[i].end()){
                tempSet.insert(vs[i].begin(), vs[i].end());
            }
        }
        ans = max(ans, (int)tempSet.size());
    }

    cout<<ans<<"\n";
    ///which number should you exclude?
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