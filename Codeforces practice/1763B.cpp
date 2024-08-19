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
    vector<ll> health(n);
    vector<ll> power(n);


    vector<pair<ll,ll>> vect(n);

    for(int i=0;i<n;i++){
        cin>>health[i];
    } 
    for(int i=0;i<n;i++){
        cin>>power[i];
    } 
    for(int i=0;i<n;i++){
        vect[i] ={health[i], power[i]};
    } 
    sort(vect.begin(), vect.end());

    

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    for(int i=0;i<n;i++){
        pq.push({vect[i].second,i});
    }

    ll num =0;
    ll index =0;
    while(k>0 && index<n &&!pq.empty()){
        num +=k;
        while(index<n && vect[index].first<=num){
            index++;
        }
        while(!pq.empty() && pq.top().second<index){
            pq.pop();
        }
        if(!pq.empty()){
            k-=pq.top().first;
        }
    }

    if(index==n){
        cout<<"YES"<<"\n";
        return;
    }
    cout<<"NO"<<"\n";


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