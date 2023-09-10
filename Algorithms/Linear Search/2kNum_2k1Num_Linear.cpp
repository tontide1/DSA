#include <stdio.h>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int a[10001], n, check = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 1 && i % 2 == 0){
            printf("%d ", a[i]);
            check++;
        }
    }
    if (check == 0)
    {
        printf("NULL");
    }
    return 0;
}