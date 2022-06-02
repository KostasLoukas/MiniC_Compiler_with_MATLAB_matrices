#pragma once
#include "STNode.h"





class CCalculator : public STNode
{
public:
	CCalculator();
	virtual ~CCalculator();

	void Visit_SyntaxTreePrinter(ofstream* dotFile, STNode* parent) override;  //specializing this method for the tree's root (prologue + epilogue + fileclose)
	
	
};


class CStatements : public STNode
{
public:
	CStatements();
	virtual ~CStatements();


};


class CStatement : public STNode
{
public:
	CStatement();
	virtual ~CStatement();

	VALUE Visit_Eval(STNode *parent) override;
};


class CIf : public STNode
{
public:
	CIf();
	virtual ~CIf();

	VALUE Visit_Eval(STNode *parent) override;
};


class CWhile : public STNode
{
public:
	CWhile();
	virtual ~CWhile();

	VALUE Visit_Eval(STNode *parent) override;
};


class CBreak : public STNode
{
public:
	CBreak();
	virtual ~CBreak();

	VALUE Visit_Eval(STNode *parent) override;
};


class CCompound_Statement : public STNode
{
public:
	CCompound_Statement();
	virtual ~CCompound_Statement();

	
};


class CStatement_List : public STNode
{
public:
	CStatement_List();
	virtual ~CStatement_List();

	
};



class CArray : public STNode
{
public:

	int* m_elements=nullptr;
	int m_length=0;
	bool m_is_inverted=false;
	int pushindex = 0;
	
	CArray();
	virtual ~CArray();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CElements : public STNode
{
public:
	CElements();
	virtual ~CElements();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CElement : public STNode
{
public:
	CElement();
	virtual ~CElement();

	VALUE Visit_Eval(STNode* parent) override;
	void Visit_GetArrayType(STNode* parent) override;

};

class CExpression : public STNode
{
public:
	explicit CExpression(NodeType type)
		: STNode(type){	}

	
};


class CNUMBER : public CExpression
{
public:

	int m_number;

	CNUMBER(char* text);
	virtual ~CNUMBER();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CIDENTIFIER : public CExpression
{
public:
	VALUE m_value;
	string m_name;  //the variable's name
	
	CIDENTIFIER(char* text);
	virtual ~CIDENTIFIER();

	VALUE Visit_Eval(STNode *parent) override;
};



class CAssignment : public CExpression
{
public:
	CAssignment();
	virtual ~CAssignment();

	VALUE Visit_Eval(STNode *parent) override;
};


class CLogical_And : public CExpression
{
public:
	CLogical_And();
	virtual ~CLogical_And();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CLogical_Or : public CExpression
{
public:
	CLogical_Or();
	virtual ~CLogical_Or();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CLogical_Not : public CExpression
{
public:
	CLogical_Not();
	virtual ~CLogical_Not();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CGreater_Than : public CExpression
{
public:
	CGreater_Than();
	virtual ~CGreater_Than();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CGreater_Than_Equal : public CExpression
{
public:
	CGreater_Than_Equal();
	virtual ~CGreater_Than_Equal();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CLess_Than : public CExpression
{
public:
	CLess_Than();
	virtual ~CLess_Than();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CLess_Than_Equal : public CExpression
{
public:
	CLess_Than_Equal();
	virtual ~CLess_Than_Equal();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CEqual : public CExpression
{
public:
	CEqual();
	virtual ~CEqual();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CNon_Equal : public CExpression
{
public:
	CNon_Equal();
	virtual ~CNon_Equal();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CBitwise_And : public CExpression
{
public:
	CBitwise_And();
	virtual ~CBitwise_And();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CBitwise_Or : public CExpression
{
public:
	CBitwise_Or();
	virtual ~CBitwise_Or();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CBitwise_Not : public CExpression
{
public:
	CBitwise_Not();
	virtual ~CBitwise_Not();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CBitwise_Xor : public CExpression
{
public:
	CBitwise_Xor();
	virtual ~CBitwise_Xor();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CShift_Left : public CExpression
{
public:
	CShift_Left();
	virtual ~CShift_Left();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CShift_Right : public CExpression
{
public:
	CShift_Right();
	virtual ~CShift_Right();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CAddition : public CExpression
{
public:
	CAddition();
	virtual ~CAddition();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CSubtraction : public CExpression
{
public:
	CSubtraction();
	virtual ~CSubtraction();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CMultiplication : public CExpression
{
public:
	CMultiplication();
	virtual ~CMultiplication();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CDivision : public CExpression
{
public:
	CDivision();
	virtual ~CDivision();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CModulo : public CExpression
{
public:
	CModulo();
	virtual ~CModulo();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};


class CPostfix_Increment : public CExpression
{
public:
	CPostfix_Increment();
	virtual ~CPostfix_Increment();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



class CPostfix_Decrement : public CExpression
{
public:
	CPostfix_Decrement();
	virtual ~CPostfix_Decrement();

	VALUE Visit_Eval(STNode *parent) override;
	void Visit_GetArrayType(STNode* parent) override;
};



