#include <unistd.h>

int main()
{
	
	const char *some_text = "Hello, I am Ouassim";
	write(1, some_text, 14);
	return 0;
}
