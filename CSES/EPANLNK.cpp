#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        string x;
        cin>>x;
        int y=x.length();
        if(y<2){
            cout<<x<<"\n";
        }

        else{
            int num= (int(x[y-1])-48)+(int(x[y-2])-48)*10;
            cout<<num%20<<"\n";
        }


    }
    return 0;
}


// always use "\n" for new line and not endl
