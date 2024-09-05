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
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    vector<ll> minAns;
    for(int i=0;i<n;i++){
        int ind = lower_bound(b.begin(), b.end() , a[i]) - b.begin();
        minAns.push_back(b[ind] - a[i]);
    }

    vector<ll> maxAns(n);

    int ind = n-1;
    for(int i=n-1;i>=0;i--){
        maxAns[i]=(b[ind] - a[i]);
        int temp = lower_bound(b.begin(), b.end() , a[i]) - b.begin();
        if(i==temp){
            ind = i-1;
        }        
    }

    for(auto x: minAns){
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto x: maxAns){
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