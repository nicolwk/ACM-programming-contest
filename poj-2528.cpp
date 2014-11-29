#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	int noOfCase;
	scanf("%d", &noOfCase);
	while(noOfCase--){
		int N;
		set<int> stackSet;
		scanf("%d", &N);
		pair<int, int> posters[N*2];
		bool visible[N];
		bool stack[N];
		fill(visible, visible+N, false);
		fill(stack, stack+N, false);
		int id = 0, idx = 0;
		for(int i=0; i<N; i++){
			int x1, x2;
			scanf("%d%d", &x1, &x2);
			posters[idx++] = make_pair(x1-1, id);
			posters[idx++] = make_pair(x2, id);
			id++;
		}
		pair<int, int>* postersEnd = posters + N*2;
		sort(posters, postersEnd);
		int oldPos = -1;
		for(pair<int, int>* it = posters; it != postersEnd; it++){
			if(oldPos != it->first){
				if(!stackSet.empty())
					visible[*stackSet.rbegin()] = true;
				oldPos = it->first;
			}
			int id = it->second;
			if(stack[id])
				stackSet.erase(id);
			else
				stackSet.insert(id);
			stack[id] = !stack[id];
		}
		if(!stackSet.empty())
			visible[*stackSet.rbegin()] = true;
		int count = 0;
		for(int i=0; i<N; i++)
			if(visible[i])
				count++;
		printf("%d\n", count);
	}
}

