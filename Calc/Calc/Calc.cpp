#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "StackParser.h"


int main(int argc, char* argv[])
{
	CStackParser p;
	p.Parse("C:\\Src\\dark_repository\\Calc\\pokus.txt");

	system("PAUSE");
	return 0;
}