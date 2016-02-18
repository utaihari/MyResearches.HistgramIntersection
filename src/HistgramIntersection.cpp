//============================================================================
// Name        : HistgramIntersection.cpp
// Author      : uchino
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "HistgramMap.h"
using namespace std;

double HistgramIntersection(vector<pair<int, int>> A,
		vector<pair<int, int>> B) {
	auto Aiter = A.begin();
	auto Biter = B.begin();

	double Asize = 0;
	double Bsize = 0;

	bool Afinished = false;
	bool Bfinished = false;

	double H = 0;

	while (!(Afinished && Bfinished)) {
		//Aのデータ番号とBのデータ番号が同じだったら頻度が小さい方を足す
		if (Aiter->first == Biter->first) {
			//小さい方の頻度を足す
			H += Aiter->second < Biter->second ? Aiter->second : Biter->second;
			if (!Bfinished) {
				Bsize += Biter->second;
				if (Biter == B.end() - 1) {
					Bfinished = true;
				} else {
					Biter++;
				}
			}
			if (!Afinished) {
				Asize += Aiter->second;
				if (Aiter == A.end() - 1) {
					Afinished = true;
				} else {
					Aiter++;
				}
			}
		} //Bのデータ番号のほうが小さければ、Bを進める
		else if (Aiter->first > Biter->first) {
			if (Bfinished) {
				//Bが終わっていたらAを進める
				Asize += Aiter->second;
				if (Aiter == A.end() - 1) {
					Afinished = true;
				} else {
					Aiter++;
				}
			} else {
				Bsize += Biter->second;
				if (Biter == B.end() - 1) {
					Bfinished = true;
				} else {
					Biter++;
				}
				Bsize += Biter->second;
			}
		} //Aのデータ番号のほうが小さければ、Aを進める
		else {
			if (Afinished) {
				Bsize += Biter->second;
				if (Biter == B.end() - 1) {
					Bfinished = true;
				} else {
					Biter++;
				}
			} else {
				Asize += Aiter->second;
				if (Aiter == A.end() - 1) {
					Afinished = true;
				} else {
					Aiter++;
				}
			}
		}
	}
	//AsizeとBsizeの小さい方で割る
	H = H / (Asize < Bsize ? Asize : Bsize);
	return H;
}
void ReadData(vector<pair<int, int>> &Histgram, string path) {
	std::ifstream ifs;
	ifs.open(path.c_str(), std::ios::in);
	while (!ifs.eof()) {
		std::string data;
		std::string frequency;
		ifs >> data;
		ifs >> frequency;

		int d = std::atoi(data.c_str());
		int f = std::atoi(frequency.c_str());
		Histgram.push_back(std::make_pair(d, f));
	}
}

int main() {
//	vector<pair<int, int>> fileA;
//	vector<pair<int, int>> fileB;
//	vector<pair<int, int>> fileC;
//
//	ReadData(fileA, "data/A.txt");
//	ReadData(fileB, "data/B.txt");
//	ReadData(fileC, "data/C.txt");
//
//	double AB;
//	AB = HistgramIntersection(fileA, fileB);
//	double AC;
//	AC = HistgramIntersection(fileA, fileC);
//	cout << "AB:" << AB << endl;
//	cout << "AC:" << AC << endl;

	vector<pair<int, int>> A;
	vector<pair<int, int>> B;

	int Adata[][2] = { { 1, 1 }, { 2, 1 }, { 3, 2 }, { 4, 1 }, { 7, 2 } };
	int Bdata[][2] = { { 1, 2 }, { 3, 1 }, { 6, 1 } };

	for (auto data : Adata) {
		A.push_back(make_pair(data[0], data[1]));
	}
	for (auto data : Bdata) {
		B.push_back(make_pair(data[0], data[1]));
	}

	double H = HistgramIntersection(A, B);
	cout << H << endl;
	return 0;
}
