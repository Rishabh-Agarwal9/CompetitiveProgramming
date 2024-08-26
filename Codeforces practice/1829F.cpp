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
    vector<ll> vect(n+1,0);
    for(int i=0;i<m;i++){
        ll t1,t2;
        cin>>t1>>t2;
        vect[t1]++;
        vect[t2]++;
    }   
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        if(vect[i]!=1){
            mp[vect[i]]++;
        }
    }

    if(mp.size()==2){
        int v1,v2;
        for(auto x: mp){
            if(x.second==1){
                v1=x.first;
            }
            else{
                v2=x.first;
            }
        }

        cout<<v1<<" "<<v2-1<<"\n";
        return;
    }
    ll val = mp.begin()->first;
    cout<<val<<" "<<val-1<<"\n";

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