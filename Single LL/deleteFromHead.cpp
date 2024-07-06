int List::deleteFromHead()
{
	if (isEmpty())
	{
		return 0;
	}
	Node* temp = head->getNext();	// A temporary pointer getting address from the next pointer of an object currently pointed by head.
	int a = head->getData();		// Getting Data of an object currently pointed by head.
	delete head;					// Deleting object pointed by head.
	size--;
	head = temp;					// Head is receiving next object`s address using temporary pointer.
	temp = nullptr;					// Temporary pointer getting out of the race.
	if (head == nullptr)			// Checking if that was the only object in the list which we have deleted.
	{								// If yes, removing that memory`s address from tail too.
		tail = nullptr;
	}
	return a;
}