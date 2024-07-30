#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    while(n--){
        int x,y;
        cin>>x>>y;
        if(x*15>=2*y){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
    
}


// always use "\n" for new line and not endl
