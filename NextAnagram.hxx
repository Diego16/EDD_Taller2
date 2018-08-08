#ifndef __NEXTANAGRAM__HXX__
#define __NEXTANAGRAM__HXX__

#include <iterator>
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
  for(lIt=lst.begin();lIt!=lst.end();lIt++)
    s.push(*lIt);

  std::stack< TValue > s2;
  std::cout<<"Inital stack: "<<std::endl;
  while(!s.empty())
  {
    TValue aux=s.top();
    std::cout<<s.top();
    s.pop();
    s2.push(aux);
  }
  while(!s2.empty())
  {
    s.push(s2.top());
    s2.pop();
  }
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
      v_aux=s.top();
      s.pop();
    } // fi

  } while( v_aux > last_v );

  // 2.5. if pivot has been found...
  if( !finished )
  {
    pivot = v_aux;
    std::cout<<"Pivot: "<<pivot<<std::endl;
    // 3. Find a value just below pivot
    /** TODO #3 **/
    do
    {
      if(q.front()<pivot)
      {
        v_aux=q.front();
        q.pop();
      }
      else
      {
        v_aux=q.front();
        q.pop();
        q.push(v_aux);
        v_aux=pivot;
      }
    } while( pivot > v_aux );
    // 4. Put it into stack
    std::cout<<"v_aux below: "<<v_aux<<std::endl;
    s.push( v_aux );
    std::cout<<"Stack below pivot: "<<std::endl;
    while(!s.empty())
    {
      TValue aux=s.top();
      std::cout<<s.top();
      s.pop();
      s2.push(aux);
    }
    while(!s2.empty())
    {
      s.push(s2.top());
      s2.pop();
    }
    // 5. Put pivot back to queue
    q.push( pivot );

    // 6. Find the value just above pivot
    /** TODO #4 **/
    do
    {
      if(q.front()<pivot)
      {
        v_aux=q.front();
        q.pop();
      }
      else
      {
        v_aux=q.front();
        q.pop();
        q.push(v_aux);
        v_aux=pivot;
      }
    } while( pivot < v_aux );
    // 7. Put it into stack
    std::cout<<"v_aux above: "<<v_aux<<std::endl;
    s.push( v_aux );
    std::cout<<std::endl<<"Stack above pivot: "<<std::endl;
    while(!s.empty())
    {
      TValue aux=s.top();
      std::cout<<s.top();
      s.pop();
      s2.push(aux);
    }
    while(!s2.empty())
    {
      s.push(s2.top());
      s2.pop();
    }

  } // fi

  // 8. Finish filling the stack by emptying the queue
  /** TODO #5 **/
  while(!q.empty())
  {
    s.push(q.front());
    q.pop();
  }
  // 9. Fill the final answer in reverse order by emptying the stack
  /** TODO #6 **/
  while(!s.empty())
  {
    res.insert(res.begin(),s.top());
    s.pop();
  }
  // 10. Return
  std::cout<<std::endl<<"res: ";
  for(lIt=lst.begin();lIt!=lst.end();lIt++)
    std::cout<<*lIt;
  std::cout<<std::endl;
  return( res );
}

// -------------------------------------------------------------------------
template< class TList >
unsigned long ComputeNumberOfAnagrams( const TList& lst )
{
  /** TODO #7 **/
  unsigned long numAnagrams=1;
  int n=0;
  n=lst.size();
  for(int i=1;i<=n;i++)
  {
    numAnagrams*=i;
  }
  return numAnagrams;
}

#endif // __NEXTANAGRAM__HXX__

// eof - NextAnagram.hxx
