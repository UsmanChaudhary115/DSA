#include"Double_List.h"
void shufflePlaylist(Double_List<int>& playlist)
{
	int count = 0;
	if (playlist.isEmpty())
	{
		cout << "Playlist is Empty!" << endl;
		return;
	}
	else
	{
		for (Node<int>* temp = playlist.getHead(); temp != nullptr; temp = temp->getNext())
		{
			count++;
		}
		if (count == 1)
		{
			cout << "List has only One Node" << endl;
			return;
		}
		else
		{
			Node<int>* temp = playlist.getHead();
			while (temp != nullptr)
			{
				if (temp->getNext() != nullptr)
				{
					int num = temp->getData();
					temp->setData(temp->getNext()->getData());
					temp->getNext()->setData(num);
					temp = temp->getNext()->getNext();
				}
				else
				{
					temp = nullptr;
				}
			}
			playlist.displayList();
		}
	}
	
}
void mergePlaylists(Double_List<int>& playlist1,Double_List<int>& playlist2)
{
	Double_List<int> result;
	if (playlist1.isEmpty() && playlist2.isEmpty())
	{
		cout << "Empty Lists!";
		exit(0);
	}
	else if (!playlist1.isEmpty() && playlist2.isEmpty())
	{
		for (Node<int>* temp = playlist1.getHead(); temp != nullptr; temp = temp->getNext())
		{
			result.addToTail(temp->getData());
		}

	}
	else if (playlist1.isEmpty() && !playlist2.isEmpty())
	{
		for (Node<int>* temp = playlist2.getHead(); temp != nullptr; temp = temp->getNext())
		{
			result.addToTail(temp->getData());
		}
	}
	else
	{
		for (Node<int>* temp = playlist1.getHead(); temp != nullptr; temp = temp->getNext())
		{
			result.addToTail(temp->getData());
		}
		for (Node<int>* temp = playlist2.getHead(); temp != nullptr; temp = temp->getNext())
		{
			result.addToTail(temp->getData());
		}
		for (Node<int>* temp = result.getHead(); temp != nullptr; temp = temp->getNext())
		{
			int lowNumber = temp->getData();
			for (Node<int>* temp2 = temp; temp2 != nullptr; temp2 = temp2->getNext())
			{
				if (lowNumber > temp2->getData())
				{
					lowNumber = temp2->getData();
					int number = temp->getData();
					temp->setData(lowNumber);
					temp2->setData(number);
				}
			}
		}
	}
	cout << endl;
	result.displayList();
	cout << endl;
}

void deleteNthSongFromEnd(Double_List<int>& playlist,int n)
{
	bool status;
	int count = 0;
	if (playlist.isEmpty())
	{
		cout << "Playlist is Empty!" << endl;
		status = false;
	}
	else
	{
		for (Node<int>* temp = playlist.getHead(); temp != nullptr; temp = temp->getNext())
		{
			count++;
		}
		if (count >= n)
		{
			status = true;
		}
		else
		{
			status = false;
		}
	}
	if (status && n != 0)
	{
		if (n == 1)
		{
			playlist.deleteFromHead();
		}
		else if (n == count)
		{
			playlist.deleteFromTail();
		}
		else
		{
			
			int tempCount = 1;
			for (Node<int>* temp = playlist.getHead(); temp != nullptr; tempCount++)
			{
				if (n == tempCount)
				{
					temp->getPrevious()->setNext(temp->getNext());
					temp->getNext()->setPrevious(temp->getPrevious());
					delete temp;
					temp = nullptr;
				}
				else
				{
					temp = temp->getNext();
				}
			}
		}
		cout << endl;
		playlist.displayList();
		cout << endl;
	}
	else
	{
		cout << "Out of Bound!" << endl;
	}
}
int main()
{
	Double_List<int> l;
	l.addToTail(3);
	l.addToTail(8);
	l.addToTail(9);
	l.addToTail(14);
	l.addToTail(15);
	l.displayList();
	cout << endl;
	Double_List<int> l2;
	l2.addToTail(1);
	l2.addToTail(5);
	l2.addToTail(17);
	l2.addToTail(20);
	//l2.displayList();
	//mergePlaylists(l, l2);
	shufflePlaylist(l);
	//l.deleteFromTail();
	//l.deleteFromHead();
	//l.deleteFromHead();

	//cout << endl;
	//l.displayList();
	//cout << endl;

	return 0;
}