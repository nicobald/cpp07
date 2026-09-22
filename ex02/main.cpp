#include "Array.hpp"
#include <string>
#include <cstdlib>

int main()
{
    std::cout << "=== Test 1 : Array vide ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;
    try {
        std::cout << empty[0] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 2 : Array de n elements (init par defaut) ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "size: " << numbers.size() << std::endl;
    std::cout << "valeurs par defaut: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    std::cout << "apres remplissage: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "=== Test 3 : Copie profonde (constructeur) ===" << std::endl;
    Array<int> copy(numbers);
    copy[0] = 999;
    std::cout << "original[0]: " << numbers[0] << " | copie[0]: " << copy[0] << std::endl;

    std::cout << "=== Test 4 : Copie profonde (operator=) ===" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    assigned[1] = 888;
    std::cout << "size apres assignation: " << assigned.size() << std::endl;
    std::cout << "original[1]: " << numbers[1] << " | assigne[1]: " << assigned[1] << std::endl;

    std::cout << "=== Test 5 : Auto-assignation ===" << std::endl;
    Array<int> &ref = numbers;
    numbers = ref;
    std::cout << "toujours valide, size: " << numbers.size() << " numbers[2]: " << numbers[2] << std::endl;

    std::cout << "=== Test 6 : Index hors limites ===" << std::endl;
    try {
        numbers[5] = 1;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        std::cout << numbers[42] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 7 : Array const ===" << std::endl;
    const Array<int> frozen(copy);
    std::cout << "frozen[0]: " << frozen[0] << " size: " << frozen.size() << std::endl;
    try {
        std::cout << frozen[100] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 8 : Array de string ===" << std::endl;
    Array<std::string> words(3);
    std::cout << "strings par defaut: [" << words[0] << "][" << words[1] << "][" << words[2] << "]" << std::endl;
    words[0] = "hello";
    words[1] = "world";
    words[2] = "cpp";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    std::cout << "=== Test 9 : Array de float ===" << std::endl;
    Array<float> floats(4);
    std::cout << "floats par defaut: ";
    for (unsigned int i = 0; i < floats.size(); i++)
        std::cout << floats[i] << " ";
    std::cout << std::endl;

    return (0);
}
