# Teoria complexității: Big O Notation

**Exemplu ghid:** împărțirea întreagă (dividend / divisor) fără operatorul `/`

---

## Obiective

La finalul lecției vei putea:

- explica ce măsoară notația Big O și de ce o folosim;
- compara doi algoritmi care rezolvă aceeași problemă, dar cu costuri foarte diferite;
- recunoaște o complexitate liniară, logaritmică și logaritmică la pătrat;
- număra operațiile unui algoritm și le legi de dimensiunea intrării.

---

## 1. Terminologie

Pentru operația `a : b` folosim:

| Termen | Engleză | Notație |
|---|---|---|
| deîmpărțit | dividend | `a` |
| împărțitor | divisor | `b` |
| cât | quotient | `q` |
| rest | remainder | `r` |

Relația de bază: **a = b · q + r**, cu 0 ≤ r < b.

Exemplu: 100 = 3 · 33 + 1, deci q = 33 și r = 1.

> **Atenție la limbaj.**
> - „a se împarte la b" = operația a : b.
> - „a este divizibil cu b" (sau „a se divide cu b") = restul este 0, adică b este divizor al lui a.
> - Evită „a divide cu b" pentru operație, pentru că în română „a divide" înseamnă relația de divizibilitate.

---

## 2. Problema

Se dau două numere întregi pozitive `a` (dividend) și `b` (divisor). Aflați **de câte ori „intră" `b` în `a`**, adică câtul q, **fără a folosi `/` sau `%`**.

---

## 3. Soluția 1: scăderi repetate

Scădem `b` din `a` cât timp se poate și numărăm scăderile.

```cpp
int DivideSlow(int a, int b) {
    int result = 0;
    while (a >= b) {
        a -= b;
        result++;
    }
    return result;
}
```

Urmărire pentru `100 / 3`:

```
100 -> 97 -> 94 -> 91 -> ... -> 4 -> 1
```

Se fac **33 de scăderi**. În general, numărul de iterații este egal cu câtul.

| a / b | Număr de scăderi |
|---|---|
| 100 / 3 | 33 |
| 1.000 / 1 | 1.000 |
| 1.000.000 / 1 | 1.000.000 |
| 1.000.000.000 / 1 | 1.000.000.000 |

Dacă `a` crește de 10 ori, timpul crește de 10 ori.

**Complexitate: O(q) = O(a/b)**, adică liniară în valoarea câtului.

---

## 4. Soluția 2: dublări și scădere

### Ideea

În loc să scădem `b` o singură dată, căutăm **cel mai mare multiplu de forma `b · 2^k`** care încă încape în `a`. Îl scădem dintr-o singură mișcare și adăugăm `2^k` la rezultat. Repetăm cu ce a rămas.

Înmulțirea cu 2 se face cu o deplasare de biți: `x << 1` este `x * 2`.

### Codul

```cpp
#include <iostream>
using namespace std;

int Divide(int a, int b) {

    int dividend = a, divisor = b, multiply, result = 0;

    while (dividend >= divisor) {

        int temp = divisor;
        multiply = 1;

        // dublăm cât timp încă încape în dividend
        while ((temp << 1) <= dividend) {
            temp <<= 1;
            multiply <<= 1;
        }

        dividend -= temp;
        result += multiply;
    }

    return result;
}

int main() {
    int a, b;

    cout << "dividend = ";
    cin >> a;

    cout << "divisor = ";
    cin >> b;

    cout << Divide(a, b);
    return 0;
}
```

### Urmărire pentru `100 / 3`

**Iterația 1** (`dividend = 100`):

```
temp:     3 -> 6 -> 12 -> 24 -> 48 -> 96     (192 > 100, ne oprim)
multiply: 1 -> 2 -> 4  -> 8  -> 16 -> 32
dividend = 100 - 96 = 4
result   = 0 + 32 = 32
```

**Iterația 2** (`dividend = 4`):

```
temp = 3        (6 > 4, nu dublăm)
multiply = 1
dividend = 4 - 3 = 1
result   = 32 + 1 = 33
```

`1 < 3`, deci ne oprim. Rezultat: **q = 33, rest = 1**.

În total: **2 scăderi și 5 deplasări**, față de 33 de scăderi la soluția 1.

### De ce funcționează

Câtul se construiește din **puteri ale lui 2**:

```
33 = 32 + 1    (în binar: 100001)
100 = 3·32 + 3·1 + 1
```

Este exact împărțirea în scris, doar că în baza 2.

---

## 5. Analiza complexității

### Ce înseamnă Big O

Big O descrie **cum crește numărul de operații când intrarea crește**, ignorând constantele. Nu ne interesează câte milisecunde durează pe calculatorul tău, ci ce se întâmplă când problema devine de 10, 100 sau 1000 de ori mai mare.

### Soluția 1

Numărul de iterații este q = a/b.

**Complexitate: O(a/b)** (liniară).

### Soluția 2: de ce logaritmică

Numărul de dublări este numărul de pași până când `b · 2^k` depășește `a`:

```
b · 2^k ≤ a   =>   2^k ≤ a/b   =>   k ≤ log₂(a/b)
```

Deci algoritmul depinde de **raportul a/b**, nu de `a` singur.

