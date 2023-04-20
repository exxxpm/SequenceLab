#include <sequence/sequence.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

using namespace sequence;
using namespace std;

SequanceItem::SequanceItem() : function_type(SequanceItemType::ARITHMETIC), first_number_progression(0.0), step_progression(0.0), denominator_progression(0.0) {}

SequanceItem::SequanceItem(SequanceItemType function_type, double first_number_progression, double step_progression, double denominator_progression) {
	this->function_type = function_type;
	this->first_number_progression = first_number_progression;
	this->step_progression = step_progression;
	this->denominator_progression = denominator_progression;
}

std::ostream& sequence::operator<<(std::ostream& out, const SequanceItemType& function_type) {
	switch (function_type) {
		case ARITHMETIC:
			out << "ARITHMETIC";
			break;
		case GEOMETRIC:
			out << "GEOMETRIC";
			break;
	}
	return out;
}

std::ostream& sequence::operator<<(std::ostream& out, const SequanceItem& elem) {
	double num_first_number_progression = elem.first_number_progression;
	double num_step_progression = elem.step_progression;
	double num_denominator_progression = elem.denominator_progression;

	if (elem.get_type() == ARITHMETIC) {
		out << "  |\033[1;34mТип:\033[0m " << "ARITHMETIC" << "|\n";
		out << "  |\033[1;34mПервый член прогрессии:\033[0m " << num_first_number_progression << "|\n";
		out << "  |\033[1;34mШаг прогрессии:\033[0m " << num_step_progression << "|\n";
		out << "\n";
	}
	else if (elem.get_type() == GEOMETRIC) {
		out << "  |\033[1;34mТип:\033[0m " << "GEOMETRIC" << "|\n";
		out << "  |\033[1;34mПервый член прогрессии:\033[0m " << num_first_number_progression << "|\n";
		out << "  |\033[1;34mЗнаменатель прогрессии:\033[0m " << num_denominator_progression << "|\n";
		out << "\n";
	}
	return out;
}

SequanceItemType SequanceItem::get_type() const{
	return function_type;
}

void SequanceItem::set_function_type(SequanceItemType type) {
	function_type = type;
}

double SequanceItem::set_first_number_progression(double num){
	first_number_progression = num;
	return first_number_progression;
}

double SequanceItem::set_step_progression(double num){
	step_progression = num;
	return step_progression;
}

double SequanceItem::set_denominator_progression(double num){
	denominator_progression = num;
	return denominator_progression;
}

double SequanceItem::get_first_number_progression() {
	return first_number_progression;
}

double SequanceItem::get_step_progression() {
	return step_progression;
}

double SequanceItem::get_denominator_progression() {
	return denominator_progression;
}


double SequanceItem::calc_nth_elem(int n) {
	switch(function_type){
		case ARITHMETIC:
			return first_number_progression + (n-1) * step_progression;
		case GEOMETRIC:
			return first_number_progression * pow(denominator_progression, n-1);
		default:
			throw runtime_error("[SequanseItem::calc_nth_elem] Error on this function");
	}
}

double SequanceItem::calc_summ_nth_elem(int n) {
	switch (function_type) {
		case ARITHMETIC:
			return (((first_number_progression + SequanceItem::calc_nth_elem(n))/2)*n);
		case GEOMETRIC:
			return (first_number_progression*(1 - pow(denominator_progression, n))/(1 - denominator_progression));
		default:
			throw runtime_error("[SequanseItem::calc_summ_nth_elem] Error on this function");
	}
}