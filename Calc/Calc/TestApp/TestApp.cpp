#include "stdafx.h"
#include "Export.h"
#include "IParser.h"
#include "BaseException.h"


IParserPtr PARSER_DLL_EXPORT CreateStackParser();


int main(int argc, char** argv)
{
	try
	{
		IParserPtr p = CreateStackParser();
		p->Parse("C:\\Src\\dark_repository\\Calc\\pokus.txt");
	}
	catch (const CBaseException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}

	system("PAUSE");
	return 0;
}
