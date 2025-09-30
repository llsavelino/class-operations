# _________ Catálogo de Sobrecarga de Operadores em C++ _________
## aves06194@gmail.com

Este documento serve como guia para os operadores que podem (e não podem) ser sobrecarregados em **C++**.

---

## ✅ Operadores que podem ser sobrecarregados

### 1. Atribuição
- `=` → atribuição

### 2. Aritméticos
- `+` (adição)
- `-` (subtração)
- `*` (multiplicação)
- `/` (divisão)
- `%` (módulo)

### 3. Aritméticos de atribuição
- `+=`
- `-=`
- `*=`
- `/=`
- `%=`

### 4. Incremento/Decremento
- `++` (prefixo e pós-fixado)
- `--` (prefixo e pós-fixado)

### 5. Relacionais
- `==`
- `!=`
- `<`
- `<=`
- `>`
- `>=`

### 6. Lógicos
- `&&`
- `||`
- `!`

### 7. Bitwise
- `&`
- `|`
- `^`
- `~`
- `<<`
- `>>`

### 8. Bitwise de atribuição
- `&=`
- `|=`
- `^=`
- `<<=`
- `>>=`

### 9. Unários
- `+` (unário, não confundir com soma)
- `-` (unário, negação aritmética)
- `*` (indireção)
- `&` (endereço)

### 10. Acesso e Funções
- `[]` (indexação)
- `()` (functor, objeto que se comporta como função)
- `->` (acesso a membro por ponteiro)
- `->*` (acesso a membro por ponteiro a membro)

### 11. Outros
- `,` (vírgula)
- Conversão de tipo (`operator int()`, `operator double()`, etc.)

### 12. Alocação de memória
- `new`
- `new[]`
- `delete`
- `delete[]`

### 13. Streams
- `<<` e `>>` podem ser sobrecarregados para **entrada/saída** (`ostream`, `istream`).

---

## ❌ Operadores que **NÃO podem** ser sobrecarregados

- `.` (ponto de acesso a membro)
- `.*` (membro por ponteiro direto)
- `::` (escopo)
- `sizeof`
- `typeid`
- `alignof`
- `?:` (ternário condicional)

---

## 📌 Exemplo simples

```cpp
#include <iostream>

class Numero {
    int valor;

public:
    Numero(int v = 0) : valor(v) {}

    // Sobrecarga de +
    Numero operator+(const Numero& other) const {
        return Numero(valor + other.valor);
    }

    // Sobrecarga de ==
    bool operator==(const Numero& other) const {
        return valor == other.valor;
    }

    // Sobrecarga de <<
    friend std::ostream& operator<<(std::ostream& os, const Numero& n) {
        os << n.valor;
        return os;
    }
};

int main() {
    Numero a(5), b(10);

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a == b ? " << (a == b ? "sim" : "nao") << std::endl;
}
