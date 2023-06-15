#include <gtest/gtest.h>
#include "../include/linked_list.hpp"
#include <sstream>

template <typename T>
class LinkedListFixture : public ::testing::Test {
public:
    LinkedListFixture() = default;
    ~LinkedListFixture() = default;
protected:
    LinkedList<T> linked_list;
    std::stringstream output;
    std::ostringstream contents_of_linked_list;
};

using IntegerLinkedListFixture = LinkedListFixture<int>;

TEST_F(IntegerLinkedListFixture, testAppendValueOperation) {
    this->linked_list.append(4);
    this->output << "4";
    this->contents_of_linked_list << this->linked_list;
    EXPECT_EQ(this->output.str(), this->contents_of_linked_list.str());
}

TEST_F(IntegerLinkedListFixture, testAppendNodeOperation) {
    NodeLinkedList<int> * node = new NodeLinkedList<int>{.value=5};
    this->linked_list.append(node);
    this->output << "5";
    this->contents_of_linked_list << this->linked_list;
    EXPECT_EQ(this->output.str(), this->contents_of_linked_list.str());
}

TEST_F(IntegerLinkedListFixture, testRemovalOperation) {
    NodeLinkedList<int> * node = new NodeLinkedList<int>{.value=5};
    this->linked_list.append(node);
    this->linked_list.append(4);
    this->linked_list.remove();
    this->output << "5";
    this->contents_of_linked_list << this->linked_list;
    EXPECT_EQ(this->output.str(), this->contents_of_linked_list.str());
}

TEST_F(IntegerLinkedListFixture, testIfExceptionThrownAfterRemovalOperationWhenListIsEmpty) {
    EXPECT_THROW(this->linked_list.remove(), LinkedListErrors::IsEmpty);
}

TEST_F(IntegerLinkedListFixture, testIfOstreamOperatorReturnsIsEmptyStringWhenTryingToPrintList) {
    this->output << "List is empty!";
    this->contents_of_linked_list << this->linked_list;
    EXPECT_EQ(this->output.str(), this->contents_of_linked_list.str());
}
