#include <iostream>
#include <new>

namespace file {

struct BitwiseInt final {
private:
    int value;

public:
    // ==================== CONSTRUTORES ====================
    explicit constexpr BitwiseInt(int v = 0) noexcept : value(v) {}
    constexpr BitwiseInt(const BitwiseInt& other) noexcept : value(other.value) {}
    ~BitwiseInt() = default;

    // Conversão explícita
    explicit constexpr operator int() const noexcept { return value; }

    // ==================== ATRIBUIÇÃO ====================
    constexpr BitwiseInt& operator=(const BitwiseInt& other) noexcept {
        if (this != &other) value = other.value;
        return *this;
    }

    // ==================== ARITMÉTICOS ====================
    constexpr BitwiseInt operator+(const BitwiseInt& o) const noexcept { return BitwiseInt(value + o.value); }
    constexpr BitwiseInt operator-(const BitwiseInt& o) const noexcept { return BitwiseInt(value - o.value); }
    constexpr BitwiseInt operator*(const BitwiseInt& o) const noexcept { return BitwiseInt(value * o.value); }
    constexpr BitwiseInt operator/(const BitwiseInt& o) const noexcept { return BitwiseInt(value / o.value); }
    constexpr BitwiseInt operator%(const BitwiseInt& o) const noexcept { return BitwiseInt(value % o.value); }

    constexpr BitwiseInt& operator+=(const BitwiseInt& o) noexcept { value += o.value; return *this; }
    constexpr BitwiseInt& operator-=(const BitwiseInt& o) noexcept { value -= o.value; return *this; }
    constexpr BitwiseInt& operator*=(const BitwiseInt& o) noexcept { value *= o.value; return *this; }
    constexpr BitwiseInt& operator/=(const BitwiseInt& o) noexcept { value /= o.value; return *this; }
    constexpr BitwiseInt& operator%=(const BitwiseInt& o) noexcept { value %= o.value; return *this; }

    // ==================== RELACIONAIS ====================
    constexpr bool operator==(const BitwiseInt& o) const noexcept { return value == o.value; }
    constexpr bool operator!=(const BitwiseInt& o) const noexcept { return value != o.value; }
    constexpr bool operator<(const BitwiseInt& o) const noexcept { return value < o.value; }
    constexpr bool operator<=(const BitwiseInt& o) const noexcept { return value <= o.value; }
    constexpr bool operator>(const BitwiseInt& o) const noexcept { return value > o.value; }
    constexpr bool operator>=(const BitwiseInt& o) const noexcept { return value >= o.value; }

    // ==================== LÓGICOS ====================
    constexpr bool operator&&(const BitwiseInt& o) const noexcept { return value && o.value; }
    constexpr bool operator||(const BitwiseInt& o) const noexcept { return value || o.value; }
    constexpr bool operator!() const noexcept { return !value; }

    // ==================== BITWISE ====================
    constexpr BitwiseInt operator|(const BitwiseInt& o) const noexcept { return BitwiseInt(value | o.value); }
    constexpr BitwiseInt operator^(const BitwiseInt& o) const noexcept { return BitwiseInt(value ^ o.value); }
    constexpr BitwiseInt operator&(const BitwiseInt& o) const noexcept { return BitwiseInt(value & o.value); }
    constexpr BitwiseInt operator<<(int s) const noexcept { return BitwiseInt(value << s); }
    constexpr BitwiseInt operator>>(int s) const noexcept { return BitwiseInt(value >> s); }

    constexpr BitwiseInt& operator|=(const BitwiseInt& o) noexcept { value |= o.value; return *this; }
    constexpr BitwiseInt& operator^=(const BitwiseInt& o) noexcept { value ^= o.value; return *this; }
    constexpr BitwiseInt& operator&=(const BitwiseInt& o) noexcept { value &= o.value; return *this; }
    constexpr BitwiseInt& operator<<=(int s) noexcept { value <<= s; return *this; }
    constexpr BitwiseInt& operator>>=(int s) noexcept { value >>= s; return *this; }

    constexpr BitwiseInt operator~() const noexcept { return BitwiseInt(~value); }

    // ==================== UNÁRIOS ====================
    constexpr BitwiseInt operator+() const noexcept { return BitwiseInt(+value); }
    constexpr BitwiseInt operator-() const noexcept { return BitwiseInt(-value); }
    constexpr BitwiseInt& operator++() noexcept { ++value; return *this; }
    constexpr BitwiseInt operator++(int) noexcept { BitwiseInt t(*this); ++value; return t; }
    constexpr BitwiseInt& operator--() noexcept { --value; return *this; }
    constexpr BitwiseInt operator--(int) noexcept { BitwiseInt t(*this); --value; return t; }

    constexpr int operator*() const noexcept { return value; }
    constexpr int* operator&() noexcept { return &value; }

    // ==================== ESPECIAIS ====================
    constexpr int operator[](int i) const noexcept { return (value >> i) & 1; }
    constexpr int operator()(int mult) const noexcept { return value * mult; }
    constexpr BitwiseInt operator,(const BitwiseInt& o) const noexcept { return o; }

    int* operator->() noexcept { return &value; }
    int* operator->*(int* BitwiseInt::* ptr) noexcept { return this->*ptr; }

    // ==================== ALOCAÇÃO ====================
    void* operator new(std::size_t sz) {
        std::cout << "Custom new\n"; return ::operator new(sz);
    }
    void operator delete(void* p) noexcept {
        std::cout << "Custom delete\n"; ::operator delete(p);
    }
    void* operator new[](std::size_t sz) {
        std::cout << "Custom new[]\n";
        bool v = [=](const std::size_t& sz) { return (sz > 0) ? 1 : 0; }(sz);
        return (v) ? ::operator new[](sz) : nullptr;
    }
    void operator delete[](void* p) noexcept {
        std::cout << "Custom delete[]\n";
        bool v = [=](void) { return (p != (void*)0x00) ? 1 : 0; }();
        if (v) ::operator delete[](p);
        p = nullptr;
        if ((void*)p == nullptr) std::cout << "ok\n";
        else std::cout << "err\n";
    }

    // ==================== STREAMS ====================
    friend std::ostream& operator<<(std::ostream& os, const BitwiseInt& obj) noexcept {
        os << obj.value; return os;
    }

    // ==================== AUXILIAR ====================
    void print() const noexcept { std::cout << "Valor: " << value << "\n"; }
};

} // namespace file

// ==================== TESTE ====================
auto main(void) -> signed int {
    using file::BitwiseInt;

    constexpr BitwiseInt a(10), b(6);

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a & b = " << (a & b) << "\n";
    std::cout << "~a = " << (~a) << "\n";
    std::cout << "a[1] = " << a[(false) ? 1 : 0] << "\n";
    std::cout << "a(3) = " << a(3) << "\n";

    BitwiseInt* arr = new BitwiseInt[2]{ BitwiseInt(5), BitwiseInt(7) };
    delete[] arr;

    return 0;
}
