#include <iostream>
using namespace std;
int main(){int w=0,t=0;
for (int i=1;i<=5;i++){
int c=0,j=4;
while (j--) {
int n;
cin >> n, c += n;
}
if (c > t)
t=c,w=i;
}
cout<<w<<" "<<t<<endl;
}
