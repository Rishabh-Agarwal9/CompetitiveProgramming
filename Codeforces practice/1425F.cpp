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
    int n;
    cin>>n;
    vector<int> ans;
    cout<<"? 2 3"<<endl;
    int tt;
    cin>>tt;
    cout<<"? 1 3"<<endl;
    int ot;
    cin>>ot;
    ans.push_back(ot-tt);
    for(int i=1;i<n;i++){
        if(i==2){
            ans.push_back(tt-ans[ans.size()-1]);
        }
        else{
            cout<<"? "<<i<<" "<<i+1<<endl;
            int temp;
            cin>>temp;
            ans.push_back(temp-ans[ans.size()-1]);
        }
    }
    cout<<"! ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}