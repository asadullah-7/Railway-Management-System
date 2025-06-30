#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
private:
    int size;
    int top;
    T* stack;

public:
    Stack(int s = 100)
    {
        size = s;
        top = -1;
        stack = new T[size];
    }

    bool isFull() const { return (top == size - 1); }

    bool isEmpty() const { return (top == -1); }

    void push(T num)
    {
        if (isFull())
        {
            cout << "Stack is full!";
            return;
        }
        stack[++top] = num;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw out_of_range("Stack is empty!");
        }
        return stack[top--];
    }

    ~Stack() { delete[] stack; }
};

template<typename T>
class Queue
{
private:
    int front;
    int back;
    int capacity;
    T* queue;

public:
    Queue(int s = 100)
    {
        capacity = s;
        front = -1;
        back = -1;
        queue = new T[capacity];
    }

    bool isFull() const { return (back == capacity - 1); }

    bool isEmpty() const { return (front == -1 || front > back); }

    int size() const {
        return isEmpty() ? 0 : (back - front + 1);
    }

    void push(T value)
    {
        if (isFull())
        {
            throw out_of_range("Queue is Full!");
        }

        if (isEmpty()) front = 0;

        queue[++back] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is Empty!");
        }

        return queue[front++];
    }

    T peek() const
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is Empty!");
        }
        return queue[front];
    }

    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw out_of_range("Invalid queue index");
        }
        return queue[front + index];
    }

    ~Queue() { delete[] queue; }
};