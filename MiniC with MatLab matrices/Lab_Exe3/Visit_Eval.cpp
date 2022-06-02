#include <iostream>
#include "SymbolNodes.h"


VALUE CStatement::Visit_Eval(STNode* parent)
{
	VALUE returnval, value;
	list <STNode*>::iterator it;
	



	if (m_children->size() != 0)
	{
		it = m_children->begin();

		value = (*it)->Visit_Eval(this);

		if (value.type == VT_INT)
		{
			cout << "Result: " << value.val.i << "\n";
		}
		else if (value.type == VT_ARRAY)
		{
			//Do nothing. The result has already been printed elsewhere
		}
	}


	returnval.type = VT_INT;
	returnval.val.i = 0;

	return returnval;
}

VALUE CIf::Visit_Eval(STNode* parent)
{
	VALUE value, returnval;

	switch (m_children->size())
	{
	case 2:
		value = GetChild(0)->Visit_Eval(this);
		if (value.val.i)
		{
			GetChild(1)->Visit_Eval(this);
		}
		break;
	case 3:
		value = GetChild(0)->Visit_Eval(this);
		if (value.val.i)
		{
			GetChild(1)->Visit_Eval(this);
		}
		else
		{
			GetChild(2)->Visit_Eval(this);
		}
		break;
	default:;
	}


	returnval.type = VT_INT;
	returnval.val.i = 0;

	return returnval;

}

VALUE CWhile::Visit_Eval(STNode* parent)
{
	VALUE value, returnval;

	value = GetChild(0)->Visit_Eval(this);
	while (value.val.i)
	{
		
		GetChild(1)->Visit_Eval(this);
		
		if (m_breakVisit)  //It's time to end
		{
			m_breakVisit = false;
			break;
		}
		else  //Load the next value of the condition's variable
		{
			value = GetChild(0)->Visit_Eval(this);
		}
		
	}


	returnval.type = VT_INT;
	returnval.val.i = 0;

	return returnval;

}

VALUE CBreak::Visit_Eval(STNode* parent)
{
	VALUE returnval;

	m_breakVisit = true;

	returnval.type = VT_INT;
	returnval.val.i = 0;

	return returnval;
}



VALUE CArray::Visit_Eval(STNode* parent)
{
	int i = 0;
	m_elements = new int[m_length];
	pushindex = 0;
	VALUE returnval;
	returnval.val.a = this;
	returnval.type = VT_ARRAY;
	
	
	STNode::Visit_Eval(this);
	
	/*
	printf("The Array is: [");
	for (i = 0; i < m_length; i++)
	{
		cout << m_elements[i] << ",";
	}
	cout << "\b]\n";
	*/


	return returnval;
}

VALUE CElements::Visit_Eval(STNode* parent)
{
	VALUE returnval ;	
	list <STNode*>::iterator it;

	for (it = m_children->begin(); it != m_children->end(); it++)
	{
		(*it)->Visit_Eval(parent);
	}
			
	returnval.val.i = 0;
	return returnval;
}

VALUE CElement::Visit_Eval(STNode* parent)
{
	VALUE returnval;
	CArray* arr = dynamic_cast<CArray *>(parent);
	
	returnval = GetChild(0)->Visit_Eval(parent);
	if ( returnval.type == VT_ARRAY )
	{
		cout << "ERROR! Nesting of arrays is not supported!";
		exit(1);
	}
	
	arr->m_elements[arr->pushindex] = returnval.val.i;
	arr->pushindex++;
	
	return returnval;
}


VALUE CNUMBER::Visit_Eval(STNode* parent)
{
	VALUE returnval;
	
	returnval.type = VT_INT;
	returnval.val.i = m_number;

	
	return returnval;
}

VALUE CIDENTIFIER::Visit_Eval(STNode* parent)
{

	return m_value;
}

VALUE CAssignment::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();
	int i = 0;

	CIDENTIFIER* id = dynamic_cast<CIDENTIFIER*>(*it);

	
	advance(it, 1);


	id->m_value = (*it)->Visit_Eval(this);


	if (id->m_value.type == VT_INT)
	{
		cout << id->m_name << "=" << id->m_value.val.i << "\n";
		
		return id->m_value;
	}
	else if (id->m_value.type == VT_ARRAY)
	{

		CArray* arr = dynamic_cast<CArray*>(id->m_value.val.a);	

		id->m_value.type = VT_ARRAY;

		
		for (i=0 ; i<arr->m_length ; i++)
		{
			id->m_value.val.a->m_elements[i] = arr->m_elements[i];
		}

		//Printing the assigned array
		cout << id->m_name << "=[";
		for (i = 0; i < arr->m_length; i++)
		{
			cout << id->m_value.val.a->m_elements[i] << ",";
		}
		cout << "\b]\n";

		
		return id->m_value;
	}
	
}

VALUE CGreater_Than::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i > value.val.i;

	return result;
}

VALUE CGreater_Than_Equal::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;


	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i >= value.val.i;

	return result;
}

VALUE CLess_Than::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i < value.val.i;

	return result;
}

VALUE CLess_Than_Equal::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i <= value.val.i;

	return result;
}

VALUE CEqual::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i == value.val.i;

	return result;
}

VALUE CNon_Equal::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i != value.val.i;

	return result;
}

VALUE CLogical_And::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i && value.val.i;

	return result;
}

VALUE CLogical_Or::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i || value.val.i;

	return result;
}

VALUE CLogical_Not::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	value = (*it)->Visit_Eval(this);
	result.val.i = !value.val.i;

	return result;
}

VALUE CBitwise_And::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i & value.val.i;

	return result;
}

VALUE CBitwise_Or::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i | value.val.i;

	return result;
}

