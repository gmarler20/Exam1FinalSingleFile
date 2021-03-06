

// I affirm that all code written below was written solely by me,
// Griffen Marler, and that any help I recieved adhered to the rules
// states for this exam. 

#include "stdafx.h"
#include <string>
#include <Iostream>
using namespace std;



class Movie {

public:

	Movie()
	{
		Title = "Lord of the Rings ";
		Genre = "Action ";
		ShowTime = 9;
	}

	// This constructor will default to any of the values set in the = if nothing is entered for them
	Movie(string Title = "Lord of the Rings", string Genre = "Comedy", int ShowTime = 9) {
		setTitle(Title);
		setGenre(Genre);
		setShowTime(ShowTime);
	}
	string GetTitle()
	{
		return Title;
	}
	string GetGenre()
	{
		return Genre;
	}
	int GetShowTime()
	{
		return ShowTime;
	}

	void setTitle(string x) {
		Title = x;
	}
	void setGenre(string y) {
		Genre = y;
	}
	void setShowTime(int z) {
		ShowTime = z;
	}

private:
	string Title;
	string Genre;
	int ShowTime;

};

class Theater {

public:
	Theater(string Name, string Phone)
	{
		Name = "Garland";
		Phone = "5096801123";
	}
	// I was not sure how to take each object created in the
	// for loop in main and then get each of its values. I tried 
	// void Addmovie(Movie& ob[]) to put in as the parameter and 
	// then to have 
	/* void AddMovie(Movie& ob) {
	{
	for(int i = 0; i < 11; i++)
	ShowTime[i] = ob[i].GetShowTime();
	Title[i] = ob[i].GetTitle();
	Genre[i] = ob[i].GetGenre();
	}*/
	/*
	I also tried
	void AddMovie(Movie& ob) {
	for (int i = 0; i < 11; i++)
	{ ShowTime[a] = ob.GetShowTime();
	Title [a] = ob.GetTitle();
	Genre[a] = ob.GetGenre();
	}
	}

	I had no luck with this.
	*/

	// I spent lots of time trying to figure this out, but ultimately
	// decided that I would rather have it run than turn in something
	// that didn't run so I went back to what I had below. I will need
	// to Skype you at some point so I can understand how I take all of the
	// objects that were created and stored in the array in main and use their 
	// individual data. My problem throughout this program is that I am only 
	// reading the data from the last object Movie("Usual Suspects", "Action", 23)
	// and could not figure out how to add each individual object from the array. 
	void AddMovie(Movie& ob) {
		{
			ShowTime = ob.GetShowTime();
			Title = ob.GetTitle();
			Genre = ob.GetGenre();
		}
	}

	// If the hour of the specific movie is equal to the hour input, output the title.
	string GetMovieForHour(int hour) {
		if (hour == ShowTime || hour == ShowTime + 1)
			cout << Title;
		else
			return "";
	}

	// Ran into a problem here as well when I was trying to read in the Genre. When I read it in
	// it is always giving me the genre from the last object created Movie("Usual Suspects, "Action, 23)
	// It works for the last object, but nothing else. 
	int GetShowTimeForGenre(string Genre1) {
		if (Genre1 == Genre)
			return 0;
		else
			return -1;
	}

	// We don't want Popcorn price or coke price to be changed, so both are const int and const functions.
	int GetPopcornPrice() const {
		return Popcorn;
	}
	int GetCokePrice() const {
		return Coke;
	}

private:
	int ShowTime;
	string Title;
	string Genre;
	const int Popcorn = 5;
	const int Coke = 3;
};
int main()
{
	//Note: you should not need to alter this code at all for your tests to pass.
	const int MOVIECOUNT = 11;
	Movie movieListing[] = {
		Movie("Bull Durham", "Comedy", 0), Movie("Ocean's Eleven", "Action", 2),
		Movie("Solo: A Star Wars Story", "Sci-Fi", 5), Movie("Jaws", "Horror", 7),
		Movie("Fletch", "Comedy", 10), Movie("Usual Suspects", "Action", 12),
		Movie("Bull Durham", "Comedy", 14), Movie("Ocean's Eleven", "Action", 16),
		Movie("Monte Python's Meaning of Life", "Comedy", 19), Movie("Jaws", "Horror", 21),
		Movie("Usual Suspects", "Action", 23),
	};
	Theater garland("The Garland", "509-327-2509");
	for (int m = 0; m < MOVIECOUNT; m++) {
		garland.AddMovie(movieListing[m]);
	}
	int errors = 0;
	if (garland.GetMovieForHour(-1) != "") {
		errors++;
		cout << "error: not handling -1 correctly\n";
	}
	if (garland.GetMovieForHour(25) != "") {
		errors++;
		cout << "error: not handling 25 correctly\n";
	}
	//Find the movie starting on or after the hour 18
	if (garland.GetMovieForHour(18) != "Monte Python's Meaning of Life") {
		errors++;
		cout << "error: incorrect movie for 18th hour\n";
	}
	if (garland.GetShowTimeForGenre("Comedy") != 0) {
		errors++;
		cout << "error: incorrect Comedy\n";
	}
	if (errors == 0) cout << "Passed\n";
	else cout << "Errors: " << errors << endl;


}
