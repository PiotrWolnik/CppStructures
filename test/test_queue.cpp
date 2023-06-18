#include <gtest/gtest.h>
#include "../include/queue.hpp"
#include "../include/person.hpp"

class FakePerson : public IPerson {
public:
    std::string getName() const override { return "Peter"; }
    ID getID() const override { return 1; }
};

TEST(testFake, testIfReturnsPeterForGetNameMethod) {
    FakePerson person{};
    EXPECT_STREQ("Peter", person.getName().c_str());
}

TEST(testFake, testIfReturnsOneForGetIDMethod) {
    FakePerson person{};
    EXPECT_EQ(1, person.getID());
}

template <typename T>
class QueueFixture : public ::testing::Test {
public:
    QueueFixture() = default;
    ~QueueFixture() = default;
protected:
    Queue<T> queue{};
    std::stringstream output{};
    std::ostringstream contents_of_queue{};
};

using PersonQueueFixture = QueueFixture<Person>;

TEST_F(PersonQueueFixture, testAppendOperation) {
    Person person1{"Peter", 1};
    Person person2{"Angela", 2};
    this->queue.append(person1);
    this->queue.append(person2);
    this->output << "Name: Peter\nID: 1\n -> Name: Angela\nID: 2\n";
    this->contents_of_queue << this->queue;
    EXPECT_STREQ(this->output.str().c_str(), 
                 this->contents_of_queue.str().c_str());
}

