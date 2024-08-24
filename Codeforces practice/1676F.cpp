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
    vector<ll> vect(n);
    map<ll,ll> umap;
    for(int i=0;i<n;i++){
        cin>>vect[i];
        umap[vect[i]]++;
    }
    vector<pair<ll,ll>> vpp;

    for(auto x: umap){
        vpp.push_back({x.first , x.second});
    }
    sort(vpp.begin(), vpp.end());

    int m = vpp.size();
    ll lans=-1, rans=-1;
    ll maxAns =0;
    ll l=0;
    ll r=0;

    while(r<m){
        if((vpp[r].first - vpp[l].first) > r-l){
            l=r;
        }

        if(vpp[r].second<k){
            l=r+1;
        }
        else{
            while(vpp[l].second<k && l<m){
                l++;
            }
            if(r-l+1>maxAns){
                maxAns = r-l+1;
                lans =vpp[l].first;
                rans =vpp[r].first;
            }
        }
        r++;
    }
    if(lans==-1){
        cout<<-1<<"\n";
        return;
    }
    cout<<lans<<" "<<rans<<"\n";
        return;
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