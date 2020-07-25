#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string outp(bool in){
    if(in) return "YES"; else return "NO";
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R,C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r,c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        bool out=0;
        for(int G_i=0;G_i<R;G_i++){
            if(G[G_i].find(P[0])!=string::npos){ size_t found = G[G_i].find(P[0]);
                for(int P_i=1;P_i<r;P_i++,G_i++){
                    if(G_i>=R) break;
                    if(G[G_i+1].find(P[P_i])==string::npos) break; else if(G[G_i+1].find(P[P_i]) != found) break;
                    if(P_i == r-1) {out = 1;break;}
                }
            }
            if(out) break;
        }
        cout << outp(out) << endl;
    }
    return 0;
}
