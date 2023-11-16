#include <iostream>
#include <chrono>
#include <random>
using namespace std;

template<class dataType>

//Insertion Sort Function
void insertionSort(dataType array[], int size){
  for(int i = 1; i < size; i++){
    dataType key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}//end insertionSort


//Driver Function of the Program
int main(void){
  int size = 300;

  /********************************************************************************
   * Random Numbers Generation
   * Using the rand() function random numbers are generated
   * Although we get the numbers but these numbers are 'Pseudo Random Numbers'
   * In this implementation, these psuedo random numbers will be useful for getting
   * multiple times for each algorithm using the same numbers generated.
   * *****************************************************************************/

  int array[size];
  for(int i = 0; i < size; i++){
    array[i] = rand() % 10000;
    cout << "Random Number: " << array[i] << endl;
  }

  /**********************************************************
  * Insertion sort Algorithm Implementation
  * Using the Chrono Library the time of the Algorithm is calculated and 
  * will be compared with the other algorithms to find the O(N)
  * **********************************************************/
  
  const auto startInsertion = std::chrono::high_resolution_clock::now();
  insertionSort(array, size);
  const auto endInsertion = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedInsertion = endInsertion - startInsertion;
  cout << "Elapsed insertionSort Time" << elapsedInsertion.count() << " ms" << endl;


  return 0;
}//end main

