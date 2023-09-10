#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,unroll-loops") // change to O3 to disable fast-math for geometry problems
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    scanf(n);
    printf("%d", n);
    return 0;
}