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
ll n,k;

ll help( vector<ll> &a, vector<ll> &b){
    ll m = a.size();
    ll ans =0;
    ll i=m-1;
    while(i>=0){
        ans+=2*a[i];
        i-=k;
    }
    if(b.size()==0){
        ans-=a[m-1];
        return ans;
    }

    m = b.size();
    i=m-1;
    while(i>=0){
        ans+=2*b[i];
        i-=k;
    }
    ans-=b[m-1];
    return ans;
}

void solve(){
    cin>>n>>k;
    vector<ll> x(n);
    vector<ll> neg;
    vector<ll> pos;

    for(int  i=0;i<n;i++){
        cin>>x[i];

        if(x[i]<0){
            neg.push_back(-x[i]);
        }
        else{
            pos.push_back(x[i]);
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    ll ans=0;
    if(neg.empty() ){
        ans=help(pos,neg);
    } 
    else if (pos.empty()){
        ans=help(neg, pos);
    }
    else if (neg[neg.size()-1] > pos[pos.size()-1]){
        ans=help(pos,neg);
    }
    else{
        ans=help(neg, pos);
    }

    cout<<ans<<"\n";


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