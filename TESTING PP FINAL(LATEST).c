//include library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

//const
#define randnum(min, max)  ((rand() % (int)(((max) + 1) - (min))) + (min))

//declare function prototype
int inputInvalid(int);
void foodsMenu(), drinksMenu(), comboMenu(), waffleMenu(), waffleClassicMenu(), wafflePremiumMenu(), popcornMenu(), cupcornMenu(), milkMenu(), teaMenu(), menuComboA(), menuComboB(), comboWaffle(int[]), comboCupcorn(int[]), comboTea(int[]), comboMilk(int[]), receiptFunction(float[], float, float), sort(int [], int , char [][50]);
float payment(float, float);

//declare global variable
int order;//for user input

//increment for each item
int food=0,drink=0,combo=0;
int waffle=0,wfClassic=0,wfPremium=0,popcorn=0,cupcorn=0,milkSeries=0,teaSeries=0;
int cocoDeluxe = 0, pandanKaya = 0, chickenFloss = 0, japaneseBBQ = 0, nyonyaKaya = 0;
int caramel = 0, blackSesame = 0, spicyCurry = 0, seaweed = 0;
int original = 0, cheezyMayo = 0, cheezyChili = 0, cheezyThai = 0;
int icedChocolate = 0, icedWhiteCoffee = 0, icedMilkTea = 0, icedLemonTea = 0, icedPeachTea = 0;
int comboA = 0, comboB = 0;
int pea = 0, mar = 0, cho = 0, blu = 0, straw = 0, ka = 0, peanutMargarine = 0, peanutChocolate = 0, peanutBlueberry = 0, peanutStrawberry = 0, peanutKaya = 0, margarineChocolate = 0, margarineBlueberry = 0, margarineStrawberry = 0, margarineKaya = 0, chocolateBlueberry = 0, chocolateStrawberry = 0, chocolateKaya = 0, blueberryStrawberry = 0, blueberryKaya = 0, strawberryKaya = 0;


//quantity and price for each item
int quantityItem[50], qtyCombo[50], qtyComboA[35], qtyComboB[35];
float priceItem[50], priceCombo[3], price[50], total;

int totalCategory1[3],totalCategory2[7],totalWC[6],totalWP[5],totalPopcorn[4],totalCupcorn[4],totalMilk[3],totalTea[2],totalCombo[2];

