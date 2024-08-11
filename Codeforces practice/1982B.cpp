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
    ll x,y,k;
    cin>>x>>y>>k;
    // get x down to 1 


    while(x>1&&k>0){
        x++;
        k--;
        ll rem = (x)%y;
        ll needed = (y-rem);
        if(needed==y){
            needed=0;
        } 
        
        ll mini= min(needed, k);

        k-=mini;

        x+=mini;
        while(x%y==0){
            x/=y;
        }
    }   

    if(k==0){
        cout<<x<<"\n";
        return;
    }

    cout<<x + k%(y-1)<<"\n";


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