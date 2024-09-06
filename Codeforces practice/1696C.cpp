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
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll k;
    cin>>k;
    vector<ll> b(k);
    for(int i=0;i<k;i++){
        cin>>b[i];
    }

    vector<pair<ll,ll>> vpp;
    for(int i =0;i<n;i++){
        int val =1;
        while(a[i]%m==0){
            val*=m;
            a[i]/=m;
        }
        if(vpp.empty()){
            vpp.push_back({a[i], val});
            continue;
        }
        if(vpp[vpp.size()-1].first==a[i]){
            vpp[vpp.size()-1].second+=val;
        }
        else{
            vpp.push_back({a[i], val});

        }
    }

    vector<pair<ll,ll>> vpp2;
    for(int i =0;i<k;i++){
        int val =1;
        while(b[i]%m==0){
            val*=m;
            b[i]/=m;
        }
        if(vpp2.empty()){
            vpp2.push_back({b[i], val});
            continue;
        }
        if(vpp2[vpp2.size()-1].first==b[i]){
            vpp2[vpp2.size()-1].second+=val;
        }
        else{
            vpp2.push_back({b[i], val});

        }
    }

    if(vpp.size()!=vpp2.size()){
        cout<<"NO"<<"\n";
        return;
    }
    for(int i=0;i<vpp.size();i++){
        if(vpp[i]!=vpp2[i]){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";

    // if some number is not divisible by m then we cant move numbers through that barrier
    ///decompose down to prime factorz
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