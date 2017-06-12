#include <stdio.h>
#include <stdlib.h>
unsigned long long SIZE = 100100;
unsigned long long bs[100100];
unsigned long long primesList[100000];
int primeIndex = 0;
void initial() {
	unsigned long long i, j;
	for (i = 0; i < SIZE; i++) {
		bs[i] = 1;
	}
	bs[0] = 0;
	bs[1] = 0;
	for (i = 2; i <= SIZE; i++) {
		if (bs[i]) {
	        for (j = i * i; j <= SIZE; j += i) {
	        	bs[j] = 0;
	     	}
	        primesList[primeIndex] = i;
	    	primeIndex++;
   		}
    }
}
char isPrime(unsigned long long num) {
	int i;
	if (num <= SIZE) {
		return bs[num];
	}
	for (i = 0; i < primeIndex; i++) {
		if (num%primesList[i] == 0) {
			return 0;
		}
	}
	return 1;
}

int findPrime(unsigned long long* primes, unsigned long long num) {
	unsigned long long i;
	int j = 0;
	if (isPrime(num)) {
		primes[0] = num;
		return 1;
	}
	for (i = 2L; (i*i) <= num; i++) {
        if (num % i == 0L){
            if (isPrime(i)) {
                primes[j] = i;
                j++;
            }
            if (num/i != i){
                if (isPrime(num/i)) {
                    primes[j] = num/i;
                    j++;
                }
            }
        }
    }
	return j;
}

int main() {
	unsigned long long num;
	int index;
	int count;
	initial();
	while (1) {
		if (scanf("%llu", &num) != 1) {
			return 0;
		}
		unsigned long long primes[100];
		if (num == 0) {
			return 0;
		}
		int factNum = findPrime(primes, num);
		for (index = 0; index < factNum; index++) {
			num = num - num/primes[index];
		}
		printf("%llu\n", num);
	}
}