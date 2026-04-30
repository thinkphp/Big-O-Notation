# Big O Notation String Pattern Matching — Overview (Big Picture)

## 1. 🟢 Algoritmul Naiv (baseline)

* Idee: compari la fiecare poziție

O(nm)

### Când îl folosești:

* doar pentru explicații
* implementare rapidă

---

## 2. 🟡 KMP (pattern optimization)

* idee: reutilizezi informația din pattern

O(n + m)

### Când îl folosești:

* un singur pattern
* streaming / text scan

👉 nu modifici textul, doar pattern-ul

---

## 3. 🟠 Boyer–Moore (skip-uri mari)

* idee: compari de la dreapta și sari peste text

O(nm) ; (worst),; sublinear ; (average)

### Când îl folosești:

* texte naturale
* căutări rapide în practică

---

## 4. 🔵 Rabin–Karp (hashing)

* idee: compari hash-uri

O(n + m) ; (average),; O(nm) ; (worst)

### Când îl folosești:

* multiple pattern-uri simple
* rolling hash problems

---

## 5. 🟣 Suffix Array (text preprocessing)

### Construire:

O(n \log n)

### Query:

O(m \log n)

### Când îl folosești:

* multe query-uri pe același text
* string analytics / genomics / search engines

---

## 6. 🔴 Aho–Corasick (multi-pattern)

O(n + m + z)

* m = total pattern length
* z = matches

### Când îl folosești:

* multe pattern-uri simultan
* detectare în texte mari

---

# 📊 COMPARAȚIE FINALĂ (foarte bun slide)

| Algoritm     | Preprocesare | Query time    | Caz ideal     |
| ------------ | ------------ | ------------- | ------------- |
| Naiv         | ❌            | O(nm)         | educațional   |
| KMP          | O(m)         | O(n)          | 1 pattern     |
| Boyer-Moore  | O(m)         | sublinear avg | text real     |
| Rabin-Karp   | O(m)         | O(n) avg      | multi-check   |
| Suffix Array | O(n log n)   | O(m log n)    | many queries  |
| Aho-Corasick | O(m)         | O(n + z)      | multi-pattern |

---

## 🟢 „Unde mutăm complexitatea?”

* Naiv → tot în query
* KMP → optimizează pattern-ul
* Boyer-Moore → sare peste text
* Rabin-Karp → transformă string în hash
* Suffix Array → mută costul în preprocesare
* Aho-Corasick → optimizează multi-pattern

---



Pattern matching algorithms differ mainly by where they spend their complexity: preprocessing, searching, or skipping work.”

* sau o diagramă tip flowchart (foarte bună pentru prezentare orală)

