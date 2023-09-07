// VirtualMethods.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
using namespace std;

class List 
{
public:
    virtual void insert(int value) = 0; // Виртуальная функция вставки
    virtual int extract() = 0;         // Виртуальная функция вытаскивания
};

class Stack : public List
{
private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int size) 
    {
        capacity = size;
        data = new int[capacity];
        top = -1;
    }

    ~Stack() 
    {
        delete[] data;
    }

    void insert(int value) 
    {
        if (top < capacity - 1)
        {
            data[++top] = value;
        }
        else 
        {
            cout << "Stack is full!" << endl;
        }
    }

    int extract() 
    {
        if (top >= 0)
        {
            return data[top--];
        }
        else
        {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
    }
};

class Queue : public List 
{
private:
    int* data;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        capacity = size;
        data = new int[capacity];
        front = rear = -1;
    }

    ~Queue() 
    {
        delete[] data;
    }

    void insert(int value) 
    {
        if (rear < capacity - 1)
        {
            data[++rear] = value;
            if (front == -1) 
            {
                front = 0;
            }
        }
        else
        {
            cout << "Queue is full!" << endl;
        }
    }

    int extract() override
    {
        if (front <= rear && front != -1) 
        {
            return data[front++];
        }
        else 
        {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
    }
};

int main()
{
    
    Stack stack(3);
    Queue queue(3);

    // Пример использования стека
    stack.insert(1);
    stack.insert(2);
    stack.insert(3);

    cout << "Extracting from stack: " << stack.extract() << endl;
    cout << "Extracting from stack: " << stack.extract() << endl;

    // Пример использования очереди
    queue.insert(7);
    queue.insert(6);
    queue.insert(30);

    cout << "Extracting from queue: " << queue.extract() << endl;
    cout << "Extracting from queue: " << queue.extract() << endl;

    return 0;
}
