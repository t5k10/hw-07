#include "gtest/gtest.h"
#include "doubly_list.cpp"

class DoubleListFixture : public testing::Test {
public:
    const size_t count = 100;
    DoubleListContainer<int> list;
    
    static void SetUpTestSuite() {}
    
    static void TearDownTestSuite() {}
    
    void SetUp() override { for (size_t i = 0; i < count; ++i) list.push_back(i); }
    
    void TearDown() override {}
};

TEST(DoubleListContainer, Empty) {
    DoubleListContainer<int> list;

    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(list.is_empty());
}

TEST(DoubleListContainer, PushFront) {
    DoubleListContainer<int> list;
    const size_t count = 1000;
    for (size_t i = 0; i < count; ++i) list.push_front(i);

    ASSERT_EQ(list.size(), count); 
}

TEST_F(DoubleListFixture, PushBack) {
    ASSERT_EQ(list.size(), count);
}

TEST_F(DoubleListFixture, PopBack) {
    ASSERT_EQ(list.size(), count);

    for (size_t i = 0; i < count; ++i) list.pop_back(); 
    ASSERT_EQ(list.size(), 0);
}

TEST_F(DoubleListFixture, PopFront) {
    ASSERT_EQ(list.size(), count);
    
    for (size_t i = 0; i < count; ++i) list.pop_front(); 
    ASSERT_EQ(list.size(), 0);
    
}

TEST_F(DoubleListFixture, Insert) {
    const size_t position1 = 1;
    const size_t position2 = 51;
    const size_t position3 = list.size() + 2;
    const int number = 99999999;

    list.insert(number, position1);
    list.insert(number, position2);
    list.insert(number, position3);

    ASSERT_EQ(list[position1], number);
    ASSERT_EQ(list[position2], number);
    ASSERT_EQ(list[position3], number);
}

TEST_F(DoubleListFixture, Erase) {
    //for (size_t i = 0; i < count; ++i) list.erase(1);    
    //ASSERT_EQ(list.size(), 0);
    const size_t position1 = 1;
    const size_t position2 = 49;
    const size_t position3 = 97;

    list.delete_node(position1);
    list.delete_node(position2);
    list.delete_node(position3);

    ASSERT_EQ(list.size(), count - 3);
}

TEST_F(DoubleListFixture, Clear) {
    list.clear();

    ASSERT_EQ(list.size(), 0);
}

TEST_F(DoubleListFixture, QuantityElements) {
    ASSERT_EQ(list.size(), count);
}

TEST_F(DoubleListFixture, CopyContainer) {
    DoubleListContainer<int> list2(list);

    ASSERT_TRUE(list == list2);
}
