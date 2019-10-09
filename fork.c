 #include <stdio.h>
 #include <unistd.h>
 
int main( void )
{
	printf( "parent pid %d\n", getpid() );
	for ( int i = 0; i < 3; i++ )
		if ( fork() == 0 )
	        {
	            printf( "[son] pid %d from pid %d\n", getpid(), getppid() );
	            exit( 0 );
 	        }
	
	for ( int i = 0; i < 3; i++ )
	        wait( NULL );
}

