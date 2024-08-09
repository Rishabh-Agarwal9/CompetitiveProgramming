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
    vector<ll> vect(n,0);
    for(int i =0;i<n;i++){
        cin>>vect[i];
        if(vect[i]<0){
            vect[i]= -vect[i];
        }
    }
    sort(vect.begin(), vect.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        int idx = upper_bound(vect.begin(), vect.end(), 2*vect[i]) - vect.begin();
        ans+=idx-i-1;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    return 0;
}