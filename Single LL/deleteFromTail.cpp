int List::deleteFromTail()
{
	if (isEmpty())
	{
		return 0;
	}
	int a = tail->getData();		//Getting Data present at Tail
	Node* temp = head;				//Starting a temporary pointer from start of the list.
	while (temp->getNext() != tail) //Iterating until one before tail. Here, temp->getNext() will be pointing to the tail at the end.
	{
		temp = temp->getNext();
	}
	delete tail;					//Object pointed by Tail be deleted here.
	size--;
	tail = temp;					//Tail pointer receiving address of 2nd last object int the list which is now the last one.
	temp = nullptr;
	tail->setNext(nullptr);			//Setting next pointer of the last object to nullptr.
	return a;						//Returning deleted Object`s Data.
}