#include "ParametersHelper.h"

ParametersHelper::ParametersHelper(vector<string> param_names, SymbolTable* sym_table)
{
	Parameter* param;
	vector<string>::iterator param_names_it;

	this->sym_table = sym_table;

	for (param_names_it = param_names.begin(); param_names_it != param_names.end(); param_names_it++)
	{
		param = InitParameter(*param_names_it);
		all_params.push_back(param);
	}
}

ParametersHelper::~ParametersHelper()
{
	DeleteParameters();
}

vector<Parameter*>* ParametersHelper::GetParameters()
{
	return &all_params;
}

void ParametersHelper::DeleteParameters()
{
	vector<Parameter*>::iterator it;
	Parameter* param;

	for (it = all_params.begin(); it != all_params.end(); it++)
	{
		param = *it;
		delete param;
	}
	all_params.clear();
}

bool ParametersHelper::IsParameter(string param)
{
	return param.length() > 0 && param[0] == '-';
}

Parameter* ParametersHelper::InitParameter(string param)
{
	Parameter* ret = NULL;

	if (param == "-dbginfo")
		ret = new DbgInfoParam(param, sym_table);

	if (ret == NULL)
		throw new LLDevParameterException("Invalid parameter " + param + ".");

	return ret;
}