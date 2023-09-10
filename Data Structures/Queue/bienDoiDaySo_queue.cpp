#include <iostream>
using namespace std;
void nhap(long long a[], long long n){
for(long long i = 0; i < n; i++){
cin >> a[i];
}
}
void sapxep(long long a[], long long n){
for(long long i = 0; i < n - 1; i++){
for(long long j = i + 1; j < n; j++){
if(a[i] % 2 == 0){
if(a[i] < a[j] ){
long long tmp = a[i];
a[i]= a[j];
a[j] = tmp;
}
}
else{
if(a[i] > a[j] ){
long long tmp = a[i];
a[i]= a[j];
a[j] = tmp;
}
}
}
}
for(long long i = 0; i < n; i++){
if(a[i] % 2 == 0){
cout << a[i] <<" ";
}
}
for(long long i = 0; i < n; i++){
if(a[i] % 2 == 1){
cout << a[i] <<" ";
}
}
}
int main()
{
long long n;
cin >> n;
long long a[n];
nhap(a, n);
sapxep(a,n);
return 0;
}