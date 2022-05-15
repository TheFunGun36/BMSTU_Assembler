#include <iostream>

extern "C" {
    void stringCopy(char* dst, const char* src, size_t amount);
    size_t stringLength(const char* str);
}

int main() {
    const char src[] = "1234";
    size_t len = stringLength(src);

    char result[] = "abcd";
    stringCopy(result, src, len);
    std::cout << result;
    return 0;
}
