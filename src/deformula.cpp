
#include "deformula.hpp"

using namespace deformula;

const static double pi = 4.0 * atan(1.0);

// deformula

Deformula::Deformula(double lower, double upper)
: m_lower(lower), m_upper(upper) {}

double Deformula::sumw() const {
	double sum = 0.0;
	for (std::vector<DeformulaElement>::const_iterator it = m_data.begin(); it != m_data.end(); it++) {
		sum += (*it).w;
	}
	return sum;
}

int Deformula::getSize() const {
	return m_data.size();
}

std::vector<double> Deformula::getTValue() const {
	std::vector<double> res(getSize());
	getTValue(res.begin(), res.end());
	return res;
}

std::vector<double> Deformula::getXValue() const {
	std::vector<double> res(getSize());
	getXValue(res.begin(), res.end());
	return res;
}

std::vector<double> Deformula::getWValue() const {
	std::vector<double> res(getSize());
	getWValue(res.begin(), res.end());
	return res;
}

// Integral over (0, infinity)

DeformulaZeroToInf::DeformulaZeroToInf()
: Deformula(-6.8, 6.8) {};

double DeformulaZeroToInf::phi(double t) const {
	return exp(M_PI * sinh(t) / 2.0);			
}

double DeformulaZeroToInf::phidash(double t) const {
	return pi * cosh(t) * exp(pi * sinh(t) / 2.0) / 2.0;
}

// Integral over (-1, 1)

DeformulaMinusOneToOne::DeformulaMinusOneToOne()
: Deformula(-3.0, 3.0) {};

double DeformulaMinusOneToOne::phi(double t) const {
	return tanh(pi * sinh(t) / 2.0);
}

double DeformulaMinusOneToOne::phidash(double t) const {
	return pi * cosh(t) * (1.0 / cosh(pi * sinh(t) / 2.0)) * (1.0 / cosh(pi * sinh(t) / 2.0)) / 2.0;
}

