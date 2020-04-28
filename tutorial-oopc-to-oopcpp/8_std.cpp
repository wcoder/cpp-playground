#include <iostream>
#include <string>
#include <vector>

class Person
{
protected:
	int age;
	std::string name;
public:
	Person(int age_, std::string name_)
	{
		age = age_;
		name = name_;
	}
	virtual void print() const = 0;
};

class Student : public Person
{
public:
	Student(int age, const char *name) : Person(age, name)
	{}

	void print() const
	{
		std::cout << "Hello, I'm " << name << " of " << age << " years old!\n";
	}
};

int main()
{
	std::vector<Person*> people  = {
       		new Student(18, "John"),
		new Student(22, "Mark")
	};
	for (auto x: people)
	{
		x->print();
	}

	return 0;
}
