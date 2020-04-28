#include <cstdio>
#include <cstring>

class Student
{
	int age;
	char name[30];
public:
	Student(int age, const char *name);
	void print() const;
};

Student::Student(int age, const char *name)
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
	Student a(18, "John");
	a.print();

	Student b(22, "Mark");
	b.print();       

	return 0;
}
