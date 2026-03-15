# GCD Reduction Trick: Polynomial Simplification
A core technique for simplifying Greatest Common Divisor problems involving variables.

## The Core Concept
The **Euclidean Algorithm** states that the GCD of two numbers doesn't change if you subtract one from the other:
**gcd(a, b) = gcd(a - b, b)**

In polynomial problems, we use this to "kill" the highest power (like n² or n) until we are left with a simple constant.

---

## The Strategy: "The Onion Peel"
To find the maximum possible value of **f(n) = gcd(Expression A, Expression B)**:

1. **Match the Terms:** Multiply the smaller expression so its highest power matches the larger one.
2. **Subtract:** Subtract them to eliminate the n² or n³ term.
3. **Repeat:** Keep peeling layers until you are left with a **singular integer** (a constant).
4. **Conclude:** The maximum GCD is simply that final number.

---

## Worked Examples

### Example 1: Killing the n²
**Problem:** Find the maximum value of **gcd(n + 3, n² + 4n + 7)**.

* **Step 1:** Multiply (n + 3) by **n** to get **n² + 3n**.
* **Step 2 (Subtract):** (n² + 4n + 7) - (n² + 3n) = **n + 7**.
* **Step 3 (Simplify):** Now we compare our new term with the original small one: **gcd(n + 3, n + 7)**.
* **Step 4 (Final Subtract):** (n + 7) - (n + 3) = **4**.
* **Result:** The maximum GCD is **4**.

### Example 2: The "Hidden Square"
**Problem:** Find f(a) - a where **f(a) = gcd(3a² + 19a + 30, a² + 6a + 9)**.

* **Step 1:** Multiply the second term by **3**: 3(a² + 6a + 9) = **3a² + 18a + 27**.
* **Step 2 (Subtract):** (3a² + 19a + 30) - (3a² + 18a + 27) = **a + 3**.
* **Step 3 (Observe):** Since the original term (a² + 6a + 9) is just (a + 3)², the GCD is simply **a + 3**.
* **Final Calculation:** f(a) - a = (a + 3) - a = **3**.

---

## Practice Problems
1. **gcd(n + 1, n² + n + 1)** → (Max: 1)
2. **gcd(n - 3, n² - 5)** → (Max: 4)
3. **gcd(2n + 1, 4n² + 1)** → (Max: 2)
4. **gcd(2n² + 3n + 1, 2n² + 2n + 3)** → (Max: 5)
5. **gcd(3n + 2, 5n + 1)** → (Max: 7)
6. **gcd(n² + 1, n + 1)** → (Max: 2)

---
