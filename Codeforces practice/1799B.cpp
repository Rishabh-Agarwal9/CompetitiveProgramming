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
    vector<ll> vect(n);
    // if array has a 1 then not possible , unless all are 1
    priority_queue<pair<ll,ll>> maxi;
    ll mini = LLONG_MAX;
    ll minInd = -1;
    for(int i=0;i<n;i++){
        cin>>vect[i];
        maxi.push({vect[i],i});
        if(vect[i]<mini){
            mini = vect[i];
            minInd = i;
        }
    }
    vector<pair<ll,ll>> vpp;
    while(maxi.top().first != mini){
        if(mini==1){
            cout<<-1<<"\n";
            return;
        }

        auto high = maxi.top();
        maxi.pop();

        high.first = ceil ((double)high.first/mini);
        vpp.push_back({high.second , minInd});

        if(high.first<mini){
            mini = high.first;
            minInd = high.second;
        }
        maxi.push(high);
    }

    cout<<vpp.size()<<"\n";

    for(auto x:vpp){
        cout<<x.first+1<<" "<<x.second+1<<"\n";
    }


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