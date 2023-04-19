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
			//double set_first_number_progression();
			//double set_step_progression();
			//double set_denominator_progression();
			//friend std::ostream& operator<<(std::ostream& out, const SequanceItemType& function_type);
			//friend std::ostream& operator<<(std::ostream& out, const SequanceItem& sequance);
	};

	class SequanceContainer {
		private:
			SequanceItem** sequence_array;
			int user_size;
		public:
			~SequanceContainer();
			SequanceContainer(int size);
			SequanceContainer(const SequanceContainer& arr);
			SequanceContainer() : user_size(0), sequence_array(nullptr) {};
			int get_size() const;
			void remove(int index);
			void insert(int index, SequanceItem& elem);
			void swap(SequanceContainer& arr);
			SequanceItem operator[](int index) const;
			SequanceItem& operator[](int index);
			SequanceContainer& operator=(SequanceContainer arr);

	};

	int max_summ_nth_elem(const SequanceContainer& sequence, int n);
}
