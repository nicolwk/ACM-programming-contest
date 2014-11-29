#include <cstdio>
#include <deque>
using namespace std;
int N, M;
char *bitmap;
void floodFill(char* bitmap, int x, int y){
	deque<pair<int, int> > q;
	q.push_back(make_pair(x, y));
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop_front();
		if(p.first >= 0 && p.first < N && p.second >= 0 && p.second < M){
			if(bitmap[p.first*M+p.second] == '.')
				continue;
			bitmap[p.first*M+p.second] = '.';
			for(int i=-1; i<=1; i++)
				for(int j=-1; j<=1; j++)
					if(!(i==0 && j==0))
						q.push_back(make_pair(p.first+i, p.second+j));
		}
	}
}
int main(){
	scanf("%d%d\n", &N, &M);
	bitmap = new char[N*M+1];
	for(int i=0; i<N; i++)
		gets(&(bitmap[i*M]));
	int count = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(bitmap[i*M+j] == 'W'){
				floodFill(bitmap, i, j);
				count++;
			}
	printf("%d\n", count);
}

