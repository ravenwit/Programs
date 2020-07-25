#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template <typename A, typename B>
multimap<B, A> flip_map(map<A, B> &__map){
    multimap<B, A> out;
    for(auto &i: __map)
        out.insert(pair<B, A>(i.second, i.first));
    return out;
}

void __init(const string &line);
int main(){
    string line;
    while(getline(cin, line)) __init(line);
    return 0;
}
bool blu = false;
void __init(const string &line){
	if(blu) cout << endl;
	else blu = true;
    map<char, int> frq;
    for(int i = 0; i < line.length(); i++) frq[line[i]]++;
    multimap<int, char> frq_out = flip_map(frq);
    for(multimap<int, char>::const_iterator it = frq_out.begin(); it != frq_out.end(); ++it){
        int count_s = frq_out.count(it->first);
        if(count_s > 1){
			for(int i = 0; i < count_s - 1; i++) it++;
			for(int i = 0; i < count_s; i++){
				cout << (int)it->second << " " << it->first << endl;
				if(i < count_s - 1) --it;
			}
			for(int i = 0; i < count_s - 1; i++) it++;
			continue;
        }
       cout << (int)it->second << " " << it->first << endl;
    }
}
