#include "stdafx.h"
#include "Export.h"
#include "IParser.h"

IParserPtr PARSER_DLL_EXPORT CreateStackParser();


int main(int argc, char** argv)
{
	IParserPtr p = CreateStackParser();
	p->Parse("C:\\Src\\dark_repository\\Calc\\pokus.txt");

	system("PAUSE");
	return 0;
}

