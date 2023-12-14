#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    // Chèn các phần tử vào set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(1);

    // Duyệt qua set sử dụng iterator
    std::cout << "Các phần tử trong set: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Kiểm tra sự tồn tại của một phần tử
    int numToCheck = 8;
    if (mySet.count(numToCheck) > 0) {
        std::cout << numToCheck << " tồn tại trong set." << std::endl;
    } else {
        std::cout << numToCheck << " không tồn tại trong set." << std::endl;
    }

    // Xóa một phần tử khỏi set
    int numToRemove = 2;
    mySet.erase(numToRemove);

    // In lại set sau khi xóa
    std::cout << "Các phần tử trong set sau khi xóa " << numToRemove << ": ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Lấy kích thước của set
    std::cout << "Kích thước của set: " << mySet.size() << std::endl;

    // Kiểm tra set có rỗng hay không
    if (mySet.empty()) {
        std::cout << "Set rỗng." << std::endl;
    } else {
        std::cout << "Set không rỗng." << std::endl;
    }

    return 0;
}