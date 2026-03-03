# Round-Robin Stride Distribution Cheat Sheet

##  Concept
Distributing **`n`** items into **`c`** groups (buckets/columns) as evenly as possible.  
The difference between the largest and smallest group size will never exceed **1**.

##  Variables
| Symbol | Meaning | Type |
| :--- | :--- | :--- |
| **`n`** | Total number of items | Integer (`≥ 0`) |
| **`c`** | Total number of groups | Integer (`> 0`) |

##  Core Formulas (Integer Arithmetic)
*Avoid floating point `ceil()` to prevent precision errors.*

| Goal | Formula | Notes |
| :--- | :--- | :--- |
| **Max Group Size** | `(n - 1) / c + 1` | Size of the fullest groups |
| **Count of Max Groups** | `(n - 1) % c + 1` | How many groups have the Max Size |
| **Min Group Size** | `n / c` | Size of the remaining groups |
| **Count of Min Groups** | `c - Count_of_Max` | How many groups have the Min Size |

> * Edge Case:** If `n = 0`, all sizes are `0`. Handle separately to avoid negative division issues.

##  Example Walkthrough
**Input:** `n = 10` items, `c = 3` groups

1.  **Max Size:** `(10 - 1) / 3 + 1` → `9 / 3 + 1` = **4**
2.  **Count of Max:** `(10 - 1) % 3 + 1` → `9 % 3 + 1` = **1**
3.  **Min Size:** `10 / 3` = **3**
4.  **Count of Min:** `3 - 1` = **2**

**Result:**
*   **Group 1:** 4 items (Max)
*   **Group 2:** 3 items (Min)
*   **Group 3:** 3 items (Min)
*   **Total:** 4 + 3 + 3 = **10** ✅


