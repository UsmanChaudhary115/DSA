bool List::deleteNode(int element) // deletes first occurance 
{
	bool status = false;
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->getData() == element)
	{
		deleteFromHead();
		size--;
		status = true;
	}
	else
	{
		for (Node* temp = head; (temp != tail) && !status; temp = temp->getNext())
		{
			if (temp->getNext()->getData() == element)
			{
				Node* p = temp->getNext();
				temp->setNext(p->getNext());
				delete p;
				size--;
				p = nullptr;
				status = true;
			}
		}
	}
	return status;
} 