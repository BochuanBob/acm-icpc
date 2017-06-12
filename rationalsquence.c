#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	if (scanf("%d", &T) <= 0) {
		return 0;
	}
	int k;
	long p, q, n;
	while (T--) {
		if (scanf("%d %ld/%ld", &k, &p, &q) <= 0){
			return 0;
		}
		if (p == q) {
			printf("%d %ld/%ld\n", k, p, q+1);
		} else if (p < q) {
			printf("%d %ld/%ld\n", k, q, q-p);
		} else {
			if (q == 1) {
				printf("%d 1/%ld\n", k, p+1);
			}
			else{
				n = p / q;
				p = p % q;
				q -= p;
				p += q;
				q += p*n;
				printf("%d %ld/%ld\n", k, p, q);
			}
		}
	}
	return 0;
}