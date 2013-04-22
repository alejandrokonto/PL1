#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void q_sort(int a[], int apo, int eos )
{
	int min, max, diax_pos,temp;
	int diax_timi;
	if (eos <= apo) return;
	diax_timi = a[apo];
	min = apo;
	max = eos;
	while ( min < max ) 
	{
		while( a[min] <= diax_timi ) min++;
		while( a[max] > diax_timi ) max--;
		if ( min < max ) 
		{
			temp=a[min];
			a[min]=a[max];
			a[max]=temp;
		}
	}
	a[apo] = a[max];
	a[max] = diax_timi;
	diax_pos=max;
	if (apo<diax_pos)
		q_sort( a, apo, diax_pos-1 );
	if (eos>diax_pos) 
		q_sort( a, diax_pos+1, eos );
 }

int main()
{
     FILE *fp1, *fp2; 
     int *pin, *telos, ar, a, i, j, apo, eos, k, l, apovoli, apovoli1, katastr, b, final_num, final_num1,  *kat, *apov, max_kat;
     char c;
     fp1=fopen("teca.txt" , "r");
     if( fp1==NULL )
     {
         puts("Provlima sto anoigma tou arxeiou");
         exit(2);
     }
     // Diavazw arithmo xwrwn
     fscanf(fp1,"%d", &ar);
     pin=malloc(ar*sizeof(int));
     i=0;
     while (!feof(fp1))
     {
           
           //if (isdigit(c))
           fscanf(fp1, " %d", &a);
           pin[i]=a;
           i++;
     }
     printf(" Arithmos stoixeiwn: %d \n", ar);
     
     fclose(fp1);
     apo=0;
     eos=ar-1;
     q_sort(pin, apo,  eos);
     // Xwres pou menoun an den ginoun apovoles
     // Katastrofes xwrwn!
     katastr=0;
     k=0;
     apovoli=0;
     l=(ar-1)-apovoli;
     while ( k < l)
     {
           if ((2*pin[k])< (pin[l]))
           {
                           katastr=katastr+1;
           }
           else
           {
           k=l;
           }
           k++;
           //printf("2h epan \n");
     }

    final_num1=ar-katastr;
    
    
    
    
    printf("Output %d %d \n", final_num1, apovoli);
    // Apovoles
    k=0;
    l=ar-1;
     
     //Create an array that will have in k-th place the number of 
     // countries that destroy the k-th country
     kat=malloc(ar*sizeof(int));
     // intialization of kat
     for(i=0; i<ar; i++)
     {
              kat[i]=0;
     }
     i=0;
     l=ar-1;
     
     while (i < (ar))
     
     {
           j=0;
           while (j<i)
           {
                 if ((2*pin[j])<pin[i])
                 {
                         kat[i]=kat[i]+1;
                         j++;
                 }
                 else
                 {
                        j=i;
                 }
           }
           i++;
     }
     
     for(i=0; i<(ar);i++)
     {
              printf("katastrofes logw %d : %d  \n", i, kat[i]);
     }
     
     // Find how many apovoles we have to make, so as to keep as many countries as possible in the union
     max_kat=kat[ar-1];
     i=ar-1;
     apovoli=0;
     final_num=ar-kat[ar-1];
     final_num1=ar-kat[ar-1];
     while ( i>0)
     {
           if ((max_kat-kat[i])> (ar-i-1))
           {
                    apovoli1=ar-i-1;
                    final_num1=ar-apovoli1-kat[ar-apovoli1-1];
                    if (final_num1>final_num)
                    {
                         apovoli=ar-i-1;
                         i--;
                         final_num=final_num1;
                    }
                    else
                    
                    i--;
                         
                    
                    
                     
                     
           }
           else
           i--;
     }
     final_num=ar-apovoli-kat[ar-apovoli-1];
     printf("Output2 %d  %d \n", final_num, apovoli);
     free(pin);
     free(kat);
     

     system("pause");
     return(0);
     
}
