#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int i, j, k;
	char s[35];
	char command[10];
	while(1){
		for(k = 0; k < 32; k++) {
			s[k] = '?';
		}
		if (scanf("%d", &n) <= 0) {
			return 0;
		}
		if (n == 0) {
			return 0;
		}
		for (k = 0; k < n; k++) {
			if (scanf("%s", command) <= 0) {
				return 0;
			}

			if (command[0] == 'O' || command[0] == 'A') {
				if (scanf("%d %d", &i, &j) <= 0) {
					return 0;
				}
				if (command[0] == 'O') {
					if (s[i] == '1' || s[j] == '1') {
						s[i] = '1';
					} else if (s[j] == '?') {
						s[i] = '?';
					}
				} else {
					if (s[i] == '0' || s[j] == '0') {
						s[i] = '0';
					} else if (s[j] == '?') {
						s[i] = '?';
					}
				}
			} else {
				if (scanf("%d", &i) <= 0) {
					return 0;
				}
				if (command[0] == 'S') {
					s[i] = '1';
				} else {
					s[i] = '0';
				}
			}
		}
		for (k = 31; k >=0; k--) {
			printf("%c", s[k]);
		}
		printf("\n");
	}
}
