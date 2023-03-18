#include <sequense/sequense.h>
#include <stdexcept>
#include <cmath>

using namespace sequence;
using namespace std;

SequanseItem::SequanseItem() : function_type(SequanseItemType::ARITHMETIC), first_number_progression(0.0), step_progression(0.0), denominator_progression(0.0) {}

SequanseItem::SequanseItem(SequanseItemType function_type, double first_number_progression, double step_progression, double denominator_progression) {
	this->function_type = function_type;
	this->first_number_progression = first_number_progression;
	this->step_progression = step_progression;
	this->denominator_progression = denominator_progression;
}

SequanseItemType SequanseItem::get_type() const { 
	return function_type;
}

double SequanseItem::calc_nth_elem(int n) {
	switch(function_type){
		case ARITHMETIC:
			return first_number_progression + (n - 1) * step_progression;
		case GEOMETRIC:
			return first_number_progression + pow(denominator_progression, n-1);
		default:
			throw runtime_error("[SequanseItem::calc_nth_elem] Error on this function");
	}
}

double SequanseItem::calc_summ_nth_elem(int n) {
	switch (function_type) {
	case ARITHMETIC:
		return (((first_number_progression + SequanseItem::calc_nth_elem(n))/2)*n);
	case GEOMETRIC:
		return (first_number_progression*(1 - pow(denominator_progression, n))/(1 - denominator_progression));
	default:
		throw runtime_error("[SequanseItem::calc_summ_nth_elem] Error on this function");
	}
}