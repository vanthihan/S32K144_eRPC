/*
 * Caculator.h
 *
 *  Created on: Aug 26, 2023
 *      Author: sai
 */

#ifndef CACULATOR_H_
#define CACULATOR_H_

namespace erpc_server {

class Caculator {
public:
	Caculator();
	virtual ~Caculator();

	int add(int num_1, int num_2);
	int subtract(int num_1, int num_2);

	void setCounterValue(int value);
	int getCounterValue();

private:
	int m_counter{0x00};
};

} /* namespace erpc_server */

#endif /* CACULATOR_H_ */
