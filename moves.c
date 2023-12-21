#include"push_swap.h"

void swap(t_stacks *s, char *m)
{
	int i;

	i = 0;
	while(m[i])
	{
		if(m[i] == 'a')
			ft_switch(&s->a[0], &s->a[1]);
		if(m[i] == 'b')
			ft_switch(&s->b[0], &s->b[1]);
		i++;
	}
	ft_printf("s");
	if(i == 1)
	{
		ft_printf("%c\n", m[0]);
		s->moves++;
		return; 
	}
	ft_printf("s\n");
	s->moves++;
}

void rotate(t_stacks *s, char *m)
{
	int i;
	int j;
	
	i = 0;
	while(m[i])
	{
		if(m[i] == 'a')
		{
			j = 0;
			s->a[s->height_a] = s->a[0];
			while(j < s->height_a)
			{
				s->a[j] = s->a[j + 1];
				j++;
			}
		}
		if(m[i] == 'b')
		{  
			j = 0;
			s->b[s->height_b] = s->b[0];
			while(j < s->height_b - 1)
			{
				s->b[j] = s->b[j + 1];
				j++;
			}
		}
		i++;
	}
	ft_printf("r");
	if(i == 1)
	{
		ft_printf("%c\n", m[0]);
		s->moves++;
		return; 
	}
	ft_printf("r\n");
	s->moves++;
	
}

void reverse_rotate(t_stacks *s, char *m)
{
	int i;
	int j;
	int temp;
	
	i = 0;
	while(m[i])
	{
		if(m[i] == 'a')
		{
			j = s->height_a - 1;
			temp = s->a[s->height_a - 1];
			while(j > 0)
			{
				s->a[j] = s->a[j - 1];
				j--;
			}
			s->a[0] = temp;
		}
		if(m[i] == 'b')
		{  
			j = s->height_b - 1;
			temp = s->a[s->height_b - 1];
			while(j > 0)
			{
				s->b[j] = s->b[j - 1];
				j--;
			}
			s->b[0] = temp;
		}
		i++;
	}
	ft_printf("rr");
	if(i == 1)
	{
		ft_printf("%c\n", m[0]);
		s->moves++;
		return; 
	}
	ft_printf("r\n");
	s->moves++;
	
}
void push(t_stacks *s, char m)
{
	int i;

	if(m == 'a')
	{
		s->height_a--;
		s->height_b++;
		i = 1;
		s->b[0] = s->a[0];
		while(i < s->height_b)
		{
			s->b[i] = s->b[i + 1];
			i++;
		}
		i = 0;
		while(i < s->height_a)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
	}
	if(m == 'b')
	{
		s->height_a++;
		s->height_b--;
		i = 1;
		s->a[0] = s->b[0];
		while(i < s->height_a)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
		i = 0;
		while(i < s->height_b)
		{
			s->b[i] = s->b[i + 1];
			i++; 
		}
	}
	ft_printf("p%c\n", m);
	s->moves++;
}