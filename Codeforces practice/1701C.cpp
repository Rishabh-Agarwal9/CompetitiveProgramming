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
vector<ll> mVect;

ll n,m;
bool check(ll x){

    ll toDistribute = 0;
    for(int i=n-1;i>=0;i--){
        if(x<=mVect[i]){
            toDistribute += (mVect[i] - x);
        }
        else{
            toDistribute -=(x-mVect[i])/2;
        }
    }
    if(toDistribute<=0) return true;
    return false;
}
void solve(){
    cin>>n>>m;
    vector<ll> vect(m);
    map<ll,ll>mp;
    for(int i=1;i<=n;i++){
        mp[i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>vect[i];
        mp[vect[i]]++;
    }
    mVect.clear();  
    for(auto x: mp){
        mVect.push_back(x.second);
    }
    sort(mVect.begin(), mVect.end());
    ll l=1;
    ll r= mVect[n-1];

    while(l+1<r){
        ll mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<"\n";
    //BINARY SEARCHHHHHHHHHHHHHHHHHHHHH

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