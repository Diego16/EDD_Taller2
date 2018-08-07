#ifndef __NEXTANAGRAM__HXX__
#define __NEXTANAGRAM__HXX__

#include <queue>
#include <stack>

// -------------------------------------------------------------------------
template< class TList >
TList NextAnagram( const TList& lst )
{
  // Get contained type
  typedef typename TList::value_type TValue;

  // Used variables
  std::queue< TValue > q;
  std::stack< TValue > s;
  TList res;
  TValue pivot, v_aux, last_v;
  bool finished;
  typename TList::const_iterator lIt;
  typename TList::reverse_iterator rIt;

  // 1. Stack the input values
  /** TODO #1 **/

  // 2. Try to find a pivot
  finished = false;
  v_aux = s.top( );
  s.pop( );
  do
  {
    q.push( v_aux );
    last_v = v_aux;
    if( s.empty( ) )
    {
      finished = true;
      break;
    }
    else
    {
      // 2.1 Pop value from stack and store it into 'v_aux'
      /** TODO #2 **/ 

    } // fi

  } while( v_aux > last_v );

  // 2.5. if pivot has been found...
  if( !finished )
  {
    pivot = v_aux;

    // 3. Find a value just below pivot
    /** TODO #3 **/

    // 4. Put it into stack
    s.push( v_aux );

    // 5. Put pivot back to queue
    q.push( pivot );

    // 6. Find the value just above pivot
    /** TODO #4 **/

    // 7. Put it into stack
    s.push( v_aux );

  } // fi

  // 8. Finish filling the stack by emptying the queue
  /** TODO #5 **/

  // 9. Fill the final answer in reverse order by emptying the stack
  /** TODO #6 **/

  // 10. Return
  return( res );
}

// -------------------------------------------------------------------------
template< class TList >
unsigned long ComputeNumberOfAnagrams( const TList& lst )
{
  /** TODO #7 **/
}

#endif // __NEXTANAGRAM__HXX__

// eof - NextAnagram.hxx
