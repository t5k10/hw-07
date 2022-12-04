#include "gtest/gtest.h"
#include "list.cpp"

class ListFixture : public testing::Test {
public:
    const size_t count = 1000;
    LinkedList<int> list;

    static void SetUpTestSuite() {}
    
    static void TearDownTestSuite() {}
    
    void SetUp() override { for (size_t i = 0; i < count; ++i) list.push_back(i); }
    
    void TearDown() override {}
};

TEST(List, Empty) {
    LinkedList<int> list;

    ASSERT_EQ(list.size(), 0);
}

TEST(List, PushFront) {
    LinkedList<int> list;
    const size_t count = 1000;
    for (size_t i = 0; i < count; ++i) list.push_front(i);

    ASSERT_EQ(list.size(), count); 
}

TEST_F(ListFixture, PushBack) {
    ASSERT_EQ(list.size(), count);
}

TEST_F(ListFixture, PopBack) {
/*    for (size_t i = 0; i < count; ++i) list.pop_back();

    ASSERT_EQ(list.size(), 0);
*/
    list.pop_back();
    list.pop_back();
    list.pop_back();

    ASSERT_EQ(list.size(), count - 3);
}

TEST_F(ListFixture, PopFront) {
    
    for (size_t i = 0; i < count; ++i) list.pop_front();

    ASSERT_EQ(list.size(), 0);
}

TEST_F(ListFixture, Insert) {
    const size_t position1 = 1;
    const size_t position2 = 501;
    const size_t position3 = list.size() + 2;
    const int number = 99999999;

    list.insert(number, position1);
    list.insert(number, position2);
    list.insert(number, position3);

    ASSERT_EQ(list[position1], number);
    ASSERT_EQ(list[position2], number);
    ASSERT_EQ(list[position3], number);
}

TEST_F(ListFixture, Erase) {
/*    for (size_t i = 0; i < count; ++i) list.erase(1);

    ASSERT_EQ(list.size(), 0);
*/    
    const size_t position1 = 1;
    const size_t position2 = 499;
    const size_t position3 = count - 2;

    list.erase(position1);
    list.erase(position2);
    list.erase(position3);

    ASSERT_EQ(list.size(), count - 3);
}

TEST_F(ListFixture, Clear) {
    ASSERT_EQ(list.size(), count);
    
    list.clear();
    
    ASSERT_EQ(list.size(), 0);
}

TEST_F(ListFixture, QuantityElements) {
    ASSERT_EQ(list.size(), count);
}

TEST_F(ListFixture, CopyContainer) {
    LinkedList<int> list2(list);

    ASSERT_TRUE(list == list2);
}
