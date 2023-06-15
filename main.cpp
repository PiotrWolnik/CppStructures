#include "include/linked_list.hpp"
#include "include/double_linked_list.hpp"

int main() {
    // LinkedList<int> linked_list{};
    // linked_list.append(5);
    // linked_list.append(1);
    // linked_list.append(2);
    // linked_list.remove();
    // linked_list.remove();
    // linked_list.remove();
    // try {
    //     linked_list.remove();
    // } catch (LinkedListErrors::IsEmpty const& er) {
    //     std::cout << er.what() << std::endl;
    // }
    // NodeLinkedList<int> *node = new NodeLinkedList<int>{.value=5};
    // linked_list.append(node);

    // std::cout << linked_list << std::endl;

    DoubleLinkedList<int> double_linked_list{};
    double_linked_list.append_at_end(1);
    double_linked_list.append_at_end(2);
    double_linked_list.append_at_end(3);
    auto new_node = new NodeDoubleLinkedList<int>{.value=5}; 
    double_linked_list.append_at_end(new_node);
    std::cout << DoubleLinkedList<int>::DoubleLinkedListForReversedOption{double_linked_list, false} << std::endl;
    return EXIT_SUCCESS;
}