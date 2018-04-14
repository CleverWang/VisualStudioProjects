#include "global.h"

int odd[5] = { 1,3,5,7,9 };
int even[5] = { 2,4,6,8,10 };

int(*odd_eve_1(int i))[5]
{
	return (i % 2 == 0) ? &even : &odd;
}

auto odd_even_2(int i) -> int(*)[5]
{
	return (i % 2 == 0) ? &even : &odd;
}

decltype(odd)* odd_even_3(int i)
{
	return (i % 2 == 0) ? &even : &odd;
}
