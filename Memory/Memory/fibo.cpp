#include "fibo.h"

uint64_t fiboSwitch(int n)
{
	switch (n) {
	case 0: return 0;
	case 1: return 1;
	default: return fiboSwitch(n - 1) + fiboSwitch(n - 2);
	}
}

uint64_t fiboIf(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fiboIf(n - 1) + fiboIf(n - 2);
}

uint64_t fiboFor(int n)
{
	int a = 0;
	int b = 1;
	if (n == 0) return a;
	if (n == 1) return b;
	for (int i = 2; i <= n; i++) {
		int c = a + b;
		a = b;
		b = c;
	}
	return b;
}
