#include "STNode.h"



int STNode::m_serialCounter = 0;  //Initialization of m_serialCounter

STNode* g_root = nullptr;   //Initialization of root symbol

bool STNode::m_breakVisit = false;   //Initialization of break statement




const char* g_nodeTypeLabels[] = 
{	"CALCULATOR", "STATEMENTS", "STATEMENT",
	"IF", "COMPOUND_STATEMENT", "STATEMENT_LIST", "WHILE", "BREAK",
	"ARRAY", "ELEMENTS", "ELEMENT", "ARRAY_ADDITION", "ARRAY_SUBTRACTION", "ARRAY_MULTIPLICATION", "ARRAY_ADDITION_WITH_VARIABLE", "ARRAY_SUBTRACTION_WITH_VARIABLE", "ARRAY_MULTIPLICATION_WITH_VARIABLE",
	"NUMBER","IDENTIFIER",
	"ASSIGNMENT",
	"LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT",
	"GREATER_THAN", "GREATER_THAN_EQUAL", "LESS_THAN", "LESS_THAN_EQUAL", "EQUAL", "NON_EQUAL",
	"BITWISE_AND", "BITWISE_OR", "BITWISE_NOT", "BITWISE_XOR",
	"SHIFT_LEFT", "SHIFT_RIGHT",
	"ADDITION", "SUBTRACTION",
	"MULTIPLICATION", "DIVISION", "MODULO",
	"POSTFIX_INCREMENT", "POSTFIX_DECREMENT"};





STNode::STNode(NodeType type)   //Constructor (initialization)
{


	
	m_nodeType = type;

	m_serial = m_serialCounter++;   

	m_children = new list<STNode*>;
	m_parents = new list<STNode*>;

	m_graphvizLabel = _strdup(g_nodeTypeLabels[m_nodeType]);

	m_graphvizLabel.append("_" + std::to_string(m_serial));  //transforms the serial number into a string and attaches it to the graphviz label

	
}





STNode::~STNode()  //Destructor
{
	list<STNode*>::iterator it;  //creation of an iterator so that we can run through the children of the current node

	for (it=m_children->begin() ; it!=m_children->end() ; it++)
	{
		delete* it;
		
	}
	delete m_children;
	delete m_parents;   //we deleted all of the children and their parents
	
}






void STNode::AddChild(STNode *node)
{
	m_children->push_back(node);   //adding a child at the end of the list

	node->m_parents->push_back(this);   //telling the parents list that the current node is parent of this node (this = the one we added in the children list above)
	
}






STNode* STNode::GetChild(int index)
{
	list<STNode*>::iterator it = m_children->begin();  //we create an iterator to access the 'index' item of the list

	advance(it, index);  //we advance the iterator at the 'index' in order child

	return *it;
	
}






STNode* STNode::GetParent(int index)
{
	list<STNode*>::iterator it = m_parents->begin();  //we create an iterator to access the 'index' item of the list

	advance(it, index);  //we advance the iterator at the 'index' in order parent

	return *it;

}




void STNode::Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent)
{

	list<STNode*>::iterator it;   //we create another iterator to access the children of the current node

	
	(*dotFile) << "\"" << parent->GetGraphvizLabel() << "\"->\"" << GetGraphvizLabel() << "\";\n";  //firstly, we need to print the acne from the parent to the current node

	
	for (it=m_children->begin() ; it!=m_children->end() ; it++)
	{
		(*it)->Visit_SyntaxTreePrinter(dotFile, this);   //retrospectively calling the same method to print the whole graph (beginning from the leaves)
		
	}
	
}




void STNode::Visit_GetArrayType(STNode* parent)
{
	
	list <STNode*>::iterator it;
	
	for (it = m_children->begin(); it != m_children->end(); it++)
	{
		(*it)->Visit_GetArrayType(this);
	}
	
}

VALUE STNode::Visit_Eval(STNode* parent)
{
	
	list <STNode*>::iterator it;
	VALUE returnval;

	returnval.val.i = 0;

	for(it=m_children->begin() ; it!=m_children->end() ; it++)
	{
		(*it)->Visit_Eval(this);
	}

	return returnval;
}





NodeType STNode::GetNodeType()  //returns the type of the node
{
	return m_nodeType;
}




string STNode::GetGraphvizLabel()  //returns the label of the node
{
	return m_graphvizLabel;
}


