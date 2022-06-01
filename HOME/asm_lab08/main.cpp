#include <iostream>

extern "C" {
    void stringCopy(char* dst, const char* src, size_t amount);
    size_t stringLength(const char* str);
}

int main() {
    char str[] = "1234ab";
    stringCopy(str + 2, str, 4);
    std::cout << stringLength(str) << ": \"" << str << "\"\n";
    return 0;
}
