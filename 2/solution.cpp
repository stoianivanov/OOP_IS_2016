// Product.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <cstring>


enum Type { WAFFLE, WATER, COSMETIC, PAPER, FIZZY };

struct Product
{

	Type type;
	char* name;
	char barcode[13];
	double price;
	int id;



};

void Create(Product& product,Type t, char* Name, char* Barcode, double Price, int Id)
{

    product.name = new char[strlen(Name)+1];
    product.type = t;
    strcpy(product.name, Name);
    product.price = Price;
    strcpy(product.barcode, Barcode);
}

void print(Product& product)
{
    std::cout<<"Product name:"<< product.name<< std::endl;
    std::cout<<"Price:"<< product.price<< std::endl;
    std::cout<<"ID:"<<product.id<<std::endl;
    std::cout<<"Type:"<<product.type;
    std::cout<<product.barcode;
}

void destroy(Product& product)
{
    delete[] product.name;
    product.price = 0;
    product.id = 0;
}

struct Market
{

	char* nameM;
	Product *arrProducts;
	int countProducts;
	int capacity;



};


void Create(Market& market,char* Name, Product *arrP, int cap)
{
    market.nameM = new char[strlen(Name)+1];
    strcpy(market.nameM, Name);
    market.arrProducts = arrP;
    market.countProducts = 0;
    market.capacity = cap;
}


bool hasThisBarcode(Market& market, Product product)
{
    for(size_t i; i< market.countProducts; ++i)
    {
        if(strcmp(market.arrProducts[i].barcode, product.barcode) == 0)
        {
            return true;
        }
    }
    return false;
}


void addProduct(Market& market,Product product)
{
    if(market.countProducts < market.capacity){
        if(!hasThisBarcode(market, product))
        {
            market.arrProducts[market.countProducts] = product;
            market.countProducts++;
        }

    }
    else
        std::cout<<"You have no space to adding products in the Market!";
}

char* LowestPriceTypeProduct(Market* arrMarkets, int size, Type type)
{
	double tempPrice = arrMarkets[0].arrProducts[0].price;
    int index = 0;


	for(int i=0; i<size; i++){
		for(int j=0; i<arrMarkets[j].countProducts; j++){
			if(arrMarkets[i].arrProducts[j].type == type){
				if(arrMarkets[i].arrProducts[j].price < tempPrice)
				 {
					 tempPrice = arrMarkets[i].arrProducts[j].price;
					 index = i;
				 }
		 }
	}

}
	return arrMarkets[index].nameM;
}
void shifft(Market& market, size_t index)
{
    for(;index < market.countProducts - 1; ++index)
    {
        market.arrProducts[index] = market.arrProducts[index + 1];
    }
}

void removeProduct(Market& market, Product product)
{
    for(size_t i = 0; i< market.countProducts; ++i)
    {
        if(strcmp(market.arrProducts[i].barcode, product.barcode) == 0)
        {
            shifft(market, i);
            market.countProducts--;
        }
    }
}

bool isEqual(Market market, Type type)
{
    Product temp;
    bool isFirst = true;
    for(size_t i; i < market.countProducts; ++i)
    {
        if(market.arrProducts[i].type == type)
        {
           if(isFirst)
           {
                Create(temp,market.arrProducts[i].type,market.arrProducts[i].name,market.arrProducts[i].barcode,
                market.arrProducts[i].price,market.arrProducts[i].id);
                isFirst = false;
           } else
           {
                if (strcmp(temp.name,market.arrProducts[i].name) != 0 || temp.price != market.arrProducts[i].price)
                {
                    return false;
                }
           }
        }
    }
    return true;
}
int main()
{
	Product CocaCola, Morena, WaterMihalkovo, WaterBankya, WaterDevin;
	Product  arrMarket[100];


	Create(CocaCola, FIZZY, "Coca Cola", "789434832432", 1.2, 761234);
	Create(Morena, WAFFLE, "Morena", "789876543432", 0.5, 721742);
	Create(WaterMihalkovo, WATER, "Mihalkovo", "439434832432", 1.2, 723124);
	Create(WaterBankya, WATER , "Bankya", "789434832432", 0.7, 761234);
	Create(WaterDevin, WATER, "Morena", "119876543432", 0.8, 721742);






	Market Billa, Kaufland, Lidl;

	Create(Billa, "Billa", arrMarket, 30);
	addProduct(Billa, CocaCola);
	addProduct(Billa, Morena);
	addProduct(Billa, WaterMihalkovo);

	Create(Kaufland, "Kaufland", arrMarket, 100);
	addProduct(Kaufland, WaterDevin);
	addProduct(Kaufland, CocaCola);

	Create(Lidl, "Lidl", arrMarket, 50);
	addProduct(Lidl, WaterBankya);
	addProduct(Lidl, CocaCola);



	Market arrMarkets[3];
	arrMarkets[0] = Kaufland;
	arrMarkets[1] = Billa;
	arrMarkets[2] = Lidl;

	std::cout<<LowestPriceTypeProduct(arrMarkets,3,WATER);



	delete[] WaterBankya.name;
	delete[] CocaCola.name;
	delete[] WaterDevin.name;
	delete[] WaterMihalkovo.name;
	delete[] Morena.name;
	delete[] Lidl.nameM;
	delete[] Kaufland.nameM;
	delete[] Billa.nameM;

	return 0;
}


