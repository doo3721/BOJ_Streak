#include <unistd.h>

int main(void)
{
	char	s[10200];

	write(1, s, read(0, s, 10200));
	return (0);
}