#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char num[11];
} Phones;

int cmp (const void *a, const void *b) {
	char* str1 = ((Phones *)a)->num;
	char* str2 = ((Phones *)b)->num;
	return strcmp(str1,str2) > 0;
}

int main() {
	int t, n, i, j;
	Phones phones[10001];
	char phoneNum[11];
	char out = 0;
	if (scanf("%d", &t) <= 0) {
		return 0;
	}
	while (t--) {
		if (scanf("%d", &n) <= 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			if (scanf("%s", phones[i].num) <= 0) {
				return 0;
			}
		}
		qsort(phones, n, sizeof(phones[0]), cmp);
		for (i = 0; i < n - 1 && out == 0; i++) {
			if (strlen(phones[i].num) < strlen(phones[i+1].num)) {
				strncpy(phoneNum, phones[i+1].num, 11);
				phoneNum[strlen(phones[i].num)] = 0;
				if (strcmp(phoneNum, phones[i].num) == 0) {
					out = 1;
				}
			}
		}
		if (out) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
		out = 0;
	}
	return 0;
}