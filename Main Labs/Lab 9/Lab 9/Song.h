#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Class Declarations

class Song {
	public:
		//Constructors
		Song();
		Song(string sSongName, string sFirstLine, int iTimesPlayed);

		//Getters
		string GetSongName() const;
		string GetFirstLine() const;
		int GetTimesPlayed() const;

		//Setters

		//Other functions
		void AddSong(vector<Song*> &vectorOfSongPointers);
		void ListAllSongs(vector<Song*> &vectorOfSongPointers);
		void PlaySong(vector<Song*> &vectorOfSongPointers, int iSongIndex);
		void IncrementSongPlayed();
	private:
		string songName;
		string firstLine;
		int timesPlayed;
};

/*

*/
