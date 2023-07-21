#include <optional>
#include <iostream>
/**
 * optional
 */
std::optional<int> getValue(bool valid) {
    if (valid) {
        return 10;
    } else {
        //不是nullptr
        return std::nullopt;
    }
}

int main() {
    auto value1 = getValue(true);
    auto value2 = getValue(false);
    if (value1) {
        //获取值需要加 *
        std::cout << "Value1: " << *value1 << std::endl;
    }
    if (value2) {
        std::cout << "Value2: " << *value2 << std::endl;
    } else {
        std::cout << "Value2 is null" << std::endl;
    }
    return 0;
}