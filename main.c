#include "linkstack.h"

int Priority(char ch)
{
	switch(ch)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	Stack *s_opt, *s_num;
	char opt[1024] = {0};
	int i = 0, tmp = 0, num1 = 0, num2 = 0;

	if(LinkStackInit(&s_opt) != SUCCESS || LinkStackInit(&s_num) != SUCCESS)
	{
		printf("Init Failure \n");
	}

	printf("Please input: \n");
	scanf("%s",opt);

	while(opt[i] != '\0' || LinkStackEmpty(s_opt) != TRUE)
	{
	if(opt[i] >= '0' && opt[i] <= '9')
	{
		tmp = tmp * 10 + opt[i] - '0';
		i++;
		if(opt[i] > '9' || opt[i] < '0')
		{
			Push(&s_num, tmp);
			tmp = 0;

		}	
	}
		else
		{
			if((opt[i] == ')') && (GetTop(s_opt) == '('))
			{
				Pop(&s_opt);
				i++;
				continue;
			}
			
			if((LinkStackEmpty(s_opt) == TRUE) || (Priority(opt[i]) > Priority(GetTop(s_opt))) ||
			  (	(GetTop(s_opt) == '(') && (opt[i] != ')')))
			{
				Push(&s_opt, opt[i]);
				i++;
				continue;
			}
	
			if( ((opt[i] == '\0') &&( LinkStackEmpty(s_opt) != TRUE)) || ( (opt[i] == ')') && (GetTop(s_opt) != '(') )||
				(Priority(opt[i]) <= Priority(GetTop(s_opt)))	)
			{
				switch(Pop(&s_opt))
				{
					case'+':
						num1 = Pop(&s_num);
						num2 = Pop(&s_num);
						Push(&s_num, (num2 + num1));
					break;	
					case'-':
						num1 = Pop(&s_num);
						num2 = Pop(&s_num);
						Push(&s_num, (num2 - num1));
					break;	
					case'*':
						num1 = Pop(&s_num);
						num2 = Pop(&s_num);
						Push(&s_num, (num2 * num1));
					break;	
					case'/':
						num1 = Pop(&s_num);
						num2 = Pop(&s_num);
						Push(&s_num, (num2 / num1));
					break;	
				}
			}	
		}
	}
	printf("%d \n",GetTop(s_num));
	return 0;


}