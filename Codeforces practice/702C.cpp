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

bool check(ll x, vector<ll> &a, vector<ll> &b){
    int ind =0;
    for(int i =0;i<b.size();i++){
        while(ind<a.size()&& (a[ind]>=b[i]-x && a[ind]<=b[i]+x) ){
            ind++;
        }
    }

    return ind==a.size();
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n,0);
    vector<ll> b(m,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll l =0,r = 1e10;

    while(l<=r){
        ll mid = l +(r-l)/2;

        if(check(mid, a,b)){
            r = mid-1;
        }
        else{   
            l = mid+1;
        }

    }
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}