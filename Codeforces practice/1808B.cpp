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
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> vect(n, vector<ll> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vect[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        vector<ll> temp;
        for(int j=0;j<n;j++){
            temp.push_back(vect[j][i]);
        }
        sort(temp.begin(), temp.end());
        ll sum=0;
        for(int j=0;j<n;j++){
            ans += temp[j]*(j)-sum;
            sum+=temp[j];
        }
    }
    cout<<ans<<"\n";
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