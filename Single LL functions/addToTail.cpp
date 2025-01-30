void List::addToTail(int element)
{
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = new Node(element);
		size++;
		head = tail;
		return;
	}
	tail->setNext(new Node(element));  // Tail`s next pointer that was previously containing nullptr, now will receive the address of newly created Node having nullptr in its next pointer.
	size++;
	tail = tail->getNext(); // Tail will be moved to the newly added Node.
}