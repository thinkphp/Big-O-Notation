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

```
// -------------------- FAST POWER (modular exponentiation) --------------------
long long fast_pow(long long base, long long exp, long long mod) {
    long long res = 1;

    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;

        base = (base * base) % mod;
        exp >>= 1;
    }

    return res;
}

// -------------------- FERMAT TEST --------------------
bool Fermat(long long n) {
    if (n < 2)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 0; i < 5; i++) {
        long long a = 2 + rand() % (n - 3); // [2, n-2]

        if (fast_pow(a, n - 1, n) != 1)
            return false;
    }

    return true;
}

// -------------------- MAIN --------------------
int main() {
    srand(time(0));

    long long n;
    cout << "N = ";
    cin >> n;

    cout << "Number: " << n << endl;

    cout << "Brute Force: ";
    if (check(n))
        cout << "is Prime" << endl;
    else
        cout << "is Not Prime" << endl;

    cout << "Fermat Test: ";
    if (Fermat(n))
        cout << "Probably Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}
```

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



# 🧮 Ciurul lui Eratosthenes

```cpp
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
```

Marchează ca **compus** fiecare multiplu al fiecărui prim, începând de la `i * i`.

---

## ⏱️ Complexitate timp

$$O(n \log \log n)$$

Bucla internă face n/p pași pentru fiecare prim p. Suma totală urmează seria lui Mertens — rezultă **aproape liniară**.

## 💾 Complexitate spațiu

$$O(n)$$

Un singur vector de n+1 bool-uri. Cu `vector<bool>`, C++ stochează 1 bit per element → **n/8 bytes** în practică.

---

## ⚠️ Când se folosește

- ✔ Trebuie **toate** primele până la n
- ✔ Faci **multe** interogări pe un interval fix → fiecare devine O(1) după preprocesare
- ❌ n foarte mare (10⁹+) → memoria O(n) devine prohibitivă → folosești *ciurul segmentat*

---

## 📊 Tabel comparativ actualizat

| Algoritm | Tip | Timp | Spațiu | Siguranță |
|---|---|---|---|---|
| Brute Force | determinist | O(√n) | O(1) | 100% |
| Fermat Test | probabilistic | O(log n) | O(1) | ~96%+ |
| Fast Power | subrutină | O(log n) | O(1) | N/A |
| **Sieve** | **determinist** | **O(n log log n)** | **O(n)** | **100%** |

---

# 🔥 6. Insight important

Diferența fundamentală:

* Brute Force → verifică **toți posibilii divizori**
* Fermat → verifică **o proprietate matematică probabilistică**
