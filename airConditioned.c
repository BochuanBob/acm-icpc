#include <stdio.h>
#include <stdlib.h>

int main() {
	int minions[300];
	int n, l, u, i;
	for (i = 0; i < 300; i++) {
		minions[i] = 0;
	}
	int room = 0, need = -1; 
	if (scanf("%d", &n) <= 0) {
		return 0;
	}

	for (i =0; i < n; i++) {
		if (scanf("%d %d", &l, &u) <= 0) {
			return 0;
		}

		if (minions[l] > u || minions[l] == 0) minions[l] = u;
	}

	for (i = 1; i <= 2 * n; i++) {
		if (minions[i] > 0 && (need == -1 || minions[i] < need)) {
			need = minions[i];
		}
		if (need == i) {
			need = -1;
			room++;
		}
	}

	printf("%d\n", room);
	return 0;
}
