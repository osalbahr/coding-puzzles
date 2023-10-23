#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
while(cin>>n)
cout<<n<<" is "<<(n%2?"odd":"even")<<endl;
}
