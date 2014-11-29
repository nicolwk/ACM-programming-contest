#include <cstdio>
using namespace std;
int main(){
	long total[10001];
	int n=1, ni=0;
	total[0] = 0;
	for(int i=1; i<=10000; i++){
		total[i] = total[i-1] + n;
		ni++;
		if(ni == n){
			n++;
			ni = 0;
		}
	}
	while(scanf("%d", &n), n)
		printf("%d %ld\n", n, total[n]);
}

