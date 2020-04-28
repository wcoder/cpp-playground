#include <cstdio>
#include <cstring>

struct Student
{
	int age;
	char name[30];

	static void init(Student *self, int age, const char *name);
	static void print(const Student *self);
};

void Student::init(Student *self, int age, const char *name)
{
	self->age = age;
	strcpy(self->name, name);
}

void Student::print(const Student *self)
{
	printf("Hello, I'm %s of %d years old!\n", self->name, self->age);
}

int main()
{
	Student a;
	Student::init(&a, 18, "John");
	Student::print(&a);

	Student b;
	Student::init(&b, 22, "Mark");
	Student::print(&b);       

	return 0;
}
