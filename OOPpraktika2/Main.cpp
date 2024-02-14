#include <iostream>
#include <string>
#include <vector>

class People {
public:
	People():name_("Name"){}
	People(std::string name):name_(name){}

	void peopleInf() {
		std::cout << "Имя владельца: " << name_ << std::endl;
	}

private:
	std::string name_;
};

class Cat {
public:
	Cat():name_("Name"), porod_("Poroda") {};
	Cat(std::string name, std::string porod):name_(name),porod_(porod)  {}
	~Cat() {}
		


	void addVladel(People* obj) {
		Vladel_.push_back(obj);
	}

	void CatInf() {
		std::cout << "Имя кота: " << name_ << std::endl;
		std::cout << "Порода кота: " << porod_ << std::endl;
		for (int i = 0; i < Vladel_.size(); i++)
			Vladel_[i]->peopleInf();
	}

	std::string name() {
		return name_;
	}

private:
	std::string name_;
	std::string porod_;
	std::vector<People*> Vladel_;
};


class CatHotel {
public:
	CatHotel():count_(0),size_(0){}
	CatHotel(int size):size_(size),count_(0){}

	void HotelInf() {
		std::cout << "Размер отеля " << count_ << "/" << size_ << std::endl;
		for (int i = 0; i < list_.size(); i++) {
			list_[i]->CatInf();
			std::cout << std::endl;
		}
	}

	void addCat(Cat* obj) {
		if (count_ < size_) {
			list_.push_back(obj);
			count_++;
		}
		else {
			std::cout << "Отель переполнен!" << std::endl;
		}
	}

	void FindCat(std::string name) {
		for (int i = 0; i < list_.size(); i++) {
			if (list_[i]->name() == name) {
				list_[i]->CatInf();
				std::cout << std::endl;
			}
		}
	}

	void deleteCat(std::string name) {
		int counter = 0;
		for (int i = 0; i < list_.size(); i++) {
			if (list_[i]->name() == name) {
				list_.erase(list_.begin() + i);
			}
		}
		
	}

	

private:
	int count_;
	int size_;
	std::vector<Cat*> list_;
};



int main() {
	setlocale(0, "");

	People P1("Alex");
	Cat C1("Barsik", "Dvorovoi");
	People P2("Sergey");
	Cat C2("Murka", "skin");
	C1.addVladel(&P1);
	C2.addVladel(&P2);
	CatHotel H1(10);
	H1.addCat(&C1);
	H1.addCat(&C2);
	H1.FindCat("Murka");
	H1.deleteCat("Murka");
	H1.HotelInf();


	





	return 0;
}