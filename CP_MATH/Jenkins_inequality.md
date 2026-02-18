# Jensen's Inequality: From Pigeonhole to AM-GM


I started with a simple question: If I put 15 objects into 5 boxes, how many pairs of objects end up in the same box?

If a box has k objects, the number of pairs is:

C(k,2) = k(k-1)/2

I tried two distributions:

**Even distribution**: (3, 3, 3, 3, 3)
- Each box: 3 objects → 3 pairs
- Total pairs = 3 + 3 + 3 + 3 + 3 = 15

**Skewed distribution**: (11, 1, 1, 1, 1)
- First box: 11 objects → 55 pairs
- Others: 1 object → 0 pairs each
- Total pairs = 55 + 0 + 0 + 0 + 0 = 55

Same number of objects, wildly different results.

---

## The Pattern I Noticed

The average objects per box is:

15/5 = 3

At this average, the pairs function gives:

f(3) = C(3,2) = 3

But the average of the actual pairs from my skewed distribution is:

(55 + 0 + 0 + 0 + 0)/5 = 11

So:

Average of f(k) = 11
f(Average of k) = 3

And 11 > 3. Every time I made the distribution more uneven, the average of the function got bigger than the function at the average.

---

## The Convexity Check

I checked why this happens. For f(k) = k(k-1)/2:

f'(k) = k - 1/2
f''(k) = 1 > 0

When the second derivative is positive, the function curves upward like a smile. That's called **convex**.

For convex functions, the line segment between any two points lies **above** the curve. This means:

f((x1 + x2)/2) ≤ (f(x1) + f(x2))/2

Or more generally:

f((x1 + x2 + ... + xn)/n) ≤ (f(x1) + f(x2) + ... + f(xn))/n

This is **Jensen's inequality**.

---

## Flipping It Around

I tried a different function: f(k) = √k

For √k:

f'(k) = 1/(2√k)
f''(k) = -1/(4k√k) < 0

Negative second derivative means the function curves downward like a cap. That's **concave**.

For the same 15 objects in 5 boxes:

**Even distribution**: (3,3,3,3,3)
√3 + √3 + √3 + √3 + √3 = 5√3 ≈ 8.66

**Skewed distribution**: (11,1,1,1,1)
√11 + 1 + 1 + 1 + 1 ≈ 3.317 + 4 = 7.317

Now the even distribution wins! For concave functions, Jensen flips:

f((x1 + x2 + ... + xn)/n) ≥ (f(x1) + f(x2) + ... + f(xn))/n

---

## What I Learned

| Function Shape | Second Derivative | Jensen Inequality | To Maximize Sum |
|----------------|-------------------|-------------------|-----------------|
| Convex | f''(x) > 0 | f(average) ≤ average of f | Make values unequal |
| Concave | f''(x) < 0 | f(average) ≥ average of f | Make values equal |

---

## Applying It: AM-GM Inequality

The Arithmetic Mean-Geometric Mean inequality says:

(a + b)/2 ≥ √(ab) for a,b > 0

I can prove this using Jensen.

**Step 1**: Take ln of both sides (ln is increasing, so inequality direction stays):

ln((a+b)/2) ≥ ln(√(ab)) = (1/2)(ln a + ln b)

**Step 2**: Multiply by 2:

2 ln((a+b)/2) ≥ ln a + ln b

**Step 3**: Rearrange:

(ln a + ln b)/2 ≤ ln((a+b)/2)

**Step 4**: Check ln x:

f(x) = ln x
f'(x) = 1/x
f''(x) = -1/x^2 < 0

So ln x is **concave**. For concave functions, Jensen says:

(f(a) + f(b))/2 ≤ f((a+b)/2)

That's exactly what we have! So Jensen proves AM-GM.

---

## Another Example: Maximizing Product

**Problem**: Given x + y = 10 with x, y > 0, find the maximum of xy.

**Method 1 (direct)**:
y = 10 - x
xy = x(10-x) = 10x - x^2
This is a parabola opening downward. Maximum at vertex x = 5:
xy = 5 × 5 = 25

**Method 2 (Jensen)**:
ln(xy) = ln x + ln y
Since ln is concave:
(ln x + ln y)/2 ≤ ln((x+y)/2) = ln(5)
ln(xy) ≤ 2 ln(5) = ln(25)
xy ≤ 25
Equality when x = y = 5.

Both methods give the same answer. The Jensen method extends easily to more variables.

---

## For 3 Variables

**Problem**: x + y + z = 10, maximize xyz

ln(xyz) = ln x + ln y + ln z

By Jensen (concave ln):

(ln x + ln y + ln z)/3 ≤ ln((x+y+z)/3) = ln(10/3)

ln(xyz) ≤ 3 ln(10/3) = ln((10/3)^3)

xyz ≤ (10/3)^3 ≈ 37.03

Equality when x = y = z = 10/3.

Try doing this with calculus. Three variables, one constraint. Possible but messy. Jensen makes it clean.

---

## Summary

| Concept | Formula |
|---------|---------|
| Jensen for convex f | f(λ₁x₁ + ... + λₙxₙ) ≤ λ₁f(x₁) + ... + λₙf(xₙ) |
| Jensen for concave f | f(λ₁x₁ + ... + λₙxₙ) ≥ λ₁f(x₁) + ... + λₙf(xₙ) |
| Where λᵢ ≥ 0 and Σλᵢ = 1 | |
| Convex test | f''(x) > 0 |
| Concave test | f''(x) < 0 |

---

## Quick Reference: Common Functions

| Function | f''(x) | Shape | Domain |
|----------|--------|-------|--------|
| x² | 2 | convex | all real |
| √x | -1/(4x√x) | concave | x > 0 |
| 1/x | 2/x³ | convex | x > 0 |
| ln x | -1/x² | concave | x > 0 |
| e^x | e^x | convex | all real |
| x³ | 6x | convex for x>0 | changes sign |

---

