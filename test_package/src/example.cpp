#include "bindey.h"
#include <vector>
#include <string>

int main() {
    bindey();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    bindey_print_vector(vec);
}
