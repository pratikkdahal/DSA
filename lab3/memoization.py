import time
table = {}
def fibo(n):
    if n == 1 or n == 2:
        return 1
    if n not in table:
        table[n] = fibo(n-1) + fibo(n-2)
    return table[n]

n = int(input("Enter a number: "))
start = time.time()
result = fibo(n)
end = time.time()

print(f"The {n}th Fibonacci term is {result}.")
print(f"It took {end - start:.10f} seconds")
