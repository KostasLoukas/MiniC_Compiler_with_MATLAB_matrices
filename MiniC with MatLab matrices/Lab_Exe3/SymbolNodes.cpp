#include "SymbolNodes.h"

#include <iostream>


#include "Grammar.tab.h"


#include "SymbolTable.h"







//we call the constructors and destructors before we start working with the actual classes

CCalculator::CCalculator() : STNode(NodeType::NT_CALCULATOR) {}
CCalculator::~CCalculator() {}


CStatements::CStatements() : STNode(NodeType::NT_STATEMENTS) {}
CStatements::~CStatements() {}


CStatement::CStatement() : STNode(NodeType::NT_STATEMENT) {}
CStatement::~CStatement() {}


CIf::CIf() : STNode(NodeType::NT_IF) {}
CIf::~CIf() {}


CWhile::CWhile() : STNode(NodeType::NT_WHILE) {}
CWhile::~CWhile() {}


CBreak::CBreak() : STNode(NodeType::NT_BREAK) {}
CBreak::~CBreak() {}


CCompound_Statement::CCompound_Statement() : STNode(NodeType::NT_COMPOUND_STATEMENT) {}
CCompound_Statement::~CCompound_Statement() {}


CStatement_List::CStatement_List() : STNode(NodeType::NT_STATEMENT_LIST) {}
CStatement_List::~CStatement_List() {}


CArray::CArray() : STNode(NodeType::NT_ARRAY) {}
CArray::~CArray() {}


CElements::CElements() : STNode(NodeType::NT_ELEMENTS) {}
CElements::~CElements() {}


CElement::CElement() : STNode(NodeType::NT_ELEMENT) {}
CElement::~CElement() {}


CNUMBER::CNUMBER(char* text) : CExpression(NodeType::NT_EXPRESSION_NUMBER)
{
	m_number = atoi(text);

	m_graphvizLabel.append("_" + std::to_string(m_number));  //we append the number onto the node's label

}
CNUMBER::~CNUMBER() {}


CIDENTIFIER::CIDENTIFIER(char* text) : CExpression(NodeType::NT_EXPRESSION_IDENTIFIER)
{
	m_name = (string)text;

	
	m_value.val.i = 0;
	m_value.val.a = nullptr;

	m_graphvizLabel.append("_" + m_name);   //we append the variable's name onto the node's label

}
CIDENTIFIER::~CIDENTIFIER() {}


CAssignment::CAssignment() : CExpression(NodeType::NT_EXPRESSION_ASSIGNMENT) {}
CAssignment::~CAssignment() {}


CGreater_Than::CGreater_Than() : CExpression(NodeType::NT_EXPRESSION_GREATER_THAN) {}
CGreater_Than::~CGreater_Than() {}


CGreater_Than_Equal::CGreater_Than_Equal() : CExpression(NodeType::NT_EXPRESSION_GREATER_THAN_EQUAL) {}
CGreater_Than_Equal::~CGreater_Than_Equal() {}


CLess_Than::CLess_Than() : CExpression(NodeType::NT_EXPRESSION_LESS_THAN) {}
CLess_Than::~CLess_Than() {}


CLess_Than_Equal::CLess_Than_Equal() : CExpression(NodeType::NT_EXPRESSION_LESS_THAN_EQUAL) {}
CLess_Than_Equal::~CLess_Than_Equal() {}


CEqual::CEqual() : CExpression(NodeType::NT_EXPRESSION_EQUAL) {}
CEqual::~CEqual() {}


CNon_Equal::CNon_Equal() : CExpression(NodeType::NT_EXPRESSION_NON_EQUAL) {}
CNon_Equal::~CNon_Equal() {}


CLogical_And::CLogical_And() : CExpression(NodeType::NT_EXPRESSION_LOGICAL_AND) {}
CLogical_And::~CLogical_And() {}


CLogical_Or::CLogical_Or() : CExpression(NodeType::NT_EXPRESSION_LOGICAL_OR) {}
CLogical_Or::~CLogical_Or() {}


CLogical_Not::CLogical_Not() : CExpression(NodeType::NT_EXPRESSION_LOGICAL_NOT) {}
CLogical_Not::~CLogical_Not() {}


CBitwise_And::CBitwise_And() : CExpression(NodeType::NT_EXPRESSION_BITWISE_AND) {}
CBitwise_And::~CBitwise_And() {}


CBitwise_Or::CBitwise_Or() : CExpression(NodeType::NT_EXPRESSION_BITWISE_OR) {}
CBitwise_Or::~CBitwise_Or() {}


CBitwise_Not::CBitwise_Not() : CExpression(NodeType::NT_EXPRESSION_BITWISE_NOT) {}
CBitwise_Not::~CBitwise_Not() {}


CBitwise_Xor::CBitwise_Xor() : CExpression(NodeType::NT_EXPRESSION_BITWISE_XOR) {}
CBitwise_Xor::~CBitwise_Xor() {}


CShift_Left::CShift_Left() : CExpression(NodeType::NT_EXPRESSION_SHIFT_LEFT) {}
CShift_Left::~CShift_Left() {}


CShift_Right::CShift_Right() : CExpression(NodeType::NT_EXPRESSION_SHIFT_RIGHT) {}
CShift_Right::~CShift_Right() {}


CAddition::CAddition() : CExpression(NodeType::NT_EXPRESSION_ADDITION) {}
CAddition::~CAddition() {}


CSubtraction::CSubtraction() : CExpression(NodeType::NT_EXPRESSION_SUBTRACTION) {}
CSubtraction::~CSubtraction() {}


CMultiplication::CMultiplication() : CExpression(NodeType::NT_EXPRESSION_MULTIPLICATION) {}
CMultiplication::~CMultiplication() {}


CDivision::CDivision() : CExpression(NodeType::NT_EXPRESSION_DIVISION) {}
CDivision::~CDivision() {}


CModulo::CModulo() : CExpression(NodeType::NT_EXPRESSION_MODULO) {}
CModulo::~CModulo() {}


CPostfix_Increment::CPostfix_Increment() : CExpression(NodeType::NT_EXPRESSION_POSTFIX_INCREMENT) {}
CPostfix_Increment::~CPostfix_Increment() {}


CPostfix_Decrement::CPostfix_Decrement() : CExpression(NodeType::NT_EXPRESSION_POSTFIX_INCREMENT) {}
CPostfix_Decrement::~CPostfix_Decrement() {}










//Down here we have the printers for the syntax tree

void CCalculator::Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent)
{
	list<STNode*>::iterator it;   //creating an iterator again... (to access the children of this node)


	if (parent == nullptr)    //if the node does not have a parent (ex. root symbol)
	{
		(*dotFile) << "digraph G{ \n";  //print the prologue

		for (it=m_children->begin() ; it!=m_children->end() ; it++)
		{
			(*it)->Visit_SyntaxTreePrinter(dotFile, this);  //retrospectively calling the same function to print the children of the current node
			
		}

		(*dotFile) << "}";   //print the epilogue

		dotFile->close();
	}
	else
	{
		STNode::Visit_SyntaxTreePrinter(dotFile, parent);
		
	}
	
}




//The overwritten methods for Visit_Eval() and Visit_GetArrayType() have been moved to their respective .cpp files

