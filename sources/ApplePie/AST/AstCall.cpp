#include "AstCall.hpp"
#include <assert.h>

namespace ApplePie
{
AstCall::AstCall (std::string calledFunction, std::vector<AstValue *> arguments) :
    calledFunction_ (calledFunction),
    arguments_ (arguments)
{

}

AstCall::~AstCall ()
{
    for (int index = 0; index < arguments_.size (); index++)
        delete arguments_.at (index);
    arguments_.clear ();
}

std::string AstCall::GetCalledFunctionName ()
{
    return calledFunction_;
}

AstValue *AstCall::GetArgumentByIndex (int index)
{
    assert (index < arguments_.size ());
    return arguments_.at (index);
}

int AstCall::GetArgumentsCount ()
{
    return arguments_.size ();
}

std::string AstCall::ToString(int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[call of function ";
    result += calledFunction_;
    result += ";\n" + indent + "arguments:\n";

    for (int index = 0; index < arguments_.size (); index++)
        result += arguments_.at (index)->ToString (addSpacesIndentation + 4) + "\n";
    result += "end of function call]";
    return result;
}
}