Имаме структурите:

struct Destination
{
	City city;
	int kilometers;
}

struct City
{
	char* name;
	int population; // в хиляди 
	bool hasMuseum;
}

struct GPS 
{
	City currentCity;
	Destination[10] path;
}

Трябва да си създадем 2 инстанции от тип City. Например:
name  | population | hasMuseum
Varna | 500        | False 
Sofia | 2 000      | True

Трябва да се създаде една инстанция на GPS. Например:
CurrentCity      | path
Sofia			 | [Plovdiv, Varna, Burgas Vidin, Ruse,
					Blagoevgrad(Best city ever), Smolqn, 
					Silistra, Bansko, Skopie]

Като цялата система трябва да подържа. няколко вида търсене:
	-	по критерия дали в града има музей
	-	по критерия за разстоянието до града
	-	по азбъчен ред

Нека да има хубав начин за принтиране на конзолата на  върнатите резултати.

П.П.
Функциите, който не са описани трябва вие сами да си напишете и да си имплеметирате.

П.П. 
Моля трийте си динамичната памет преди краят на програмата.