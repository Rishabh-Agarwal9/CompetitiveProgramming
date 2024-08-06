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
    ll l  =1;
    ll r  = 1e6;

    while(l<=r){
        ll mid = (l+r)/2;
        cout<<mid<<endl;
        // fflush(stdout);
        string response;
        cin>>response;

        if(response=="<"){
            r =mid-1;
        }
        else{
            l= mid+1;
        }
    }
    cout<<"! "<<l-1<<endl;
    fflush(stdout);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}