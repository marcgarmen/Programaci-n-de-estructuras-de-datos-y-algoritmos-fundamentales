#ifndef _ALGORITHM_SORT_H_
#define _ALGORITHM_SORT_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

template <class T>
class AlgorithmSort {
  private:
    // semilla del generador de numeros aleatorios (time-based)
    unsigned seed; 
    // generador de numeros aleatorios (Mersenne Twister 64 bits)
    std::mt19937_64 gen;

    void merge(std::vector<T> &A, int low, int m, int high, unsigned int &compara);
    int partition(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap);
    void heapify(std::vector<T> &A, int n, int i, unsigned int &compara, unsigned int &swap);

  public:
    AlgorithmSort();
    ~AlgorithmSort();
    void randomShuffle(std::vector<T> &A);
    void printVector(std::vector<T> A);

    void swapSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap);
    void selectionSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap);
    void bubbleSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap);
    void insertionSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap);
    void mergeSort(std::vector<T> &A, int low, int high, unsigned int &compara);
    void quickSort(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap);
    void heapSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap);

};


template<class T>
AlgorithmSort<T>::AlgorithmSort() {
  // semilla del generador de numeros aleatorios (time-based)
  seed = std::chrono::system_clock::now().time_since_epoch().count();
  // generador de numeros aleatorios (Mersenne Twister 64 bits)
  std::mt19937_64 gen;
  // inicializar el generador con la semilla creada
  gen.seed(seed);
}

template<class T>
AlgorithmSort<T>::~AlgorithmSort() {

}

// Mezcla los elementos del vector en forma aleatoria
template<class T>
void AlgorithmSort<T>::randomShuffle(std::vector<T> &A) {
  std::shuffle(A.begin(), A.end(), gen);
}

// Imprime en pantalla los elementos del vector
template<class T>
void AlgorithmSort<T>::printVector(std::vector<T> A) {
    std::cout << "Los elementos del vector ordenado son: " << std::endl;
    for(int i = 0; i < (int)A.size(); i++) {
      std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// O(n^2)
template<class T>
void AlgorithmSort<T>::swapSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = i + 1; j < n; j++) {
      compara++;
      if (A[i] > A[j]) {
        std::swap(A[i], A[j]);
        swap++;
      }
    }
  }
}

// O(n^2)
template<class T>
void AlgorithmSort<T>::selectionSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 0; i < n-1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      compara++;
      if (A[j] < A[minIndex])
        minIndex = j;
    }

    std::swap(A[minIndex], A[i]);
    swap++;
  }
}

// O(n^2)
template<class T>
void AlgorithmSort<T>::bubbleSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      compara++;
      if (A[j] > A[j+1]) {
        std::swap(A[j], A[j+1]);
        swap++;
      }
    }
  }
}

// O(n^2)
template<class T>
void AlgorithmSort<T>::insertionSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 1; i < n; i++) {
    T key = A[i]; // // ERROR CORREGIDO tipo T
    int j = i - 1;
    compara++;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
      compara++;
      swap++;
    }
    A[j+1] = key;
  }
}

template<class T>
void AlgorithmSort<T>::merge(std::vector<T> &A, int low, int m, int high, unsigned int &compara) {
  int i, j, k;
  // Calcular el tamaño de los vectores L y R
  int n1 = m - low + 1;
  int n2 = high - m;
  // Crear los vectores auxiliares L y R
  std::vector<T> L(n1);
  std::vector<T> R(n2);
  for (i = 0; i < n1; i++) L[i] = A[low + i];
  for (j = 0; j < n2; j++) R[j] = A[m + 1 + j];
  // Mezclar los vectores L y R de forma ordenada
  i = j = 0;
  k = low;
  while (i < n1 && j < n2) {
    compara++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    k++;
  }
  // Copia los elementos restantes de L y R
  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

template<class T>
void AlgorithmSort<T>::mergeSort(std::vector<T> &A, int low, int high, unsigned int &compara) {
  if (low < high) {
    // encontrar el punto medio
    int m = low + (high - low) / 2;
    // Dividir el problema en mitades
    mergeSort(A, low, m, compara);
    mergeSort(A, m+1, high, compara);
    // Mezcla de ambas mitades
    merge(A, low, m, high, compara);
  }
}

template<class T>
int AlgorithmSort<T>::partition(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap) {
  T pivot = A[high];
  int i = low - 1;
  for (int j = low; j <= high; j++) { // ERROR CORREGIDO j <= high
    compara++;
    if (A[j] < pivot) {
      i++;
      std::swap(A[i], A[j]);
      swap++;
    }
  }
  std::swap(A[i+1], A[high]);
  swap++;
  return i + 1;  
}

template<class T>
void AlgorithmSort<T>::quickSort(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap) {
  if (low < high) {
    // encontrar la particion del vector
    int pi = partition(A, low, high, compara, swap);
    // ordenar la particion izquierda y derecha
    quickSort(A, low, pi - 1, compara, swap);
    quickSort(A, pi + 1, high, compara, swap);
  }
}

template<class T>
void AlgorithmSort<T>::heapify(std::vector<T> &A, int n, int k, unsigned int &compara, unsigned int &swap) {
  // elemento mas grande
  int largest = k;
  // hijo izquierdo
  int left = 2*k + 1;
  // hijo derecho
  int right = 2*k + 2;
  // Si el hijo izquierdo es mas grande que la raiz
  if (left < n && A[left] > A[largest])
    largest = left;
  // Si el hijo derecho es mas grande que la raiz
  if (right < n && A[right] > A[largest])
    largest = right;
  compara+=2;
  // Si el mas grande no es la raiz
  if (largest != k) {
    std::swap(A[k], A[largest]);
    swap++;
    // Recursivamente se llama a reacomodo hacia abajo
    heapify(A, n, largest, compara, swap);
  }
}

template<class T>
void AlgorithmSort<T>::heapSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  // 1. Construir el Heap a partir de la lista 
  for (int i = n/2-1; i >= 0; i--) {
    heapify(A, n, i, compara, swap);
  }
  // 2. Extraer elemento por elemento del heap
  for (int i = n-1; i > 0; i--) {
    // intercambiar raiz con la ultima hoja
    std::swap(A[0], A[i]);
    swap++;
    heapify(A, i, 0, compara, swap);
  }
}


#endif   // _ALGORITHM_SORT_H_
