#include <stdio.h>
const int limit = 100;
int done(int index)
{
	return (index > limit);
}
int main() {
	int i = 0;
	while(!done(i)){
		printf("%d\n", i);
		i++;
	}
}
