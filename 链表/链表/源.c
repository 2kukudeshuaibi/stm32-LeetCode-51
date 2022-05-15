#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
struct Tdate
{
	int date;
	struct Tdate* add;
};

int main()
{
	struct Tdate* list = NULL;
	struct Tdate* tail = NULL;
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int m = 0;
	int d = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		struct Tdate* pn = (struct Tdate*)malloc(sizeof(struct Tdate));
		pn->date = m;
		pn->add = NULL;

		if (list == NULL)
		{
			list = pn;
			tail = pn;
		}
		else
		{
			tail->add = pn;
			tail = pn;
		}
	}

	scanf("%d", &d);
	struct Tdate* cur = list;
	struct Tdate* prev = NULL;
	while (cur)
	{
		if (cur->date == d)
		{
			struct Tdate* pd = cur;
			if (cur == list)
			{
				list = list->add;
				cur = list;
			}
			else
			{
				prev->add = cur->add;
				cur = prev->add;
			}
			free(pd);
			n--;
		}
		else
		{
			prev = cur;
			cur = cur->add;
		}
	}

	printf("%d\n", n);
	cur = list;
	while (cur)
	{
		printf("%d ", cur->date);
		cur = cur->add;
	}
	cur = list;
	struct Tdate* del = NULL;
	while (cur)
	{
		del = cur;
		cur = cur->add;
		free(del);
	}
	list = NULL;

	return 0;
}