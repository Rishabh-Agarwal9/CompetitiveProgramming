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
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=261;

        //anything with a 0 can be evaluated to 0(except 2 digit numbers like 10 or 01 and 3 digit nums)

        for(int i=1;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(j==i){
                    int a = temp[temp.size()-1];
                    temp.pop_back();
                    a=a*10+s[j]-'0';
                    temp.push_back(a);
                }
                else{
                    temp.push_back(s[j]-'0');
                }
            }
            ll sum =0;

            for(auto x:temp){
                if(x==1){
                    
                    continue;
                } 
                if(x==0){
                    ans=0;
                }
                else{
                    sum+=x;
                }
            }
            if(sum==0) sum=1;
            ans = min(ans, sum);
        }


        cout<<ans<<"\n";
    }
    return 0;
}



