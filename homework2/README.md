Трябва да се реализира class String, в когото трябва да бъдат реализирани следните методи:

	class String
	{
		public:
			String();
			String(char* data);
			String& operator=(const String);
			~String();
	 
			char at(size_t idx);//връща елемент на позиция

			size_t size() const;


	 		char operator[](size_t idx);
	 		const char operator[](size_t idx);

			String& operator+=(const String& rhs);
			bool operator<(const String& rhs);
			bool operator>(const String& rhs);
			bool operator<=(const String& rhs);
			bool operator>=(const String& rhs);

			bool operator==(const String& rhs);
			bool operator!=(const String& rhs);

			friend String operator+ (String lhs, const String& rhs);
			friend ostream& operator<<(ostream& os, const String& obj);
			friend istream& operator>>(istream& is, String& obj);

		private:
			char* data;
	}