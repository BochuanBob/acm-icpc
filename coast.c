#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char map[1002][1003];
char isRead[1002][1002];
void isSea(int i, int j) {
	isRead[i][j] = 1;
	if (i-1>=0) {
		if ((isRead[i-1][j] == 0) && (map[i-1][j] == '0')){
			isSea(i-1, j);
		}
	}
	if (i+1<=n+1) {
		if ((isRead[i+1][j] == 0) && (map[i+1][j] == '0')){
			isSea(i+1, j);
		}
	}
	if (j+1<=m+1) {
		if ((isRead[i][j+1] == 0) && (map[i][j+1] == '0')) {
			isSea(i, j+1);
		}
	}
	if (j-1>=0) {
		if ((isRead[i][j-1] == 0) && (map[i][j-1] == '0')) {
			isSea(i, j-1);
		}
	}
}

int main() {
	int i, j;
	if(scanf("%d %d", &n, &m) <= 0) {
		return 0;
	}

	for (i = 0; i < n+2; i++) {
		for (j = 0; j< m+2; j++) {
			map[i][j] = '0';
			isRead[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		if (scanf("%s", &map[i+1][1]) <= 0) {
			return 0;
		}
		map[i+1][m+1] = '0';
	}
	isSea(0, 0);
	int count = 0;
	for (i = 1; i < n+1; i++) {
		for (j = 1; j < m+1; j++) {
			if (isRead[i][j] == 0) {
				count += (isRead[i][j-1]) + (isRead[i][j+1])
					+ (isRead[i-1][j]) + (isRead[i+1][j]);
			}
		}
	}
	printf("%d\n", count);
	return 0;
}