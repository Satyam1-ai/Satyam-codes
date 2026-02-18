# Pigeonhole Principle & Jensen's Inequality: The Unexpected Connection

So I was messing around with the pigeonhole principle and stumbled onto something that connects it to Jensen's inequality in a really visual way. Let me show you what I found.

---

## The Classic Pigeonhole Setup

We all know the basics: `n` objects into `m` boxes. If `n > m`, one box gets at least 2 objects. Yawn.

But here's where it gets interesting. Let's say we have **15 objects** and **5 boxes**. And instead of just asking "does any box have multiple objects?", I want to count something specific: **how many pairs of objects end up in the same box**.

If a box has `k` objects, the number of pairs in that box is:

\[
\binom{k}{2} = \frac{k(k-1)}{2}
\]

So if I distribute my 15 objects as `(k₁, k₂, k₃, k₄, k₅)`, the total number of pairs is:

\[
\sum_{i=1}^{5} \frac{k_i(k_i-1)}{2}
\]

---

## Two Extremes

Let's look at two very different distributions:

**Even distribution**: `(3, 3, 3, 3, 3)`
- Each box: 3 objects → 3 pairs
- Total = 3 + 3 + 3 + 3 + 3 = **15 pairs**

**Skewed distribution**: `(11, 1, 1, 1, 1)`
- First box: 11 objects → 55 pairs
- Others: 1 object → 0 pairs each
- Total = 55 + 0 + 0 + 0 + 0 = **55 pairs**

Same total objects (15). Same number of boxes (5). Wildly different results.

---

## The Average Game

Here's what caught my attention. The average number of objects per box is:

\[
\frac{15}{5} = 3 \text{ objects per box}
\]

Now, if I plug this average into my "pairs function":

\[
f(3) = \binom{3}{2} = 3 \text{ pairs}
\]

But if I calculate the *average* of the actual pairs across my skewed distribution:

\[
\frac{55 + 0 + 0 + 0 + 0}{5} = 11 \text{ pairs}
\]

So:

\[
\text{Average of } f(k) = 11
\]
\[
f(\text{Average of } k) = 3
\]

And 11 > 3. Every single time I skew the distribution, the average of the function ends up bigger than the function at the average.

---

## Jensen's Inequality Appears

Turns out this is exactly what Jensen's inequality predicts. For a **convex function** (one that curves upward), the average of the function values is **greater than or equal to** the function at the average.

**Jensen's Inequality (for convex functions):**

\[
f\left(\frac{x_1 + x_2 + ... + x_n}{n}\right) \leq \frac{f(x_1) + f(x_2) + ... + f(x_n)}{n}
\]

Or with weights:

\[
f\left(\sum_{i=1}^{n} \lambda_i x_i\right) \leq \sum_{i=1}^{n} \lambda_i f(x_i)
\]

Where \( \lambda_i \geq 0 \) and \( \sum \lambda_i = 1 \)

The function \( f(k) = \binom{k}{2} = \frac{k(k-1)}{2} \) is convex. Let's check its second derivative:

\[
f(k) = \frac{1}{2}(k^2 - k)
\]
\[
f'(k) = \frac{1}{2}(2k - 1) = k - \frac{1}{2}
\]
\[
f''(k) = 1 > 0
\]

Positive second derivative = convex.

---



