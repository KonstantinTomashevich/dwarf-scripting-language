#pragma once
#include <string>
#include <vector>

#include <ApplePie/AST/Declaration.hpp>
#include <ApplePie/AST/VariableDeclaration.hpp>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned FUNCTION_DECLARATION_TYPE_HASH = StringToHash ("FunctionDeclaration");

class FunctionDeclaration : public Declaration
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (FunctionDeclaration, FUNCTION_DECLARATION_TYPE_HASH)
protected:
    std::string name_;
    std::string returnType_;
    std::vector <VariableDeclaration *> arguments_;
public:
    FunctionDeclaration (std::string name, std::string returnType, std::vector <VariableDeclaration *> &arguments);
    virtual ~FunctionDeclaration ();

    std::string GetReturnType ();
    VariableDeclaration *GetArgumentDeclarationByIndex (int index);
    int GetArgumentsCount ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
