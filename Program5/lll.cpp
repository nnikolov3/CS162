#include "lll.h"
// calling the class constructor
lll ::lll() 
{
	head = NULL ;
}


/* 
A young man was walking along in the forest, when he heard a muffled voice crying for help from behind a log. 
 He leaned over to see a frog sitting in the mud.

The frog looked up at him and said, "I'm actually a beautiful princess, and if you kiss me, 
I'll transform back into my true self, and be yours for eternity."

Silently, the man scooped up the frog and continued on his walk.

A minute or two later, the frog piped up again, "Hey, buddy, maybe you didn't hear me -- I said, if you kiss me, I'll turn into a princess. 
What are you waiting for?"

Annoyed, the man stuffed the frog into his coat pocket.

Shocked, the frog yelled from inside the man's pocket, "What the hell?  I'm a princess!  All you have to do is kiss me!"

Opening his pocket and peering in, the man said,
 "Listen -- I'm a software engineer.  I don't have time for a girlfriend.  But a talking frog is kind of cool."


*/



lll ::~lll() // calling the destructor 
{
delete head;
}

// insert function
void lll:: insert(char*park_name,char*park_location,char*park_description,char*park_fenced,char*park_size,char*park_rating)
 
{
	if (!head) 
	{
		head = new node;
		head -> data.insert(park_name,park_location,park_description,park_fenced,park_size,park_rating);
		head -> next = NULL;
		return ;
	}
	node*temp = new node;	
	temp -> data.insert(park_name,park_location,park_description,park_fenced,park_size,park_rating);
	if (strcmp ( temp -> data.getName() , head -> data.getName ()) < 0 ) // Index parks in alphabetical order 
		{
		
			temp -> next  = head ;
			head = temp ; 
			
			return ;
		}
	node*current = head ; 
	while (current -> next && strcmp(current -> next -> data.getName(), temp -> data.getName()) < 0 ) 
	{ 
		current = current -> next;	
	}
		temp -> next = current -> next ;
		current -> next = temp ; 
}
void lll:: display () // calling the display function 
{
	node*current = head; 
	while (current != NULL )
	{
	current -> data.disp();
	current =current -> next ;
	}
}

