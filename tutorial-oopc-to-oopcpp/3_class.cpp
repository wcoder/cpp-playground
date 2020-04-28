#include <cstdio>
#include <cstring>

class Student
{
	int age;
	char name[30];
public:
	void init(int age, const char *name);
	void print() const;
};

void Student::init(int age, const char *name)
{
	this->age = age;
	strcpy(this->name, name);
}

void Student::print() const
{
	printf("Hello, I'm %s of %d years old!\n", this->name, this->age);
}

int main()
{
	Student a;
	a.init(18, "John");
	a.print();

	Student b;
	a.init(22, "Mark");
	a.print();       

	return 0;
}
