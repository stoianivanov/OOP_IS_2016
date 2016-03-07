Имаме структурите:

struct Destination
{
	City city;
	int kilometers;
}

struct City
{
	char* name;
	int population;
	bool hasMuseum;
}

struct GPS 
{
	Citu currentCity;
	Destination[10] path;
}