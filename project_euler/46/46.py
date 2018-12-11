n = 200

prime_sieve = [True for i in range(n * n + 1)]

for i in range(2, n + 1):
    if not prime_sieve[i]:
        continue

    c = i
    while c <= n * n:
        if c * i < n * n + 1:
            prime_sieve[c * i] = False
        else:
            break
        c += 1

# print(list(enumerate(prime_sieve)))

primes = set()
for i in range(2, len(prime_sieve)):
    if prime_sieve[i]:
        primes.add(i)

# print(sorted(list(primes)))

nums = set()
for i in range(n):
    for p in primes:
        nums.add(p + 2 * i ** 2)

# print(sorted([i for i in nums if i % 2 == 1 and i not in primes]))

for (num, p) in enumerate(prime_sieve):
    if num % 2 == 1 and not p:
        if num not in nums:
            print(num)
            break