int main()
{
	int nextCus, nextItem;
	
	char nameC1 [3][50] ={"FOOD", "DRINK", "COMBO"};
	char nameC2 [7][50]={"WAFFLE","POPCORN","CUPCORN", "MILK SERIES","TEA SERIES","COMBO A","COMBO B"};
	char nameWfC[6][50]={"PEANUT","MARGARINE","CHOCOLATE", "BLUEBERRY","STRAWBERRY","KAYA"};
	char nameWfP[5][50]={"COCO DELUXE","PANDAN KAYA","CHICKEN FLOSS", "JAPANESE BBQ","NYONYA KAYA"};
	char namePopcorn[4][50]={"CARAMEL POPCORN","BLACK SESAME","SPICY CURRY", "SEAWEED"};
	char nameCupcorn[4][50]={"CUPCORN ORIGINAL","CUPCORN CHEEZY MAYO","CUPCORN CHEEZY CHILI", "CUPCORN CHEEZY THAI"};
	char nameMilk[3][50]={"ICED CHOCOLATE","ICED WHITE COFFEE","ICED MILK TEA"};
	char nameTea[2][50]={"ICED LEMON TEA","ICED PEACH TEA"};
	char nameCombo[2][50]={"COMBO A (CUPCORN+WAFFLE+TEA SERIES)","COMBO B (CUPCORN+WAFFLE+MILK SERIES)"};

	do
	{
		float totalPrice = 0, totalPayment = 0;

		for (int i = 0; i < 50; i++)
		{
			quantityItem[i]=0;
			priceItem[i]=0;
		}

		do
		{
			system("cls");
			printf("\n---- Welcome to Daily Fresh ----\n");
			printf("\n---------------------|---------|");
			printf("\n 	CATEGORY     |  CODE   |");
			printf("\n---------------------|---------|");
			printf("\n	FOODS        |    1    |");
			printf("\n	DRINKS       |    2    |");
			printf("\n	COMBO        |    3    |");
			printf("\n--------------------------------");
			
			printf("\nEnter category code : ");
			order = inputInvalid(3);

			switch (order)
			{
			case 1:
				foodsMenu();
				food++;
				break;
			case 2:
				drinksMenu();
				drink++;
				break;
			case 3:
				comboMenu();
				combo++;
				break;
			}

			// ask for another item?

			printf("\nWant to add another item? Yes(1) No(2): \n");
			nextItem = inputInvalid(2);

		} while (nextItem == 1);

		for (int count = 0; count < 50; count++)
		{
			if (priceItem[count] > 0)
				totalPrice += quantityItem[count] * priceItem[count];
		}

		system("cls");

		receiptFunction(priceItem, totalPrice, totalPayment);
		

		// ask for next cus
		nextCus = 0;

		printf("\nNext customer? Yes(1) No(2): ");
		nextCus = inputInvalid(2);
		
		totalCategory1[0]+=food;
		totalCategory1[1]+=drink;
		totalCategory1[2]+=combo;
		
		totalCategory2[0]+=waffle;
		totalCategory2[1]+=popcorn;
		totalCategory2[2]+=cupcorn;
		totalCategory2[3]+=milkSeries;
		totalCategory2[4]+=teaSeries;
		totalCategory2[5]+=comboA;
		totalCategory2[6]+=comboB;
		
		totalWC[0]+=pea;
		totalWC[1]+=mar;
		totalWC[2]+=cho;
		totalWC[3]+=blu;
		totalWC[4]+=straw;
		totalWC[5]+=ka;
		
		totalWP[0]+=cocoDeluxe;
		totalWP[1]+=pandanKaya;
		totalWP[2]+=chickenFloss;
		totalWP[3]+=japaneseBBQ;
		totalWP[4]+=nyonyaKaya;
		
		totalPopcorn[0]+=caramel;
		totalPopcorn[1]+=blackSesame;
		totalPopcorn[2]+=spicyCurry;
		totalPopcorn[3]+=seaweed;
		
		totalCupcorn[0]+=original;
		totalCupcorn[1]+=cheezyMayo;
		totalCupcorn[2]+=cheezyChili;
		totalCupcorn[3]+=cheezyThai;
		
		totalMilk[0]+=icedChocolate;
		totalMilk[1]+=icedWhiteCoffee;
		totalMilk[2]+=icedMilkTea;
		
		totalTea[0]+=icedLemonTea;
		totalTea[1]+=icedPeachTea;
		
		totalCombo[0]+=comboA;
		totalCombo[0]+=comboB;
		
		total += totalPrice;

	} while (nextCus == 1);
	system("cls");


	printf("************************************************************************************************************************\n");
	printf("                       RANKING\n                                          Quantity");
	
	printf("\nCategory 1:\n\n");
	sort(totalCategory1, 3, nameC1);
	
	printf("\nCategory 2:\n\n");
	sort(totalCategory2, 7, nameC2);
	
	printf("\nWaffle Classic:\n\n");
	sort(totalWC, 6, nameWfC);
	
	printf("\nWaffle Premium:\n\n");
	sort(totalWP, 5, nameWfP);
	
	printf("\nPopcorn:\n\n");
	sort(totalPopcorn, 4, namePopcorn);
	
	printf("\nCupcorn:\n\n");
	sort(totalCupcorn, 4, nameCupcorn);
	
	printf("\nMilk Series:\n\n");
	sort(totalMilk, 3, nameMilk);
	
	printf("\nTea Series:\n\n");
	sort(totalTea, 2, nameTea);
	
	printf("\nCombo:\n\n");
	sort(totalCombo, 2, nameCombo);
	
	

	printf("\n ====================================================================================================================");
	printf("\n                                                  SUMMARY");
	printf("\n ====================================================================================================================");
	printf("----------------------------------------------------------------------------------------------\n");
	printf("|    CATEGORY 1    |    CATEGORY 2     |        ITEM              |        SPREAD           |\n");
	printf("|------------------|-------------------|--------------------------|-------------------------|\n");
	printf("|    FOOD - %d      |    WAFFLE   - %d   | WAFFLE CLASSIC      - %d  |        PEANUT      - %d  |\n",food,waffle,wfClassic,pea);
	printf("|                  |                   |                          |       MARGARINE    - %d  |\n",mar);
	printf("|                  |                   |                          |       CHOCOLATE    - %d  |\n",cho);
	printf("|                  |                   |                          |       BLUEBERRY    - %d  |\n",blu);
	printf("|                  |                   |                          |       STRAWBERRY   - %d  |\n",straw);
	printf("|                  |                   |                          |         KAYA       - %d  |\n",ka);
	printf("|                  |                   |--------------------------|-------------------------|\n");	
	printf("|                  |                   | WAFFLE PREMIUM      - %d  |      COCO DELUXE   - %d  |\n",wfPremium,cocoDeluxe);
    printf("|                  |                   |                          |      PANDAN KAYA   - %d  |\n",pandanKaya);	
    printf("|                  |                   |                          |      CHICKEN FLOSS - %d  |\n",chickenFloss); 	
    printf("|                  |                   |                          |      JAPANESE BBQ  - %d  |\n",japaneseBBQ); 	
    printf("|                  |                   |                          |      NYONYA KAYA   - %d  |\n",nyonyaKaya); 
    printf("|                  |-------------------|--------------------------|-------------------------|\n");
	printf("|                  | POPCORN     - %d   | CARAMEL POPCORN     - %d  |                         |\n",popcorn,caramel);    
	printf("|                  |                   | BLACK SESAME        - %d  |                         |\n",blackSesame); 		
	printf("|                  |                   | SPICY CURRY         - %d  |                         |\n",spicyCurry); 	
	printf("|                  |                   | SEAWEED             - %d  |                         |\n",seaweed); 		
    printf("|                  |-------------------|--------------------------|-------------------------|\n");		
	printf("|                  | CUPCORN     - %d   | CUPCORN ORIGINAL    - %d  |                         |\n",cupcorn,original);   
	printf("|                  |                   | CUPCORN CHEEZY MAYO - %d  |                         |\n",cheezyMayo); 
	printf("|                  |                   | CUPCORN CHEEZY CHILI- %d  |                         |\n",cheezyChili); 
	printf("|                  |                   | CUPCORN CHEEZY THAI - %d  |                         |\n",cheezyThai); 	
	printf("|------------------|-------------------|--------------------------|-------------------------|\n");
	printf("|    DRINK - %d     | MILK SERIES - %d   | ICED CHOCOLATE      - %d  |                         |\n",drink,milkSeries,icedChocolate);	
    printf("|                  |                   | ICED WHITE COFFEE   - %d  |                         |\n",icedWhiteCoffee); 	
    printf("|                  |                   | ICED MILK TEA       - %d  |  	                    |\n",icedMilkTea); 	
	printf("|                  |-------------------|--------------------------|-------------------------|\n");				  	 	
	printf("|                  | TEA SERIES  - %d   | ICED LEMON TEA      - %d  |                         |\n",teaSeries,icedLemonTea);  
    printf("|                  |                   | ICED PEACH TEA      - %d  |                         |\n",icedPeachTea); 
	printf("|------------------|-------------------|--------------------------|-------------------------|\n");
	printf("|   COMBO - %d      | COMBO A     - %d   |                          |                         |\n",combo,comboA);
    printf("|                  |                   |                          |                         |\n"); 
    printf("|                  |-------------------|--------------------------|-------------------------|\n");		
	printf("|                  | COMBO B     - %d   |                          |                         |\n",comboB);
    printf("|                  |                   |                          |                         |\n"); 
    printf("---------------------------------------------------------------------------------------------\n");
	printf("\n =================================================================================================================");
	printf("\n =================================================================================================================");
	printf("\n Total           	                                              \t\t\t\t\t  %0.2f",total);
	printf("\n =================================================================================================================");
	printf("\n =================================================================================================================");

	return 0;
}
int inputInvalid(int numValid)
{
	int input, invalid;
	invalid = scanf("%d", &input);
	while (invalid == 0 || input<1 || input>numValid)
	{
		printf("\nInvalid input.Please enter the 1-%d: ", numValid);
		fflush(stdin);
		invalid = scanf("%d", &input);
	}
	return input;
}

