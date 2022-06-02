#include "SymbolNodes.h"





void CArray::Visit_GetArrayType(STNode* parent)
{
	m_length = 0;

	STNode::Visit_GetArrayType(this);
	//printf("Array Size : %d\n", m_length);
}

void CElements::Visit_GetArrayType(STNode* parent)
{
	list <STNode*>::iterator it;

	for (it = m_children->begin(); it != m_children->end(); it++)
	{
		(*it)->Visit_GetArrayType(parent);
	}
}
void CElement::Visit_GetArrayType(STNode* parent)
{
	list <STNode*>::iterator it;

	for (it = m_children->begin(); it != m_children->end(); it++)
	{
		(*it)->Visit_GetArrayType(parent);
	}
}


void CNUMBER::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}

	
}

void CLogical_And::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CLogical_Or::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CLogical_Not::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CGreater_Than::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CGreater_Than_Equal::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CLess_Than::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CLess_Than_Equal::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CEqual::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CNon_Equal::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CBitwise_And::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CBitwise_Or::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CBitwise_Not::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CBitwise_Xor::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CShift_Left::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CShift_Right::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CAddition::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CSubtraction::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CMultiplication::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CDivision::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CModulo::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CPostfix_Increment::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}

void CPostfix_Decrement::Visit_GetArrayType(STNode* parent)
{
	CArray* arr = dynamic_cast<CArray*>(parent);

	if (arr != nullptr)
	{
		arr->m_length++;
	}


}
