#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[40];
	int level;
} person;
int cmp (const void *a, const void *b) {
	if (((person *)b)->level - ((person *)a)->level == 0) {
		return strncmp(((person *)a)->name, ((person *)b)->name, 40);
	}
	return ((person *)b)->level - ((person *)a)->level;
}

void getLevel(char *class, int *level) {
	int i, index = 0;
	for (i = 0; i < strlen(class);) {
		if(class[i] == 'u') {
			level[index] = 1;
			index++;
			i+=6;
		} else if (class[i] == 'm') {
			level[index] = 0;
			index++;
			i+=7;
		} else if (class[i] == 'l') {
			level[index] = -1;
			index++;
			i+=6;
		} else {
			printf("It is wrong\n");
			exit(0);
		}
	}
	int temp;
	for (i = 0; i < index/2; i++) {
		temp = level[i];
		level[i] = level[index - 1 - i];
		level[index - 1 - i] = temp;
	}
}

int main() {
	int t;
	int n;
	int i, j;
	int L;
	char name[40], class[100], notUsed[10];
	if (scanf("%d\n", &t) <= 0) {
		return 0;
	}
	while(t--) {
		if (scanf("%d\n", &n) <= 0) {
			return 0;
		}
		person p[n];
		int level[n][11];
		for (i = 0; i < n; i++) {
			for (j = 0; j < 11; j++) {
				level[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			if (scanf("%s %s %s", name, class, notUsed) <= 0) {
				return 0;
			}
			name[strlen(name)-1] = '\0';
			strncpy(p[i].name, name, 40);
			getLevel(class, level[i]);
		}
		for (i = 0; i < n; i++) {
			L = 0;
			for (j = 0; j < 11; j++) {
				L = L*3 + level[i][j];
			}
			p[i].level = L;
		}
		qsort(p, n, sizeof(p[0]), cmp);
		for (i = 0; i < n; i++) {
			printf("%s\n", p[i].name);
		}
		printf("==============================\n");
	}
	return 0;
}
