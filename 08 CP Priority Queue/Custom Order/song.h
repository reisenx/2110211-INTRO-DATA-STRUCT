#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


// Create Compare01 class (Sorting by Artist -> Title -> Count)
class Compare01
{
  public:
    bool operator()(const Song &lhs, const Song &rhs)
    {
      // Compare Artist (Sorted in ascending order)
      if(lhs.artist == rhs.artist) {
        // Compare Title (Sorted in ascending order)
        if(lhs.title == rhs.title) {
          // Compare Count (Sorted in descending order)
          return lhs.count < rhs.count;
        }
        return lhs.title > rhs.title;
      }
      return lhs.artist > rhs.artist;
    }
};

// Create Compare01 class (Sorting by Count -> Artist -> Title)
class Compare02
{
  public:
    bool operator()(const Song &lhs, const Song &rhs)
    {
      // Compare Count (Sorted in descending order)
      if(lhs.count == rhs.count) {
        // Compare Artist (Sorted in ascending order)
        if(lhs.artist == rhs.artist) {
          // Compare Title (Sorted in ascending order)
          return lhs.title > rhs.title;
        }
        return lhs.artist > rhs.artist;
      }
      return lhs.count < rhs.count;
    }
};

// Change the declaration of pq1 and pq2 (Using Compare class)
CP::priority_queue<Song, Compare01> pq1;
CP::priority_queue<Song, Compare02> pq2;

#endif
