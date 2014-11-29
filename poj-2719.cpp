#include <cstdio>
using namespace std;
int main(){
	long N, ori;
	while(scanf("%ld", &N), N){
		int base = 1;
		while(base < N)
			base *= 10;
		ori = N;
		while(base > 0){
			ori -= (ori/base+5)/10*base;
			base /= 10;
		}
		printf("%ld: %ld\n", N, ori);
	}
}

