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
string flipWhole(string a){
    string temp;

    for(auto x: a){
        if(x=='1'){
            temp.push_back('0');
        }
        else{
            temp.push_back('1');
        }
    }

    return temp;
}
void solve(){   
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    bool extra = false;
    if(a==b){
       extra = false;
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                cout<<"NO"<<"\n";
                return;
            }
        }
        extra = true;
    }
    vector<pair<int,int>> op;
    if(extra){
        op.push_back({1,n});
    }
    a=b;
    int count1=0;
    for(auto x:a){
        if(x=='1'){
            count1++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            op.push_back({i+1,i+1});
        }
    }   
    
    if(count1%2==1){
        int ind = op[op.size()-1].first;
        op.pop_back();
        if(ind==1){
            op.push_back({2,n});
            op.push_back({1,n});
        }
        else{
            op.push_back({1,ind-1});
            op.push_back({1,ind});
        }

    }
    cout<<"YES"<<"\n"<<op.size()<<"\n";
    for(auto x: op){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    

}
//odd no of 1s and even n then there is an issue.

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