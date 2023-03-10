#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

int sum(int n);
bool prime(int n);
int findPrime(int n);
int* fibo(int n);
int findFibo(int n);
int findIndexLastMax(int* arr, int size);
int findIndexLastMin(int* arr, int size);
int findIndexFirstMax(int* arr, int size);
int findIndexFirstMin(int* arr, int size);
bool checkMoutain(int* arr, int size);
int findIndexSecondMax(int*arr, int size);

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__