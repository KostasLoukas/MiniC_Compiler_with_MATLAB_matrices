#pragma once
#include <list>
#include <string>
#include <fstream>



using namespace std;



typedef enum valueType
{
	VT_INT, VT_ARRAY
	
}ValueType;

class CArray;
typedef union actualVal
{
	int i;
	CArray* a;
	
}ActualVal;


typedef struct value
{
	ValueType type;
	ActualVal val;
	
}VALUE;



typedef enum nodeType
{
	NT_CALCULATOR, NT_STATEMENTS, NT_STATEMENT,
	NT_IF, NT_COMPOUND_STATEMENT, NT_STATEMENT_LIST, NT_WHILE, NT_BREAK,
	NT_ARRAY, NT_ELEMENTS, NT_ELEMENT, NT_ARRAY_ADDITION, NT_ARRAY_SUBTRACTION, NT_ARRAY_MULTIPLICATION, NT_ARRAY_ADDITION_WITH_VARIABLE, NT_ARRAY_SUBTRACTION_WITH_VARIABLE, NT_ARRAY_MULTIPLICATION_WITH_VARIABLE,
	NT_EXPRESSION_NUMBER, NT_EXPRESSION_IDENTIFIER,
	NT_EXPRESSION_ASSIGNMENT,
	NT_EXPRESSION_LOGICAL_AND, NT_EXPRESSION_LOGICAL_OR, NT_EXPRESSION_LOGICAL_NOT,
	NT_EXPRESSION_GREATER_THAN, NT_EXPRESSION_GREATER_THAN_EQUAL, NT_EXPRESSION_LESS_THAN, NT_EXPRESSION_LESS_THAN_EQUAL, NT_EXPRESSION_EQUAL, NT_EXPRESSION_NON_EQUAL,
	NT_EXPRESSION_BITWISE_AND, NT_EXPRESSION_BITWISE_OR, NT_EXPRESSION_BITWISE_NOT, NT_EXPRESSION_BITWISE_XOR,
	NT_EXPRESSION_SHIFT_LEFT, NT_EXPRESSION_SHIFT_RIGHT,
	NT_EXPRESSION_ADDITION, NT_EXPRESSION_SUBTRACTION,
	NT_EXPRESSION_MULTIPLICATION, NT_EXPRESSION_DIVISION, NT_EXPRESSION_MODULO,
	NT_EXPRESSION_POSTFIX_INCREMENT, NT_EXPRESSION_POSTFIX_DECREMENT

	
}NodeType;




class STNode
{
public:

	STNode(NodeType type);  //Constructor (initialization)
	virtual ~STNode();     //Destructor
	
	NodeType GetNodeType();
	string GetGraphvizLabel();
	STNode* GetChild(int index);
	STNode* GetParent(int index = 0);  //default value is 0
	
	void AddChild(STNode* node);   //Adds a new children node (adds it at the end of the list m_children)

	virtual void Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent);
	virtual void Visit_GetArrayType(STNode* parent);
	virtual VALUE Visit_Eval(STNode* parent);

protected:

	//For the break keyword
	static bool m_breakVisit;
	
	//Type of node
	NodeType m_nodeType;
	
	//Label of node in the graphviz generated file
	string m_graphvizLabel;
	
	//Serial number of the node (unique for each node)
	int m_serial;
	
	//Serial Counter (χρησιμοποιειται κυριως για να παραγεται ο επομενος καθε φορα serial number)
	static int m_serialCounter;
	
	//Children nodes list
	list<STNode*>* m_children;
	//Parent nodes list
	list<STNode*>* m_parents;   //(και οι δυο λιστες περιεχονται μεσα στο std και υπαρχουν στο namespace list)

	
};


extern STNode* g_root;