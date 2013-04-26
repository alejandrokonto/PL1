#include <stdio.h>
#include <stdlib.h>

 typedef struct
        {
                int species;
                int height;
        } Player;

void display(Player list[], int n);
void displayParser(int list[], const int n);
void swap(Player *x,Player *y);
int choose_pivot(int i,int j );
void quicksort(Player list[],int m,int n);
void initializeArray(int list[], const int n);

main(){
	
       
	FILE *fp;
	
      int i,j,k,tail,min,head,heightDiff, SIZE, SPECIES, *heightParser;
      Player *canditates;
      heightDiff=0;
      fp = fopen("test.txt", "r");
      if(fp==NULL){
         printf("Problem locating the input file\n");
      }
     
	  /*allocate memory according to datasize and number of species*/
	  fscanf(fp,"%d %d\n", &SIZE, &SPECIES);
	  printf("%d %d\n",SIZE,SPECIES);
      canditates=malloc(SIZE*sizeof(Player));
      heightParser=malloc(SPECIES*sizeof(int));
      
        initializeArray(heightParser,SPECIES);   
       /*Read datasheet*/   
		for(i=0;i<SIZE;i++){
		
			fscanf(fp,"%d %d\n",&canditates[i].species, &canditates[i].height);
		}
           printf("efdafds");
      close(fp);
        
      
       quicksort(canditates,0,SIZE-1);
        
       printf("kai edw");
       
       /*initialize Player pointers to their starting values*/
       i=1;
       k=1;
       head=0;
       tail=0;
       
       while(i<SPECIES-1){
			
			if(heightParser[canditates[k].species -1] ==0 && canditates[k].species!=canditates[tail].species ){
			   heightParser[canditates[k].species -1] = k;
			  
			   i++;
			   }
			   k++;
       } printf("kai edw231");
       head = k-1;
       min = canditates[head].height - canditates[tail].height;
      printf("Tail:%d Head:%d\nMinimun difference so far:%d (heightDiff is %d)\n",tail,head,min, heightDiff);  	   
   /* printf("the parser goes like this:\n");
    displayParser(heightParser,SPECIES);*/
		
		/*begin the actual parsing*/  
        while(head<SIZE-1){
			
        
         /*check to which point your tail could lower the difference*/
         if(canditates[tail].species==canditates[tail+1].species){
				
				while(canditates[tail].species==canditates[tail+1].species){
				tail++;
				   }
				heightParser[canditates[tail].species -1] = tail;
		        heightDiff = canditates[head].height - canditates[tail].height;
                 if( heightDiff < min)min = heightDiff;
         }
         heightDiff = canditates[head].height - canditates[tail].height;
       if( heightDiff < min)min = heightDiff;
	   /*move the head of the parser*/
	   head++; 
	   heightParser[canditates[head].species - 1] = head;
	  if(canditates[head].species == canditates[tail].species){
			tail+=1;
			while(tail < heightParser[canditates[tail].species - 1]){
				tail++;
			}
		
			
	  }
	  
	   heightDiff = canditates[head].height - canditates[tail].height;
       if( heightDiff < min)min = heightDiff;
	  
	   
    
     printf("Tail:%d Head:%d\nMinimun difference so far:%d (heightDiff is %d)\n",tail,head,min, heightDiff);      
      
	}
   
   printf("oops did it again\n");
   heightDiff = canditates[head].height - canditates[tail].height;
       if( heightDiff < min)min = heightDiff;
	  
     printf("Tail:%d Head:%d\nMinimun difference so far:%d (heightDiff is %d)\n",tail,head,min, heightDiff); 
	   
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
void displayParser(int list[], const int n){
	int i;
	for(i=0;i<n;i++)
	   printf("To eidos:%d  Brisketai sth 8esh:%d\n",i+1,list[i]);
	   printf("\n");
}
void initializeArray(int list[], const int n){
	int i;
	for(i=0;i<n;i++)
	 list[i]= 0;
}
