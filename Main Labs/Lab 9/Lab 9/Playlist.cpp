#include "Playlist.h"

//-------------Constructors-----------------//
Playlist::Playlist() {
	
}
Playlist::Playlist(string playlistName) {
	this->playlistName = playlistName;
}

//-----------------Getters-------------------//
string Playlist::GetPlaylistName() const{
	return playlistName;
}
//-----------------------Setters--------------------//
void Playlist::SetPlaylistName(string sPlaylistName) {
	this->playlistName = sPlaylistName;
}
//------------------Other Functions------------------------//
void Playlist::AddPlaylist(vector<Playlist> &vectorOfPlaylists) {
	string sPlaylistName;

	cout << "Playlist name: ";
	cin.ignore();
	getline(cin, sPlaylistName);
	cout << endl;

	//Create an object for the playlist
	Playlist oPlaylist(sPlaylistName);
	//Add playlist to the vectorOfPlaylists
	vectorOfPlaylists.push_back(oPlaylist);
}
void Playlist::ListAllPlaylists(vector<Playlist> &vectorOfPLaylists) const {
	for (unsigned int i = 0; i < vectorOfPLaylists.size(); ++i) {
		cout << i << ": " << vectorOfPLaylists.at(i).GetPlaylistName() << endl;
	}
	cout << endl;
}
void Playlist::AddSongToPlaylist(vector<Playlist> &vectorOfPlaylists, vector<Song*> &vectorOfSongPointers) {
	int iPlaylistIndexNumber;
	int iSongIndexNumber;

	//List all of the playlists so they can select which playlist they want
	ListAllPlaylists(vectorOfPlaylists);
	cout << "Pick a playlist index number : ";
	cin >> iPlaylistIndexNumber;
	cout << endl;

	//display all of the songs that we have in our song library
	for (unsigned int i = 0; i < vectorOfSongPointers.size(); ++i) {
		cout << i << " : " << vectorOfSongPointers.at(i)->GetSongName() << endl;
	}
	cout << "Pick a song index number : ";
	cin >> iSongIndexNumber;
	cout << endl;

	//1. Get the desired playlist they want
	//2. In that playlist, go to our vector of song pointers
	//3. In that vector of song pointers, add the address of the song the user wanted to add
	vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.push_back
		(vectorOfSongPointers.at(iSongIndexNumber));
}
void Playlist::PlayPlaylist(vector<Playlist> &vectorOfPlaylists) const {
	int iPlaylistIndexNumber;

	//List all of the playlist names and let the user select one of them.
	ListAllPlaylists(vectorOfPlaylists);
	cout << "Pick a playlist index number: ";
	cin >> iPlaylistIndexNumber;
	cout << endl << endl;

	//Output what this function is doing
	cout << "Playing first lines of playlist: " << vectorOfPlaylists.at(iPlaylistIndexNumber).playlistName << endl;

	//Play the songs in the chosen playlist by firstname
	int iNumSongsInPlaylist = vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.size();
	for (unsigned int iSongVectorPointerLocation = 0; iSongVectorPointerLocation < iNumSongsInPlaylist; 
		++iSongVectorPointerLocation) {
		cout << vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.at(iSongVectorPointerLocation)->
			GetFirstLine() << endl;
		//Increment the times that the song has been played 
		vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.at(iSongVectorPointerLocation)->
			IncrementSongPlayed();
	}
}
void Playlist::DeletePlaylist(vector<Playlist> &vectorOfPlaylists) {
	int iDeleteThisIndex;

	//Display the playlists
	ListAllPlaylists(vectorOfPlaylists);

	cout << "Pick a playlist index number to delete : ";
	cin >> iDeleteThisIndex;
	cout << endl << endl;

	//Delete a playlist from the vector of playlists.
	vectorOfPlaylists.erase(vectorOfPlaylists.begin() + iDeleteThisIndex);
}
void Playlist::DeleteSongFromPlaylist(vector<Playlist> &vectorOfPlaylists) {
	int iPlaylistIndexNumber;
	int iSongIndexNumber;

	//Print out the playlists
	ListAllPlaylists(vectorOfPlaylists);

	cout << "Pick a playlist index number: ";
	cin >> iPlaylistIndexNumber;
	cout << endl;

	//Print out the songs in the playlist
	for (unsigned int i = 0; i < vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.size(); ++i) {
		cout << i << ": " << vectorOfPlaylists.at(iPlaylistIndexNumber).
			vectorOfSongPointersForPlaylist.at(i)->GetSongName() << endl;
	}

	cout << "Pick a song index number to delete : ";
	cin >> iSongIndexNumber;
	cout << endl;

	//Now search the playlists and destroy (just erase) the song from its memory muahhahahah
	vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist. //This should delete the pointer in this 
		//vector that references the song object
		//but it doesn't man... It says it is out of reference. Happens for all elements in this vector of pointers.
		erase(vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.begin() + iSongIndexNumber);
	
	/*
		for (unsigned int i = 0; i < vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.size(); ++i) {
			cout << vectorOfPlaylists.at(iPlaylistIndexNumber).vectorOfSongPointersForPlaylist.at(i);
		}
	*/

	//Below is the input that will give me this error
	/*
	add
	Penny Lane
	In Penny Lane there is a barber showing photographs
	Hello, Goodbye
	You say yes, I say no
	Let It Be
	When I find myself in times of trouble
	Wild World
	Now that I've lost everything to you
	Summer Breeze
	See the curtains hangin' in the window
	STOP
	addp
	Biking Music
	addp
	142 calm down collection
	addp
	Professor's Lounge
	addsp
	2
	1
	addsp
	1
	2
	addsp
	1
	4
	addsp
	0
	3
	addsp
	0
	0
	addsp
	0
	4
	listp
	delp
	2
	listp
	delsp
	1
	0
	**Error when I try to delete element 0 of the pointers to song objects in the playlist vector.
	*/
}
void Playlist::DeleteSongFromLibrary(vector<Playlist> &vectorOfPlaylists, vector<Song*> &vectorOfSongPointers) {
	int iSongIndex;
	
	for (unsigned int i = 0; i < vectorOfSongPointers.size(); ++i) {
		cout << i << ": " << vectorOfSongPointers.at(i)->GetSongName() << endl;
	}

	cout << "Pick a song index number : ";
	cin >> iSongIndex;
	cout << endl;

	string sSongName = vectorOfSongPointers.at(iSongIndex)->GetSongName();

	//Delete song from vectorOfSongPointersforPlaylists
	for (unsigned int i = 0; i < vectorOfPlaylists.size(); ++i) {
		for (unsigned int j = 0; j < vectorOfPlaylists.at(i).vectorOfSongPointersForPlaylist.size(); ++j) {
			if (vectorOfPlaylists.at(i).vectorOfSongPointersForPlaylist.at(j)->GetSongName() == sSongName) {
				vectorOfPlaylists.at(i).vectorOfSongPointersForPlaylist.erase(vectorOfPlaylists.at(i).
					vectorOfSongPointersForPlaylist.begin() + j);
			}
		}
	}
	
	//Free up the storage space that the song is currently taking using the delete keyword
	delete vectorOfSongPointers.at(iSongIndex);

	//Delete from the vector that is storing the pointer to its address
	vectorOfSongPointers.erase(vectorOfSongPointers.begin() + iSongIndex);
}