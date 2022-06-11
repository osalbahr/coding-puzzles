#include <iostream>
// #include <bits/stdc++.h>
#include <math.h> 
#include <cmath>
#include <map>
#include <cassert>
#include <utility>  
#include <string.h>  
#include <list>
#include <algorithm>
#include <string>
#include <cstdlib>
// #include <bits/stl_algobase.h>
#include <iterator>	
using namespace std;


int main() {		
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
		
	int t;
	cin >>t;
	for(int i = 0; i <t;i++){
		int num;
		cin >> num;
		int b1,b2,b3;
		b1 = 0;
		b2 = 0;
		b3 = 0;
		num-=3;
		b1++;
		b2++;
		b3++;
		while(num > 0){
			if(b2-b1 > 1){
				b1++;
				num--;
			}
			else if(b1-b3 > 1){
				b3++;
				num--;
			}
			else{
				b2++;
				num--;
			}

		}
		cout << b1 << " " << b2 << " " << b3 << endl;
	}

	
}



