#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b) {
	return *((int *)a) - *((int *)b);
}

int insertSort (int *array, int size) {
	int i, j;
	int temp;
	for (i = 1 ; i < size; i++) {
    j = i;
 
    while (j > 0 && array[j] < array[j-1]) {
      temp= array[j];
      array[j] = array[j-1];
      array[j-1] = temp;
      j--;
    }
  }
}
int main() {
	int n, m;
	int i, j;
	int temp;
	int count = 0;
	if (scanf("%d %d\n", &n, &m) <= 0) {
		return 0;
	}
	int researcher[n][2];
	int terminate[n];
	for (i = 0; i < n; i++) {
		terminate[i] = 0;
		if (scanf("%d %d", &researcher[i][0], &researcher[i][1]) <= 0) {
			return 0;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (researcher[i][0] > researcher[j][0]) {
				temp = researcher[i][0];
				researcher[i][0] = researcher[j][0];
				researcher[j][0] = temp;
				temp = researcher[i][1];
				researcher[i][1] = researcher[j][1];
				researcher[j][1] = temp;
			}
		}
	}
	int workstations = 1;
	int begin = 0;
	terminate[0] = researcher[0][0] + researcher[0][1];
	for (i = 1; i < n; i++) {
		for (j = begin; j < n; j++) {
			if (terminate[j] == 0) {
				terminate[j] = researcher[i][0] + researcher[i][1];
				workstations++;
				//qsort(terminate+begin, workstations-begin, sizeof(terminate[0]), cmp);
				insertSort(&terminate[begin], workstations);
				break;
			} else if (terminate[j] <= researcher[i][0] && terminate[j] + m >= researcher[i][0]) {
				count++;
				terminate[j] = researcher[i][0] + researcher[i][1];
				break;
			} 
			else if (terminate[j]!= 0 && terminate[j] + m < researcher[i][0]) {
				begin++;
				workstations--;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
