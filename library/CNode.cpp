#include "CNode.h"
#include "CLayer.h"
#include <iostream>

namespace ML {
	CNeuron::CNeuron (int numberWeights){
		for (int i = 0; i < numberWeights; i++) {
			m_weights.push_back (1.0); //arbitrary starting value - 0.0 is the safest bet.
		}
		m_error = 0.0;
		m_value = 0.0;
	}
	std::vector<double>& CNeuron::getRawWeights () {
		return m_weights;
	}

	void CNeuron::wSum (std::vector<double> lastLayerValues) {
		double nVal = 0.0;
		for (int i = 0; i < m_weights.size (); i++) {
			std::cout << "llva " << lastLayerValues[i] << std::endl;
			std::cout << "weights " << m_weights [i] << std::endl;
			std::cout << "calculating " << lastLayerValues [i] * m_weights[i] << std::endl;
			nVal += lastLayerValues [i] * m_weights [i];
		}
		m_value = nVal;
		std::cout<<nVal << std::endl;
	}

	double CNeuron::getValue () {
		return m_value;
	}

	void CNeuron::setValue (double value) {
		m_value = value;
	}

	double CNeuron::getError() {
		return m_error;
	}

	void CNeuron::setError (double error) {
		m_error = error;
	}

	void CNeuron::addError (double error) {
		m_error += error;
	}

	void CNeuron::adjustWeights(){
			for (int i = 0; i < m_weights.size(); i++) {
				m_weights[i] += 0.25 * m_error;
			}
	}

	std::vector<double> CNeuron::backpropagate(){
		std::vector<double> retErrors;
		for (int i = 0; i < m_weights.size(); i++) {
			retErrors.push_back(m_error * m_weights[i]);
		}
		return retErrors;
	}
}
