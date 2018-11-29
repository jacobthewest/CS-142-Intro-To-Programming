/**************************
HEADER
Jacob West, section 3, jacobthewest@gmail.com

TEST CASE 1: Checks for displaying options, adding songs, listing songs, and deleting songs from the library
	Input: 
		options
		add
		Buddy Holly
		I don't remember the first line of the song...
		Electromagnetic spectrum
		Radio waves, micro waves, infrared, radiation, visible light...
		FourFive Seconds
		I think I've had enough..
		Lonely
		I'm lonely, I'm Mr. Lonely, I've got nobody
		STOP
		delsl
		3
	Output:
		add      Adds a list of songs to the library
		list     Lists all the songs in the library
		addp     Adds a new playlist
		addsp    Adds a song to a playlist
		listp    Lists all the playlists
		play     Plays a playlist
		delp     Deletes a playlist
		delsp    Deletes a song from a playlist
		delsl    Deletes a song from the library(and all playlists)
		options  Prints this options menu
		quit     Quits the program

		Read in Song names and first lines(type "STOP" when done) :
		Song Name : Buddy Holly
		Song's first line: I don't remember the first line of the song...
		Song Name : Electromagnetic spectrum
		Song's first line: Radio waves, micro waves, infrared, radiation, visible light...
		Song Name : FourFive Seconds
		Song's first line: I think I've had enough..
		Song Name : Lonely
		Song's first line: I'm lonely, I'm Mr. Lonely, I've got nobody
		Song Name : STOP

		0: Buddy Holly
		1: Electromagnetic spectrum
		2: FourFive Seconds
		3: Lonely
		Pick a song index number : 3

		Goodbye!
TEST CASE 2: Checks for adding songs to specific playlists and for the quit option in the menu
	Input:
		add
		Buddy Holly
		I don't remember the first line of the song...
		Electromagnetic spectrum
		Radio waves, micro waves, infrared, radiation, visible light...
		FourFive Seconds
		I think I've had enough..
		Lonely
		I'm lonely, I'm Mr. Lonely, I've got nobody
		STOP
		addp
		Jacob's Beats
		addsp
		0
		0
		addsp
		0
		3
		quit
	Output:
		Playlist name: Jacob's Beats
		Enter your selection now : addsp
		0: Jacob's Beats
		Pick a playlist index number : 0

		0 : Buddy Holly
		1 : Electromagnetic spectrum
		2 : FourFive Seconds
		3 : Lonely
		Pick a song index number : 0


		0: Jacob's Beats
		Pick a playlist index number : 0

		0 : Buddy Holly
		1 : Electromagnetic spectrum
		2 : FourFive Seconds
		3 : Lonely
		Pick a song index number : 3


TEST CASE 3: Checks for deleting songs from a playlist and for deleting songs from the library
	Input:
		add
		Buddy Holly
		I don't remember the first line of the song...
		Electromagnetic spectrum
		Radio waves, micro waves, infrared, radiation, visible light...
		FourFive Seconds
		I think I've had enough..
		Lonely
		I'm lonely, I'm Mr. Lonely, I've got nobody
		STOP
		addp
		Jacob's Beats
		addsp
		0
		0
		addsp
		0
		3
		delsp
		0
		0
		delsl
		3
	Output:
		0: Jacob's Beats
		Pick a playlist index number: 0

		0: Buddy Holly
		1: Lonely
		Pick a song index number to delete : 0

		0: Buddy Holly
		1: Electromagnetic spectrum
		2: FourFive Seconds
		3: Lonely
		Pick a song index number : 3
***************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "Song.h"
#include "Playlist.h"

//Magic numbers
const string ADD_LIST_OF_SONGS_TO_LIBRARY = "add";
const string LIST_ALL_SONGS_IN_LIBRARY = "list";
const string ADD_NEW_PLAYLIST = "addp";
const string ADD_SONG_TO_PLAYLIST = "addsp";
const string LIST_ALL_PLAYLISTS = "listp";
const string PLAY_A_PLAYLIST = "play";
const string DELETE_A_PLAYLIST = "delp";
const string DELETE_SONG_FROM_PLAYLIST = "delsp";
const string DELETE_SONG_FROM_LIBRARY = "delsl";
const string PRINT_OPTIONS_MENU = "options";
const string QUIT_PROGRAM = "quit";

void PrintOptionsMenu() {
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library(and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl << endl;
}

int main() {
	//Other variables
	bool bWeAreInTheProgram = true;
	string sChoice = "";
	vector<Song*> vectorOfSongPointers;
	vector<Playlist> vectorOfPlaylists;
	Song songObject;
	Playlist playlistObject;

	cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;

	while (bWeAreInTheProgram) {

		cout << "Enter your selection now : ";
		cin >> sChoice;
		cout << endl;
		if (cin.fail() || !(sChoice == ADD_LIST_OF_SONGS_TO_LIBRARY || sChoice == LIST_ALL_SONGS_IN_LIBRARY
			|| sChoice == ADD_NEW_PLAYLIST || sChoice == ADD_SONG_TO_PLAYLIST
			|| sChoice == LIST_ALL_PLAYLISTS || sChoice == PLAY_A_PLAYLIST
			|| sChoice == DELETE_A_PLAYLIST || sChoice == DELETE_SONG_FROM_PLAYLIST
			|| sChoice == DELETE_SONG_FROM_LIBRARY || sChoice == PRINT_OPTIONS_MENU
			|| sChoice == QUIT_PROGRAM)) {
			PrintOptionsMenu();
		}

		if (sChoice == ADD_LIST_OF_SONGS_TO_LIBRARY) {
			songObject.AddSong(vectorOfSongPointers);
		}
		else if (sChoice == LIST_ALL_SONGS_IN_LIBRARY) {
			songObject.ListAllSongs(vectorOfSongPointers);
		}
		else if (sChoice == ADD_NEW_PLAYLIST) {
			playlistObject.AddPlaylist(vectorOfPlaylists);
		}
		else if (sChoice == ADD_SONG_TO_PLAYLIST) {
			playlistObject.AddSongToPlaylist(vectorOfPlaylists, vectorOfSongPointers);
		}
		else if (sChoice == LIST_ALL_PLAYLISTS) {
			playlistObject.ListAllPlaylists(vectorOfPlaylists);
		}
		else if (sChoice == PLAY_A_PLAYLIST) {
			playlistObject.PlayPlaylist(vectorOfPlaylists);
		}
		else if (sChoice == DELETE_A_PLAYLIST) {
			playlistObject.DeletePlaylist(vectorOfPlaylists);
		}
		else if (sChoice == DELETE_SONG_FROM_PLAYLIST) {
			playlistObject.DeleteSongFromPlaylist(vectorOfPlaylists);
		}
		else if (sChoice == DELETE_SONG_FROM_LIBRARY) {
			playlistObject.DeleteSongFromLibrary(vectorOfPlaylists, vectorOfSongPointers);
		}
		else if (sChoice == PRINT_OPTIONS_MENU) {
			PrintOptionsMenu();
		}
		else if (sChoice == QUIT_PROGRAM) {
			bWeAreInTheProgram = false;
		}

	}
	cout << "Goodbye!" << endl;
	//system("pause");

	return 0;
}