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

    if(m==1){
        cout<<0<<"\n";
        for(int i=0;i<n;i++){
            cout<<0<<"\n";
        }
        return;
    }

    cout<<min(n+1 , m)<<"\n";
    for(int i=0;i<n;i++){
        int num =(i+1)%m;
        if(num==0) num++;
        for(int j=0;j<m;j++){
            cout<<num<<" ";
            num = (num +1) % (m);
        }
        cout<<"\n";
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