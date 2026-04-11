# Big-O-Notation

## Spațiu O(1) vs O(n)

### Spațiu O(1) — spațiu constant
Programul folosește **aceeași cantitate de memorie** indiferent cât de mare e `n`.

```cpp
int fib_optimized(int n) {
    int a = 0, b = 1;      // mereu doar 2 variabile
    for (int i = 2; i <= n; i++) {
        int c = a + b;     // mereu doar 1 variabilă temporară
        a = b;
        b = c;
    }
    return b;
}
```
Pentru `n = 10` sau `n = 1.000.000` → tot **3 variabile** în memorie (`a`, `b`, `c`).

---

### Spațiu O(n) — spațiu liniar
Programul folosește **mai multă memorie pe măsură ce `n` crește**.

```cpp
int fib_tabulation(int n) {
    vector<int> dp(n + 1);  // aloci n+1 elemente!
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
```
Pentru `n = 10` → **11 elemente** în memorie
Pentru `n = 1000` → **1001 elemente** în memorie
Pentru `n = 1.000.000` → **1.000.001 elemente** în memorie

---

### Analogie simplă

Imaginează-ți că calculezi suma `1 + 2 + 3 + ... + n`:

**O(1) spațiu** — ca un calculator cu un singur afișaj:
```
total = 0
total += 1  → 1
total += 2  → 3
total += 3  → 6
...
```
Mereu doar o variabilă, indiferent de `n`.

**O(n) spațiu** — ca și cum ai scrie toate numerele pe hârtie înainte să le aduni:
```
[1, 2, 3, 4, 5, ..., n]  → apoi le aduni
```
Cu cât `n` e mai mare, cu atât ai nevoie de mai multă hârtie.

---

### De ce contează?

| | O(1) spațiu | O(n) spațiu |
|---|---|---|
| `n = 100` | ~12 bytes | ~400 bytes |
| `n = 1.000.000` | ~12 bytes | ~4 MB |
| `n = 100.000.000` | ~12 bytes | ~400 MB ⚠️ |

Pentru `n` mic diferența e neglijabilă. Pentru `n` foarte mare, **O(n) spațiu poate epuiza memoria**, pe când **O(1) rulează fără probleme**.



### References 
- https://neetcode.io/courses/lessons/big-o-notation
- https://www.w3schools.com/dsa/dsa_timecomplexity_binarysearch.php
