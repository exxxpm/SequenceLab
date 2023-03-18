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
			SequanseItemType get_type() const;
			SequanseItem(SequanseItemType function_type, double first_number_progression, double denominator_progression);
			double calc_nth_elem(int n);
			double calc_summ_nth_elem(int n);
	};

	class SequanseContainer {
		public:
			static const int DATASIZE = 10;
		private:
			SequanseItem sequance_array[DATASIZE];
			int user_size;
		public:
			SequanseContainer();
			int get_size() const;
			void remove(int index);
			void insert(int index, SequanseItem s);
			SequanseItem operator[](int index) const;
	};

	int max_summ_nth_elem(const SequanseContainer& sequence, int n);
}
