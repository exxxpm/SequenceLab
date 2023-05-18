#include <sequence/sequence.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

using namespace sequence;
using namespace std;

std::ostream& sequence::operator<<(std::ostream& out, const SequancePtr& ptr) {
	auto arith_seq = dynamic_cast<ArithmeticSequance*>(ptr.get());
	auto geom_seq = dynamic_cast<GeometricSequance*>(ptr.get());
	if (arith_seq != nullptr) {
		double num_first_number_progression = arith_seq->get_first_number_progression();
		double num_step_progression = arith_seq->get_step_progression();
		out << "  |\033[1;34mТип:\033[0m " << "ARITHMETIC" << "|\n";
		out << "  |\033[1;34mПервый член прогрессии:\033[0m " << num_first_number_progression << "|\n";
		out << "  |\033[1;34mШаг прогрессии:\033[0m " << num_step_progression << "|\n";
		out << "\n";
	}
	else if (geom_seq != nullptr) {
		double num_first_number_progression = geom_seq->get_first_number_progression();
		double num_denominator_progression = geom_seq->get_denominator_progression();
		out << "  |\033[1;34mТип:\033[0m " << "GEOMETRIC" << "|\n";
		out << "  |\033[1;34mПервый член прогрессии:\033[0m " << num_first_number_progression << "|\n";
		out << "  |\033[1;34mЗнаменатель прогрессии:\033[0m " << num_denominator_progression << "|\n";
		out << "\n";
	}
	return out;
}

ArithmeticSequance::ArithmeticSequance(double first_number_progression, double step_progression) {
	this->first_number_progression = first_number_progression;
	this->step_progression = step_progression;
}

void ArithmeticSequance::set_first_number_progression(double num) { first_number_progression = num; }
void ArithmeticSequance::set_step_progression(double num) { step_progression = num; }
double ArithmeticSequance::get_first_number_progression() const { return first_number_progression; }
double ArithmeticSequance::get_step_progression() const { return step_progression; }

double ArithmeticSequance::calc_nth_elem(int n) const {
	return first_number_progression + (n - 1) * step_progression;
}

double ArithmeticSequance::calc_summ_nth_elem(int n) const {
	return (((first_number_progression + ArithmeticSequance::calc_nth_elem(n)) / 2) * n);
}

SequancePtr ArithmeticSequance::clone_item() const { return make_shared<ArithmeticSequance>(first_number_progression, step_progression); }

GeometricSequance::GeometricSequance(double first_number_progression, double denominator_progression) {
	this->first_number_progression = first_number_progression;
	this->denominator_progression = denominator_progression;
}

void GeometricSequance::set_first_number_progression(double num) { first_number_progression = num; }
void GeometricSequance::set_denominator_progression(double num) { denominator_progression = num; }
double GeometricSequance::get_first_number_progression() const { return first_number_progression; }
double GeometricSequance::get_denominator_progression() const { return denominator_progression; }

double GeometricSequance::calc_nth_elem(int n) const {
	return first_number_progression * pow(denominator_progression, n - 1);
}

double GeometricSequance::calc_summ_nth_elem(int n) const {
	return (first_number_progression * (1 - pow(denominator_progression, n)) / (1 - denominator_progression));
}

SequancePtr GeometricSequance::clone_item() const { return make_shared<GeometricSequance>(first_number_progression, denominator_progression); }