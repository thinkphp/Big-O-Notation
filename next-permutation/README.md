# ✅ Implementare C++

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool nextPermutation(vector<int>& a) {
    int n = a.size();
    int i = n - 2;

    // 1. găsește pivotul
    while (i >= 0 && a[i] >= a[i + 1]) {
        i--;
    }

    // dacă e ultima permutare
    if (i >= 0) {
        int j = n - 1;

        // 2. caută elementul de schimb
        while (a[j] <= a[i]) {
            j--;
        }

        swap(a[i], a[j]);
    }

    // 3. inversează sufixul
    reverse(a.begin() + i + 1, a.end());

    return i >= 0;
}

int main() {
    vector<int> a = {1, 2, 3, 6, 5, 4};

    nextPermutation(a);

    for (int x : a) {
        cout << x << " ";
    }
}
```

---

# 🐍 Implementare Python

```python
def next_permutation(a):
    n = len(a)
    i = n - 2

    # 1. găsește pivotul
    while i >= 0 and a[i] >= a[i + 1]:
        i -= 1

    if i >= 0:
        j = n - 1

        # 2. caută elementul de schimb
        while a[j] <= a[i]:
            j -= 1

        a[i], a[j] = a[j], a[i]

    # 3. inversează sufixul
    a[i+1:] = reversed(a[i+1:])

    return a


# exemplu
a = [1, 2, 3, 6, 5, 4]
print(next_permutation(a))
```

---

# 🔥 Observație importantă

* complexitate: **O(n)**
* spațiu: **O(1)**
* folosit în:

  * generarea permutărilor
  * probleme combinatorice
  * STL C++ (`std::next_permutation`)


* sau o variantă optimizată pentru competiții (IOI / Codeforces)
