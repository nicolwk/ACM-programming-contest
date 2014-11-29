#include <cstdio>
#include <set>
using namespace std;
int main(){
	int N;
	set<long long> list;
	long long number[1500];
	list.insert(1);
	for(int i=0; i<1500; i++){
		long long head = *list.begin();
		number[i] = head;
		list.erase(list.begin());
		list.insert(head*2);
		list.insert(head*3);
		list.insert(head*5);
	}
	while(scanf("%d", &N), N)
		printf("%lld\n", number[N-1]);
}