void foodsMenu()
{
	system("cls");

	printf("\n----------------------|---------|---------|");
	printf("\n  	 FOOD         |  CODE   |PRICE(RM)|");
	printf("\n----------------------|---------|---------|");
	printf("\n	WAFFLE        |    1    |    -    |");
	printf("\n	POPCORN       |    2    |   6.50  |");
	printf("\n	CUPCORN       |    3    |    8    |");
	printf("\n-------------------------------------------");

	printf("\nEnter food code : ");
	order = inputInvalid(3);

	switch (order)
	{
	case 1:
		waffleMenu();
		waffle++;
		break;

	case 2:
		popcornMenu();
		popcorn++;
		break;

	case 3:
		cupcornMenu();
		cupcorn++;
		break;
	}
}
void drinksMenu()
{
	system("cls");

	printf("\n----------------------|---------|---------|");
	printf("\n  	 DRINK        |  CODE   |PRICE(RM)|");
	printf("\n----------------------|---------|---------|");
	printf("\n	MILK SERIES   |    1    |   5.50  |");
	printf("\n	TEA SERIES    |    2    |   4.50  |");
	printf("\n-------------------------------------------");

	printf("\nEnter drink code :");
	order = inputInvalid(2);

	switch (order)
	{
	case 1:
		milkMenu();
		milkSeries++;
		break;

	case 2:
		teaMenu();
		teaSeries++;
		break;
	}

}
void comboMenu()
{
	system("cls");

	printf("\n-------------------------------------|---------|---------|");
	printf("\n  	      COMBO                  |  CODE   |PRICE(RM)|");
	printf("\n-------------------------------------|---------|---------|");
	printf("\n  CUP CORN+WAFFLE+TEA SERIES  (A)    |    1    |   15.5  |");
	printf("\n  CUP CORN+WAFFLE+MILK SERIES (B)    |    2    |   15.5  |");
	printf("\n----------------------------------------------------------");

	printf("\nEnter combo code : ");
	order = inputInvalid(2);

	switch (order)
	{
	case 1:
		menuComboA();
		comboA++;
		break;

	case 2:
		menuComboB();
		comboB++;
		break;
	}
}
void waffleMenu()
{
	system("cls");
	printf("\n----------------------|---------|---------|");
	printf("\n  	WAFFLE        |  CODE   |PRICE(RM)|");
	printf("\n----------------------|---------|---------|");
	printf("\n  	CLASSIC       |   1     |    6    |");
	printf("\n  	PREMIUM       |   2     |    8    |");
	printf("\n-------------------------------------------");

	printf("\nEnter waffle code : ");
	order = inputInvalid(2);

	switch (order)
	{
	case 1:
		waffleClassicMenu();
		wfClassic++;
		break;

	case 2:
		wafflePremiumMenu();
		wfPremium++;
		break;
	}

}

