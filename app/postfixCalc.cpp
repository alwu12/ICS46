#include "postfixCalc.hpp"
#include <unordered_map>
#include "LLStack.hpp"

unsigned add(unsigned x, unsigned y){return x+y;}
unsigned subtract(unsigned x, unsigned y){return x-y;}
unsigned mult(unsigned x, unsigned y){return x*y;}
unsigned div(unsigned x, unsigned y){return x/y;}

unsigned postfixCalculator(const std::vector<std::string> & entries)
{
	if(entries.empty())
	{
		throw CannotEvaluateException("Expression is empty at the beggining");
	}

	std::unordered_map<std::string, unsigned (*)(unsigned, unsigned)> operatorMap = {{"+",add}, {"-",subtract},{"*",mult},{"/",div}};
	LLStack<unsigned> numStack;
	for(auto& element: entries) // for each entry in the vector
	{
		if (operatorMap.find(element) != operatorMap.end()) // if the vector is an operator
		{
			unsigned secondNum = numStack.top();
			numStack.pop();
			unsigned firstNum = numStack.top();
			numStack.pop();//take the top two elements in the stack 
			
			numStack.push(operatorMap[element](firstNum,secondNum)); //readd to the stack the post operated value
		}
		else
		{
			numStack.push(stoul(element));
		}
	}
	

	if(numStack.size() != 1)
	{
		throw CannotEvaluateException("Expression cannot be evaluated: incorrect number of integers in stack");
	}
	return numStack.top();
}

