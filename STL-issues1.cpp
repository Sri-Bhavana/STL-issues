#include <memory>
#include <iostream>
#include <vector>
#include <string>

extern "C" void ProcessVector(std::unique_ptr<std::vector<std::string>> input_vector) {
    // Example algorithm that modifies the vector
    for (auto& item : *input_vector) {
        item += " processed";
    }
}
int main() {
    std::vector<std::string> my_vector = { "apple", "banana", "orange" };
    std::unique_ptr<std::vector<std::string>> unique_ptr_vector(new std::vector<std::string>(my_vector));

    // Call the function that processes the vector
    ProcessVector(std::move(unique_ptr_vector));

    // unique_ptr_vector is now empty, as ownership has been transferred
    // You can re-obtain the data if needed:
    auto& processed_data = *unique_ptr_vector;

    for (const auto& item : processed_data) {
        std::cout << item << std::endl;
    }
    return 0;
}