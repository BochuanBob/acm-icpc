#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i, j;
	int size, maxLength;
	int count = 0;
	if (scanf("%d", &n) <= 0) {
		return 0;
	}
	if (n == 0) {
		return 0;
	}
	while (1) {
		char words[n][101];
		for (i = 0; i < n; i++) {
			for (j = 0; j < 101; j++) {
				words[i][j] = '\0';
			}
		}
		maxLength = 0;
		if (fgets(words[0], 101, stdin) == NULL) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			if (fgets(words[i], 101, stdin) == NULL) {
				return 0;
			}
			size = strlen(words[i]);
			if (size > maxLength) {
				maxLength = size - 1;
			}
		}
		char output[maxLength][n+1];
		for (i = 0; i < maxLength; i++) {
			output[i][n] = '\0';
		}
		for (i = 0; i < maxLength; i++) {
			for (j = 0; j < n; j++) {
				if (words[n-1-j][i] == '+') {
					output[i][j] = '+';
				} else if (words[n-1-j][i] == '-') {
					output[i][j] = '|';
				} else if (words[n-1-j][i] == '|') {
					output[i][j] = '-';
				} else {
					output[i][j] = ' ';
				}
			}
		}
		for (i = 0; i < maxLength; i++) {
			for (j = n - 1; j >= 0; j--) {
				if (output[i][j] == ' ') {
					output[i][j] = '\0';
				} else {
					break;
				}
			}
		}
		for (i = 0; i < maxLength; i++) {
			printf("%s\n", output[i]);
		}
		if (scanf("%d", &n) <= 0) {
			return 0;
		}
		if (n == 0) {
			return 0;
		}
		printf("\n");
	}
}