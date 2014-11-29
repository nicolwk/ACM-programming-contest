#include <cstdio>
#include <set>
using namespace std;
int main(){
	int N;
	set<long long> list;
	long long number[5842];
	list.insert(1);
	for(int i=0; i<5842; i++){
		long long head = *list.begin();
		number[i] = head;
		list.erase(list.begin());
		list.insert(head*2);
		list.insert(head*3);
		list.insert(head*5);
		list.insert(head*7);
	}
	while(scanf("%d", &N), N){
		printf("The %d", N);
		int d1 = N%10, d2 = (N%100)/10;
		if(d2 == 1)
			printf("th");
		else{
			if(d1 == 1)
				printf("st");
			else if(d1 == 2)
				printf("nd");
			else if(d1 == 3)
				printf("rd");
			else
				printf("th");
		}
		printf(" humble number is %lld.\n", number[N-1]);
	}
}

