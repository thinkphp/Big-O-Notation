# Introducere în Big O Notation (prin suma Gauss)

# 🔹 1. Hook

👉 Începi cu o întrebare simplă:

> „Cum calculați suma:
> 1 + 2 + 3 + ... + n ?”

Lasă 2–3 răspunsuri.

---

# 🔹 2. Varianta 1 — O(n²)

```cpp
int suma = 0;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (j <= i) {
            suma++;
        }
    }
}
```

👉 Întrebare:

> „De câte ori se execută codul?”

✔ Răspuns:

* aproximativ n × n → **O(n²)**

👉 Mesaj:

> „Funcționează… dar e lent”

---

# 🔹 2. Varianta 2 — O(n)

```cpp
#include <iostream> 

using namespace std; 

int sum(int a, int b) { 

    if(a == b) return a; 
    
    else 
    
    return sum(a, ( a + b ) /2 ) + sum( (a + b) / 2 + 1, b); 
} 

int main(int argc, char const *argv[]) { 

    int n = 10; cout<<sum(1, 10); return 0; 
}
```

# 🔹 3. Varianta 2 — O(n) 

```cpp
int suma = 0;
for (int i = 1; i <= n; i++) {
    suma += i;
}
```

👉 Întrebare:

> „Câte operații avem acum?”

✔ Răspuns:

* n → **O(n)**

👉 Mesaj:

> „Am optimizat de la n² la n”

---

# 🔹 4. Varianta 3 — O(1) 

Formula lui Carl Friedrich Gauss:

[
S = \frac{n(n+1)}{2}
]

```cpp
int suma = n * (n + 1) / 2;
```

👉 Întrebare:

> „Depinde de n numărul de pași?”

✔ Răspuns:

* NU → **O(1)**

👉 Mesaj:

> „Aceeași problemă, dar rezolvată instant”

---

# 🔹 5. Conceptul Big O (2–3 min)

👉 Definiție simplă:

> **Big O măsoară cum crește timpul de execuție când crește n**

---

# 🔹 6. Comparație vizuală (foarte important)

| n     | O(n²)     | O(n)  | O(1) |
| ----- | --------- | ----- | ---- |
| 10    | 100       | 10    | 1    |
| 100   | 10.000    | 100   | 1    |
| 1.000 | 1.000.000 | 1.000 | 1    |

👉 întrebare:

> „Care variantă alegem pentru n mare?”

✔ răspuns: **O(1)**

---


# 🎯 Structură finală (pe scurt)

1. Problemă simplă
2. Soluție proastă (O(n²))
3. Soluție mai bună (O(n))
4. Soluție optimă (O(1))
5. Definiție Big O
6. Comparație
7. Concluzie

