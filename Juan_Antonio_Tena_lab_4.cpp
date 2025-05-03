#include <iostream>

using namespace std;

const int max_queue = 10;
string karaoke_queue[max_queue];

int front = 0;
int rear = -1;
int count = 0;
bool isFull() {
    return count == max_queue;
}

bool isEmpty() {
    return count == 0; 
}

string enqueue(string song) {
    if (isFull()) {
        return "The queue is Full. Try again later";
    }
    
    rear = (rear + 1) % max_queue; 
    karaoke_queue[rear] = song;
    count++; 
    return "A new song has been added to the queue: " + song;
}

string dequeue() {
    if (isEmpty()) {
        return "There is no song in the queue. Try adding first";
    }
    
    string song = karaoke_queue[front];
    front = (front + 1) % max_queue; 
    count--; 
    return "Dequeued song: " + song; 
}

int main() {
    cout << enqueue("Kung wala ka") << endl;
    cin >> karaoke_queue[0];
    cout << enqueue("Happier") << endl;
    cin >> karaoke_queue[1];
    cout << enqueue("Tibok") << endl;
    cin >> karaoke_queue[2];

    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl; 

    return 0;
}