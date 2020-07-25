#include <cstdio>
#include <iostream>
#include <cmath>
#define pi 3.14159265358979323846

using namespace std;

int main(){
	int R,L,W;
	double A; int count=0;
	while(cin >> R >> L >> W){
		
		double w6=W/2;double l6=L/2;
	if(R>W/2 && R<=L/2){
		A = pi*R*R - 2*(R*R*acos(w6/R)-w6*sqrt(R*R-w6*w6));
	}
	else if(R<=W/2 && R>L/2){
		A = pi*R*R - 2*(R*R*acos(l6/R)-l6*sqrt(R*R-l6*l6));
	}
	else if(R>L/2 && R>W/2){
		A = L*W;
	}
	else{
		A = pi*R*R;
	}
	
	printf("%.8lf",A);
	}
	
	return 0;
}
