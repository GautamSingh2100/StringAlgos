#include <iostream>
using namespace std ;

void permutation(int *array , int n ,int *combi, int * lock , int depth , int level)
{

	if(level >= n)
	{
		return ;
	}

	if(level == depth)
	{
		for(int i = 0 ; i < level ; i ++)
			cout << combi[i] << "  " ;
		cout <<  endl ;
		return ; 
	}

	for(int i = 0 ; i < n ; i ++)
	{
		if(lock[i] ==0)
		{
			lock[i] = 1 ;
			combi[level] = array[i] ;
			permutation(array, n , combi , lock ,depth , level + 1 ) ;		
			lock[i] = 0 ;
		}
	}

}

void combination(int *array , int n ,int *combi, int start , int depth , int level)
{
	if(level == depth)
	{
		for(int i = 0 ; i < level ; i ++)
			cout << combi[i] << "  " ;
		cout <<  endl ;
		return ; 
	}

	if(level >= n)
	{
		return ;
	}

	

	for(int i = start ; i < n ; i ++)
	{
			combi[level] = array[i] ;
			combination(array, n , combi , i + 1 ,depth , level + 1 ) ;		
	}
}


int main() 
{
	int arr[] = {1,2,3,4,5,6,7} ;
	int combi [] = {0,0,0,0,0,0,0,0,0,0} ;
	int lock [] = {0,0,0,0,0,0,0,0,0,0} ;
	permutation(arr, 7, combi,lock  , 3, 0) ;
	combination(arr, 4, combi, 0  , 4, 0) ;

	return 0 ;
}
