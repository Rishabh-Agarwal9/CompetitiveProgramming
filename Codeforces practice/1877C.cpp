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
    ll n,m,k;
    cin>>n>>m>>k;
    //  i dont thinl its possible for k above 3

    if(k>3){
        cout<<0<<"\n";
        return;
    }
    if(k==1){
        cout<<1<<"\n";
        return;
    }
    if(k==2){
        ll mini = min(n-1, m);
        cout<<m/n + mini<<"\n";
        return;
    }
    if(k==3){
        if(m<=n){
            cout<<0<<"\n";
            return;
        }
        cout<<m-n - m/n+1<<"\n";
        return;
    }


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