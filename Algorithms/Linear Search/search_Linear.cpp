#include <stdio.h>
int a[10001];
int linearSearch(int a[10001], int n, int key){
    for(int index = 0; index < n; ++index){
        if(a[index] == key)
            return index;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n, key;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &key);
    printf("%d", linearSearch(a,n,key));
    return 0;
}