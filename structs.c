#include <stdio.h>
#include <stdlib.h>

struct simple {
	int number;
};

struct child {
	char *name;
};

struct parent {
	char *name;
	struct child *child;
};


int simpleFunc(struct simple *param) {
	param->number = 42;
	return 0;
}

int simplePointerFunc(struct simple **param) {
	struct simple *simple = malloc(sizeof(struct simple));
	simple->number = 24;
	*param = simple;
	return 0;
}

int parentFunc(struct parent **p) {
	struct child *c = malloc(sizeof(struct child));
	c->name = "child";
	struct parent *p2 = malloc(sizeof(struct parent));
	p2->name = "parent";
	p2->child = c;
	*p = p2;
	return 0;
}

int freeParentFunc(struct parent *p) {
	free(p->child);
	free(p);
}

int main() {
	struct simple s = {1};
	struct simple *ps;

	simpleFunc(&s);
	printf("simple: %i\n", s.number);

	simplePointerFunc(&ps);
	printf("simple pointer: %i\n", (*ps).number);
	free(ps);

	struct parent *p;
	parentFunc(&p);
	printf("parent: %s\n", (*p).name);
	printf("parent with child: %s\n", (*p).child->name);
	printf("parent with child: %s\n", (p->child)->name);
	freeParentFunc(p);
//	child *c = (*p).child;
//	printf("%d", c);
//	char *name = (*(*p).child).name;
//	printf("parent with child: %s\n", (p->child)->name);
}
