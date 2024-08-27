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
    ll n ,w, h;
    cin>>n>>w>>h;
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(h>w){
        cout<<"NO"<<"\n";
        return;
    }
    vector<vector<ll>> vect(n);
    for(int i=0;i<n;i++){
        vector<ll> temp;

        temp = {(a[i]-w) - (b[i]-h) ,  (a[i]+w) - (b[i]+h)};

        sort(temp.begin(), temp.end());
        vect[i]=temp;
        
    }

    ll l = vect[0][0];
    ll r = vect[0][1];
    for(int i=1;i<n;i++){
        if(vect[i][1] < l || vect[i][0] > r){
            cout<<"NO"<<"\n";    
            return;
        }
        l =  max(l, vect[i][0]);
        r =  min(r, vect[i][1]);
    }

    cout<<"YES"<<"\n";

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