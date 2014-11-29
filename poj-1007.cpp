#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Seq{
	int count;
	char* seq;
	bool operator < (const Seq& s) const{
		return count < s.count;
	}
};
int main(){
	int N, M;
	scanf("%d%d\n", &N, &M);
	vector<Seq> dna;
	for(int i=0; i<M; i++){
		char* seq = new char[N+1];
		gets(seq);
		int count = 0;
		for(int j=0; j<N-1; j++)
			for(int k=j+1; k<N; k++)
				if(seq[j] > seq[k])
					count++;
		dna.push_back((Seq){count, seq});
	}
	stable_sort(dna.begin(), dna.end());
	for(vector<Seq>::iterator it=dna.begin(); it!=dna.end(); it++)
		printf("%s\n", (*it).seq);
}