void waffleClassicMenu()
{
	system("cls");

	int peanut = 0, margarine = 0, chocolate = 0, blueberry = 0, strawberry = 0, kaya = 0;//for looping increment to choose waffle classic	

	printf("\n----------------------|---------|");
	printf("\n  	SPREAD        |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n      PEANUT          |    1    |");
	printf("\n      MARGARINE	      |    2    |");
	printf("\n      CHOCOLATE	      |    3    |");
	printf("\n      BLUEBERRY	      |    4    |");
	printf("\n      STRAWBERRY      |    5    |");
	printf("\n      KAYA	      |    6    |");
	printf("\n---------------------------------");
	
	printf("\nChoose any two different spread or any two same spread.\n");
	
	for (int a = 1; a <= 2; a++)
	{

		printf("\nEnter spread code %d: ",a);
		order = inputInvalid(6);

		switch (order)
		{
			case 1:
				peanut++;
				pea++;
				break;
	
			case 2:
				margarine++;
				mar++;
				break;
	
			case 3:
				chocolate++;
				cho++;
				break;
	
			case 4:
				blueberry++;
				blu++;
				break;
	
			case 5:
				strawberry++;
				straw++;
				break;
	
			case 6:
				kaya++;
				ka++;
				break;
		}
	}

	if (peanut == 2)
	{
		priceItem[0] = 6;
		quantityItem[0] += 1;
	}

	if (margarine == 2)
	{
		priceItem[1] = 6;
		quantityItem[1] += 1;
	}

	if (chocolate == 2)
	{
		priceItem[2] = 6;
		quantityItem[2] += 1;
	}

	if (blueberry == 2)
	{
		priceItem[3] = 6;
		quantityItem[3] += 1;
	}
	if (strawberry == 2)
	{
		priceItem[4] = 6;
		quantityItem[4] += 1;
	}

	if (kaya == 2)
	{
		priceItem[5] = 6;
		quantityItem[5] += 1;
	}

	if (peanut > 0 && margarine > 0 && peanut < 2 && margarine < 2)
	{
		priceItem[6] = 6;
		quantityItem[6] += 1;
	}

	if (peanut > 0 && chocolate > 0 && peanut < 2 && chocolate < 2)
	{
		priceItem[7] = 6;
		quantityItem[7] += 1;
	}

	if (peanut > 0 && blueberry > 0 && peanut < 2 && blueberry < 2)
	{
		priceItem[8] = 6;
		quantityItem[8] += 1;
	}

	if (peanut > 0 && strawberry > 0 && peanut < 2 && strawberry < 2)
	{
		priceItem[9] = 6;
		quantityItem[9] += 1;
	}

	if (peanut > 0 && kaya > 0 && peanut < 2 && kaya < 2)
	{
		priceItem[10] = 6;
		quantityItem[10] += 1;
	}

	if (chocolate > 0 && margarine > 0 && chocolate < 2 && margarine < 2)
	{
		priceItem[11] = 6;
		quantityItem[11] += 1;
	}

	if (blueberry > 0 && margarine > 0 && blueberry < 2 && margarine < 2)
	{
		priceItem[12] = 6;
		quantityItem[12] += 1;
	}

	if (strawberry > 0 && margarine > 0 && strawberry < 2 && margarine < 2)
	{
		priceItem[13] = 6;
		quantityItem[13] += 1;
	}

	if (kaya > 0 && margarine > 0 && kaya < 2 && margarine < 2)
	{
		priceItem[14] = 6;
		quantityItem[14] += 1;
	}

	if (chocolate > 0 && blueberry > 0 && chocolate < 2 && blueberry < 2)
	{
		priceItem[15] = 6;
		quantityItem[15] += 1;
	}

	if (chocolate > 0 && strawberry > 0 && chocolate < 2 && strawberry < 2)
	{
		priceItem[16] = 6;
		quantityItem[16] += 1;
	}

	if (chocolate > 0 && kaya > 0 && chocolate < 2 && kaya < 2)
	{
		priceItem[17] = 6;
		quantityItem[17] += 1;
	}

	if (blueberry > 0 && strawberry > 0 && blueberry < 2 && strawberry < 2)
	{
		priceItem[18] = 6;
		quantityItem[18] += 1;
	}

	if (blueberry > 0 && kaya > 0 && blueberry < 2 && kaya < 2)
	{
		priceItem[19] = 6;
		quantityItem[19] += 1;
	}

	if (strawberry > 0 && kaya > 0 && strawberry < 2 && kaya < 2)
	{
		priceItem[20] = 6;
		quantityItem[20] += 1;
	}

}
void wafflePremiumMenu()
{
	system("cls");

	printf("\n----------------------|---------|");
	printf("\n  	SPREAD        |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n      COCO DELUXE     |    1    |");
	printf("\n      PANDAN KAYA     |    2    |");
	printf("\n      CHICKEN FLOSS   |    3    |");
	printf("\n      JAPANESE BBQ    |    4    |");
	printf("\n      NYONYA KAYA     |    5    |");
	printf("\n---------------------------------");

	printf("\nEnter spread code : ");
	order = inputInvalid(5);


	switch (order) {
	case 1:
		cocoDeluxe++;
		priceItem[21] = 8;
		quantityItem[21] += 1;
		break;
	case 2:
		pandanKaya++;
		priceItem[22] = 8;
		quantityItem[22] += 1;
		break;
	case 3:
		chickenFloss++;
		priceItem[23] = 8;
		quantityItem[23] += 1;
		break;
	case 4:
		japaneseBBQ++;
		priceItem[24] = 8;
		quantityItem[24] += 1;
		break;
	case 5:
		nyonyaKaya++;
		priceItem[25] = 8;
		quantityItem[25] += 1;
		break;
	}
}
void popcornMenu()
{
	system("cls");

	printf("\n----------------------|---------|");
	printf("\n  	POPCORN       |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n    CARAMEL           |    1    |");
	printf("\n    BLACK SESAME      |    2    |");
	printf("\n    SPICY CURRY       |    3    |");
	printf("\n    SEAWEED           |    4    |");
	printf("\n---------------------------------");

	printf("\nEnter popcorn code: ");
	order = inputInvalid(4);

	switch (order)
	{
	case 1:
		caramel++;
		priceItem[26] = 6.5;
		quantityItem[26] += 1;
		break;

	case 2:
		blackSesame++;
		priceItem[27] = 6.5;
		quantityItem[27] += 1;
		break;

	case 3:
		spicyCurry++;
		priceItem[28] = 6.5;
		quantityItem[28] += 1;
		break;

	case 4:
		seaweed++;
		priceItem[29] = 6.5;
		quantityItem[29] += 1;
		break;
	}

}
void cupcornMenu()
{
	system("cls");

	printf("\n----------------------------------------|---------|");
	printf("\n  			CUPPCORN        |  CODE   |");
	printf("\n----------------------------------------|---------|");
	printf("\n  	CUPCORN ORIGINAL    	        |    1    |");
	printf("\n    	CUPCORN CHEEZY MAYO 	        |    2    |");
	printf("\n    	CUPCORN CHEEZY CHILI	        |    3    |");
	printf("\n    	CUPCORN CHEEZY THAI	        |    4    |");
	printf("\n---------------------------------------------------");
	printf("\nEnter cupcorn code : ");
	order = inputInvalid(4);

	switch (order)
	{
	case 1:
		original++;
		priceItem[30] = 8;
		quantityItem[30] += 1;
		break;

	case 2:
		cheezyMayo++;
		priceItem[31] = 8;
		quantityItem[31] += 1;
		break;

	case 3:
		cheezyChili++;
		priceItem[32] = 8;
		quantityItem[32] += 1;
		break;

	case 4:
		cheezyThai++;
		priceItem[33] = 8;
		quantityItem[33] += 1;
		break;
	}
}
void milkMenu()
{
	system("cls");

	printf("\n----------------------|---------|");
	printf("\n    MILK SERIES       |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n   ICED CHOCCOLATE    |    1    |");
	printf("\n   ICED WHITE COFFEE  |    2    |");
	printf("\n   ICED MILK TEA      |    3    |");
	printf("\n---------------------------------");

	printf("\n\nEnter milk series code: ");
	order = inputInvalid(3);

	switch (order)
	{
	case 1:
		icedChocolate++;
		priceItem[34] = 5.5;
		quantityItem[34] += 1;
		break;

	case 2:
		icedWhiteCoffee++;
		priceItem[35] = 5.5;
		quantityItem[35] += 1;
		break;

	case 3:
		icedMilkTea++;
		priceItem[36] = 5.5;
		quantityItem[36] += 1;
		break;
	}
}
void teaMenu()
{
	system("cls");

	printf("\n----------------------|---------|");
	printf("\n    TEA SERIES        |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n   ICED  LEMON TEA    |    1    |");
	printf("\n   ICED PEACH TEA     |    2    |");
	printf("\n---------------------------------");

	printf("\nEnter tea series code : ");
	order = inputInvalid(2);


	switch (order)
	{
	case 1:
		icedLemonTea++;
		priceItem[37] = 4.5;
		quantityItem[37] += 1;
		break;

	case 2:
		icedPeachTea++;
		priceItem[38] = 4.5;
		quantityItem[38] += 1;
		break;
	}
}
void menuComboA()
{
	priceItem[39] = 15.5;
	quantityItem[39] += 1;

	comboWaffle(qtyComboA);
	comboCupcorn(qtyComboA);
	comboTea(qtyComboA);
}
void menuComboB()
{
	priceItem[40] = 15.5;
	quantityItem[40] += 1;

	comboWaffle(qtyComboB);
	comboCupcorn(qtyComboB);
	comboMilk(qtyComboB);
}

