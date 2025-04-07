#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void)
{
	srand(time(NULL));
	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = (rand() % 52) + 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) i--;
		}
		cout << arr[i] << "\n";
	}

	return 0;
}