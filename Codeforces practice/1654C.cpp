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
    ll sum =0;
    priority_queue<ll> pq;
    priority_queue<ll> pq2;
    for(int i=0;i<n;i++){
        cin>>vect[i];
        sum+=vect[i];
        pq.push(vect[i]);
    }   
    pq2.push(sum);

    while(!pq.empty()){
        if(pq.top()==pq2.top()){
            pq.pop();
            pq2.pop();
        }
        else if(pq.top()>pq2.top()){
            cout<<"NO"<<"\n";
            return;
        }
        else{
            ll top = pq2.top();
            pq2.pop();
            pq2.push(top/2);
            pq2.push(top/2 + (top%2));
        }
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