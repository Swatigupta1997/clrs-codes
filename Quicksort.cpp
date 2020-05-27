#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
   // Your code here
  int i = low-1;
  for(int j=low; j<=high-1; j++){
      if(arr[j]<arr[high]){
          i++;
          swap(arr[i], arr[j]);
      }
  }
  i++;
  swap(arr[i], arr[high]);
  return i;
}  
    
void quicksort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){
    int arr[8]={1,4,5,6,2,7,8,3};
    quicksort(arr, 0, 7);
    for(int i=0; i<8; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
