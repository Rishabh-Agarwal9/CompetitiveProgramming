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
    ll n,x;
    cin>>n>>x;
    if(n%x!=0){
        cout<<-1<<"\n";
        return;
    }
    // if n is prime then impossible 
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){
        ans[i]  = i;
    }
    ans[1] = x;
    ans[n]=1;
    while(x<n){
        for(int i =2*x;i<=n;i+=x){
            if(n%i==0){
                ans[x] = i;
                x=i;
                break;
            }
        }
    }


    for(int i =1;i<=n;i++){
        cout<<ans[i]<<" ";
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