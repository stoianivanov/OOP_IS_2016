	Да се реализира следния клас:

	class Mammal
	{
	public:
    	    Mammal();
    	    Mammal(bool hasFur, unsigned numberOfLegs, unsigned age);
	
    	    //declaration of getters and setters here

    	    virtual char* getSpeciesName() const; //returns the name of the class
   	    virtual bool eats(Food food) const;//Food is an enum
	    virtual Color furColor() const;//Color is an enum
	    virtual bool canJump() const;
    	    virtual bool canSwim() const;
    	    virtual bool isSameSpeciesLike(Mammal* otherMammal);

	protected:
    	    bool hasFur;
    	    unsigned numberOfLegs;
    	    unsigned age;
	};

	Да се реализират класове Hippo, Dog, Kangaroo, Human, които наследяват Mammal.
