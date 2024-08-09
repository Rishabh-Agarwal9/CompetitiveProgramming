#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vi;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;

void print(vi &a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << "\n";
}
void print(int &a){
    cout << a << " ";
}
void print(string &s){
    cout << s << " ";
}
void print(pair<int,int> &p){
    cout << p.first << " " << p.second << "\n";
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }

    vector<int> dp(n,0);

    for(int i=n-2;i>=0;i--){
        if(vect[i+1]>=vect[i]){
            dp[i]=dp[i+1] +(vect[i+1]-vect[i]+1);
        }
        else{
            dp[i] = max(1LL*0 , dp[i+1]+vect[i+1]-vect[i]+1);
        }
    }
    ll ans =INT_MIN;
    for(int i=0;i<n;i++) ans = max(ans, vect[i]+dp[i]);
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