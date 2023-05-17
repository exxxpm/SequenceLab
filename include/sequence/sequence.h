#pragma once
#include <string>
#include <memory>
#include <vector>
namespace sequence {
	class Sequance;
	using SequancePtr = std::shared_ptr<Sequance>;

	class Sequance{
		public:
			virtual ~Sequance() = default;
			int get_type() const;
			virtual double calc_nth_elem(int n) const = 0;
			virtual double calc_summ_nth_elem(int n) const = 0;
			virtual SequancePtr clone_item() const = 0;
		protected:
			Sequance() = default;
			Sequance(const Sequance&) = default;
			Sequance& operator=(const Sequance&) = default;
	};

	class ArithmeticSequance : public Sequance{
		private:
			double first_number_progression;
			double step_progression;
		public:
			ArithmeticSequance(double first_number_progression, double step_progression);
			void set_first_number_progression(double num);
			void set_step_progression(double num);
			double get_first_number_progression() const;
			double get_step_progression() const;
			double calc_nth_elem(int n) const override;
			double calc_summ_nth_elem(int n) const override;
			SequancePtr clone_item() const override;
	};

	class GeometricSequance : public Sequance {
		private:
			double first_number_progression;
			double denominator_progression;
		public:
			GeometricSequance(double first_number_progression, double denominator_progression);
			void set_first_number_progression(double num);
			void set_denominator_progression(double num);
			double get_first_number_progression() const;
			double get_denominator_progression() const;
			double calc_nth_elem(int n) const override;
			double calc_summ_nth_elem(int n) const override;
			SequancePtr clone_item() const override;
	};

	class SequanceContainer {
		private:
			std::vector<SequancePtr> sequence_array;
		public:
			SequanceContainer() = default;
			SequanceContainer(const SequanceContainer& arr);
			int size() const;
			void remove(int index);
			void insert(SequancePtr elem);
			void swap(SequanceContainer& arr);
			SequancePtr operator[](int index) const;
			SequanceContainer& operator=(SequanceContainer& arr);
	};
	std::ostream& operator<<(std::ostream& out, const SequancePtr& ptr);
	int max_summ_nth_elem(const SequanceContainer& sequence, int n);
}