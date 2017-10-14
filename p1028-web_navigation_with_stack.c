#include <stdio.h>
#define MAX_URL 72
#define MAX_STACK 128
#define MAXN 256 

char URL[MAXN][MAX_URL] = {{"http://www.acm.org/"}};
int stack_back[MAX_STACK], top_back = -1,
    stack_forw[MAX_STACK], top_forw = -1,
    urln = 1, current = 0;
void push(int [], int *, int);
int pop(int [], int *);
void clear(int *);
int empty(int *);

int
main()
{
	char	cmd[10];

	while (scanf("%s", cmd) != EOF
			&& cmd[0] != 'Q') {	// QUIT
		switch (cmd[0]) {
			case 'V':
				visit();
				break;
			case 'B':
				back();
				break;
			case 'F':
				forward();
				break;
			default:
				continue;
		}
	}
}

int
visit()
{
	push(stack_back, &top_back, current);
	scanf("%s", URL[urln]);
	current = urln;
	if (urln >= MAXN)
		urln = 0;
	else
		urln++;
	printf("%s\n", URL[current]);
	clear(&top_forw);

	return 0;
}

int
back()
{
	if (empty(&top_back)) {
		printf("Ignored\n");
	} else {
		push(stack_forw, &top_forw, current);
		current = pop(stack_back, &top_back);
		printf("%s\n", URL[current]);
	}

	return 0;
}

int
forward()
{
	if (empty(&top_forw)) 
		printf("Ignored\n");
	else {
		push(stack_back, &top_back, current);
		current = pop(stack_forw, &top_forw);
		printf("%s\n", URL[current]);
	}

	return 0;
}

void
push(int stack[], int *top, int it)
{
	(*top)++;
	stack[*top] = it;
}

int
pop(int stack[], int *top)
{
	int	it;

	it = stack[*top];
	(*top)--;

	return it;
}

void
clear(int *top)
{
	*top = -1;
}

int
empty(int *top)
{
	if (*top < 0)
		return 1;
	else
		return 0;
}
