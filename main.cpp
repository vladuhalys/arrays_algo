#include <iostream>
#include <ctime>
using namespace std;


template <typename T>
T* create_array(size_t size)
{
    return new T[size];
}

template <typename T>
bool fill_array(T* array, size_t size)
{
    if (array == nullptr)
    {
		return false;
	}
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
	return true;
}

template <typename T>
void print_array(T* array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template <typename T>
bool push_back(T*& array, size_t& size, T value)
{
	T* new_array = create_array<T>(size + 1);
	if (new_array == nullptr)
	{
		return false;
	}
	for (size_t i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}
	new_array[size] = value;
	delete[] array;
	array = new_array;
	size++;
	return true;
}

template <typename T>
bool push_front(T*& array, size_t& size, T value)
{
	T* new_array = create_array<T>(size + 1);
	if (new_array == nullptr)
	{
		return false;
	}
	new_array[0] = value;
	for (size_t i = 0; i < size; i++)
	{
		new_array[i + 1] = array[i];
	}
	delete[] array;
	array = new_array;
	size++;
	return true;
}

template <typename T>
bool insert(T*& array, size_t& size, T value, size_t index)
{
	if (index > size)
	{
		return false;
	}
	T* new_array = create_array<T>(size + 1);
	if (new_array == nullptr)
	{
		return false;
	}
	for (size_t i = 0; i < index; i++)
	{
		new_array[i] = array[i];
	}
	new_array[index] = value;
	for (size_t i = index; i < size; i++)
	{
		new_array[i + 1] = array[i];
	}
	delete[] array;
	array = new_array;
	size++;
	return true;
}

template <typename T>
T pop_back(T*& array, size_t& size)
{
	if (size == 0)
	{
		return T();
	}
	T value = array[size - 1];
	T* new_array = create_array<T>(size - 1);
	if (new_array == nullptr)
	{
		return T();
	}
	for (size_t i = 0; i < size - 1; i++)
	{
		new_array[i] = array[i];
	}
	delete[] array;
	array = new_array;
	size--;
	return value;
}

template <typename T>
T pop_front(T*& array, size_t& size)
{
	if (size == 0)
	{
		return T();
	}
	T value = array[0];
	T* new_array = create_array<T>(size - 1);
	if (new_array == nullptr)
	{
		return T();
	}
	for (size_t i = 1; i < size; i++)
	{
		new_array[i - 1] = array[i];
	}
	delete[] array;
	array = new_array;
	size--;
	return value;
}

template <typename T>
T erase(T*& array, size_t& size, size_t index)
{
	if (index >= size)
	{
		return T();
	}
	T value = array[index];
	T* new_array = create_array<T>(size - 1);
	if (new_array == nullptr)
	{
		return T();
	}
	for (size_t i = 0; i < index; i++)
	{
		new_array[i] = array[i];
	}
	for (size_t i = index + 1; i < size; i++)
	{
		new_array[i - 1] = array[i];
	}
	delete[] array;
	array = new_array;
	size--;
	return value;
}




int main()
{
    srand(time(0));
	size_t size;
	cout << "Enter size of array: ";
	cin >> size;
	int* array = create_array<int>(size);
	int choice;
	do
	{
		system("cls");
		cout << "1. Fill array" << endl;
		cout << "2. Print array" << endl;
		cout << "3. Push back" << endl;
		cout << "4. Push front" << endl;
		cout << "5. Insert" << endl;
		cout << "6. Pop back" << endl;
		cout << "7. Pop front" << endl;
		cout << "8. Erase" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				if (fill_array(array, size))
				{
					cout << "Array filled" << endl;
				}
				else
				{
					cout << "Failed to fill array" << endl;
				}	
			}break;
			case 2:
			{
				print_array(array, size);
			}break;
			case 3:
			{
				int value;
				cout << "Enter value: ";
				cin >> value;
				if (push_back(array, size, value))
				{
					cout << "Value pushed back" << endl;
				}
				else
				{
					cout << "Failed to push back value" << endl;
				}
			}break;
			case 4:
			{
				int value;
				cout << "Enter value: ";
				cin >> value;
				if (push_front(array, size, value))
				{
					cout << "Value pushed front" << endl;
				}
				else
				{
					cout << "Failed to push front value" << endl;
				}
			}break;
			case 5:
			{
				int value;
				size_t index;
				cout << "Enter value: ";
				cin >> value;
				cout << "Enter index: ";
				cin >> index;
				if (insert(array, size, value, index))
				{
					cout << "Value inserted" << endl;
				}
				else
				{
					cout << "Failed to insert value" << endl;
				}
			}break;
			case 6:
			{
				int value = pop_back(array, size);
				if (value != 0)
				{
					cout << "Value popped back: " << value << endl;
				}
				else
				{
					cout << "Failed to pop back value" << endl;
				}
			}break;
			case 7:
			{
				int value = pop_front(array, size);
				if (value != 0)
				{
					cout << "Value popped front: " << value << endl;
				}
				else
				{
					cout << "Failed to pop front value" << endl;
				}
			}break;
			case 8:
			{
				size_t index;
				cout << "Enter index: ";
				cin >> index;
				int value = erase(array, size, index);
				if (value != 0)
				{
					cout << "Value erased: " << value << endl;
				}
				else
				{
					cout << "Failed to erase value" << endl;
				}
			}break;
			case 0:
			{
				delete[] array;
				exit(0);
			}
		}
		system("pause");
	} while (true);

    return 0;
}