#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int N, row[100], row2[100];
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<i+1; j++)
			cin>>row[j];
		if(i>0){
			row[0]+=row2[0];
			for(int j=1; j<i; j++)
				row[j]+=max(row2[j-1], row2[j]);
			row[i]+=row2[i-1];
		}
		memcpy(row2, row, 100*sizeof(int));
	}
	int maxNum = 0;
	for(int i=0; i<N; i++)
		maxNum = max(maxNum, row[i]);
	cout<<maxNum<<endl;
}

