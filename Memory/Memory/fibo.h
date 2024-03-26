#pragma once
#include <cstdint>
/**
	Fibonacci
	n = 0 => 0
	n = 1 => 1
	n > 1 => fibo(n-1) + fibo(n-2)
*/
uint64_t fiboSwitch(int n);

uint64_t fiboIf(int n);

uint64_t fiboFor(int n);

