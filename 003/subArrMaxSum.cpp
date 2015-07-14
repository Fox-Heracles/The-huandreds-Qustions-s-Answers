#include <iostream>
using namespace std;
static int steps=0;
int subArrayMaxSum(int *arr,int n)
{
    int sum=0;
    for(int j=1; j<n-1; j++)
    {
        int sumtemp=0;
        for(int i=0; i<n; i++)
        {
            for(int k=i;k<=j;k++)
            {
                sumtemp+=arr[k];
                steps++;
            }
            if(sumtemp>sum) sum=sumtemp;
        }
    }
    return sum;
}
int main()
{
    int a[]={1, -2, 3, 10, -4, 7, 2, -5};
    int b=subArrayMaxSum(a,8);
    std::cout<<b<<" "<<steps;
    return 0;
}
