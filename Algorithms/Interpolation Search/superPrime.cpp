#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using ll = long long;
int checkPrime(ll n){
    if(n < 2)
        return -1;
    else{
        for(ll i = 2; i <= sqrt(n); i++){
            if(n % i == 0)
                return -1;
        }
    }
    return 1;
}

int main(){
    ll n;
    scanf("%lld", &n);
    ll count = 0;
    for (ll i = 2; i <= n; ++i) {
        if (checkPrime(i) == 1) {
            for (ll j = 2; j <= i / 2; ++j) {
                if (checkPrime(j) && checkPrime(i - j)) {
                    ++count;
                    break;
                }
            }
        }
    }
    printf("%lld", count);
    
    return 0;
}