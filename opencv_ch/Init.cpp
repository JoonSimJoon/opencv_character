#include "Init.h"


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 20); //1num = 5%

int tmp[64][64] = { 0, };
int dx[10] = { 1,1,1,0,0,0,-1,-1,-1, };
int dy[10] = { 1,0,-1,1,0,-1,1,0,-1, };


void Init_Map(int arr[][64], int size) {
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 64; i += 8) {
		Create_Random_noize(arr, 4, i / 2, 60 - i, 1);
	}
	for (int i = 0; i < 10; i++) {
		if(Cellular_Automata(arr, size)==1) break;
	}
	
	//Create_Random_noize(arr, 4, 0, 70, 1);
	//Create_Random_noize(arr, 4, 4, 60, 2);
}

void Create_Random_noize(int arr[][64], int length, int start, int rate, int color) {
	for (int i = start; i < 64 - start-length; i++) {
		for (int j = 0; j < length; j++) {
			if (dis(gen) * 5 <= rate) arr[i][j + start] = color;
			if (dis(gen) * 5 <= rate) arr[j + start][i + length] = color;
			if (dis(gen) * 5 <= rate) arr[63 - j - start][i] = color;
			if (dis(gen) * 5 <= rate) arr[i + length][63 - j - start] = color;
		}
	}
}

int Cellular_Automata(int arr[][64],int size){
	int cnt = 9;
	int space = 0;
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cnt = 9;
			space = 0;
			for (int k = 0; k < 9; k++) {
				if (i + dx[k] < 0 || i + dx[k] > size - 1 || j + dy[k] < 0 || j + dy[k] > size - 1) {
					cnt--;
				}
				else if (arr[i+dx[k]][j+dy[k]] == 1) space++;
			}
			//std::cout << cnt << " " << space << std::endl;

			if (cnt / 2 < space) tmp[i][j] = 1;
			//else tmp[i][j] = 0;

			/*if (cnt%2==0 && space == cnt / 2) tmp[i][j] = arr[i][j];
			if (space == cnt / 2) {
				if (dis(gen) >= 10) tmp[i][j] = 1;
				else tmp[i][j] = 0;
			}
			else if (space > cnt / 2) {
				tmp[i][j] = 1;
			}
			else tmp[i][j] = 0;*/
			
		}
	}
	int xcnt = 0;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			if (arr[i][j] != tmp[i][j]) xcnt++;
			arr[i][j] = tmp[i][j];
		}
	}
	if (xcnt < 64 ) return 1;
	else return 0;
}
