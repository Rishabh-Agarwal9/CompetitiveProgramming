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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--){
        ll n;
        cin>>n;
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        
        ll s1=0,s2=0;
        ll ones=0, minus=0;
        for(int i =0;i<n;i++){
            if(a[i]>b[i]){
                s1+=a[i];
            }
            else if(a[i]<b[i]){
                s2+=b[i];
            }
            else{
                if(a[i]==1) ones++;
                else if(a[i]==-1) minus++;
            }
        }

        while(minus--){
            if(s1<s2){
                s2--;
            }
            else{
                s1--;
            }
        }
        while(ones--){
            if(s1<s2){
                s1++;
            }
            else{
                s2++;
            }
        }

        cout<<min(s1,s2)<<"\n";


    }
    return 0;
}