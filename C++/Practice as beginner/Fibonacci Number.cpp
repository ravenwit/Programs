#include <iostream>

using namespace std;
int fibo(int n);
int main(void)
{
    int n;
    cout<<"How many ? : ";
    cin>>n;
    cout<<"\n\nfirst"<<n<<"fibonacci number: ";
    for(int i=1;i<=n;i++)
    {
        cout<<fibo(i)<<" ";
    }
    return 0;
    getch();
}
int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return (fibo(n-1)+fibo(n-2));
    }

}
