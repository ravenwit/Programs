#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	int t,n,a,b,c,rsult=1;
	cin >> t; int i=1;
	while(i<=t){
		cin >> n; vector<double>slopes; vector<int>count; int j=0;rsult=1;
		while(j<n){
			cin >> a >> b >> c;
			double sl=b/a;
				for(int yui=0;yui<slopes.size();yui++){
					if(sl==slopes[yui]) {count[yui]++; goto con;}}
				
				slopes.push_back(sl);count.push_back(1);

				con:
				int hj = slopes.size();

			j++;
		}
		for(int yui=0;yui<count.size();yui++){
			rsult*=count[yui];
		}
		cout << rsult << endl;
		i++;
	}
	return 0;
}