/*
 * MathLib v1.0
 * Copyright (c) 2021 miniprime1.
 */ 

#pragma once

#define PI 3.141592653589793238462643383279502884197169399375
#define E 2.718281828459045235360287471352662497757247093699
#define SQRT_2 1.414213562373095048801688724209698078569671875376
#define SQRT_3 1.732050807568877293527446341505872366942805253810
#define SQRT_5 2.236067977499789696409173668731276235440618359611
#define GAMMA 0.577215664901532860606512090082402431042159335939
#define PHI 1.618033988749894848204586834365638117720309179805 

namespace mathlib {
	double add(double a, double b) {
		double result;
		result = a + b;
		return result;
	}

	double sub(double a, double b) {
		double result;
		result = a - b;
		return result;
	}

	double mul(double a, double b) {
		double result;
		result = a * b;
		return result;
	}

	double div(double a, double b) {
		double result;
		result = a / b;
		return result;
	}

	double abs(double x) {
		double result = 0;
		if (x >= 0) result = x;
		else result = -x;
		return result;
	}

	double fact(int x) {
		double result = 1;
		if (x == 0 || x == 1) return 1;
		else for (int i = 1; i < x + 1; i++) { result *= i; }
		return result;
	}

	double pow(double x, int n) {
		if (n == 0) return 1;
		else if ((n % 2) == 0)
			return pow(x * x, n / 2);
		else return x * pow(x * x, (n - 1) / 2);
	}

	double sqrt(double x) {
		auto x_n1 = [](double S, double x_n) { return (x_n + S / x_n) / 2; };
		double result = 0;
		double bef = 1, aft = x_n1(x, bef);
		double lim = 1000000.0;
		for (int n = 1; n < lim; n++) {
			bef = aft;
			aft = x_n1(x, bef);
		}
		result = aft;
		return result;
	}

	double cbrt(double x) {
		auto x_n1 = [](double S, double x_n) { return (2*x_n + S / pow(x_n, 2)) / 3; };
		double result = 0;
		double bef = 1, aft = x_n1(x, bef);
		double lim = 1000000.0;
		for (int n = 1; n < lim; n++) {
			bef = aft;
			aft = x_n1(x, bef);
		}
		result = aft;
		return result;
	}

	double sin(double t) {
		int lim = 84;
		int num = 0;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			num = 2 * n + 1;
			temp = pow(-1, n) * pow(x, num) / fact(num);
			result += temp;
		}
		return result;
	}

	double cos(double t) {
		int lim = 84;
		int num = 0;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			num = 2 * n;
			temp = pow(-1, n) * pow(x, num) / fact(num);
			result += temp;
		}
		return result;
	}

	double tan(double t) {
		double result = 0;
		result = sin(t) / cos(t);
		return result;
	}

	double cot(double t) {
		double result = 0;
		result = cos(t) / sin(t);
		return result;
	}

	double sec(double t) {
		double result = 0;
		result = 1 / cos(t);
		return result;
	}

	double csc(double t) {
		double result = 0;
		result = 1 / sin(t);
		return result;
	}
	
	double exp(double t) {
		int lim = 84;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			temp = pow(x, n) / fact(n);
			result += temp;
		}
		return result;
	}

	double log(double x) {
		double result = 0;
		double temp = 0;
		double limit = (double)1000;

		if (0.0 < x && x < 2.0) {}
		else { return 53303; }

		for (int i = 1; i < limit; i++) {
			temp = pow(x - 1, i) * pow(-1, i + 1) / i;
			result += temp;
		}

		return result;
	}

	double asin(double t) {
		int lim = 84;
		int num = 0;

		if (abs(t) <= 1) {}
		else { return 53303; }

		double x = t;
		double result = 0;
		double temp = 0;

		for (int n = 0; n < lim; n++) {
			num = 2 * n + 1;
			temp = (pow(x, num) * fact(2 * n)) / (pow(4, n) * pow(fact(n), 2) * num);
			result += temp;
		}
		return result;
	}

	double acos(double t) {
		double result = 0;
		if (abs(t) <= 1) {}
		else { return 53303; }
		double x = t;
		result = PI / 2 - asin(x);
		return result;
	}

	double atan(double t) {
		int lim = 84;
		int num = 0;

		if (abs(t) <= 1) {}
		else { return 53303; }

		double x = t;
		double result = 0;
		double temp = 0;

		for (int n = 0; n < lim; n++) {
			num = 2 * n + 1;
			temp = (pow(x, num) * pow(-1, n)) / num;
			result += temp;
		}
		return result;
	}

	double sinh(double t) {
		int lim = 84;
		int num = 0;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			num = 2 * n + 1;
			temp = pow(x, num) / fact(num);
			result += temp;
		}
		return result;
	}

	double cosh(double t) {
		int lim = 84;
		int num = 0;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			num = 2 * n;
			temp = pow(x, num) / fact(num);
			result += temp;
		}
		return result;
	}

	double tanh(double t) {
		double result = 0;
		result = sinh(t) / cosh(t);
		return result;
	}

	double coth(double t) {
		double result = 0;
		result = cosh(t) / sinh(t);
		return result;
	}

	double sech(double t) {
		double result = 0;
		result = 1 / cosh(t);
		return result;
	}

	double csch(double t) {
		double result = 0;
		result = 1 / sinh(t);
		return result;
	}

	double asinh(double t) {
		int lim = 84;
		int num = 0;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			num = 2 * n + 1;
			temp = (pow(-1, n) * pow(x, num) * fact(2 * n)) / (pow(4, n) * pow(fact(n), 2) * num);
			result += temp;
		}
		return result;
	}

	double atanh(double t) {
		int lim = 84;
		int num = 0;
		double x = t;
		double result = 0;
		double temp = 0;
		for (int n = 0; n < lim; n++) {
			num = 2 * n + 1;
			temp = pow(x, num) / num;
			result += temp;
		}
		return result;
	}

	double derive(double (*f)(double), double a)
	{
		const double h = 1.0e-6;
		double x1 = a - h;
		double x2 = a + h;
		double y1 = f(x1);
		double y2 = f(x2);
		return (y2 - y1) / (x2 - x1);
	}

	double integrate(double (*f)(double), double a, double b) {
		double n = 1000000.0;

		auto delta_x = [](double a, double b, double n) -> double { return (b - a) / n; };
		auto x_k = [](double a, double b, double k, double n) -> double { return a + (b - a) * k / n; };
		auto y_k = [](double (*f)(double), double a, double b, double k, double n) -> double { return f(a + (b - a) * k / n); };

		double I = 0;
		double L = 0;
		double T = 0;

		for (int k = 0; k < n; k++) {
			T = y_k(f, a, b, k, n);
			if (k == 0 || k == n) { L += T; }
			else { L += 2 * T; }
		}

		I = delta_x(a, b, n) / 2 * L;
		return I;
	}
}
