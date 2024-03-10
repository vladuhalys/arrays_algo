#include <iostream>
#include <ctime>
using namespace std;


template <typename T>
T get_size_value(string text)
{
	int size;
	cout << text;
	cin >> size;
	return size;
}

template <typename T>
T get_elem(string text)
{
	return get_size_value<T>(text);
}

template <typename T>
T get_random_elem(T* filter, size_t filter_size)
{
	bool is_valid;
	T rand_value;
	do
	{
		is_valid = true;
		rand_value = rand() % 20 - 10;
		for (size_t j = 0; j < filter_size; j++)
		{
			if (rand_value == filter[j])
			{
				is_valid = false;
				break;
			}
		}
		if (is_valid)
		{
			return rand_value;
		}
	} while (true);
}


template <typename T>
void rand_array(T*&_array, size_t size)
{
	srand(time(0));
	int filter_size = get_size_value<int>("Enter filter_size: ");
	int* filter = new int[filter_size];
	for (size_t i = 0; i < filter_size; i++)
	{
		filter[i] = get_elem<T>("Enter element: ");
	}
	for (size_t i = 0; i < size; i++)
	{
		_array[i] = get_random_elem<T>(filter, filter_size);
	}
}



int main()
{
    srand(time(0));
	int size = get_size_value<int>("Enter size: ");
	int* array = new int[size];

	rand_array(array, size);

	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
    return 0;
}