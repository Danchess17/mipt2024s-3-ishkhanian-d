#include <stacklst/stacklst.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[stacklst] - simple push/pop test") {
    StackLst stack;
    CHECK(stack.IsEmpty() == true);
    stack.Push(3.0);
    CHECK(stack.Top() == 3.0);
    CHECK(stack.IsEmpty() == false);
    CHECK(stack.Size() == 1);
    stack.Pop();
    CHECK(stack.Size() == 0);
    CHECK(stack.IsEmpty() == true);
    stack.Push(5.0);
    stack.Push(7.0);
    stack.Push(9.0);
    CHECK(stack.Top() == 9.0);
    stack.Pop();
    CHECK(stack.Top() == 7.0);
}

TEST_CASE("[stacklst] - assignment operator test") {
    StackLst stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackLst stack_copy = stack;
    CHECK(stack.Top() == stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size());
    stack_copy.Push(7.0);
    CHECK(stack.Top() != stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size() - 1);
}

TEST_CASE("[stacklst] - copy constructor test") {
    StackLst stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackLst stack_copy(stack);
    CHECK(stack.Top() == stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size());
    stack_copy.Pop();
    CHECK(stack.Top() != stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size() + 1);
}

TEST_CASE("[stacklst] - move assignment operator test") {
    StackLst stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackLst stack_copy = std::move(stack);
    CHECK(stack.IsEmpty() == true);
    CHECK(stack.Size() == 0);
    CHECK(stack_copy.Size() == 2);
    CHECK(stack_copy.Top() == 5.0);
}

TEST_CASE("[stacklst] - move constructor test") {
    StackLst stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackLst stack_copy(std::move(stack));
    CHECK(stack.IsEmpty() == true);
    CHECK(stack.Size() == 0);
    CHECK(stack_copy.Size() == 2);
    CHECK(stack_copy.Top() == 5.0);
}

TEST_CASE("[stacklst] - clear test") {
    StackLst stack;
    stack.Push(3.0);
    stack.Push(5.0);
    stack.Push(7.0);
    stack.Clear();
    CHECK(stack.IsEmpty() == true);
    CHECK(stack.Size() == 0);
    stack.Push(9.0);
    CHECK(stack.IsEmpty() == false);
    CHECK(stack.Size() == 1);
    CHECK(stack.Top() == 9.0);
}
