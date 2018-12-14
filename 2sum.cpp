#include <bits/stdc++.h>

using namespace std;

int sum_exists(int arr[], int x, int n){
    int i=0, j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==x){
            cout<<"Yes"<<endl;
            return 1;
        }
        else if(arr[i]+arr[j]<x){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<"No"<<endl;
    return 0;
}


int main(){
    // check if a pair of numbers with sum = x exists in the given array.
    int n, x, t;
    cin>>t;
    for(int h=0; h<t; h++){
        cin>>n>>x;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        sum_exists(arr, x, n);
    }
    return 0;
}
