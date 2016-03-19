Да се реализират класовете и методите към тях:


	class Song 
	{
		public:
			Song(char* name, float length);
			Song(char* name, float length, char* artist);
			char* getName() const;
			float getLength() const;
			char* getArtist() const;
		private:
			char* name; // име на песнта
			float length;//дължина на песента
			char* artist; // име на певеца(или групата, която изпълнява песента)
	}

	class Album
	{
		public:
			void addSong(const Song); // когато добавяме песни към албум, трябва да се внимава дали песните са на един и същ изпълнител или група
			void removeSong(const char* name); // като аргумент се подава името на песента
			void removeSong(const int index);  //по индекс от масива(започват от 0)
			Album(char* name);
			Album(char* name, Song song);
			ALbum(char* name, Song* song);
		private:
			Song* songs;
			char* name; // Името на албума;
	}
	class MP3Player 
	{
		public:
			MP3Player();
			MP3Player(Song* songs);
			MP3Player(Album* albums);
			MP3Player(Song* songs, Album* albums);

			void addSong(Song);
			void addSongs(Song* songs);
			void addAlbum(Album album);
			void addAlbums(Album* Albums);
			void removeAlbum(char* name);

			void charge();
			void stopCharge();
			void play(bool shuffle); /* пуска песен, но при пускането на песен имаме няколко условия:
			ако батерията е по-малко от 15 % трябва да бъде изведено съобщение, че батерията налява.
			при пускането на песента тя хаби толкова батерия колкото е дълга( взима се само цялата част, тоест на песен, която е дълга 2.22 взима 2 % от батерията)
			ако MP3Player-а се зарежда в момента не можем да пускаме песни.
			ако нямаме песни също не може да пуснем песни.
			ако shuffle e true трябва да се пусне рандом песен.
			ако shuffle e false трябва да се пусне песента последната песен.
*/
		private:
			Song* songs;
			Album* albums;
			int batteryPower; // Когато батерията е пълна batteryPower  е 100, когато е празна е 0
			bool isCharge;

	}

Може да се добавят нови методи, член данни, конструктори, деструктори. Само не трябва да се разрушава текущата структура на класовете