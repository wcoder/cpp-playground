#include <cstdio>
#include <cstring>

class Person
{
protected:
	int age;
	char name[30];
public:
	

	void print() const
	{
		printf("Hello, I'm %s of %d years old!\n", this->name, this->age);
	}
};

class Student : public Person
{
public:
	Student(int age, const char *name)
	{
		this->age = age;
		strcpy(this->name, name);
	}
};

int main()
{
	Student a(18, "John");
	Student b(22, "Mark");

	Person *people[2] = { &a, &b };
	for (int i = 0; i < 2; i++)
	{
		people[i]->print();
	}

	return 0;
}
