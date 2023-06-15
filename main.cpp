#include "include/linked_list.hpp"

int main() {
    LinkedList<int> linked_list{};
    linked_list.append(5);
    linked_list.append(1);
    linked_list.append(2);
    linked_list.remove();
    linked_list.remove();
    linked_list.remove();
    try {
        linked_list.remove();
    } catch (LinkedListErrors::IsEmpty const& er) {
        std::cout << er.what() << std::endl;
    }
    NodeLinkedList<int> *node = new NodeLinkedList<int>{.value=5};
    linked_list.append(node);

    std::cout << linked_list << std::endl;

    return EXIT_SUCCESS;
}