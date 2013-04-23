#include <stdio.h>
#include <stdlib.h>

 typedef struct
        {
                int species;
                int height;
        } Player;

void display(Player list[], int n);
void swap(Player *x,Player *y);
int choose_pivot(int i,int j );
void quicksort(Player list[],int m,int n);

main(){
	
       
	FILE *fp;
	
      int i,j, SIZE, SPECIES;
      Player *canditates;
      fp = fopen("basket.txt", "r");
      if(fp==NULL){
         printf("Problem locating the input file\n");
      }
     
	  /*allocate memory according to datasize and number of species*/
	  fscanf(fp,"%d %d\n", &SIZE, &SPECIES);
      canditates=malloc(SIZE*sizeof(Player));
      /*heightParser=malloc(SPECIES*sizeof(int));*/
           Player  *heightParser[SPECIES];
           Player  *first, *last, *moving;
      
           
       /*Read datasheet*/   
		for(i=0;i<SIZE;i++){
		
			fscanf(fp,"%d %d\n",&canditates[i].species, &canditates[i].height);
		}
           
      close(fp);
           
      /*
         printf("Eisodos:\n");
         display(canditates,SIZE);
      */
       quicksort(canditates,0,SIZE-1);
        
        printf("Meta thn taksinomhsh\n");
       display(canditates,SIZE);
       
       
    
      
      
   
}

void swap(Player *x,Player *y)
{
    Player temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(Player list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m].height;
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i].height <= key))
                i++;
            while((j >= m) && (list[j].height > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}
void display(Player list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d %d\n",list[i].species,list[i].height);
         printf("\n");
}
