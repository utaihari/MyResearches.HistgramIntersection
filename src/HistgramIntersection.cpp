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

double HistgramIntersection(vector<pair<int, int>> A, vector<pair<int, int>> B){
  auto Aiter = A.begin();
  auto Biter = B.begin();

  double Asize = 0;
  double Bsize = 0;

  bool Afinished = false;
  bool Bfinished = false;

  double H = 0;

  while (!(Afinished && Bfinished)){
    if (Aiter->first == Biter->first){
      H += Aiter->second < Biter->second ? Aiter->second : Biter->second;

      if (!Bfinished){
        Bsize += Biter->second;
        Biter++;
        if (Biter == B.end()){
          Bfinished = true;
          Biter--;
        }
      }
      if (!Afinished){
        Asize += Aiter->second;
        Aiter++;
        if (Aiter == A.end()){
          Afinished = true;
          Aiter--;
        }
      }
    }
    else if (!Bfinished && (Afinished || (Aiter->first > Biter->first))){
      if (!Bfinished){
        Bsize += Biter->second;
        Biter++;
        if (Biter == B.end()){
          Bfinished = true;
          Biter--;
        }
      }
    }
    else{
      if (!Afinished){
        Asize += Aiter->second;
        Aiter++;
        if (Aiter == A.end()){
          Afinished = true;
          Aiter--;
        }
      }
    }

  }

  H = H / (Asize < Bsize ? Asize : Bsize);
  return H;
}
void ReadData(vector<pair<int,int>> &Histgram,string path){
	std::ifstream ifs;
	ifs.open(path.c_str(),std::ios::in);
	while(!ifs.eof()){
		std::string data;
		std::string frequency;
		ifs >> data;
		ifs >> frequency;

		int d = std::atoi(data.c_str());
		int f = std::atoi(frequency.c_str());
		Histgram.push_back(std::make_pair(d,f));
	}
}

int main() {
	vector<pair<int,int>> fileA;
	vector<pair<int,int>> fileB;
	vector<pair<int,int>> fileC;

	ReadData(fileA,"data/A.txt");
	ReadData(fileB,"data/B.txt");
	ReadData(fileC,"data/C.txt");

	double AB;
	AB = HistgramIntersection(fileA,fileB);
	double AC;
	AC = HistgramIntersection(fileA,fileC);
	cout << "AB:" << AB <<endl;
	cout << "AC:" << AC <<endl;

	return 0;
}