| a / b | log₂(a/b) | Pași (aprox.) |
|---|---|---|
| 1.000.000 / 1 | ~20 | ~20 |
| 1.000.000 / 1.000 | ~10 | ~10 |
| 1.000.000 / 999.999 | ~0 | 1 |

Dacă `a` și `b` sunt mari, dar apropiate, algoritmul face foarte puțini pași. Cazul cel mai rău pentru un `a` dat este `b = 1`, când log(a/b) = log a.

### O observație importantă: bucla în buclă

Codul de la secțiunea 4 are **două bucle imbricate**:

- bucla exterioară rulează de cel mult log q ori (de câte ori are câtul biți de 1);
- bucla interioară rulează de cel mult log q ori la fiecare iterație, pentru că `temp` **se reia de la `divisor`** de fiecare dată.

În cel mai rău caz (de exemplu q = 111...1 în binar, cum este 7 = 111₂ sau 15 = 1111₂), numărul de deplasări este:

```
(log q) + (log q − 1) + (log q − 2) + ... + 1  ≈  (log q)² / 2
```

Deci codul de la secțiunea 4 are complexitatea **O(log²(a/b))**, nu O(log(a/b)).

Diferența față de O(a/b) rămâne uriașă, dar putem face și mai bine.

---

## 6. Optimizare: O(log(a/b))

Găsim puterea maximă **o singură dată**, apoi **coborâm** de la ea spre 0. Nu mai reluăm urcarea de fiecare dată.

```cpp
int DivideFast(int a, int b) {
    if (b == 0) return -1;              // împărțire la zero, tratată separat

    long long dividend = a, divisor = b;
    int result = 0, shift = 0;

    // urcăm o singură dată: cel mai mare shift care încă încape
    while ((divisor << (shift + 1)) <= dividend)
        shift++;

    // coborâm de la shift la 0
    for (int i = shift; i >= 0; i--) {
        if ((divisor << i) <= dividend) {
            dividend -= (divisor << i);
            result += (1 << i);
        }
    }
    return result;      // la final, dividend este restul
}
```

Urmărire pentru `100 / 3` (`shift = 5`, pentru că 3·32 = 96 ≤ 100, iar 3·64 = 192 > 100):

| i | divisor << i | încape în dividend? | dividend | result |
|---|---|---|---|---|
| 5 | 96 | da | 4 | 32 |
| 4 | 48 | nu | 4 | 32 |
| 3 | 24 | nu | 4 | 32 |
| 2 | 12 | nu | 4 | 32 |
| 1 | 6 | nu | 4 | 32 |
| 0 | 3 | da | 1 | 33 |

Avem cel mult log q pași la urcare și cel mult log q la coborâre, deci **O(log(a/b))** în total.

---

## 7. Comparație finală

| | Soluția 1 | Soluția 2 (secț. 4) | Soluția 3 (secț. 6) |
|---|---|---|---|
| Idee | scăderi repetate | dublări, reluate | dublări o dată + coborâre |
| Complexitate | O(a/b) | O(log²(a/b)) | O(log(a/b)) |
| 1.000.000 / 1 | 1.000.000 operații | ~200 | ~40 |

**Concluzia lecției:** același parametru (a/b), dar trei ritmuri de creștere diferite: liniar, logaritmic la pătrat, logaritmic. Alegerea algoritmului contează mult mai mult decât alegerea calculatorului.

---

## 8. Cazuri limită

1. **`b = 0`:** în `Divide` din secțiunea 4, bucla `while (dividend >= divisor)` nu se mai termină, pentru că `temp` rămâne 0. Verifică întotdeauna înainte.
2. **Overflow:** `temp << 1` poate depăși `INT_MAX` când `a` este aproape de limită, ceea ce duce la comportament nedefinit. Soluția este folosirea lui `long long`.
3. **`a < b`:** bucla nu rulează deloc, rezultatul este 0 și restul este `a`.
4. **Numere negative:** codul funcționează doar pentru valori pozitive. Semnul se tratează separat, iar împărțirea se face pe valorile absolute.

---

## 9. Exerciții

1. Adaugă un **contor de operații** în fiecare soluție și rulează pentru a = 10, 100, 1.000, 10.000, ... (cu b = 1). Trasează graficul numărului de operații în funcție de `a`.
2. Modifică soluția 2 să returneze și **restul**. (Indiciu: ce valoare are `dividend` la final?)
3. Testează `Divide` pentru `7 / 1`, `15 / 1` și `16 / 1`. Numără deplasările și explică de ce primele două sunt cazuri defavorabile.
4. Demonstrează de ce O(log²(a/b)) devine O(log(a/b)) în varianta cu coborâre.
5. Implementează împărțirea pentru **numere negative**.
6. Folosind `DivideFast`, scrie o funcție `bool EsteDivizibil(int a, int b)` fără `%`.

---

## 10. Recapitulare

- Big O măsoară **creșterea** numărului de operații, nu timpul exact.
- Scăderile repetate sunt **O(a/b)**.
- Dublările cu deplasări de biți reduc costul la **logaritmic**, pentru că câtul se construiește din puteri ale lui 2.
- Complexitatea depinde de **raportul a/b**, nu de `a` singur.
- Două bucle imbricate pot ascunde un factor în plus (aici log²). Citește mereu ce se întâmplă cu variabilele la fiecare reluare a buclei interioare.

