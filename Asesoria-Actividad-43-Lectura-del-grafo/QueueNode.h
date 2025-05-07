#ifndef _QUEUENODE_H_
#define _QUEUENODE_H_

template <class T>
class QueueNode {
  private:
    T data;
    QueueNode<T> *next;

  public:
    QueueNode();
    QueueNode(T value);
    // El template QueueLinkedList<U> tiene acceso a los elementos privados de esta clase
    template<typename U> friend class QueueLinkedList;

};

template <class T>
QueueNode<T>::QueueNode() : data{}, next{nullptr} {}

template <class T>
QueueNode<T>::QueueNode(T value) : data{value}, next{nullptr} {}


#endif  // _QUEUENODE_H_