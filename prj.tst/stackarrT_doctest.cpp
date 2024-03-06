#include <templ_stackarr/stackarrT.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[stackarr] - simple push/pop test") {
    StackArrT<float> stack;
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

TEST_CASE("[stackarr] - assignment operator test") {
    StackArrT<float> stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackArrT<float> stack_copy = stack;
    CHECK(stack.Top() == stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size());
    stack_copy.Push(7.0);
    CHECK(stack.Top() != stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size() - 1);
}

TEST_CASE("[stackarr] - copy constructor test") {
    StackArrT<float> stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackArrT<float> stack_copy(stack);
    CHECK(stack.Top() == stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size());
    stack_copy.Pop();
    CHECK(stack.Top() != stack_copy.Top());
    CHECK(stack.Size() == stack_copy.Size() + 1);
}

TEST_CASE("[stackarr] - move assignment operator test") {
    StackArrT<float> stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackArrT<float> stack_copy = std::move(stack);
    CHECK(stack.IsEmpty() == true);
    CHECK(stack.Size() == 0);
    CHECK(stack_copy.Size() == 2);
    CHECK(stack_copy.Top() == 5.0);
}

TEST_CASE("[stackarr] - move constructor test") {
    StackArrT<float> stack;
    stack.Push(3.0);
    stack.Push(5.0);
    StackArrT<float> stack_copy(std::move(stack));
    CHECK(stack.IsEmpty() == true);
    CHECK(stack.Size() == 0);
    CHECK(stack_copy.Size() == 2);
    CHECK(stack_copy.Top() == 5.0);
}

TEST_CASE("[stackarr] - clear test") {
    StackArrT<float> stack;
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
