#ifndef ACTIVATION_H
#define ACTIVATION_H

#define CONST_PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127324587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609
#define CONST_E 2.718281828459

#include <stdexcept>
#include <cmath>


#define act_sigmoid 1
#define act_threshact 2
#define act_gauss 3
#define act_ramp 7
#define act_binarystep 8
#define act_identity 9

namespace ML {
	int activation (double input, unsigned int function_id) {
		if (function_id > 9 || function_id < 1) {throw std::invalid_argument ("Activation-function not known!");} //if the activation function doesnt exist
		
		int output = 0;
		
		if (function_id == act_identity) {output = input;} //the identity function
		
		if (function_id == act_threshact) { //the threshold-activation function
			if (input < 0) {
				output = -1;
			} else {
				output = 1;
			}
		}
		
		if (function_id == act_ramp) { //the ramp function
			output = 0;
			if (input > 0) {
				output = input;
			}
		}
		
		if (function_id == act_binarystep) { //everything below 0 is 0, else its a normal identity
			output = 0;
			if (input > 0) {
				output = 1;
			}				
		}
		
		if (function_id == act_gauss) {
			output = pow(CONST_E, - 1 / 2 * pow (input, 2));
		}
		
		if (function_id == act_sigmoid) {
			output = 1 / 1 + pow (CONST_E, - input); 
		}

		return output;

	}

}

#endif