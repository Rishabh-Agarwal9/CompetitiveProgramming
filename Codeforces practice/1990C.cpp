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
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>vect[i];
        ans+=vect[i];
    }
    unordered_set<ll> st;
    vector<ll> a(n,0);
    ll maxi =0;
    for(ll i=0;i<n;i++){
        if(st.find(vect[i])==st.end()){
            st.insert(vect[i]);
        }
        else{
            maxi = max(maxi , vect[i]);
        }
        a[i]=maxi;
        ans+=maxi;
    }
    st.clear();
    maxi =0;
    for(ll i=0;i<n;i++){
        if(st.find(a[i])==st.end()){
            st.insert(a[i]);
        }
        else{
            maxi = max(maxi , a[i]);
        }
        a[i]=maxi;
    }
    st.clear();

    for(ll i=0;i<n;i++){
        ans+= a[i] *(n-i);
    }

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