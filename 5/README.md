

class Autor
{
	private:
		char* firstName;
		char* lastName;
		int age;
		int rating;
	public:
		Autor(char* firstName=NULL,char* lastName=NULL, int age=0, int raitin=-1);
		Autor(const Autor&);
		~Autor();

		char* getFirstName() const;
		char* getLastName() const;
		int getAge() const;
		int getRating() const;
}


class Movie
{
	private: 
		char* name;
		Autor* authors;
		int price;
	public:
		Movie(char* name=NULL, char* authors=NULL, int price=0);
		~Movie();
		char* getName() const;
		char* getAuthor() const;
		int getPrice() const;
		void newPrice(int price);
};


class MovieStore
{
	private:
		Movie *movies;
		int budget;
		size_t size;
		size_t capacity;

	public:
		MovieStore();
		MovieStore(Movie *movies = NULL, int budget = 0, int size = 0, int capacity = 0);
		MovieStore(int budget);
		~MovieStore();

		//Може да си добавите допълнителни(помощни) функции
		bool searchByMovie(Movie);	
		void resize(size_t newSize);//Преоразмеряване
		void sortMovies();//Сортировка
		void deleteMovie(char *);//delete from input name
		void pushMovie(Movie);//push movie from backside
		void print();
		//Може да се реализират допълнителни сетове, това е по ваше желание
		void setMovie(Movie*, size_t);
		void setBudget(int);
		void setSize(int);
		//Може да добавите допълнителни гетове
		Movie  getMovie() const;
		int getBudget() const;
};

