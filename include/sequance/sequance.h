#pragma once
namespace sequance {
	enum SequanseItemType {
		ARITHMETIC,
		GEOMETRIC,
	};

	class SequanseItem {
		private:
			SequanseItemType function_type;
			double first_number_progression;
			double step_progression;
			double denominator_progression;
		public:
			SequanseItem();
			SequanseItem(SequanseItemType function_type, double first_number_progression, double denominator_progression);
			double calc_nth_elem(SequanseItemType function_type, int n);
			double calc_summ_nth_elem(SequanseItemType function_type, int n);
	};

	class SequanseContaier {
		public:
			static const int DATASIZE = 10;
		private:
			SequanseItem sequance_array[DATASIZE];
			int user_size;
		pu
	};
}
