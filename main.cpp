#include <iostream>
#include <chrono>
#include <random>
using namespace std;

const int Max_Array_Size = 1000000;
//Array are declared in global scope so that
//large datasets can be tested without stack limiting it
int arrayBubble[Max_Array_Size];
int arrayInsert[Max_Array_Size];
int arrayMerge[Max_Array_Size];
int arrayQuick[Max_Array_Size];
 

template<class dataType>
//Bubble Sort Implementation
void bubbleSort(dataType array[], int size){
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - i - 1; j++){
			if(array[j] > array[j + 1])
			{
				dataType temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

template<class dataType>
//Bubble Sort Implementation
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

//Merge Function for Merge Sort

template <class dataType>
void merge(dataType array[], int left, int mid, int right){
  int leftArraySize = mid - left + 1;
  int rightArraySize = right - mid;

  dataType* leftArray = new dataType[leftArraySize];
  dataType* rightArray = new dataType[rightArraySize];
  
  //Populating the newly created arrays
  int i, j, k;

  for(i = 0; i < leftArraySize; i++)
    leftArray[i] = array[left + i];
  for(j = 0; j < rightArraySize; j++)
    rightArray[j] = array[mid + 1 + j];

  //comparing the values in the arrays
  i = 0;
  j = 0;
  k = left;

  while (i < leftArraySize || j < rightArraySize) {
    if (j >= rightArraySize || (i < leftArraySize && leftArray[i] <= rightArray[j])) {
      array[k] = leftArray[i];
      i++;
    }
    else {
    array[k] = rightArray[j];
    j++;
    }
    k++;
  }
  delete[] leftArray;
  delete[] rightArray;
}//end merge
 
//Merge Sort Function
template<class dataType>
void mergeSort(dataType array[], int left,int right){
  if (left <right) {
    int mid = left + (right - left)/2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
  }
}//end mergeSort

//QuickSort Algorithm Function
template<class dataType>
void swap(dataType array[], int first, int second){
  dataType temp;
  temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}
template<class dataType>
int partition(dataType array[], int first, int last){
  dataType pivot;

  int index, smallIndex;
  swap(array, first, (first + last)/2);

  pivot = array[first];

  smallIndex = first;

  for (index = first + 1; index <= last; index++) {
    if (array[index] < pivot) {
      smallIndex++;
      swap(array, smallIndex, index);
    }
  
  }
  swap(array, first, smallIndex);
  return smallIndex;

}
template<class dataType>

void quickSort(dataType array[], int first, int last){
  int pivot;
  if (first < last) {
    pivot = partition(array, first, last);
    quickSort(array, first, pivot - 1);
    quickSort(array, pivot + 1, last);
  }
}


//Driver Function of the Program
int main(void){
  cout << "For N = " << Max_Array_Size << endl;
  /********************************************************************************
   * Random Numbers Generation
   * Using the rand() function random numbers are generated
   * Although we get the numbers but these numbers are 'Pseudo Random Numbers'
   * In this implementation, these psuedo random numbers will be useful for getting
   * multiple times for each algorithm using the same numbers generated.
   * *****************************************************************************/

    for(int i = 0; i < Max_Array_Size; i++){
    arrayBubble[i] = rand() % 100001;
    arrayInsert[i] = arrayBubble[i];
    arrayMerge[i] = arrayBubble[i];
    arrayQuick[i] = arrayBubble[i];
//    cout << "Random Number: " << array[i] << endl;
  }

  const auto startBubble = std::chrono::high_resolution_clock::now();
  bubbleSort(arrayBubble, Max_Array_Size);
  const auto endBubble = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedBubble = endBubble - startBubble;
  cout << "Elapsed bubbleSort Time: \t" << elapsedBubble.count() << " ms" << endl;


  /**********************************************************
  * Insertion sort Algorithm Implementation
  * Using the Chrono Library the time of the Algorithm is calculated and 
  * will be compared with the other algorithms to find the O(N)
  * **********************************************************/
  
  const auto startInsertion = std::chrono::high_resolution_clock::now();
  insertionSort(arrayInsert, Max_Array_Size);
  const auto endInsertion = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedInsertion = endInsertion - startInsertion;
  cout << "Elapsed insertionSort Time: \t" << elapsedInsertion.count() << " ms" << endl;

 /*
  * Merge sort Algorithm Implementation
  * Merge uses the divide and conquer approach 
  * It divides the array into two halves
  * then sort the two halves and after sorting the halves
  * are merged together by calling the merge() function.
  * It is a pretty fast algorithm and it has the time complexity of
  * O(NlogN)
  */
  const auto startMerge = std::chrono::high_resolution_clock::now();
  mergeSort(arrayMerge, 0, Max_Array_Size - 1);
  const auto endMerge = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedMerge = endMerge - startMerge;
  cout << "Elapsed mergeSort Time: \t" << elapsedMerge.count() << " ms" << endl;
  
  /*
   * Quick sort Algorithm Implementation
   *
   *
   */
  const auto startQuick = std::chrono::high_resolution_clock::now();
  quickSort(arrayQuick, 0, Max_Array_Size - 1);
  const auto endQuick = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedQuick = endQuick - startQuick;
  cout << "Elapsed quickSort Time: \t" << elapsedQuick.count() << " ms" << endl;


  return 0;
}//end main
