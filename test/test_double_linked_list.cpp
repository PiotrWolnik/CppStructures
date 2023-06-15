#include <gtest/gtest.h>
#include "../include/double_linked_list.hpp"



template <typename T>
class DoubleLinkedListFixture : public ::testing::Test {
public:
    DoubleLinkedListFixture() = default;
    ~DoubleLinkedListFixture() = default;
protected:
    DoubleLinkedList<T> double_linked_list{};
    std::stringstream output_normal{};
    std::stringstream output_reversed{};
    std::ostringstream contents_of_linked_list_normal{};
    std::ostringstream contents_of_linked_list_reversed{};
    typename DoubleLinkedList<T>::DoubleLinkedListForReversedOption normal{double_linked_list, false};
    typename DoubleLinkedList<T>::DoubleLinkedListForReversedOption reversed{double_linked_list, true};
};

using FloatingPointDoubleLinkedList = DoubleLinkedListFixture<double>;

TEST_F(FloatingPointDoubleLinkedList, testAppendAtEndValueOperation) {
    this->double_linked_list.append_at_end(4.0);
    this->double_linked_list.append_at_end(5.0);
    this->output_normal << "4.000000 -> 5.000000";
    this->output_reversed << "5.000000 -> 4.000000";
    this->contents_of_linked_list_normal << this->normal;
    this->contents_of_linked_list_reversed << this->reversed;
    EXPECT_EQ(this->output_normal.str(), this->contents_of_linked_list_normal.str());
    EXPECT_EQ(this->output_reversed.str(), this->contents_of_linked_list_reversed.str());
}

TEST_F(FloatingPointDoubleLinkedList, testAppendAtBeginValueOperation) {
    this->double_linked_list.append_at_begin(4.0);
    this->double_linked_list.append_at_begin(3.0);
    this->output_normal << "3.000000 -> 4.000000";
    this->output_reversed << "4.000000 -> 3.000000";
    this->contents_of_linked_list_normal << this->normal;
    this->contents_of_linked_list_reversed << this->reversed;
    EXPECT_EQ(this->output_normal.str(), this->contents_of_linked_list_normal.str());
    EXPECT_EQ(this->output_reversed.str(), this->contents_of_linked_list_reversed.str());
}

TEST_F(FloatingPointDoubleLinkedList, testAppendAtEndNodeOperation) {
    auto new_node1 = new NodeDoubleLinkedList<double>{.value=4.0};
    auto new_node2 = new NodeDoubleLinkedList<double>{.value=5.0};
    this->double_linked_list.append_at_end(new_node1);
    this->double_linked_list.append_at_end(new_node2);
    this->output_normal << "4.000000 -> 5.000000";
    this->output_reversed << "5.000000 -> 4.000000";
    this->contents_of_linked_list_normal << this->normal;
    this->contents_of_linked_list_reversed << this->reversed;
    EXPECT_EQ(this->output_normal.str(), this->contents_of_linked_list_normal.str());
    EXPECT_EQ(this->output_reversed.str(), this->contents_of_linked_list_reversed.str());
}

TEST_F(FloatingPointDoubleLinkedList, testAppendAtBeginNodeOperation) {
    auto new_node1 = new NodeDoubleLinkedList<double>{.value=4.0};
    auto new_node2 = new NodeDoubleLinkedList<double>{.value=3.0};
    this->double_linked_list.append_at_begin(new_node1);
    this->double_linked_list.append_at_begin(new_node2);
    this->output_normal << "3.000000 -> 4.000000";
    this->output_reversed << "4.000000 -> 3.000000";
    this->contents_of_linked_list_normal << this->normal;
    this->contents_of_linked_list_reversed << this->reversed;
    EXPECT_EQ(this->output_normal.str(), this->contents_of_linked_list_normal.str());
    EXPECT_EQ(this->output_reversed.str(), this->contents_of_linked_list_reversed.str());
}

// TEST_F(FloatingPointDoubleLinkedList, testIfExceptionThrownAfterRemovalOperationWhenListIsEmpty) {
//     EXPECT_THROW(this->linked_list.remove(), LinkedListErrors::IsEmpty);
// }

// TEST_F(FloatingPointDoubleLinkedList, testIfOstreamOperatorReturnsIsEmptyStringWhenTryingToPrintList) {
//     this->output << "List is empty!";
//     this->contents_of_linked_list << this->linked_list;
//     EXPECT_EQ(this->output.str(), this->contents_of_linked_list.str());
// }
