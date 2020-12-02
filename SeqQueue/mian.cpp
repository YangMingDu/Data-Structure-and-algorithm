#include <iostream>
using namespace std;

template<class T>
class SeqQueue{
public:
    SeqQueue(int sz = 0);
    ~SeqQueue(){if (element != NULL) delete[]element;}
    bool EnQueue(const T& x);
    bool DeQueue();
    bool getFront(T& x);
    void setEmpty();
    bool isEmpty()const;
    bool isFull()const;
    template<class U>
    friend ostream& operator << (ostream& os,const SeqQueue<U>& s);
private:
    T *element;
    int front,rear,maxsize;
};
template<class T>
SeqQueue<T>::SeqQueue(int sz){
    if (!sz){
        element = NULL;
    } else {
        element = new T[sz];
    }
    front = rear = 0;
    maxsize = sz;
}

template<class T>
bool SeqQueue<T>::EnQueue(const T &x){
    if (isFull())
        return false;
    element[rear] = x;
    rear = (rear + 1) % maxsize;
    return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(){
    if(isEmpty())
        return false;
    front = (front + 1) % maxsize;
    return true;
}

template<class T>
bool SeqQueue<T>::isEmpty()const{
    return front == rear;
}
template<class T>
bool SeqQueue<T>::isFull()const{
    return (rear+1) % maxsize == front;
}
template<class T>
bool SeqQueue<T>::getFront(T& x){
    if (isEmpty())
        return false;
    x = element[front];
    return true;
}

template<class T>
void SeqQueue<T>::setEmpty(){
    front = rear = 0;
}

template<class U>
ostream& operator << (ostream& os,const SeqQueue<U>& s){
    os << "front = "<< s.front<< ", rear = "<< s.rear<< endl;
    for (int i = s.front;i != s.rear;i = (i + 1) % s.maxsize){
        if (i != s.front){
            os << "->";
        }
        os << s.element[i];
    }
    return os;
}

int main(){
    SeqQueue<int> s(10);
    for (int i = 0; i < 10; ++i)
        s.EnQueue(i *123 - 12);
    cout << s<< endl;
    for (int i = 0; i < 5; ++i)
        s.DeQueue();
    cout << s<< endl;
}