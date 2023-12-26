#include"push_swap.h"

void swap(t_stacks *s, char *m)
{
	int i;

	i = 0;
	if(s->height_a <= 1)	
	{	
		i++;	
		if(s->height_b <= 1)
			return;
	}
	while(m[i])
	{
		if(m[i] == 'a')
		{
			ft_switch(&s->a[0], &s->a[1]);
		}
		if(m[i] == 'b')
		{
			if(s->height_b <= 1)
				return;
			ft_switch(&s->b[0], &s->b[1]);
		}
		i++;
	}
	ft_printf("s");
	if(ft_strlen(m) == 1)
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
	int temp;

	i = 0;
	while(m[i])
	{
		if(m[i] == 'a')
		{
			if(s->height_a <=1)
				return;
			j = 0;
			temp = s->a[0];
			while(j < s->height_a)
			{
				s->a[j] = s->a[j + 1];
				j++;
			}
			s->a[j - 1] = temp;
		}
		if(m[i] == 'b')
		{  
			if(s->height_b <=1)
				return;
			j = 0;
			temp = s->b[0];
			while(j < s->height_b)
			{
				s->b[j] = s->b[j + 1];
				j++;
			}
			s->b[j - 1] = temp;

		}
		i++;
	}
	ft_printf("r");
	if(ft_strlen(m) == 1)
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
			if(s->height_a <= 1)
				return;
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
			if(s->height_b <= 1)
				return;
			j = s->height_b - 1;
			temp = s->b[s->height_b - 1];
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
		if(s->height_a < 1)
			return;
		s->height_a--;
		s->height_b++;
		i = s->height_b;
		while(i > 0)
		{
			s->b[i] = s->b[i - 1];
			i--;
		}
		s->b[0] = s->a[0];
		i = 0;
		while(i < s->height_a)
		{
			s->a[i] = s->a[i + 1];
			i++;
		}
		s->a[i] = 0;
	}
	if(m == 'b')
	{
		if(s->height_b < 1)
			return;
		s->height_a++;
		s->height_b--;
		i = s->height_a;
		while(i > 0)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
		s->a[0] = s->b[0];
		i = 0;
		while(i < s->height_b)
		{
			s->b[i] = s->b[i + 1];
			i++; 
		}
		s->b[i] = 0;
	}
	ft_printf("p%c\n", m);
	s->moves++;
}