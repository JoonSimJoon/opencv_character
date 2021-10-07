#include "Init.h"


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 20); //1num = 5%

void Init_Map(int arr[][64], int size) {
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			arr[i][j] = 0;
		}
	}
	Create_Random_noize(arr, 4, 0, 70, 1);
	Create_Random_noize(arr, 4, 4, 60, 2);
}

void Create_Random_noize(int arr[][64], int length, int start, int rate, int color) {
	for (int i = start; i < 64 - start-length; i++) {
		for (int j = 0; j < length; j++) {
			arr[i][j + start] = color;
			arr[j + start][i + length] = color;
			arr[63 - j - start][i] = color;
			arr[i + length][63 - j - start] = color;
		}
	}
}
