#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>

#include "NextAnagram.h"

#define MAX_ANAGRAMS 1000

// -------------------------------------------------------------------------
// Lists used in this code
typedef std::vector< char >        TCharacterList;
typedef std::vector< std::string > TStringList;

// -------------------------------------------------------------------------
TCharacterList ReadAsCharacterList( std::istream& input );
TStringList ReadAsStringList( std::istream& input );

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  // Get a valid input stream
  std::istream* input = &std::cin;
  if( argc > 1 )
    input = new std::ifstream( argv[ 1 ] );
  if( !( *input ) )
  {
    std::cerr << "Error opening input stream." << std::endl;
    return( -1 );

  } // fi

  // Loop over input
  unsigned int line_type;
  do
  {
    // Get complete text line
    std::string line;
    std::getline( *input, line );

    // Prepare a simple tokenizer
    std::stringstream line_stream( line );

    // Get type of data
    line_stream >> line_type;
    std::cout<<line_type<<std::endl;
    if( line_type == 0 )
    {
      // String list
      TStringList stringList = ReadAsStringList( line_stream );

      // Compute number of anagrams
      unsigned long nAnagrams = ComputeNumberOfAnagrams( stringList );
      if( nAnagrams >= MAX_ANAGRAMS )
        nAnagrams = MAX_ANAGRAMS;

      // Print all (or at least MAX_ANAGRAMS) anagrams
      for( unsigned long i = 0; i < nAnagrams; ++i )
      {
        std::copy(
          stringList.begin( ), stringList.end( ),
          std::ostream_iterator< std::string >( std::cout, " : " )
          );
        std::cout << std::endl;
        stringList = NextAnagram( stringList );

      } // rof
    }
    else if( line_type == 1 )
    {
      // Char list
      TCharacterList charList = ReadAsCharacterList( line_stream );
      // Compute number of anagrams
      unsigned long nAnagrams = ComputeNumberOfAnagrams( charList );
      if( nAnagrams >= MAX_ANAGRAMS )
        nAnagrams = MAX_ANAGRAMS;

      // Print all (or at least MAX_ANAGRAMS) anagrams
      for( unsigned long i = 0; i < nAnagrams; ++i )
      {
        std::copy(
          charList.begin( ), charList.end( ),
          std::ostream_iterator< char >( std::cout, "" )
          );
        std::cout << std::endl;
        charList = NextAnagram( charList );

      } // rof

    } // fi

  } while( line_type != 2 );

  // Close input stream, if needed (ie. it wasn't taken from std::cin)
  dynamic_cast< std::ifstream* >( input )->close( );
  delete input;

  return( 0 );
}

// -------------------------------------------------------------------------
TCharacterList ReadAsCharacterList( std::istream& input )
{
  // Prepare output
  TCharacterList lst;

  // Loop over a space separated stream (tokenizer)
  while( !input.eof( ) )
  {
    std::string str;
    input >> str;

    for(
      std::string::const_iterator sIt = str.begin( );
      sIt != str.end( );
      ++sIt
      )
      lst.push_back( *sIt );

  } // elihw

  return( lst );
}

// -------------------------------------------------------------------------
TStringList ReadAsStringList( std::istream& input )
{
  // Prepare output
  TStringList lst;

  // Loop over a space separated stream (tokenizer)
  while( !input.eof( ) )
  {
    std::string str;
    input >> str;
    lst.push_back( str );

  } // elihw

  return( lst );
}

// eof - solve_anagram.cxx