void comboWaffle(int quantityCombo[])
{
	system("cls");

	waffle++;
	
	printf("\n----------------------|---------|");
	printf("\n  	WAFFLE        |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n  	CLASSIC       |   1     |");
	printf("\n  	PREMIUM       |   2     |");
	printf("\n---------------------------------");

	printf("\nEnter waffle code : ");
	order = inputInvalid(2);

	if (order == 1)
	{
		system("cls");
		wfClassic++;
		
		int peanut = 0, margarine = 0, chocolate = 0, blueberry = 0, strawberry = 0, kaya = 0;//for looping increment to choose waffle classic	
		int classic;

		printf("\n----------------------|---------|");
		printf("\n  	SPREAD        |  CODE   |");
		printf("\n----------------------|---------|");
		printf("\n      PEANUT          |    1    |");
		printf("\n      MARGARINE	      |    2    |");
		printf("\n      CHOCOLATE	      |    3    |");
		printf("\n      BLUEBERRY	      |    4    |");
		printf("\n      STRAWBERRY      |    5    |");
		printf("\n      KAYA	      |    6    |");
		printf("\n---------------------------------");

		printf("\nChoose any two different spread or any two same spread.\n");
		
		for (int a = 1; a <= 2; a++)
		{

			printf("\nEnter spread code %d: ",a);
			classic = inputInvalid(6);

			switch (classic)
			{
				case 1:
					peanut++;
					pea++;
					break;
	
				case 2:
					margarine++;
					mar++;
					break;
	
				case 3:
					chocolate++;
					cho++;
					break;
	
				case 4:
					blueberry++;
					blu++;
					break;
	
				case 5:
					strawberry++;
					straw++;
					break;
	
				case 6:
					kaya++;
					ka++;
					break;
			}
		}

		if (peanut == 2)
		{
			quantityCombo[0] += 1;
		}

		if (margarine == 2)
		{
			quantityCombo[1] += 1;
		}

		if (chocolate == 2)
		{
			quantityCombo[2] += 1;
		}

		if (blueberry == 2)
		{
			quantityCombo[3] += 1;
		}
		if (strawberry == 2)
		{
			quantityCombo[4] += 1;
		}

		if (kaya == 2)
		{
			quantityCombo[5] += 1;
		}

		if (peanut > 0 && margarine > 0 && peanut < 2 && margarine < 2)
		{
			quantityCombo[6] += 1;
		}

		if (peanut > 0 && chocolate > 0 && peanut < 2 && chocolate < 2)
		{
			quantityCombo[7] += 1;
		}

		if (peanut > 0 && blueberry > 0 && peanut < 2 && blueberry < 2)
		{
			quantityCombo[8] += 1;
		}

		if (peanut > 0 && strawberry > 0 && peanut < 2 && strawberry < 2)
		{
			quantityCombo[9] += 1;
		}

		if (peanut > 0 && kaya > 0 && peanut < 2 && kaya < 2)
		{
			quantityCombo[10] += 1;
		}

		if (chocolate > 0 && margarine > 0 && chocolate < 2 && margarine < 2)
		{
			quantityCombo[11] += 1;
		}

		if (blueberry > 0 && margarine > 0 && blueberry < 2 && margarine < 2)
		{
			quantityCombo[12] += 1;
		}

		if (strawberry > 0 && margarine > 0 && strawberry < 2 && margarine < 2)
		{
			quantityCombo[13] += 1;
		}

		if (kaya > 0 && margarine > 0 && kaya < 2 && margarine < 2)
		{
			quantityCombo[14] += 1;
		}

		if (chocolate > 0 && blueberry > 0 && chocolate < 2 && blueberry < 2)
		{
			quantityCombo[15] += 1;
		}

		if (chocolate > 0 && strawberry > 0 && chocolate < 2 && strawberry < 2)
		{
			quantityCombo[16] += 1;
		}

		if (chocolate > 0 && kaya > 0 && chocolate < 2 && kaya < 2)
		{
			quantityCombo[17] += 1;
		}

		if (blueberry > 0 && strawberry > 0 && blueberry < 2 && strawberry < 2)
		{
			quantityCombo[18] += 1;
		}

		if (blueberry > 0 && kaya > 0 && blueberry < 2 && kaya < 2)
		{
			quantityCombo[19] += 1;
		}

		if (strawberry > 0 && kaya > 0 && strawberry < 2 && kaya < 2)
		{
			quantityCombo[20] += 1;
		}
	}

	if (order == 2)
	{
		system("cls");
		wfPremium++;
		
		int premium;

		printf("\n----------------------|---------|");
		printf("\n  	SPREAD        |  CODE   |");
		printf("\n----------------------|---------|");
		printf("\n      COCO DELUXE     |    1    |");
		printf("\n      PANDAN KAYA     |    2    |");
		printf("\n      CHICKEN FLOSS   |    3    |");
		printf("\n      JAPANESE BBQ    |    4    |");
		printf("\n      NYONYA KAYA     |    5    |");
		printf("\n---------------------------------");

		printf("\nEnter spread code : ");
		premium = inputInvalid(5);


		switch (premium)
		{
		case 1:
			cocoDeluxe++;
			quantityCombo[21] += 1;
			break;

		case 2:
			pandanKaya++;
			quantityCombo[22] += 1;
			break;

		case 3:
			chickenFloss++;
			quantityCombo[23] += 1;
			break;

		case 4:
			japaneseBBQ++;
			quantityCombo[24] += 1;
			break;

		case 5:
			nyonyaKaya++;
			quantityCombo[25] += 1;
			break;
		}
	}

}
void comboCupcorn(int quantityCombo[])
{
	system("cls");
	cupcorn++;
	
	printf("\n----------------------------------------|---------|");
	printf("\n  			CUPPCORN        |  CODE   |");
	printf("\n----------------------------------------|---------|");
	printf("\n  	CUPCORN ORIGINAL    	        |    1    |");
	printf("\n    	CUPCORN CHEEZY MAYO 	        |    2    |");
	printf("\n    	CUPCORN CHEEZY CHILI	        |    3    |");
	printf("\n    	CUPCORN CHEEZY THAI	        |    4    |");
	printf("\n---------------------------------------------------");
	printf("\nEnter cupcorn code : ");
	order = inputInvalid(4);

	switch (order)
	{
	case 1:
		original++;
		quantityCombo[26] += 1;
		break;

	case 2:
		cheezyMayo++;
		quantityCombo[27] += 1;
		break;

	case 3:
		cheezyChili++;
		quantityCombo[28] += 1;
		break;

	case 4:
		cheezyThai++;
		quantityCombo[29] += 1;
		break;
	}
}
void comboTea(int quantityCombo[])
{
	system("cls");
	
	teaSeries++;

	printf("\n----------------------|---------|");
	printf("\n    TEA SERIES        |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n   ICED  LEMON TEA    |    1    |");
	printf("\n   ICED PEACH TEA     |    2    |");
	printf("\n---------------------------------");

	printf("\nEnter tea series code : ");
	order = inputInvalid(2);

	switch (order)
	{
	case 1:
		icedLemonTea++;
		quantityCombo[30] += 1;
		break;

	case 2:
		icedPeachTea++;
		quantityCombo[31] += 1;
		break;
	}
}
void comboMilk(int quantityCombo[])
{
	system("cls");
	
	milkSeries++;
	
	printf("\n----------------------|---------|");
	printf("\n    MILK SERIES       |  CODE   |");
	printf("\n----------------------|---------|");
	printf("\n   ICED CHOCCOLATE    |    1    |");
	printf("\n   ICED WHITE COFFEE  |    2    |");
	printf("\n   ICED MILK TEA      |    3    |");
	printf("\n---------------------------------");

	printf("\nEnter milk series code: ");
	order = inputInvalid(3);


	switch (order)
	{
	case 1:
		icedChocolate++;
		quantityCombo[30] += 1;
		break;

	case 2:
		icedChocolate++;
		quantityCombo[31] += 1;
		break;

	case 3:
		icedMilkTea++;
		quantityCombo[32] += 1;
		break;
	}
}

