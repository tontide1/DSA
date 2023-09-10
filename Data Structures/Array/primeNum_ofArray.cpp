#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int checkPrime(int n){
    if(n < 2)
        return 0;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a[1001], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++){
        if(checkPrime(a[i]) == 1 )
            printf("%d ", a[i]);
    }
    system("pause");
    return 0;
}