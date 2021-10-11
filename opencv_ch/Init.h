#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"
#include <random>
#include <string.h>
#pragma once
using namespace cv;


void Init_Map(int arr[][64], int size);
void Create_Random_noize(int arr[][64], int length, int start, int rate, int color);
int Cellular_Automata(int arr[][64], int size);
void Create_Border(int arr[][64], int size);