void receiptFunction(float priceItem[], float totalPrice, float totalPay)
{

	char itemName[50][50] = { "Waffle Classic - (Peanut)                 ","Waffle Classic - (Margarine)              ","Waffle Classic - (Chocolate)              ","Waffle Classic - (Blueberry)              ","Waffle Classic - (Strawberry)             ","Waffle Classic - (Kaya)                   ","Waffle Classic - (Peanut + Margarine)     ","Waffle Classic - (Peanut + Chocolate)     ","Waffle Classic - (Peanut + Blueberry)     ","Waffle Classic - (Peanut + Strawberry)   ","Waffle Classic - (Peanut + Kaya)          ","Waffle Classic - (Margarine + Chocolate) ","Waffle Classic - (Margarine + Blueberry) ","Waffle Classic - (Margarine + Strawberry)","Waffle Classic - (Margarine + Kaya)      ","Waffle Classic - (Chocolate + Blueberry) ","Waffle Classic - (Chocolate + Strawberry)","Waffle Classic - (Chocolate + Kaya)      ","Waffle Classic - (Blueberry + Strawberry)","Waffle Classic - (Blueberry + Kaya)      ","Waffle Classic - (Strawberry + Kaya)     ","Waffle Premium - (Coco Deluxe)            ","Waffle Premium - (Pandan Kaya)            ","Waffle Premium - (Chicken Floss)          ","Waffle Premium - (Japanese BBQ)           ","Waffle Premium - (Nyonya Kaya)            ","Popcorn - (Caramel)                       ","Popcorn - (Black Sesame)                  ","Popcorn - (Spicy Curry)                   ","Popcorn - (Seaweed)                       ","Cupcorn - (Original)                      ","Cupcorn - (Cheezy Mayo)                   ","Cupcorn - (Cheezy Chili)                  ","Cupcorn - (Cheezy Thai)                   ","Milk - (Iced Chocolate)                   ","Milk - (Iced White Coffee)                ","Milk - (Iced Milk Tea)                    ","Tea - (Iced Lemon Tea)                    ","Tea - (Iced Peach Tea)                    ","Combo A                                   ","Combo B                                   " };
	char nameComboA[35][50] = { "Waffle Classic - (Peanut)","Waffle Classic - (Margarine)","Waffle Classic - (Chocolate)","Waffle Classic - (Blueberry)","Waffle Classic - (Strawberry)","Waffle Classic - (Kaya)","Waffle Classic - (Peanut + Margarine)","Waffle Classic - (Peanut + Chocolate)","Waffle Classic - (Peanut + Blueberry)","Waffle Classic - (Peanut + Strawberry)","Waffle Classic - (Peanut + Kaya)","Waffle Classic - (Margarine + Chocolate)","Waffle Classic - (Margarine + Blueberry)","Waffle Classic - (Margarine + Strawberry)","Waffle Classic - (Margarine + Kaya)","Waffle Classic - (Chocolate + Blueberry)","Waffle Classic - (Chocolate + Strawberry)","Waffle Classic - (Chocolate + Kaya)","Waffle Classic - (Blueberry + Strawberry)","Waffle Classic - (Blueberry + Kaya)","Waffle Classic - (Strawberry + Kaya)","Waffle Premium - (Coco Deluxe)","Waffle Premium - (Pandan Kaya)","Waffle Premium - (Chicken Floss)","Waffle Premium - (Japanese BBQ)","Waffle Premium - (Nyonya Kaya)","Cupcorn - (Original)","Cupcorn - (Cheezy Mayo)","Cupcorn - (Cheezy Chili)","Cupcorn - (Cheezy Thai)","Tea - (Iced Lemon Tea)","Tea - (Iced Peach Tea)" };
	char nameComboB[35][50] = { "Waffle Classic - (Peanut)","Waffle Classic - (Margarine)","Waffle Classic - (Chocolate)","Waffle Classic - (Blueberry)","Waffle Classic - (Strawberry)","Waffle Classic - (Kaya)","Waffle Classic - (Peanut + Margarine)","Waffle Classic - (Peanut + Chocolate)","Waffle Classic - (Peanut + Blueberry)","Waffle Classic - (Peanut + Strawberry)","Waffle Classic - (Peanut + Kaya)","Waffle Classic - (Margarine + Chocolate)","Waffle Classic - (Margarine + Blueberry)","Waffle Classic - (Margarine + Strawberry)","Waffle Classic - (Margarine + Kaya)","Waffle Classic - (Chocolate + Blueberry)","Waffle Classic - (Chocolate + Strawberry)","Waffle Classic - (Chocolate + Kaya)","Waffle Classic - (Blueberry + Strawberry)","Waffle Classic - (Blueberry + Kaya)","Waffle Classic - (Strawberry + Kaya)","Waffle Premium - (Coco Deluxe)","Waffle Premium - (Pandan Kaya)","Waffle Premium - (Chicken Floss)","Waffle Premium - (Japanese BBQ)","Waffle Premium - (Nyonya Kaya)","Cupcorn - (Original)","Cupcorn - (Cheezy Mayo)","Cupcorn - (Cheezy Chili)","Cupcorn - (Cheezy Thai)","Milk - (Iced Chocolate)","Milk - (Iced White Coffee)","Milk - (Iced Milk Tea)" };
	int validation;
	int qty = 0;//total quantity

	srand(time(NULL));
	time_t currentTime;
	time(&currentTime);
	int  i;
	char nameCash[3][30];

	int change;

	system("cls");
	printf("\nTotal price include with tax : RM %.2f\t\n", totalPrice + 0.06*totalPrice);
	printf("\nEnter amount of payment : RM ");
	validation = scanf("%f", &totalPay);
	fflush(stdin);

	do
	{
		if (validation < 1 || totalPay < totalPrice)
		{
			printf("\nInsufficient amount or invalid input, please pay : RM %0.2f\n", totalPrice + 0.06*totalPrice);
			printf("\nEnter amount of payment : RM ");
			validation = scanf("%f", &totalPay);
			fflush(stdin);
		}

	} while (validation < 1 || totalPay < totalPrice);

	if (totalPrice < totalPay)
	{
		change = totalPay - (totalPrice + 0.06*totalPrice);
	}

	for (int count = 0; count < 50; count++)
	{
		if (quantityItem[count] > 0)
			qty += quantityItem[count];
	}

	system("cls");

	printf("\nEnter name cashier : ");
	fflush(stdin);
	rewind(stdin);
	gets(nameCash);
	while (strlen(nameCash) == 0)
	{
		printf("\nSorry, you did not enter any name.\nPlease enter cashier name: ");
		gets(nameCash);
	}

	system("cls");

	printf("\n================================================================\n");
	printf("                        Dairy Fresh\n");
	printf("                    www.dailyfresh.com\n");
	printf("\n--------------------------------------------------------------\n");
	printf("\t\tPagoh Rest and Service\n");
	printf("\t\tArea (South Bound), KM 135.5,\n");
	printf("\t\tNorth South Expressway,\n");
	printf("\t\tPagoh, Johor.\n\n");
	printf("\n\t\tDate: %s", ctime(&currentTime));
	printf("--------------------------------------------------------------\n");
	printf("\nOrder: #%d\n", randnum(1,1000));
	printf("Cashier : %s\n", nameCash);

	for (int count = 0; count < 39; count++)
	{
		if (quantityItem[count] > 0)
			printf("\n\n%d    %sRM%0.2f", quantityItem[count], itemName[count], (quantityItem[count] * priceItem[count]));
	}

	if (quantityItem[39] > 0)
	{
		printf("\n\n%d    %sRM%0.2f", quantityItem[39], itemName[39], (quantityItem[39] * priceItem[39]));

		for (int count = 0; count < 35; count++)
		{
			if (qtyComboA[count] > 0)
				printf("\n     -%sx%d", nameComboA[count], qtyComboA[count]);
		}
	}

	if (quantityItem[40] > 0)
	{
		printf("\n\n%d    %sRM%0.2f", quantityItem[40], itemName[40], (quantityItem[40] * priceItem[40]));

		for (int count = 0; count < 35; count++)
		{
			if (qtyComboB[count] > 0)
				printf("\n     -%sx%d", nameComboB[count], qtyComboB[count]);
		}
	}

	printf("\n");
	printf("\n -------------------------------------------------------------");
	printf("\n Total item count:                                  %d", qty);
	printf("\n -------------------------------------------------------------");
	printf("\n Subtotal:                                     RM%0.2f", totalPrice);
	printf("\n Service tax(6%):                               RM%0.2f", 0.06*totalPrice);
	printf("\n -------------------------------------------------------------");
	printf("\n Total:                                        RM%0.2f", totalPrice + 0.06*totalPrice);
	printf("\n -------------------------------------------------------------");
	printf("\n Pay:                                          RM%0.2f", totalPay);
	printf("\n Balance:                                      RM%0.2f", totalPay - (totalPrice + 0.06*totalPrice));
	printf("\n -------------------------------------------------------------\n\n");


	//printf("\n\n%d-%s  %s %s  %d-%d", rand(), _DATE, __TIME_, cashierName, rand(), rand());
	// use rand() function to to generate number
}

void sort(int array[], int size, char name[][50])
{
	int outer=0, temporary, beforeSort[size];
	char temporaryName[50], sortString[size][50];
	
	for(int i=0;i<size;i++)
	{
		beforeSort[i]=array[i];
		strcpy(sortString[i],name[i]);
	}
			

	for(int outer=0;outer<size;outer++)
	{       
        for(int inner=outer+1;inner<size;inner++)
		{          
            if(array[inner]>array[outer])
			{               
                temporary=array[outer];
                strcpy(temporaryName,sortString[outer]);
                array[outer]=array[inner];
                strcpy(sortString[outer],sortString[inner]);
                array[inner]=temporary;
            	strcpy(sortString[inner],temporaryName);   
            }
        }
    }
    
    for (int i=0;i<size;i++)
    {
    	printf("%2d. %-40s %d\n",(i+1),sortString[i],array[i]);
	}
}