VALUE CBitwise_Not::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	value = (*it)->Visit_Eval(this);
	result.val.i = ~value.val.i;

	return result;
}

VALUE CBitwise_Xor::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i ^ value.val.i;

	return result;
}

VALUE CShift_Left::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i << value.val.i;

	return result;
}

VALUE CShift_Right::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i >> value.val.i;

	return result;
}

VALUE CAddition::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE value1, value2, result;

	value1 = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value2 = (*it)->Visit_Eval(this);



	if (value1.type == VT_INT && value2.type == VT_INT)  //Integer with integer
	{
		result.val.i = value1.val.i + value2.val.i;

		
		result.type = VT_INT;

		return result;
	}
	else if (value1.type == VT_INT && value2.type == VT_ARRAY)  //Integer with array
	{
		int i = 0;

		
		cout << "Array Addition Result with Variable (array): ";
		for (i = 0 ; i < value2.val.a->m_length ; i++)
		{
			cout << value2.val.a->m_elements[i] + value1.val.i << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;
		
	}
	else if (value1.type == VT_ARRAY && value2.type == VT_INT)  //Array with integer
	{
		int i = 0;

		
		cout << "Array Addition Result with Variable (array): ";
		for (i = 0; i < value1.val.a->m_length; i++)
		{
			cout << value1.val.a->m_elements[i] + value2.val.i << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;

	}
	else if (value1.type == VT_ARRAY && value2.type == VT_ARRAY)   //Array with array
	{
		
		int i = 0;
		
		
		cout << "Array Addition Result (array): ";
		for (i = 0; i < value1.val.a->m_length ; i++)
		{
			cout << value1.val.a->m_elements[i] + value2.val.a->m_elements[i] << ",";
		}
		cout << "\b \n";
		

		result.type = VT_ARRAY;


		return result;

	}
	
}

VALUE CSubtraction::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE value1, value2, result;

	value1 = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value2 = (*it)->Visit_Eval(this);


	if (value1.type == VT_INT && value2.type == VT_INT)  //Integer with integer
	{
		result.val.i = value1.val.i - value2.val.i;


		result.type = VT_INT;

		return result;
	}
	else if (value1.type == VT_INT && value2.type == VT_ARRAY)  //Integer with array
	{
		int i = 0;


		cout << "Array Subtraction Result with Variable (array): ";
		for (i = 0; i < value2.val.a->m_length; i++)
		{
			cout << value2.val.a->m_elements[i] - value1.val.i << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;

	}
	else if (value1.type == VT_ARRAY && value2.type == VT_INT)  //Array with integer
	{
		int i = 0;


		cout << "Array Subtraction Result with Variable (array): ";
		for (i = 0; i < value1.val.a->m_length; i++)
		{
			cout << value1.val.a->m_elements[i] - value2.val.i << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;

	}
	else if (value1.type == VT_ARRAY && value2.type == VT_ARRAY)   //Array with array
	{

		int i = 0;


		cout << "Array Subtraction Result (array): ";
		for (i = 0; i < value1.val.a->m_length; i++)
		{
			cout << value1.val.a->m_elements[i] - value2.val.a->m_elements[i] << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;

	}
	
}

VALUE CMultiplication::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE value1, value2, result;

	value1 = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value2 = (*it)->Visit_Eval(this);
	

	if (value1.type == VT_INT && value2.type == VT_INT)  //Integer with integer
	{
		result.val.i = value1.val.i * value2.val.i;


		result.type = VT_INT;

		return result;
	}
	else if (value1.type == VT_INT && value2.type == VT_ARRAY)  //Integer with array
	{
		int i = 0;


		cout << "Array Multiplication Result with Variable (array): ";
		for (i = 0; i < value2.val.a->m_length; i++)
		{
			cout << value2.val.a->m_elements[i] * value1.val.i << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;

	}
	else if (value1.type == VT_ARRAY && value2.type == VT_INT)  //Array with integer
	{
		int i = 0;


		cout << "Array Multiplication Result with Variable (array): ";
		for (i = 0; i < value1.val.a->m_length; i++)
		{
			cout << value1.val.a->m_elements[i] * value2.val.i << ",";
		}
		cout << "\b \n";


		result.type = VT_ARRAY;


		return result;

	}
	else if (value1.type == VT_ARRAY && value2.type == VT_ARRAY)   //Array with array
	{

		int i = 0;
		int res = 0;

		
		for (i = 0; i < value1.val.a->m_length; i++)
		{
			res = res + (value1.val.a->m_elements[i] * value2.val.a->m_elements[i]);
		}
		cout << "Array Multiplication Result: " << res << "\n";


		result.type = VT_ARRAY;


		return result;

	}
	
}

VALUE CDivision::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);


	if (value.val.i != 0)
	{
		result.val.i = result.val.i / value.val.i;

		return result;
	}
	else
	{
		printf("Could not divide with zero!\n");
		exit(1);
	}

}

VALUE CModulo::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();   //we initialiaze the iterator to show at the first child
	VALUE result, value;

	result = (*it)->Visit_Eval(this);

	advance(it, 1);  //We move the iterator to show on the next child

	value = (*it)->Visit_Eval(this);
	result.val.i = result.val.i % value.val.i;

	return result;
}

VALUE CPostfix_Increment::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();
	VALUE result;

	result = (*it)->Visit_Eval(this);

	result.val.i++;

	return result;
}

VALUE CPostfix_Decrement::Visit_Eval(STNode* parent)
{
	list <STNode*>::iterator it = m_children->begin();
	VALUE result;

	result = (*it)->Visit_Eval(this);

	result.val.i--;

	return result;
}