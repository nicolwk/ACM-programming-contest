#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
using namespace std;
int main(){
	unsigned int _MAX, dequeMax = 0, count = 0, diffMax = 0, lastOne = 0;
	long double plog = 0;
	cin >> _MAX;
	vector<unsigned int> prime;
	deque<unsigned int> window;
	window.push_back(0);
	window.push_back(0);
	window.push_back(1);
	unsigned int sroot = sqrt(_MAX);
	unsigned int _MAX_i = _MAX;
	auto movePrime = [&](unsigned int j, unsigned int inc){
		while(j <= _MAX_i){
			if(j >= window.size())
				for(unsigned int k=window.size(); k<=j; k++)
					window.push_back(1);
			if(window[j] > 1)
				j += inc;
			else
				break;
		}
		if(j <= _MAX_i)
			window[j] = inc;
	};
	for(unsigned int i=0; i<=_MAX; i++){
		unsigned int I = window.front();
		if(I > 1){
			movePrime(0, I);
		}else if(I == 1){
			if(i <= sroot)
				movePrime(i, i);
			count++;
			if(i-lastOne > diffMax)
				diffMax = i-lastOne;
			lastOne = i;
			plog += log(i);
		}
		if(window.size() > dequeMax)
			dequeMax = window.size();
		window.pop_front();
		_MAX_i--;
	}
	cout << "Maximum window size: " << dequeMax << endl;
	cout << "Prime numbers count: " << count << endl;
	cout << "Last prime number: " << lastOne << endl;
	cout << "Log of product of all prime number found: " << plog/log(2) << endl;
	cout << "Average bits of prime number found: " << plog/log(2)/count << endl;
	cout << "Largest difference: " << diffMax << endl;
}
