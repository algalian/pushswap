#include"push_swap.h"

static void exec_move(t_stacks *s, int index)
{
	int *temp;
	int i;
	
	temp = s->b[index];
	i = 0;
	if(temp[3] == 1)
	{			
		while(s->b[0][0] != temp[0] && i < temp[1])
		{
			rotate(s, "ab");
			i++;
		}
		while(s->b[0][0] != temp[0])
		{
			rotate(s,"b");
		}
		while(i < temp[1])
		{
			rotate(s, "a");
			i++;
		}
		push(s,'a');
	}
	if(temp[3] == 2)
	{
		while(s->b[0][0] != temp[0])
		{
			rotate(s,"b");
		}
		while(i < s->height_a - temp[1])
		{
			reverse_rotate(s, "a");
			i++;
		}
		i++;
		push(s,'a');
	}
	if(temp[3] == 3)
	{
		while(s->b[0][0] != temp[0])
		{
			reverse_rotate(s, "b");
		}
		while(i < temp[1])
		{
			rotate(s, "a");
			i++;
		}
		push(s, 'a');
	}
	if(temp[3] == 4)
	{
		while(s->b[0][0] != temp[0] && i < s->height_a - temp[1])
		{
			reverse_rotate(s, "ab");
			i++;
		}
		while(s->b[0][0] != temp[0])
		{
			reverse_rotate(s, "b");
		}
		while(i < s->height_a - temp[1])
		{
			reverse_rotate(s,"a");
			i++;
		}
		push(s,'a');
	}
}