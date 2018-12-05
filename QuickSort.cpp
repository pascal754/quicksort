/*
  Quick Sort Algorithm
  November 10, 2018
  by SM

========================================
Hoare partition scheme
----------------------------------------

algorithm quicksort(A, lo, hi) is
	if lo < hi then
		p := partition(A, lo, hi)
		quicksort(A, lo, p)
		quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
	pivot := A[lo]
	i := lo - 1
	j := hi + 1
	loop forever
		do
			i := i + 1
		while A[i] < pivot

		do
			j := j - 1
		while A[j] > pivot

		if i >= j then
			return j

		swap A[i] with A[j]
========================================
*/

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

template <typename T>
int partition(vector<T>& vi, int low, int high)
{
	T pivot = vi[low];
	int i = low - 1;
	int j = high + 1;
	T temp{ 0 };
	for (;;) {
		do {
			++i;
		} while (vi[i] < pivot);

		do {
			--j;
		} while (vi[j] > pivot);

		if (i >= j) {
			return j;
		}

		temp = vi[i];
		vi[i] = vi[j];
		vi[j] = temp;
	}
}

template <typename T>
void QuickSort(vector<T>& vi, int low, int high)
{
	if (low < high) {
		int p = partition(vi, low, high);
		QuickSort(vi, low, p);
		QuickSort(vi, p + 1, high);
	}
}




int main() {

	vector<int> va{ 3, 7, 8, 5, 2, 1, 9, 5, 4 };

	for (int& x : va) {
		cout << x << ' ';
	}
	cout << endl;

	QuickSort(va, 0, va.size() - 1);

	for (int& x : va) {
		cout << x << ' ';
	}
	cout << endl;

	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100); // distribution in range [1, 100]

	for (int i = 1; i <= 100; ++i) {
		va.push_back(dist6(rng));
	}
	
	for (int& x : va) {
		cout << x << ' ';
	}
	cout << endl;

	auto start = std::chrono::system_clock::now();
	QuickSort(va, 0, va.size() - 1);
	auto end = std::chrono::system_clock::now();



	cout << endl;

	for (int& x : va) {
		cout << x << ' ';
	}
	cout << endl;

	std::chrono::duration<double> elapsed_seconds = end - start;
	//std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	return 0;
}
