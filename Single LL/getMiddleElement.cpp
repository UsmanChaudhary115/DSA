int List::getMiddleElement() const
{
	Node* temp1 = head;
	Node* temp2 = head;
	while (temp2->getNext() != nullptr)
	{
		temp2 = temp2->getNext();
		if (temp2->getNext() != nullptr)
		{
			temp1 = temp1->getNext();
			temp2 = temp2->getNext();
		}
	}
	int data = temp1->getData();
	temp1 = nullptr;
	temp2 = nullptr;
	return data;
}