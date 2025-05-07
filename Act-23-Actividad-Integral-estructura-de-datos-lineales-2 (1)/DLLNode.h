#ifndef _DLLNODE_H_
#define _DLLNODE_H_

template <class T>
class DLLNode {
  private:
    T data;
    DLLNode<T> *next;
    DLLNode<T> *prev;

  public:
    DLLNode();
    DLLNode(T value);
    // El template DLinkedList<U> tiene acceso a los elementos privados de esta clase
    template<typename U> friend class DLinkedList;

};

template <class T>
DLLNode<T>::DLLNode() : data{}, next{nullptr}, prev{nullptr} {}

template <class T>
DLLNode<T>::DLLNode(T value) : data{value}, next{nullptr}, prev{nullptr} {}


#endif  // _DLLNODE_H_