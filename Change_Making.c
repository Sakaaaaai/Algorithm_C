#include <stdio.h>


int main()
{
	int money;
	int coin[4] = {1, 5, 10, 25};
	int sum, tmp;
	int i;

	scanf("%d", &money);


	sum = 0;
	for(i = 0; i < 4; i++){
		if( (tmp = money / coin[3 - i]) ){
			sum += money / coin[3 - i];
			money %= coin[3 - i];
		}
	}


	printf("%d\n", sum);

	return 0;
}
