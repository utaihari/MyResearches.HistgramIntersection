/*
 * HistgramMap.h
 *
 *  Created on: 2016/01/21
 *      Author: uchinosub
 */

#ifndef HISTGRAMMAP_H_
#define HISTGRAMMAP_H_
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
namespace histgram_map {

/**
 * @note <出力文字,頻度>
 */
class HistgramMap: public std::map<int, int> {
public:
	HistgramMap();
	HistgramMap(std::string path):max(0){
		std::ifstream ifs;
		ifs.open(path.c_str(),std::ios::in);
		while(!ifs.eof()){
			std::string data;
			std::string frequency;
			ifs >> data;
			ifs >> frequency;

			int d = std::atoi(data.c_str());
			int f = std::atoi(frequency.c_str());
			if(d > max){
				max = d;
			}
			this->insert(std::make_pair(d,f));
		}
	}
	virtual ~HistgramMap();
	int& operator[](int value) {
		auto result = this->find(value);
		if (result == this->end()) {
			//textが登録されていない時の処理
			this->insert(std::make_pair(value, 0));
			result = this->find(value);
		}
		return result->second;
	}
	int max;
};

}
/* namespace histgram_map */

#endif /* HISTGRAMMAP_H_ */
