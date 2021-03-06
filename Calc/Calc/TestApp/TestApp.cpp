#include "stdafx.h"
#include "Export.h"
#include "IParser.h"
#include "BaseException.h"


IParserPtr PARSER_DLL_EXPORT CreateStackParser();
IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser();


void ParseFile(IParserPtr p)
{
	if (p != NULL)
	{
		try
		{
			p->Parse("C:\\Src\\dark_repository\\Calc\\pokus.txt");
			std::cout << "The file has been parsed successfully." << std::endl;
		}
		catch (const CBaseException& e)
		{
			std::cout << e.GetMessage() << " at " << e.GetLine() << ":" << e.GetColumn() << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	//ParseFile(CreateStackParser());
	ParseFile(CreateRecursiveParser());


	system("PAUSE");
	return 0;
}
