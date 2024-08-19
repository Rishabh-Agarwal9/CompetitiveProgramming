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
    ll n, q;
    cin>>n>>q;
    vector<ll> vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    vector<ll> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    vector<ll> maxi(n);
    vector<ll> pre(n);
    pre[0]=vect[0];
    maxi[0]=vect[0];

    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+ vect[i];
    }
    for(int i=1;i<n;i++){
        maxi[i] = max(maxi[i-1], vect[i]);
    }
    vector<ll> ans;
    for(int i=0;i<q;i++){
        ll k = queries[i];
        ll ind = upper_bound(maxi.begin(), maxi.end(), k) - maxi.begin();
        if(ind==0){
            ans.push_back(0);
        }
        else{
            ans.push_back(pre[ind-1]);
        }
    }

    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";
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