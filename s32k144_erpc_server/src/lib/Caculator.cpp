/*
 * Caculator.cpp
 *
 *  Created on: Aug 26, 2023
 *      Author: sai
 */

#include "Caculator.h"

namespace erpc_server {

Caculator::Caculator() {
	// TODO Auto-generated constructor stub

}

Caculator::~Caculator() {
	// TODO Auto-generated destructor stub
}

int Caculator::add(int num_1, int num_2){
	return num_1 + num_2;
}

int Caculator::subtract(int num_1, int num_2){
	return num_1 - num_2;
}

void Caculator::setCounterValue(int value){
	m_counter = value;
}

int Caculator::getCounterValue(){
	return m_counter;
}

} /* namespace erpc_server */
