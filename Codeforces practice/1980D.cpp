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

bool helper(vector<int> &a){
    int n  =a.size();
    int prev = __gcd(a[0], a[1]);
    for(int i=1;i<n-1;i++){
        int curr = __gcd(a[i], a[i+1]);
        if(curr<prev){
            return false;
        }
        prev =curr;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    int ind =-1;
    int prev = __gcd(vect[0], vect[1]);
    for(int i=1;i<n-1;i++){
        int curr = __gcd(vect[i], vect[i+1]);
        if(curr<prev){
            ind=i;
            break;
        }
        prev =curr;
    }
    if(ind==-1){
        cout<<"YES"<<"\n";
        return;
    } 
    vector<int> a=vect,b=vect, c=vect;
    a.erase(a.begin()+ind-1);
    b.erase(b.begin()+ind);
    c.erase(c.begin()+ind+1);
    if(helper(a)||helper(b)||helper(c)){
        cout<<"YES"<<"\n";

    }
    else{
        cout<<"NO"<<"\n";

    }

    return;
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