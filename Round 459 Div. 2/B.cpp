#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void) {
	map<string, string> M;
	int n, m;
	cin >> n >> m;
	while (n--) {
		string name, ip;
		cin >> name >> ip;
		M[ip+';'] = '#'+name;
	}
	while (m--) {
		string command, ip;
		cin >> command >> ip;
		cout << command << ' ' << ip << ' ' << M[ip] << '\n';
	}
}
