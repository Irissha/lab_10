#include <iostream>
#include <ctime>
using namespace std;
bool check(int, int);
void print(int*, int&);
int main()
{
	locale::global(locale(""));
	srand(unsigned(time(NULL)));
	int size = rand() % 5 + 3;
	int* a = NULL, * t = NULL;
	a = new int[size];
	for (int n = 0; n < size; n++) a[n] = rand() % 90 + 10;
	print(a, size);
	int del;
	cout << endl << " Введите индекс удаляемого элемента: ";
	cin >> del;
	bool flag;
	flag = check(del, size);
	if (flag)
	{
		t = new int[size];
		for (int n = 0; n < size; n++) t[n] = a[n];
		int newsize = size - 1;
		delete[] a;
		a = new int[newsize];
		for (int n = 0, m = 0; n < size; n++, m++)
		{
			if (n == del)
			{
				--m;
				continue;
			}
			a[m] = t[n];
		}
		delete[] t;
		size = newsize;
		print(a, size);
	}
	int ins;
	cout << endl << " Введите индекс вставляемого элемента: ";
	cin >> ins;
	flag = check(ins, size + 1);
	if (flag)
	{
		int num;
		cout << endl << " Введите значение элемента: ";
		cin >> num;
		t = new int[size];
		for (int n = 0; n < size; n++) t[n] = a[n];
		int newsize = size + 1;
		bool yes = true;
		delete[] a;
		a = new int[newsize];
		for (int n = 0, m = 0; n < newsize; n++, m++)
		{
			if (n == ins && yes)
			{
				a[n] = num;
				--n;
				yes = false;
				continue;
			}
			a[m] = t[n];
		}
		delete[] t;
		size = newsize;
		print(a, size);
	}
	delete[] a;
	cin.get(); cin.get();
	return 0;
}
bool check(int index, int size)
{
	if (index < 0 || index >= size)
	{
		cout << endl;
		if (index >= 0) cout << "\a Элемента с заданным индеком в массиве не существует! ";
		else cout << "\a Индекс не может быть отрицательным! ";
		cout << endl;
		return false;
	}
	return true;
}
void print(int* p, int& sz)
{
	cout << endl;
	for (int n = 0; n < sz; n++) cout << ' ' << p[n];
	cout << endl;
}