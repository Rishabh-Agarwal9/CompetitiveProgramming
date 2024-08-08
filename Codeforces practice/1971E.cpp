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
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(k);
    vector<ll> b(k);
    for(int i=0;i<k;i++){
        cin>>a[i];
    }

    for(int i=0;i<k;i++){
        cin>>b[i];
    }

    vi qur(q);
    for(int i=0;i<q;i++){
        cin>>qur[i];
    }
    a.insert(a.begin(),0);
    b.insert(b.begin(),0);

    vector<ll> ans(q);

    for(int i=0;i<q;i++){
        int query = qur[i];
        int idx = lower_bound(a.begin(),a.end(), query) - a.begin();
        if(a[idx]==query){
            ans[i]=b[idx];
            continue;
        }

        ll num = (double)((query-a[idx-1]) *(b[idx]-b[idx-1]))/((a[idx]-a[idx-1])) ;
        ans[i]=b[idx-1]+num;
    }
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";

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