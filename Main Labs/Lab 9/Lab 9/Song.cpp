#include "Song.h"

//Constructors
Song::Song() {
	this->songName = "";
	this->firstLine = "";
	this->timesPlayed = 0;
}
Song::Song(string sSongName, string sFirstLine, int iTimesPlayed) {
	this->songName = sSongName;
	this->firstLine = sFirstLine;
	this->timesPlayed = iTimesPlayed;
}
//Getters
string Song::GetSongName() const {
	return songName;
}
string Song::GetFirstLine() const {
	return firstLine;
}
int Song::GetTimesPlayed() const {
	return timesPlayed;
}
//Other functions
void Song::AddSong(vector<Song*> &vectorOfSongPointers) {
	string sStop = "STOP";
	string sSongName;
	string sFirstLine;
	bool bProgramIsRunning = true;
	int iTimesPlayed = 0;
	int iNumTimesRepeatingLoop = 0;

	cout << "Read in Song names and first lines(type \"STOP\" when done) : " << endl;

	while (bProgramIsRunning) {
		if (iNumTimesRepeatingLoop == 0) {
			cin.ignore();
		}
		else {
			cout << flush;
		}
		cout << "Song Name : ";
		getline(cin, sSongName);
		cout << endl;
		if (sSongName == sStop) {
			bProgramIsRunning = false;
		}
		else {
			cout << "Song's first line: ";
			getline(cin, sFirstLine);
			cout << endl;

			//Create a pointer to a new song object
			Song* pointerToSongObject = new Song(sSongName, sFirstLine, iTimesPlayed);
			//Store the pointer in our vector of song pointers
			vectorOfSongPointers.push_back(pointerToSongObject);
		}
		iNumTimesRepeatingLoop++;
	}
}
void Song::ListAllSongs(vector<Song*> &vectorOfSongPointers) {
	ostringstream oss;
	for (unsigned int i = 0; i < vectorOfSongPointers.size(); ++i) {
		oss << vectorOfSongPointers.at(i)->GetSongName() << " : " << "\"" << vectorOfSongPointers.at(i)->GetFirstLine() 
			<< "\", " << vectorOfSongPointers.at(i)->GetTimesPlayed() << " play(s)." << endl;
	}
	cout << oss.str();
}
void Song::PlaySong(vector<Song*> &vectorOfSongPointers, int iSongIndex) {
	cout << vectorOfSongPointers.at(iSongIndex)->GetSongName() << endl;
}
void Song::IncrementSongPlayed() {
	this->timesPlayed++;
}
