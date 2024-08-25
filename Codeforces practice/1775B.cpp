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
    
    vector<vector<ll>> vect;
    map<ll, ll> umap;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        vector<ll> temp;
        for(int j=0;j<k;j++){
            ll t;
            cin>>t;
            temp.push_back(t);
            umap[t]++;
        }
        vect.push_back(temp);
    }
    if(n==1){
        if(umap[0]==1){
            cout<<"YES"<<"\n";
            return;
        }
        else{
            cout<<"NO"<<"\n";
            return;
        }
        
    }
    int count =0;
    for(int i=0;i<n;i++){
        bool found =false;
        for(int j=0;j<vect[i].size();j++){
            if(umap[vect[i][j]]==1){
                found = true;
                break;
            }
        }
        if(found){
            count++;
        }

    }
    if(count==n){
        cout<<"no"<<"\n";
        return;
    }
    cout<<"yes"<<"\n";
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