#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(){
	bool number[10001];
	fill(number, number+10001, true);
	for(int i=1; i<=10000; i++){
		char str[100];
		sprintf(str, "%d", i);
		int length = strlen(str);
		int dn = i;
		for(int i=0; i<length; i++)
			dn += str[i]-'0';
		if(dn <= 10000)
			number[dn] = false;
	}
	for(int i=1; i<=10000; i++)
		if(number[i])
			printf("%d\n", i);
}

