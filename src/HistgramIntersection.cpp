//============================================================================
// Name        : HistgramIntersection.cpp
// Author      : uchino
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HistgramMap.h"
using namespace std;

double HistgramIntersection(histgram_map::HistgramMap& A,histgram_map::HistgramMap& B,int roop){
	double HI = 0.0;
	int sizeA = 0 ,sizeB = 0;
	for(int i = 0 ; i < roop; ++i){
		sizeA += A[i];
		sizeB += B[i];
		int min = A[i] < B[i] ? A[i] : B[i];
		HI += min;
	}
	int min_size = sizeA < sizeB ? sizeA : sizeB;
	HI = HI / min_size;
	return HI;
}

int main() {
	histgram_map::HistgramMap fileA("data/A.txt");
	histgram_map::HistgramMap fileB("data/B.txt");
	histgram_map::HistgramMap fileC("data/C.txt");

	double AB;
	AB = HistgramIntersection(fileA,fileB,50000);
	double AC;
	AC = HistgramIntersection(fileA,fileC,50000);
	cout << "AB:" << AB <<endl;
	cout << "AC:" << AC <<endl;

	return 0;
}
