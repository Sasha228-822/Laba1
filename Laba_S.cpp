#include <iostream>
#include <cstring>
#include <climits>
#include <cstdint>

void printTypeSizes() {
    std::cout << "bool:        " << sizeof(bool) << " байт\n";
    std::cout << "char:        " << sizeof(char) << " байт\n";
    std::cout << "short int:   " << sizeof(short int) << " байт\n";
    std::cout << "int:         " << sizeof(int) << " байт\n";
    std::cout << "long int:    " << sizeof(long int) << " байт\n";
    std::cout << "float:       " << sizeof(float) << " байт\n";
    std::cout << "double:      " << sizeof(double) << " байт\n";
    std::cout << "long double: " << sizeof(long double) << " байт\n\n";
}

void printIntBinary(int number) {
    int totalBits = sizeof(int) * 8;
    int signBit = (number >> (totalBits - 1)) & 1;
    std::cout << signBit << " | ";

    for (int i = totalBits - 2; i >= 0; i--) {
        std::cout << ((number >> i) & 1);
        if (i % 4 == 0 && i != 0) std::cout << " ";
    }
    std::cout << "\n";
}

void printFloatBinary(float number) {
    unsigned int bits;
    std::memcpy(&bits, &number, sizeof(float));

    std::cout << ((bits >> 31) & 1) << " | ";

    for (int i = 30; i >= 23; i--) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << " | ";

    for (int i = 22; i >= 0; i--) {
        std::cout << ((bits >> i) & 1);
        if (i % 4 == 0 && i != 0) std::cout << " ";
    }
    std::cout << "\n";
}

void printDoubleBinary(double number) {
    unsigned long long bits;
    std::memcpy(&bits, &number, sizeof(double));

    std::cout << ((bits >> 63) & 1) << " | ";

    for (int i = 62; i >= 52; i--) {
        std::cout << ((bits >> i) & 1);
    }
    std::cout << " | ";

    for (int i = 51; i >= 0; i--) {
        std::cout << ((bits >> i) & 1);
        if (i % 4 == 0 && i != 0) std::cout << " ";
    }
    std::cout << "\n";
}

int roundDownToEven(int number) {
    return number & ~1;
}

int main() {
    system("chcp 65001 > nul");

    std::cout << "задание 1\n";
    printTypeSizes();

    std::cout << "задание 2\n";
    std::cout << "42:  "; printIntBinary(42);
    std::cout << "-42: "; printIntBinary(-42);
    std::cout << "\n";

    std::cout << "задание 3\n";
    std::cout << "8.5: "; printFloatBinary(8.5f);
    std::cout << "\n";

    std::cout << "задание 4\n";
    std::cout << "8.5: "; printDoubleBinary(8.5);
    std::cout << "\n";

    std::cout << "задание 5\n";
    std::cout << "7 -> " << roundDownToEven(7) << "\n";
    std::cout << "6 -> " << roundDownToEven(6) << "\n";
    std::cout << "\n";

    std::cout << "задание 6\n";
    std::cout << "[Int+] 100:   "; printIntBinary(100);
    std::cout << "[Int-] -100:  "; printIntBinary(-100);
    std::cout << "[Float] 0.15: "; printFloatBinary(0.15625f);
    std::cout << "[Denorm]:     "; printFloatBinary(1.4e-45f);
    std::cout << "\n";

    return 0;
}
