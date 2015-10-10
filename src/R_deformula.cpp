#include "deformula.hpp"

#include <R.h>
#include <Rinternals.h>

SEXP mkans(double x) {
	SEXP ans;
	PROTECT(ans = allocVector(REALSXP, 1));
	REAL(ans)[0] = x;
	UNPROTECT(1);
	return ans;
}

// functional

class Func {
private:
	SEXP m_f;
	SEXP m_rho;

public:
	Func(SEXP f, SEXP rho) : m_f(f), m_rho(rho) { }
	virtual ~Func() {}

	double operator()(double x) {
		defineVar(install("x"), mkans(x), m_rho);
		return REAL(eval(m_f, m_rho))[0];
	}
};

extern "C" {

	SEXP integrate_zero_to_inf(SEXP f, SEXP rho,
		SEXP zero, SEXP reltol, SEXP startd, SEXP maxiter) {
		deformula::DeformulaZeroToInf de;
		Func func(f, rho);
		de.getWeight(func, asReal(zero), asReal(reltol), asInteger(startd), asInteger(maxiter));

		SEXP t, x, w, s, h, info, ans;
		int n = de.getSize();
		PROTECT(t = allocVector(REALSXP, n));
		PROTECT(x = allocVector(REALSXP, n));
		PROTECT(w = allocVector(REALSXP, n));
		PROTECT(s = allocVector(REALSXP, 1));
		PROTECT(h = allocVector(REALSXP, 1));
		PROTECT(info = allocVector(INTSXP, 1));
		de.getTValue(REAL(t), REAL(t)+n);
		de.getXValue(REAL(x), REAL(x)+n);
		de.getWValue(REAL(w), REAL(w)+n);
		REAL(s)[0] = de.getSum();
		REAL(h)[0] = de.getH();
		INTEGER(info)[0] = de.getInfo();

		PROTECT(ans = allocVector(VECSXP, 6));
		SET_VECTOR_ELT(ans, 0, s);
		SET_VECTOR_ELT(ans, 1, x);
		SET_VECTOR_ELT(ans, 2, w);
		SET_VECTOR_ELT(ans, 3, t);
		SET_VECTOR_ELT(ans, 4, h);
		SET_VECTOR_ELT(ans, 5, info);

		UNPROTECT(7);
		return ans;
	}

	SEXP integrate_mone_to_one(SEXP f, SEXP rho,
		SEXP zero, SEXP reltol, SEXP startd, SEXP maxiter) {
		deformula::DeformulaMinusOneToOne de;
		Func func(f, rho);
		de.getWeight(func, asReal(zero), asReal(reltol), asInteger(startd), asInteger(maxiter));

		SEXP t, x, w, s, h, info, ans;
		int n = de.getSize();
		PROTECT(t = allocVector(REALSXP, n));
		PROTECT(x = allocVector(REALSXP, n));
		PROTECT(w = allocVector(REALSXP, n));
		PROTECT(s = allocVector(REALSXP, 1));
		PROTECT(h = allocVector(REALSXP, 1));
		PROTECT(info = allocVector(INTSXP, 1));
		de.getTValue(REAL(t), REAL(t)+n);
		de.getXValue(REAL(x), REAL(x)+n);
		de.getWValue(REAL(w), REAL(w)+n);
		REAL(s)[0] = de.getSum();
		REAL(h)[0] = de.getH();
		INTEGER(info)[0] = de.getInfo();

		PROTECT(ans = allocVector(VECSXP, 6));
		SET_VECTOR_ELT(ans, 0, s);
		SET_VECTOR_ELT(ans, 1, x);
		SET_VECTOR_ELT(ans, 2, w);
		SET_VECTOR_ELT(ans, 3, t);
		SET_VECTOR_ELT(ans, 4, h);
		SET_VECTOR_ELT(ans, 5, info);

		UNPROTECT(7);
		return ans;
	}
}

