#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	long long position[N];
	long long total = 0;
	for(int i=0; i<N; i++){
		long long pos;
		scanf("%lld", &pos);
		position[i] = pos;
		total += pos;
	}
	sort(position, position+N);
	total -= position[0]*N;
	long long sum = total;
	long long n = N-1;
	for(int i=1; i<N; i++){
		total -= (position[i]-position[i-1])*(n--);
		sum += total;
	}
	printf("%lld\n", sum*2);
}

