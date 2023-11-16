#include <iostream>
#include <chrono>
#include <vector>

void bubbleSort(vector <int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
    {
        if (a[j] > a[j+1])
        {
            int temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }
}

void insertionSort(vector <int> &a)
{
    int n = a.size();
    for (int i = 1;; i < n; i++)
    {
        int j, key = a[i];
        for (j = i; j > 0 && a[j - 1] > key; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = key;
    }
}

int main()
{

	int size = 200;
	std::cout << "For N = " << size << std::endl;
	int array[size];
	for(int i = 0; i < size ; i++)
	{

		array[i] = rand() % size;
	}
	//Starting and Ending Time of the Naive Algorithm using high_resolution_clock class from chrono library
	const auto startNaive = std::chrono::high_resolution_clock::now();
	naiveFunction(array, size);
	const auto endNaive = std::chrono::high_resolution_clock::now();
	//Calculating the Elapsed Time using duration class from chrono and converting the time into milliseconds
	std::chrono::duration<double, std::milli> naiveElapsed = endNaive - startNaive;
	std::cout << "Naive Function Elapsed Time: " << naiveElapsed.count() << " ms" << std::endl;
	const auto startImproved = std::chrono::high_resolution_clock::now();
	improvedFunction(array, size);
	const auto endImproved = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> improvedElapsed = endImproved - startImproved;
	std::cout << "Imrpoved Algorithm Elapsed Time: " << improvedElapsed.count() << " ms" << std::endl;
	const auto startBinary = std::chrono::high_resolution_clock::now();
	int binaryResult = divideAndRule(array, 0, size - 1);
	const auto endBinary = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> binaryElapsed = endBinary - startBinary;
	 std::cout << "Maximum Subsequent Sum for the given data by Divide and Conquer Algorithm: " << binaryResult << std::endl;
	std::cout << "Divide and Conquer Elapsed Time: " << binaryElapsed.count() << " ms" << std::endl;

	return 0;
}

