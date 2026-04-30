# Big O Analysis: Primality Testing (Brute Force vs Fermat)

## 📌 Overview

Acest proiect compară două abordări pentru testarea primalității:

1. **Brute Force Deterministic Check**
2. **Fermat Probabilistic Primality Test**

și include o funcție auxiliară de:

* **Exponentiere modulară rapidă (Fast Power)**

Scopul este analiza complexității în timp și spațiu folosind **Big O Notation**.

---

# 🧠 1. Brute Force Primality Check

## 🔹 Algoritm

```
// -------------------- CHECK (brute force) --------------------
bool check(long long n) {
    if (n == 2 || n == 3)
        return true;

    if (n < 2)
        return false;

    if (n % 2 == 0)
        return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}


```

Se verifică dacă un număr ( n ) are divizori până la ( \sqrt{n} ).

i \le \sqrt{n}

---

## ⏱️ Complexitate timp

În cel mai rău caz (număr prim):

O(\sqrt{n})

✔ Motiv:

* verificăm toți divizorii posibili până la √n
* fiecare operație este O(1)

---

## 💾 Complexitate spațiu

O(1)

✔ Motiv:

* folosim doar variabile simple (`i`, `n`)
* fără structuri auxiliare

---

# ⚡ 2. Fast Modular Exponentiation

## 🔹 Algoritm

Calculăm eficient:

a^b \bmod m

prin metoda exponentierii binare.

---

## ⏱️ Complexitate timp

O(\log n)

✔ Motiv:

* exponentul este împărțit la 2 la fiecare pas
* numărul de pași este logaritmic

---

## 💾 Complexitate spațiu

O(1)

---

# 🔬 3. Fermat Primality Test

## 🔹 Algoritm

Verificăm condiția:

a^{n-1} \equiv 1 \pmod n

pentru mai multe valori aleatoare ale lui ( a ).

---

## ⏱️ Complexitate timp

Fiecare test:

* fast_pow → O(log n)

Se repetă de k ori (în cod k = 5):

O(k \log n)

✔ Deoarece k este constant:

O(\log n)

---

## 💾 Complexitate spațiu

O(1)

✔ Motiv:

* doar variabile scalare
* fără memorii auxiliare

---

## ⚠️ Observație importantă

Fermat este:

* ✔ rapid
* ✔ eficient
* ❌ probabilistic (nu garantat corect)

Există numere compuse (Carmichael numbers) care trec testul.

---

# 📊 4. Comparatie finală

| Algoritm              | Tip           | Timp     | Spațiu | Siguranță |
| --------------------- | ------------- | -------- | ------ | --------- |
| Brute Force (`check`) | determinist   | O(√n)    | O(1)   | 100%      |
| Fermat Test           | probabilistic | O(log n) | O(1)   | ~99%+     |
| Fast Power            | subrutina     | O(log n) | O(1)   | N/A       |

---

# 🚀 5. Concluzie

* **Brute Force** → simplu, dar lent
* **Fermat Test** → foarte rapid, dar probabilistic
* **Fast Power** → optimizare esențială pentru algoritmi modulari

---

# 🔥 6. Insight important

Diferența fundamentală:

* Brute Force → verifică **toți posibilii divizori**
* Fermat → verifică **o proprietate matematică probabilistică**

---

Dacă vrei, pot să-ți fac și:

✔ versiune GitHub profesională (cu badges, structura repo)
✔ diagramă de complexitate (graf comparativ O(√n) vs O(log n))
✔ sau upgrade la Miller–Rabin (standard industrial)
