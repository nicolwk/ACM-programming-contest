#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int main(){
	int N;
	while(1){
		scanf("%d", &N);
		if(N == 0)
			break;
		double bx, by, cx, cy, r;
		scanf("%lf%lf", &bx, &by);
		map<double, short> intervals;
		for(int i = 0; i < N; i++){
			scanf("%lf%lf%lf", &cx, &cy, &r);
			double d = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
    		double k2 = r / sqrt(d - r * r);
    		double k1 = -(bx - cx) / (by - cy);
			intervals[(k1 - k2) / (1 + k1 * k2) * by + bx]++;
			intervals[(k1 + k2) / (1 - k1 * k2) * by + bx]--;
		}
		int count = 0, oldCount;
		for(map<double, short>::iterator it = intervals.begin(); it != intervals.end(); it++){
			oldCount = count;
			count += it->second;
			if(oldCount == 0 && count > 0)
				printf("%.2f ", it->first);
			else if(oldCount > 0 && count == 0)
				printf("%.2f\n", it->first);
		}
		printf("\n");
	}
}

