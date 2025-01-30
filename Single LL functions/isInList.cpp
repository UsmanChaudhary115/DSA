bool List::isInList(int element) const
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return false;
	}
	for (Node* temp = head; temp != nullptr; temp = temp->getNext())		//Starting a temporary pointer from start of the list.
	{																		//Iterating until the end of the list.
		if (temp->getData() == element)										//If element found, return statement will terminate the loop.
		{
			return true;
		}
	}
	return false;															//If whole list traversed without encountering the key, this return statement will be executed.
}