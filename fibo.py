from functools import lru_cache

@lru_cache
def fibo(n):
    match n:
        case 0:
            return 0
        case 1:
            return 1
        case _:
            return fibo(n-1) + fibo(n-2)