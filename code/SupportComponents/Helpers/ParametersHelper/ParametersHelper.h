#pragma once
#include <string>
#include <vector>
#include "../../../Parameters/Parameters.h"
#include "../../../Types/TypeDef.h"
#include "../../../Exceptions/LLDevExceptions.h"

using namespace std;

class ParametersHelper
{
public:
	ParametersHelper(vector<string> param_names);
	~ParametersHelper();
	vector<Parameter*>* GetParameters();
	static bool IsParameter(string param);
private:
	Parameter* InitParameter(string param);
	void DeleteParameters();

	vector<Parameter*> all_params;
};