#include <cstdio>
#include <math.h>

using namespace std;
int main(){
    long long int x;
    scanf("%lld", &x);
    double a = (pow((1+pow(5,0.5))/(2.0),x) - pow(((1-pow(5,0.5))/(2.0)),x))/pow(5,0.5);
    printf("%f", a);
    return 0;
}