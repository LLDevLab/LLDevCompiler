#include "Parser/Parser.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		try
		{
			LexAnalyzer analyzer(argv[1]);
			Parser parser(&analyzer);

			parser.Parse();
			cout << "Compilation complete." << endl;
		}
		catch (LLDevIOException& e)
		{
			cout << e.what() << endl;
			return 0;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
			return -1;
		}
	}
}
