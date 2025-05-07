#ifndef _QUEUELINKEDLIST_H_
#define _QUEUELINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "QueueNode.h"

template <class T>
class QueueLinkedList {
  private:
    QueueNode<T> *front;
    QueueNode<T> *rear;
    int numElements;

  public:
    QueueLinkedList();
    ~QueueLinkedList();
    int getNumElements();
    void printQueue();
    bool isEmpty();
    void enqueue(T value);
    void dequeue();
    T getFront();
    T getRear();
};

// Complejidad O(1)
template <class T>
QueueLinkedList<T>::QueueLinkedList() {
  front = nullptr;
  rear = nullptr;
  numElements = 0;
}

// Complejidad O(n)
template <class T>
QueueLinkedList<T>::~QueueLinkedList() {
    QueueNode<T> *p, *q;
    p = front;
    while (p != nullptr) {
      q = p->next;
      delete p;
      p = q;
    }
    front = nullptr;
    rear = nullptr;
    numElements = 0;
}

// Complejidad O(1)
template <class T>
int QueueLinkedList<T>::getNumElements() {
  return numElements;  
}

// Complejidad O(n)
template <class T>
void QueueLinkedList<T>::printQueue() {
  if (front == nullptr && rear == nullptr)
    std::cout << "La fila esta vacia" << std::endl;
  else {
    std::cout << "El contenido de la fila es: " << std::endl;
    QueueNode<T> *p = front;
    while(p != nullptr) {
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }    
}

// Complejidad O(1)
template <class T>
bool QueueLinkedList<T>::isEmpty() {
  return (front == nullptr && rear == nullptr);
}

// Complejidad O(1)
template <class T>
void QueueLinkedList<T>::enqueue(T value) {
  // 1. crear nuevo nodo
  QueueNode<T> *newNode = new QueueNode<T>(value);
  // La lista esta vacia
  if (front == nullptr && rear == nullptr) {
      front = newNode;
      rear = newNode;
  }
  else {
      // 2. apuntar rear->next a newNode
      rear->next = newNode;
      // 3. actualizar rear para apuntar a newNode
      rear = newNode;
  }
  numElements++;
}

// Complejidad O(1)
template <class T>
void QueueLinkedList<T>::dequeue() {
    // La lista esta vacia
  if (front == nullptr && rear == nullptr) {
    throw std::out_of_range("La lista esta vacia");
  } 
  else {
    QueueNode<T> *p = front;
    // si la lista contiene un solo nodo
    if (p != nullptr && p->next == nullptr) {
      front = nullptr;
      rear = nullptr;
    }
    else
      front = p->next;
    delete p;
    p = nullptr;
    numElements--;
  }
}

// Complejidad O(1)
template <class T>
T QueueLinkedList<T>::getFront() {
  if (front == nullptr && rear == nullptr) {
    throw std::out_of_range("La lista esta vacia");
  } 
  else
    return front->data;
}

// Complejidad O(1)
template <class T>
T QueueLinkedList<T>::getRear() {
  if (front == nullptr && rear == nullptr) {
    throw std::out_of_range("La lista esta vacia");
  } 
  else
    return rear->data;
}

#endif  // _QUEUELINKEDLIST_H_