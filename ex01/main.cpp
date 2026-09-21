#include "iter.hpp"

// ========== Fonctions simples ==========

void printInt(int x) {
    std::cout << x << " ";
}

void printDouble(double x) {
    std::cout << x << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

// ========== Fonction modifiante (non-const) ==========

void increment(int& x) {
    x++;
}

// ========== Template de fonction ==========

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

template <typename T>
void triple(T& x) {
    x = x * 3;
}

// ========== Functor (bonus) ==========

class Multiplier {
private:
    int factor;
public:
    Multiplier(int f) : factor(f) {}
    void operator()(int& x) const {
        x *= factor;
    }
};

// ========== Main ==========

int main() {
    std::cout << "=== Test 1 : Array d'int ===" << std::endl;
    int intArr[5] = {1, 2, 3, 4, 5};
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::cout << "=== Test 2 : Array de double ===" << std::endl;
    double doubleArr[4] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArr, 4, printDouble);
    std::cout << std::endl;

    std::cout << "=== Test 3 : Array de string ===" << std::endl;
    std::string strArr[3] = {"hello", "world", "cpp"};
    iter(strArr, 3, printString);
    std::cout << std::endl;

    std::cout << "=== Test 4 : Modifier l'array (non-const ref) ===" << std::endl;
    int modifyArr[3] = {10, 20, 30};
    std::cout << "Avant: ";
    iter(modifyArr, 3, printInt);
    std::cout << std::endl;
    
    iter(modifyArr, 3, increment);
    std::cout << "Après increment: ";
    iter(modifyArr, 3, printInt);
    std::cout << std::endl;

    std::cout << "=== Test 5 : Template de fonction ===" << std::endl;
    iter(intArr, 5, print<int>);
    std::cout << std::endl;

    std::cout << "=== Test 6 : Modifier avec template ===" << std::endl;
    int tripleArr[3] = {1, 2, 3};
    std::cout << "Avant: ";
    iter(tripleArr, 3, printInt);
    std::cout << std::endl;
    
    iter(tripleArr, 3, triple<int>);
    std::cout << "Après triple: ";
    iter(tripleArr, 3, printInt);
    std::cout << std::endl;

    std::cout << "=== Test 7 : Functor (bonus) ===" << std::endl;
    int functorArr[4] = {2, 4, 6, 8};
    std::cout << "Avant: ";
    iter(functorArr, 4, printInt);
    std::cout << std::endl;
    
    Multiplier mult(5);
    iter(functorArr, 4, mult);
    std::cout << "Après multiplier par 5: ";
    iter(functorArr, 4, printInt);
    std::cout << std::endl;

    return 0;
}