#include <stdio.h>

typedef struct {
	int number;
} simple;

typedef struct {
	char *name;
} child;

typedef struct {
	char *name;
	child *child;
} parent;


int simpleFunc(simple *param) {
	(*param).number = 42;
	return 0;
}

int simplePointerFunc(simple **param) {
	simple s = {24};
	*param = &s;
	return 0;
}

int parentFunc(parent **p) {
	child c = {"child"};
	parent p2 = {.name = "parent", .child = &c};
	*p = &p2;
	return 0;
}

int main() {
	simple s = {1};
	simple *ps;

	simpleFunc(&s);
	printf("simple: %i\n", s.number);

	simplePointerFunc(&ps);
	printf("simple pointer: %i\n", (*ps).number);

	parent *p;
	parentFunc(&p);
	printf("parent: %s\n", (*p).name);
	printf("parent with child: %s\n", (*(*p).child).name);
//	printf("parent with child: %s\n", (p->child)->name);
//	child *c = (*p).child;
//	printf("%d", c);
//	char *name = (*(*p).child).name;
//	printf("parent with child: %s\n", (p->child)->name);
}
