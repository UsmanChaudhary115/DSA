void List::addToHead(int element)
{
	head = new Node(element, head);
	size++;
	//While new Node`s next pointer will receive current address hold by head. 
	//Head will point to the new Node.
	
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = head;
	}
}