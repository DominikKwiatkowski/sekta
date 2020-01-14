// sekta.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
int main()
{
	int a;
	scanf_s("%d", &a);
	long long int ilosc, zabicie;
	for (int i = 0; i < a; i++)
	{
		scanf_s("%lld%lld", &ilosc, &zabicie);
		if (ilosc == 1)
			printf("1\n");
		else
		{
			if (zabicie < 0)
			{
				zabicie += 1 + ilosc;
			}
			long long int wejscie;
			long long int potega = 2;
			long long int najzyj = 1;
			long long int zabici = 0;
			for (;;)
			{
				if((ilosc & 1)==0)
				{
					ilosc >>= 1;
					if (zabicie <= zabici + ilosc)
					{
						wejscie = najzyj + potega/2 + (zabicie - zabici - 1)*potega;
						break;
					}
					else
					{
						zabici += ilosc;
						potega <<= 1;
					}
				}
				else
				{
					ilosc >>= 1;
					if (zabicie <= zabici + ilosc)
					{
						wejscie = najzyj + potega/2 +(zabicie - zabici - 1)*potega;
						break;
					}
					else if (zabicie == zabici + ilosc + 1)
					{
						wejscie = najzyj;
						break;
					}
					else
					{
						najzyj += potega;
						zabici += ilosc + 1;
						potega <<= 1;
					}
				}
				
			}
			printf("%lld\n", wejscie);
		}
	}
	return 0;
}

