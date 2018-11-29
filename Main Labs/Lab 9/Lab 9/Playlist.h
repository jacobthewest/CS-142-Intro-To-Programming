#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Song.h"

using namespace std;

class Playlist {
public:
	//Constructors
	Playlist();
	Playlist(string playlistName);

	//Getters
	string GetPlaylistName() const;

	//Setters
	void SetPlaylistName(string sPlaylistName);

	//Other Functions
	void AddPlaylist(vector<Playlist> &vectorOfPlaylists);
	void ListAllPlaylists(vector<Playlist> &vectorOfPLaylists) const;
	void AddSongToPlaylist(vector<Playlist> &vectorOfPlaylists, vector<Song*> &VectorOfSongPointers);
	void PlayPlaylist(vector<Playlist> &vectorOfPlaylists) const;
	void DeletePlaylist(vector<Playlist> &vectorOfPlaylists);
	void DeleteSongFromPlaylist(vector<Playlist> &vectorOfPlaylists);
	void DeleteSongFromLibrary(vector<Playlist> &vectorOfPlaylists, vector<Song*> &vectorOfSongPointers);
private:
	string playlistName;
	vector<Song*> vectorOfSongPointersForPlaylist;
};