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
    ll n,k;
    cin>>n>>k;
    vector<ll> vect(k);
    for(int i=0;i<k;i++){
        cin>>vect[i];
    }
    if(k==1){
        cout<<"YES"<<"\n";
        return;
    }
    vector<ll> temp ={vect[1]-vect[0]} ;
    for(int i=2;i<k;i++){
        ll num =vect[i] - vect[i-1];

        if(num <temp[temp.size()-1] ){
            cout<<"NO"<<"\n";
            return;
        } 
        temp.push_back(num);
    }   

    if((n-k+1)* temp[0] < vect[0]){
        cout<<"NO"<<"\n";
        return;
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