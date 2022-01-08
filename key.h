#include<iostream>
#include<cmath>
using namespace std;
int hasFn(string key, int ts) {
	int idx = 0;
	int power = 1;
	for (auto ch : key) {
		idx = (idx + ch * power) % ts;
		power = (power * 29) % ts;
	}
	return idx;
}