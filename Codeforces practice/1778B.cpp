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
    ll n,m,d;
    cin>>n>>m>>d;
    vector<ll> perm(n);
    vector<ll> a(m);
    map<int,int> pos;
    for(int i=0;i<n;i++){
        cin>>perm[i];
        pos[perm[i]]=i;
    }

    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    ll ans = LLONG_MAX;
    for(int i=0;i<m-1;i++){
        ll pos1 = pos[a[i]];
        ll pos2 = pos[a[i+1]];

        ll k = pos2-pos1;
        if(k<0) k=0;

        ll t = LLONG_MAX;

        if(pos2>pos1){
            ll diff = d + 1 - (pos2 - pos1);
            if(diff<=0){
                t=0;
            }
            else{
                if(pos1 + (n-1 -pos2)>=diff){
                    t = diff;
                }
            }
        }

        ans=  min({ans, k,t });
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