#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,unroll-loops") // change to O3 to disable fast-math for geometry problems
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <stdio.h>
#include <stdlib.h>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[],int low,int high)
{
  //choose the pivot

    int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
    int i=(low-1);

    for(int j=low;j<=high;j++)
    {
    //If current element is smaller than the pivot
        if(arr[j]<pivot)
        {
      //Increment index of smaller element
        i++;
        swap(arr[i],arr[j]);
    }
}
    swap(arr[i+1],arr[high]);
    return (i+1);
}

// The Quicksort function Implement
            
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
    if(low<high)
    {
        // pi is the partition return index of pivot
        
        int pi=partition(arr,low,high);
        
        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int a[] = {11, 13, 1, -5, 32, 99, 78, 6};
    int n = sizeof(a) / 4;

    quickSort(a, 0, 7);

    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
    return 0;
}