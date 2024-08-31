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

ll n;
vector<ll> vect;

ll oddPos(){
    ll num =0;

    for(int i=1;i<n-1;i+=2){
        if(vect[i]<= max(vect[i-1], vect[i+1])){
            num +=max(vect[i-1], vect[i+1]) - vect[i] +1;
        }
    }

    return num;
}
ll evenPos(){
    vector<ll> temp;
    for(int i=1;i<n-1;i++){
        if(vect[i]<= max(vect[i-1], vect[i+1])){
            temp.push_back(max(vect[i-1], vect[i+1]) - vect[i] +1);
        }
        else{
            temp.push_back(0);
        }
    }
    
    vector<ll> v1,v2;
    v2.push_back(temp[temp.size()-1]);
    v1.push_back(temp[temp.size()-2]);

    for(int i=temp.size()-3;i>=0;i--){
        if(i%2==1){
            v2.push_back(v2[v2.size()-1]+temp[i]);
        }
        else{
            v1.push_back(temp[i]);
        }
    }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    ll ans = LLONG_MAX;
    ll sum =0;
    for(int i=0;i<v1.size();i++){
        ans = min(ans, sum + v2[i]);

        sum +=v1[i];
    }
    ans = min(ans, sum);
    return ans;

}
void solve(){
    cin>>n;
    vect.resize(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }

    ll needed =0;
    if(n%2==1){
        cout<<oddPos()<<"\n";
    }
    else{
        cout<<evenPos()<<"\n";
    }


// we actually haVE no choice when odd 
    
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