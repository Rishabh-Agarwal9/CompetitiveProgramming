#include<bits/stdc++.h>

using namespace std;

void deletion(vector<int> &arr, int &n ){
    swap(arr[1], arr[n-1]);
    n--;
    int i =1;
    while(i<=n/2-1){
        int leftChild = 2*i;
        int rightChild = 2*i+1;
        if(max(arr[leftChild], arr[rightChild])>arr[i]){
            if(arr[leftChild]>arr[rightChild]){
                swap(arr[leftChild], arr[i]);
                i=leftChild;
            }
            else{
                swap(arr[rightChild], arr[i]);
                i=rightChild;
            }
        }
        else{
            break;
        }
    }
}


int main(){
    vector<int> arr = {-1,1,2,456,23,4,656,723};
    int n = arr.size();
    for(int i =1;i<n;i++ ){
        int parent = i/2;
        int curr = i;
        while(parent>=1&&arr[curr]>arr[parent]){
            
            
            swap(arr[curr],arr[parent]);
            curr = parent;
            parent = parent/2;
        }

    }

    deletion(arr, n);
    deletion(arr, n);


    //we want to remove top;

    


    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}