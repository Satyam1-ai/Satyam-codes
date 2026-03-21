# Legendre's Formula Calculator 🧮

A simple implementation of **Legendre's Formula** to find the exponent of a prime number **p** in the prime factorization of **n!** (n-factorial).

## 📖 What is Legendre's Formula?

Legendre's Formula calculates how many times a prime number **p** divides the factorial of a positive integer **n**. 

### The Formula:
**E_p(n!) = [n/p] + [n/p^2] + [n/p^3] + ...**

Where:
*   **n**: The number you are taking the factorial of (e.g., 21 for 21!).
*   **p**: The prime factor you are looking for (e.g., 2).
*   **[ ]**: The **Floor Function** (round down to the nearest whole number).

## 🚀 Example: Finding the exponent of 2 in 21!

1.  21 / 2 = **10**
2.  21 / 4 = **5**
3.  21 / 8 = **2**
4.  21 / 16 = **1**
5.  21 / 32 = **0** (Stop here)

**Total:** 10 + 5 + 2 + 1 = **18**  
**Result:** 21! is divisible by 2 to the power of 18 (2^18).

## 🛠️ Common Uses
*   **Trailing Zeros:** Finding how many zeros are at the end of 100! (by checking the exponent of 5).
*   **Efficiency:** Finding prime factors of massive numbers without actually calculating the full factorial.

## 💻 Logic (Python Snippet)
```python
def legendre(n, p):
    res = 0
    while n > 0:
        n //= p
        res += n
    return res

# Output for 21! and prime 2
print(legendre(21, 2)) 
