#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,unroll-loops") // change to O3 to disable fast-math for geometry problems
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <stdio.h>

void selectionSort(int a[], int n){
    int min_index;
    for(int i = 0; i<n-1; i++){
        min_index = i;
        for(int j =i+1; j < n; j++){
            if(a[j] < a[min_index])
                min_index = j;
        }
        if(i != min_index){
            int tmp;
            tmp = a[i];
            a[i] = a[min_index];
            a[min_index] = tmp; 
        }
    }
}

int main(){
    int a[10001], n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    selectionSort(a,n);
    
    for(int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}