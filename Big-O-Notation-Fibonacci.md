# Fibonacci Sequence — Big O Notation

# 🔹 1. Hook

👉 Începi cu o întrebare simplă:

> „Cum calculați al n-lea număr Fibonacci?"

Lasă 2–3 răspunsuri.

---

# 🔹 2. Varianta 1 — O(2^n) Recursiv naiv

```cpp
long long fib_exponential(int n) {
    if (n <= 1) return n;
    return fib_exponential(n - 1) + fib_exponential(n - 2);
}
```

👉 Întrebare:

> „De câte ori se apelează funcția pentru n = 5?"

✔ Răspuns:

* Fiecare apel generează **2 apeluri noi** → arbore binar de adâncime n
* Total apeluri ≈ 2^n → **O(2^n)**

👉 Mesaj:

> „Funcționează… dar recalculează aceleași valori de sute de ori"

---

# 🔹 3. Varianta 2 — O(n) Memoization Top-Down (Hash Map)

```cpp
#include <unordered_map>
using namespace std;

unordered_map<int, long long> memo;

long long fib_memo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
}
```

👉 Întrebare:

> „De câte ori calculăm acum fiecare subproblemă?"

✔ Răspuns:

* Exact o dată — rezultatul se salvează în `memo`
* n subprobleme × O(1) fiecare → **O(n)**

👉 Mesaj:

> „Am eliminat recalculările — de la exponențial la liniar"

---

# 🔹 4. Varianta 3 — O(n) Memoization Top-Down (Vector)

```cpp
#include <vector>
#include <functional>
using namespace std;

long long fib_memo_vec(int n) {
    vector<long long> dp(n + 1, -1);
    function<long long(int)> solve = [&](int k) -> long long {
        if (k <= 1) return k;
        if (dp[k] != -1) return dp[k];
        return dp[k] = solve(k - 1) + solve(k - 2);
    };
    return solve(n);
}
```

👉 Întrebare:

> „Care e diferența față de varianta cu unordered_map?"

✔ Răspuns:

* Vector → acces O(1) garantat, fără hash overhead
* Complexitate identică **O(n)**, dar mai rapid în practică

---

# 🔹 5. Varianta 4 — O(n) Bottom-Up DP

```cpp
long long fib_dp(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```

👉 Întrebare:

> „Câtă memorie folosim acum?"

✔ Răspuns:

* Doar 2 variabile, indiferent de n → **O(1) spațiu**
* Timp → **O(n)**

👉 Mesaj:

> „Iterativ, fără recursie, fără memorie suplimentară — cea mai practică variantă"

---

# 🔹 6. Varianta 5 — O(log n) Exponențiere Rapidă a Matricei

```cpp
#include <vector>
using namespace std;
typedef vector<vector<long long>> Mat;

Mat multiply(const Mat& A, const Mat& B) {
    Mat C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Mat matpow(Mat M, int p) {
    Mat R = {{1, 0}, {0, 1}};
    while (p > 0) {
        if (p & 1) R = multiply(R, M);
        M = multiply(M, M);
        p >>= 1;
    }
    return R;
}

long long fib_matrix(int n) {
    if (n <= 1) return n;
    Mat M = {{1, 1}, {1, 0}};
    return matpow(M, n)[0][1];
}
```

👉 Identitatea matematică:

```
| 1 1 |^n     | F(n+1)  F(n)  |
| 1 0 |    =  | F(n)    F(n-1)|
```

✔ Răspuns:

* Divide-and-conquer pe puterea matricei → **O(log n)**

👉 Mesaj:

> „Optim pentru n foarte mare — ex: n = 10^9 cu modulo"

---

# 🔹 7. Varianta 6 — O(1) Formula lui Binet

```cpp
#include <cmath>

long long fib_binet(int n) {
    const double SQRT5 = sqrt(5.0);
    const double PHI   = (1.0 + SQRT5) / 2.0;  // ≈ 1.6180 (Numărul de Aur)
    const double PSI   = (1.0 - SQRT5) / 2.0;  // ≈ -0.6180
    return (long long) round((pow(PHI, n) - pow(PSI, n)) / SQRT5);
}
```

Formula matematică:

```
        φⁿ - ψⁿ
F(n) = ---------     unde φ = (1 + √5) / 2
           √5
```

👉 Întrebare:

> „Depinde de n numărul de pași?"

✔ Răspuns:

* NU → **O(1)**

👉 Atenție:

> Erori de virgulă mobilă (`double`) pentru n > 70 — doar pentru demonstrație matematică

---

# 🔹 8. Main — test complet

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 10;

    cout << "Fibonacci F(" << n << ")" << endl;
    cout << "─────────────────────────────────" << endl;
    cout << "O(2^n)  Recursiv:      " << fib_exponential(n) << endl;
    cout << "O(n)    Memo HashMap:  " << fib_memo(n)        << endl;
    cout << "O(n)    Memo Vector:   " << fib_memo_vec(n)    << endl;
    cout << "O(n)    Bottom-Up DP:  " << fib_dp(n)          << endl;
    cout << "O(logn) Matrice:       " << fib_matrix(n)      << endl;
    cout << "O(1)    Binet:         " << fib_binet(n)       << endl;

    return 0;
}
```

**Output:**
```
Fibonacci F(10)
─────────────────────────────────
O(2^n)  Recursiv:      55
O(n)    Memo HashMap:  55
O(n)    Memo Vector:   55
O(n)    Bottom-Up DP:  55
O(logn) Matrice:       55
O(1)    Binet:         55
```

---

# 🔹 9. Comparație vizuală

| n | O(2^n) | O(n) | O(log n) | O(1) |
| --- | --- | --- | --- | --- |
| 10 | 1.024 | 10 | 3 | 1 |
| 20 | 1.048.576 | 20 | 4 | 1 |
| 30 | 1.073.741.824 | 30 | 5 | 1 |
| 100 | 2^100 ≈ 10^30 | 100 | 7 | 1 |

👉 Întrebare:

> „Care variantă alegem pentru n = 10^9?"

✔ Răspuns: **O(log n)** cu matrice (Binet pică din cauza erorilor float)

---

# 🎯 Structură finală (pe scurt)

1. Problemă simplă
2. Soluție naivă — O(2^n)
3. Memoization Hash — O(n)
4. Memoization Vector — O(n)
5. Bottom-Up DP — O(n) timp, O(1) spațiu
6. Exponențiere matrice — O(log n)
7. Formula Binet — O(1) cu limitări
8. Definiție Big O
9. Comparație
10. Concluzie

---

## References

* [Big O Notation — Suma Gauss](https://github.com/thinkphp/Big-O-Notation/blob/main/big-o-notation-sum-gauss.md)
* [Big O Notation Repository](https://github.com/thinkphp/Big-O-Notation)
