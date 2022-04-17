#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c;
    float l, s;
    scanf("%d %d %d", &a, &b, &c);
    l = a + b + c;
    float p = l / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("circumference=%.2f area=%.2f", l, s);
    return 0;
}