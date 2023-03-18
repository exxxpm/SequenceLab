#pragma once
namespace sequence {
	enum SequanceItemType {
		ARITHMETIC,
		GEOMETRIC,
	};

	class SequanceItem {
		private:
			SequanceItemType function_type;
			double first_number_progression;
			double step_progression;
			double denominator_progression;
		public:
			SequanceItem();
			SequanceItem(SequanceItemType function_type, double first_number_progression, double step_progression, double denominator_progression);
			SequanceItemType get_type() const;
			double calc_nth_elem(int n);
			double calc_summ_nth_elem(int n);
	};

	class SequanceContainer {
		public:
			static const int DATASIZE = 10;
		private:
			SequanceItem sequence_array[DATASIZE];
			int user_size;
		public:
			SequanceContainer();
			int get_size() const;
			void remove(int index);
			void insert(int index, SequanceItem s);
			SequanceItem operator[](int index) const;
	};

	int max_summ_nth_elem(const SequanceContainer& sequence, int n);
}
