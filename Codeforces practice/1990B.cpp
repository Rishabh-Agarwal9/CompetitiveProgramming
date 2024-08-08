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
    ll n,x,y;
    cin>>n>>x>>y;
    vector<int> ans(n,1);
    int flag =0;
    for(int i=y-2;i>=0;i--){
        if(flag==0){
            ans[i]=-1;
        }
        else{
            ans[i]=1;
        }
        flag=1-flag;
    }
    flag =0;
    for(int i =x;i<n;i++){
        if(flag==0){
            ans[i]=-1;
        }
        else{
            ans[i]=1;
        }
        flag = 1-flag;
    }
    for(auto x: ans){
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