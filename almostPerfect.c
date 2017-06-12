#include <stdio.h>
#include <stdlib.h>

void calcSum(unsigned long long* sum, unsigned long int num) {
	unsigned long int i;
	for (i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			*sum += i;
			if(num != (i*i)) {
				*sum += num/i;
			}
		}
	}
}

int main() {
	unsigned long int num;
	unsigned long long sum;
	while(1) {
		if (scanf("%lu", &num) != 1) {
			return 0;
		}
		sum = 1L;
		calcSum(&sum, num);
		if (sum == num) {
			printf("%lu perfect\n", num);
		} else if (llabs(num-sum) <= 2) {
			printf("%lu almost perfect\n", num);
		} else {
			printf("%lu not perfect\n", num);
		}
	}
}