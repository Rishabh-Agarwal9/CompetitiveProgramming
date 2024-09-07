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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> vect(n , vector<ll> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vect[i][j];
        }
    }
    
    vector<vector<ll>> sorted = vect;

    for(int i=0;i<n;i++){
        vector<ll> temp = sorted[i];
        sort(temp.begin(), temp.end());
        sorted[i] = temp;
    }

    

    vector<pair<int,int>> vpp;
    vector<int> rows;
    for(int i=0;i<n;i++){
        vector<int> incorr;
        for(int j=0;j<m;j++){
            if(vect[i][j]!=sorted[i][j]){
                incorr.push_back(j);
            }
        }
        if(incorr.size()>2){
            cout<<-1<<"\n";
            return;
        }

        if(incorr.size()==0){
            rows.push_back(i);
        }
        else if(incorr.size()==2){
            if(vpp.size()==0){
                vpp.push_back({incorr[0], incorr[1]});
                continue;
            }

            if(!(vpp[0].first == incorr[0] && vpp[0].second == incorr[1])){
                cout<<-1<<"\n";
                return;
            }
        }
    }

    if(vpp.empty()){
        cout<<1<<" "<<1<<"\n";
        return;
    }

    for(auto x: rows){
        if(vect[x][vpp[0].first] != vect[x][vpp[0].second]) {
            cout<<-1<<"\n";
            return;
        }
    }

    cout<<vpp[0].first+1<<" "<<vpp[0].second+1<<"\n";
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