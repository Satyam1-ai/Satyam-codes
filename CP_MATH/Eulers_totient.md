# Number Theory Notes: Inclusion-Exclusion, Prime Counting, and Euler's Totient

## Overview
This document explores the connections between three fundamental concepts in number theory:
1. The Principle of Inclusion-Exclusion (PIE)
2. Counting Primes (using sieving)
3. Euler's Totient Function (phi)

We will see how removing multiples of primes connects these ideas.

---

## 1. The Principle of Inclusion-Exclusion (PIE)

PIE is a counting technique to find the size of combined sets without double-counting.

**For two sets A and B:**
|A union B| = |A| + |B| - |A intersect B|

**For three sets A, B, and C:**
|A union B union C| = |A| + |B| + |C| 
                   - (|A intersect B| + |A intersect C| + |B intersect C|) 
                   + |A intersect B intersect C|

**General Logic:**
1. Add the sizes of individual sets.
2. Subtract the sizes of pairwise intersections (fix double counting).
3. Add the sizes of triple intersections (fix over-subtraction).
4. Keep alternating signs for larger intersections.

---

## 2. Application: Counting Primes by Sieving

A classic use of PIE is counting primes up to a number N.

### The Problem
Find the number of primes up to N = 180.

### The Method
To check if a number <= 180 is prime, we only need to test divisibility by primes <= sqrt(180).
sqrt(180) ≈ 13.41
So the primes we sieve with are: 2, 3, 5, 7, 11, 13.

*(Note: Some simple examples only use 2, 3, 5 to show the idea, but for an exact count up to 180, you need all primes up to sqrt(N).)*

### Using PIE to Count Composites
Instead of counting primes directly, we count the composites (numbers divisible by our sieving primes) and subtract them.

Let A2 = multiples of 2 up to 180
Let A3 = multiples of 3 up to 180
Let A5 = multiples of 5 up to 180
...and so on for 7, 11, 13.

The number of multiples of k up to N is: floor(N / k)

The intersection of multiples of a and b is multiples of lcm(a, b). For distinct primes, lcm(a,b) = a * b.

**The PIE Formula for Composites:**
|union of all Ap| = 
    sum of floor(N/p) for each prime p
  - sum of floor(N/(pi * pj)) for each pair of primes
  + sum of floor(N/(pi * pj * pk)) for each triple
  - ... (keep alternating)

**The Count of Primes pi(N):**
pi(N) = (Total numbers from 2 to N) 
        - |union of all Ap| 
        + (number of sieving primes we used)

*(We add back the sieving primes themselves because they got removed as "multiples" of themselves.)*

---

## 3. Euler's Totient Function (phi)

Euler's Totient Function, written phi(n), counts how many positive integers <= n are relatively prime to n (meaning their GCD with n is 1).

### Multiplicative Property
If gcd(m, n) = 1 (m and n share no common factors), then:
phi(m * n) = phi(m) * phi(n)

*Example:*
phi(10) = phi(2 * 5) = phi(2) * phi(5) = 1 * 4 = 4
(The numbers coprime to 10 are: 1, 3, 7, 9)

### The Product Formula
Using Inclusion-Exclusion logic, we can derive a clean formula. If the prime factorization of n is:
n = p1^a1 * p2^a2 * ... * pk^ak

Then:
phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)

**Why this works:**
1. Start with n numbers.
2. Remove the fraction that are divisible by p1: multiply by (1 - 1/p1)
3. From what remains, remove the fraction divisible by p2: multiply by (1 - 1/p2)
4. Since divisibility by different primes is independent, we can just multiply these factors.

---

## 4. The Connection Between the Two Ideas

You noticed that counting primes and calculating phi(n) feel similar. You are right!

### Why they look alike
Both methods work by **removing multiples of primes** from a total set.

| Feature | Prime Counting (Sieving) | Euler's Totient (phi) |
|---------|--------------------------|----------------------|
| Goal | Count numbers with NO prime factors <= sqrt(N) | Count numbers with NO common prime factors with n |
| Method | Inclusion-Exclusion on sets of multiples | Inclusion-Exclusion on residue classes |
| Formula Style | Sum of floor functions with alternating signs | Product of terms: n * (1 - 1/p) |
| Scope | Global: counts primes up to N | Local: counts coprimes to a specific n |

### Important: They Are NOT the Same Result
Even though the logic is similar, phi(N) does NOT equal the number of primes up to N.

- phi(180) counts numbers coprime to 180 (removes multiples of 2, 3, 5 only)
- pi(180) counts primes up to 180 (removes multiples of 2, 3, 5, 7, 11, 13)

**Example: Calculate phi(180)**
Prime factorization: 180 = 2^2 * 3^2 * 5^1

phi(180) = 180 * (1 - 1/2) * (1 - 1/3) * (1 - 1/5)
         = 180 * 1/2 * 2/3 * 4/5
         = 48

So there are 48 numbers less than 180 that are coprime to 180.
(This is different from the count of primes up to 180, which is 41.)

---

## 5. Simple Python Code to Verify

```python
import math

def euler_totient(n):
    """Calculate Euler's Totient Function phi(n)"""
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    if n > 1:
        result -= result // n
    return result

def count_primes_up_to(limit):
    """Simple Sieve of Eratosthenes"""
    if limit < 2:
        return 0
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(limit)) + 1):
        if is_prime[i]:
            for j in range(i*i, limit + 1, i):
                is_prime[j] = False
    return sum(is_prime)

# Test with N = 180
N = 180
print(f"Number of primes up to {N}: {count_primes_up_to(N)}")
print(f"Euler's Totient phi({N}): {euler_totient(N)}")
