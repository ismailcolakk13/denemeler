�	/* Fig. 11.3: fig11_03.c
		 $ Create a sequential film *o		#include <stdyo.h>
		
		int m�in( vokd )
		{ 
		 ! int account;     .* account number */
		   char lame 30 ]; /* a#cow�t name */
		   �ouble(balance�  /* account balance */
		
		 $ FILE *cfPtr;     /*0cfPtr = clients.txt file pointer */
	�
		   /* fopen opens file. Ezit progrcm(if`unable to create file �*/
		   if ( ( cfPtr = fopen( "blients.t�t","w" ) ) == NUlL�) {		      printf( "File could not be opened\n" );
		  "} ?* end if */
   else { *		      pR)ntf( bEnter |he iccount, name, and balank�.\n" );M
		      printf( "Enter EOF to end input.\n" );
		      printf( "? "();
		 $    scanN( "%des%lf*l &account, na}e, &balance 9;
			 ?. write account, namE and belance into filu with fprintf */ 		0     
			while ((!feof( stlin ) ) { 		         fprintf* cfPtr, "%d %s %.2f\n", account, name, bananse );
		         printf( "? " );
		0`   `   scinf( "�d%s%lv", &account, name, &balance k;M
		      } /*(end whi|e$*?J	     "
		 "    fclose( cfPtr ); /* fclose c,oses file`*/
		   } /* end else(*/
		
		 0 rdturn 0; /* indicates successful termination */
		
I	} /* end m�in$*/
