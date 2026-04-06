**Algoritmul Narayana Pandita (sec. XIV) – soluție O(n) pentru „următoarea permutare”**

Narayana Pandita, un matematician indian din secolul al XIV-lea, a descris practic ceea ce astăzi numim **algoritmul „next permutation”** — o metodă de a genera următoarea permutare în ordine lexicografică în timp liniar.

Narayana Pandita

---

## Ideea algoritmului

Dată o permutare, vrem să obținem **următoarea permutare mai mare lexicografic** (ca în dicționar), în timp **O(n)**.

Algoritmul face 3 pași simpli:

---

## Pasul 1: Găsește „pivotul”

Parcurgi vectorul de la dreapta la stânga și cauți prima poziție `i` unde:

[
a[i] < a[i+1]
]

Acesta este punctul unde secvența începe să scadă.

Dacă nu există un astfel de `i`, permutarea este ultima → inversăm tot (prima permutare).

---

## Pasul 2: Găsește elementul de schimb

Din dreapta, cauți primul element `a[j]` care este:

[
a[j] > a[i]
]

---

## Pasul 3: Swap + inversare

* interschimbi `a[i]` cu `a[j]`
* inversezi segmentul `[i+1 ... n-1]`

---

## De ce este O(n)?

* fiecare pas parcurge cel mult o dată vectorul
* nu există bucle imbricate dependente de n

➡️ complexitate totală: **O(n)**

---

## Pseudocod

```text
i = n - 2
while i >= 0 and a[i] >= a[i+1]:
    i--

if i >= 0:
    j = n - 1
    while a[j] <= a[i]:
        j--
    swap(a[i], a[j])

reverse(a[i+1 : n])
```

---

## Exemplu

Permutare:

```
1 2 3 6 5 4
```

Pivot: `3`
Schimb cu `4`:

```
1 2 4 6 5 3
```

Inversezi finalul:

```
1 2 4 3 5 6
```

---

## Intuiție

Algoritmul caută:

* „cea mai mică creștere posibilă”
* apoi „cea mai mică reorganizare a restului”

---

Dacă vrei, îți pot arăta și:

* implementare C++ / Python
* sau cum se leagă de generarea tuturor permutărilor în O(n!) fără recursie costisitoare.

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
