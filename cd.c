#include <stdio.h>
#include <stdlib.h>

int jack[1000001];
int jill[1000001];
int main() {
	int n, m;
	int i, j;
	while(1) {
		if (scanf("%d %d", &n, &m) <= 0) {
			return 0;
		}
		if (n == 0 && m == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			if (scanf("%d", jack + i) <= 0) {
				return 0;
			}
		}
		for (i = 0; i < m; i++) {
			if (scanf("%d", jill + i) <= 0) {
				return 0;
			}
		}
		i = 0;
		j = 0;
		int count = 0;
		while(i<n && j<m) {
			if(jack[i] == jill[j]) {
				count++;
				i++;
				j++;
			} else if (jack[i] < jill[j]) {
				i++;
			} else j++;
		}
		printf("%d\n", count);
	}
}