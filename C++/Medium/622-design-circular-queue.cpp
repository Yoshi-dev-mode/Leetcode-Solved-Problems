#include <iostream>
#include <vector>

using namespace std;

/**
 * LeetCode 622: Design Circular Queue
 *
 * Problem:
 * Implement a circular queue with a fixed capacity.
 * A circular queue reuses empty spaces by wrapping
 * around to the beginning of the underlying array.
 *
 * Approach:
 * - Use a vector to store queue elements.
 * - Use front to track the first element.
 * - Use rear to track the last inserted element.
 * - Use size to track the number of elements.
 * - Use capacity to store the maximum queue size.
 * - Use the modulo operator (%) for circular indexing.
 *
 * Time Complexity: O(1) for all queue operations.
 * Space Complexity: O(k), where k is the queue capacity.
 */
class MyCircularQueue {
public:
    vector<int> q;    // Stores the queue elements
    int front;        // Index of the front element
    int rear;         // Index of the rear element
    int size;         // Current number of elements
    int capacity;     // Maximum number of elements

    /**
     * Constructor: Initializes an empty circular queue.
     *
     * @param k Maximum capacity of the queue.
     */
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = 0;
        rear = -1;  // No elements have been inserted yet
        size = 0;
    }

    /**
     * Inserts a value at the rear of the queue.
     *
     * @param value The value to insert.
     * @return true if insertion succeeds, false if full.
     */
    bool enQueue(int value) {
        // Cannot insert when the queue is full.
        if (isFull())
            return false;

        // Advance rear and wrap around when necessary.
        rear = (rear + 1) % capacity;

        // Store the value and update the element count.
        q[rear] = value;
        size++;

        return true;
    }

    /**
     * Removes the front element from the queue.
     *
     * @return true if removal succeeds, false if empty.
     */
    bool deQueue() {
        // Cannot remove an element from an empty queue.
        if (isEmpty())
            return false;

        // Advance front without shifting other elements.
        front = (front + 1) % capacity;

        // Decrease the number of elements.
        size--;

        return true;
    }

    /**
     * Returns the front element of the queue.
     *
     * @return The front value, or -1 if the queue is empty.
     */
    int Front() {
        if (isEmpty())
            return -1;

        return q[front];
    }

    /**
     * Returns the last element inserted into the queue.
     *
     * @return The rear value, or -1 if the queue is empty.
     */
    int Rear() {
        if (isEmpty())
            return -1;

        return q[rear];
    }

    /**
     * Checks whether the queue contains no elements.
     *
     * @return true if empty, otherwise false.
     */
    bool isEmpty() {
        return size == 0;
    }

    /**
     * Checks whether the queue has reached its capacity.
     *
     * @return true if full, otherwise false.
     */
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Main function for local testing.
 * LeetCode provides its own test driver, so remove main()
 * when submitting the solution to LeetCode.
 */
int main() {
    MyCircularQueue q(3);

    cout << boolalpha;

    // Insert elements into the queue.
    cout << q.enQueue(10) << endl; // true
    cout << q.enQueue(20) << endl; // true
    cout << q.enQueue(30) << endl; // true
    cout << q.enQueue(40) << endl; // false: queue is full

    // Check the rear element and queue capacity.
    cout << q.Rear() << endl;      // 30
    cout << q.isFull() << endl;    // true

    // Remove the front element and reuse its position.
    cout << q.deQueue() << endl;   // true: removes 10
    cout << q.enQueue(40) << endl; // true: wraps around

    // Check the updated front and rear elements.
    cout << q.Front() << endl;     // 20
    cout << q.Rear() << endl;      // 40

    return 0;
}