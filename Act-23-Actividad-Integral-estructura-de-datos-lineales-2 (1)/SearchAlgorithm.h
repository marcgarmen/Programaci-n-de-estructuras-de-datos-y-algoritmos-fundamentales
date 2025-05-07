#ifndef _SEARCH_ALGORITHM_H_
#define _SEARCH_ALGORITHM_H_

#include <iostream>
#include <vector>

template <class T>
class SearchAlgorithm {
  public:
    SearchAlgorithm();
    ~SearchAlgorithm();
    int busquedaSecuencial(std::vector<T> &A, T key, int &compara);
    int busquedaSecuencialVectorOrdenado(std::vector<T> &A, T key, int &compara);
    int busquedaBinaria(std::vector<T> &A, T key, int &compara);
    int busquedaBinariaRecursiva(std::vector<T> &A, int low, int high, T key, int &compara);

};

template <class T>
SearchAlgorithm<T>::SearchAlgorithm() {

}

template <class T>
SearchAlgorithm<T>::~SearchAlgorithm() {

}

// O(n)
template <class T>
int SearchAlgorithm<T>::busquedaSecuencial(std::vector<T> &A, T key, int &compara) {
  compara = 0;
  int i = 0;
  while (i < A.size() && A[i] != key) {
    compara++;
    i++;
  }
  if (i < A.size())
    return i;
  else
    return -1;
}

// O(n)
template <class T>
int SearchAlgorithm<T>::busquedaSecuencialVectorOrdenado(std::vector<T> &A, T key, int &compara) {
  compara = 0;
  for (int i = 0; i < A.size(); i++) {
    compara++;
    if (key <= A[i]) {
      compara++;
      if (key == A[i])
        return i;
      else
        return -1;
    }
  }
  return -1;
}

// O(log n)
template <class T>
int SearchAlgorithm<T>::busquedaBinaria(std::vector<T> &A, T key, int &compara) {
  int l = 0;
  int r = A.size() - 1;
  compara = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    compara++;
    if (key == A[m])
      return m;
    else if (key < A[m]) 
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

// O(log n)
template <class T>
int SearchAlgorithm<T>::busquedaBinariaRecursiva(std::vector<T> &A, int low, int high, T key, int &compara) {
  if (low > high)
    return -1;
  int m = low + (high - low) / 2;
  compara++;
  if (key == A[m]) 
    return m;
  else if (key < A[m])
    return busquedaBinariaRecursiva(A, low, m-1, key, compara);
  else 
    return busquedaBinariaRecursiva(A, m+1, high, key, compara);
}
#endif  // _SEARCH_ALGORITHM_H_
