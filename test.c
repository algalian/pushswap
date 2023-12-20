void *copy_right(void *dst, const void *src, int n) {
    unsigned int i;
    char *char_dst;
    const char *char_src;

    if (!dst || !src) {
        return 0;
    }

    char_src = (const char *)src;
    char_dst = (char *)dst;
    i = n;

    while (i > 0) {
        char_dst[i - 1] = char_src[i - 1];
        i--;
    }

    return dst;
}

void    *ft_memcpy(void *dst, const void *src, int n)
{
    unsigned int    i;
    char            *char_dst;
    const char        *char_src;

    if (!dst && !src)
    {
        return (0);
    }
    char_src = (char *) src;
    char_dst = (char *) dst;
    i = 0;
    while (i < n)
    {
        char_dst[i] = char_src[i];
        i++;
    }
    return (char_dst);
}

static void ft_quick_sort(int *a, int *b, int pivot, int size)
{
    int    i;
    int    j;
    int temp;
    int *l;
    int *r;

    i = 0;
    j = size/2;
    while(i < size/2)
    {
        if(a[i] > pivot)
        {
          while(a[j] > pivot)
            j++;  
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
          b[i]--;
          j++;
        }
        i++;
    }
    l = malloc(sizeof(int) * size/2);
    r = malloc(sizeof(int) * size/2);
    l = ft_memcpy(l, a, sizeof(int) * size/2);
    r = copy_right(r, a, sizeof(int) * size/2);
    ft_quick_sort(l, b, a[size/2], size/2);
    ft_quick_sort(r, b, a[size/2], size/2);
}

int main()
{
  int a[] = {8, 1, 2, 4, 5, 6, 7, 9};
  int b[] = {8, 8, 8, 8, 8, 8, 8, 8};
  ft_quick_sort(a,b, 5, 8);
}