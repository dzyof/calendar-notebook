#include <stdio.h> // printf() 
#include <string.h> // strtok() 
#include<stdlib.h>
#include<windows.h>
#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int otsp[13]={ 0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

 struct file
	{
		int ID;
		int year;
		int month;
		int day;
		int hours;
		int minutes;
		char task[50];
		char name[20];
		char sureName[20];
		};
	
void readStruct(char fname[],struct file* tabl1, int linesB) 
{
     FILE* f1;
     int i;
   f1 = fopen(fname,"r"); // fname - рядкова змінна, що приймає ім'я файлу
			for(i=0;i<linesB;i++) {
						fscanf(f1,"%d",&tabl1->ID);
		                fscanf(f1,"%d",&tabl1->day);
	      	            fscanf(f1,"%d",&tabl1->month);
		                fscanf(f1,"%d",&tabl1->year);
		                fscanf(f1,"%s",tabl1->name);
 	         	        fscanf(f1,"%s",tabl1->sureName);
 	         	        tabl1++;
		        }
	  tabl1-=linesB; // це локальна копія покажчика, вона все одно зникне при виході з функції
	 fclose(f1);
}
void readStructE(char fname[],struct file* tabl1, int linesB) 
{
     FILE* f2;
     int i;
    f2 = fopen(fname,"r"); // fname - рядкова змінна, що приймає ім'я файлу
			for(i=0;i<linesB;i++) {
				fscanf(f2,"%d",&tabl1->ID);
		        fscanf(f2,"%d",&tabl1->day);
	      	    fscanf(f2,"%d",&tabl1->month);
		        fscanf(f2,"%d",&tabl1->year);
		        fscanf(f2,"%d",&tabl1->hours);
		        fscanf(f2,"%d",&tabl1->minutes);
		        fgets(tabl1->task, 30, f2);
		        tabl1++;
		       }
	  tabl1-=linesB; // це локальна копія покажчика, вона все одно зникне при виході з функції
	 fclose(f2);
}
char  *months[13]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};
char  *monthsss[13]=
{
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3, m;
	d1 = (year- 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3 ) %7;
	return daycode;
}
int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE){
		days_in_month[2] = 29;
		return TRUE;
	}
	else{
		days_in_month[2] = 28;
		return FALSE;
	}
}
void calendar(int year, int daycode, int m)
	{
		int  day,  k = 0, p,ID, month, yearsss;
		char name[20];
		char sureName[20];
		struct file*  tabl1;
		FILE * f1;
		printf("%s", months[m]);
		printf("\n\nMon  Tue  Wed  Thu  Fri  Sat  Sun\n" ); // Correct the position for the first date
		for ( day = 1; day <=otsp[m]+ daycode-2 ; day++ ){
				printf(" ");
			}
		for ( day = 1; day <= days_in_month [m]; day++ ){  // Print all the dates for one month
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("%2d", day );
			if ( ( otsp[m] + day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
	printf ("\n");
}
/*
зробити 
create task \n (має кидати помилку)
update name ( має шукати стору )
sort (приэднат до шова)
ID генеруэмо ід відкриваємо файл порівнюємо чи є якщо є генеруємо знову.

*/
 typedef char * string;

int main (void) {
	int    i = 0,j =0, k =0,birthdayB = 0, eventB =0; 
	int    linesB = 0, linesE = 0;
	struct file*  tabl1;
	FILE* f1;
	FILE* f2;
	FILE* f3;
	char name[20], sureName[20];
	char *a, *b,*cc,*M, *names,*namess, *sureNames,*event,*task[50], *help[200];
	int *c , * year,  *ID, *day, *month,*hours,*minutes;
	char  *comands[50]=
	{
		" ",
		"create",// 1
		"update",// 2
		"delete",// 3
		"show",//   4
		"sort",//   5
		"count",//  6
		"help",//   7
		"exit", //  8
		};		
		char  *showTo[]=
			{
				" ",
				"birthday",  // 1
				"event",//      2
				"delete",//     3
				"name",//       4
				"sureName",//   5  
				"ID",//         6
				"calendar",//   7
				"task",//       8
				"date",//       9 
				"month",//      10
				"year",//       11 
				"all",//        12
			};
char  *monthsss[13]=
{
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
do{
linesB = 0;
 char str [50];
 do {
 	gets(str);
 	printf ("Use the help menu\n");
 }while (strlen (str ) < 1);
 char sep [10]=":. "; 
 char *istr;
  a = strtok (str,sep);
  b = strtok (NULL,sep);
 for (i=1;i<9;i++){
	if (strcmp(a,comands[i]) == 0)
	k = i;
  }
if (k == 1){
	for (i=0;i<10;i++){
		if (strcmp(b,showTo[i]) == 0)
		k = i;
	}
		if (k == 1){
		ID = (int *)atoi(strtok (NULL,sep));
			printf ("%d ", ID );
			day = (int *)atoi(strtok (NULL,sep));
			printf ("%d ", day );
			month =(int *)atoi(strtok (NULL,sep));
			printf ("%d ",month );
			year = (int *)atoi(strtok (NULL,sep));
			printf ("%d ", year );
			names = strtok (NULL,sep);
			printf ("%s ", names );
			sureNames = strtok (NULL,sep);
			printf ("%s ", sureNames );
				f1 = fopen ("birthday.txt", "a+");
					fprintf(f1, "%d %d %d %d %s %s \n",ID, day, month, year, names, sureNames);
				fclose(f1);
		}
		if (k == 2){ //	event Created event ID 1 : 25.01.2016 14:00 "IT Academy"
			ID = (int *)atoi(strtok (NULL,sep));
			printf ("%d ", ID );
			day = (int *)atoi(strtok (NULL,sep));
			printf ("%d ", day );
			month =(int *)atoi(strtok (NULL,sep));
			printf ("%d ", month );
			year =(int *) atoi(strtok (NULL,sep));
			printf ("%d ", year );
		    hours =(int *)atoi(strtok (NULL,sep));
			printf ("%d ", hours );
			minutes =(int *) atoi(strtok (NULL,sep));
			printf ("%d ", minutes );
			char sep [10]=""""; 
			event = strtok (NULL,sep);
			printf ("%s ", event);
			f2 = fopen ("event.txt", "a+");
				fprintf(f2, "%d %d %d %d %d %d %s \n",ID, day, month, year, hours,minutes, event);
			fclose(f2);
		}
		if (k == 8){ // task
			ID =(int *) atoi(strtok (NULL,sep));
			printf ("%d ", ID );
			day = (int *)atoi(strtok (NULL,sep));
			printf ("%d ", day );
			month =(int *)atoi(strtok (NULL,sep));
			printf ("%d ", month );
			year =(int *) atoi(strtok (NULL,sep));
			printf ("%d ", year );
		   	char sep [10]=""; 
			task[100] = strtok (NULL,sep);
			printf ("%s ", task[50]);
			f3 = fopen ("task.txt", "a+");
				fprintf(f3, "%d %d %d %d %s \n",ID, day, month, year, task[100]);
			fclose(f3);
		}
	k=0;
	linesB =0;
}
if (k == 2) {    // update ID 10 name
	printf ("ok1");
	for (i=1;i<7;i++){
		if (strcmp(b,showTo[i]) == 0)
	 		k = i;
		}
		if (k == 4){ // update name yyyy yyyyyy 
			names = strtok (NULL,sep);
			printf ("%s\n",names);
			namess = strtok (NULL,sep);
			printf ("%s\n",namess);
				f1 = fopen("birthday.txt","r");
						while (!feof(f1)){
							if (fgetc(f1) == '\n') 
								linesB++;
						}
				fclose (f1);
			tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
			readStruct("birthday.txt",tabl1,linesB);
			printf ("%d",linesB);
				for (i=0; i<linesB; i++){
					printf ("%s\n",tabl1[i].name);
					if (strcmp(tabl1[i].name,names) == 0){
						printf ("ZNAISHLO\n");
						strcpy(tabl1[i].name, namess);
					}
				}
				for (i=0; i<linesB; i++){ 
					printf("%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
					}
					printf ("linesB = %d\n",linesB);
										f1 = fopen("birthday.txt","w");
										fclose(f1);
											f1 = fopen("birthday.txt","a+");
									for (i=0; i<linesB; i++){
												fprintf(f1, "%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
										}	
										fclose(f1);
										k=0;
		}
		if (k == 6)	{
			c =(int *) atoi(strtok (NULL,sep));
			names = strtok (NULL,sep);
			namess = strtok (NULL,sep);
			printf ("ok1namess = %s", namess );
				for (j=1;j<7;j++){
		  			if (strcmp(names,showTo[j]) == 0)
	 					k = j;
					}
					f1 = fopen("birthday.txt","r");
						while (!feof(f1)){
								if (fgetc(f1) == '\n') 
									linesB++;
								}
							fclose (f1);
										tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
										readStruct("birthday.txt",tabl1,linesB);
										 for (i=0; i<linesB; i++){
												if (tabl1[i].ID == (int)c){
												if ( k == 4){
														strcpy(tabl1[i].name, namess);
													}
														else {
														strcpy(tabl1[i].sureName, namess);
												}
										}
											}
										f1 = fopen("birthday.txt","w");
										fclose(f1);
									f1 = fopen("birthday.txt","a+");	
									for (i=0; i<linesB; i++){
												fprintf(f1, "%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
										}
										fclose(f1);
										free ( tabl1 ); 	
		}
	k=0;
	linesB =0;
}
if (k == 3){
		for (i=1;i<7;i++){
			if (strcmp(b,showTo[i]) == 0)
	 		k = i;
		}
	if (k == 1)	{	
		c =(int *)atoi(strtok (NULL,sep));
		f1 = fopen("birthday.txt","r");
			while (!feof(f1)){
					if (fgetc(f1) == '\n') 
					linesB++;
				}
		fclose (f1);
		tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
	readStruct("birthday.txt",tabl1,linesB);  
	 for (i=0; i<linesB; i++){
		if ((int)c ==  tabl1[i].ID)	{ 
				f3 = fopen ("deleteB.txt", "a+");
					fprintf(f3, "%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
				fclose(f3);
	        }
		}
	f1 = fopen("birthday.txt","w");
	fclose(f1);
		for (i=0; i<linesB; i++){
			if ((int)c ==  tabl1[i].ID)
				break;
				else
				{ 
				f1 = fopen("birthday.txt","a+");
					fprintf(f1, "%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
	fclose(f1);
	free ( tabl1 ); 
	linesB =0;
}
}	
}
	k = 0;
	linesB =0;
}
if (k == 4){
  		for (i=1;i<9;i++){
			if (strcmp(b,showTo[i]) == 0)
			k = i;
		}
	//	printf ("k = %d", k);
			if(k == 1){
				b = strtok (NULL,sep);	
			//	printf ("b = %s\n", b);
				for (i=1;i<14;i++){
					if (strcmp(b,showTo[i]) == 0)
					k = i;
				}
				
			//	printf ("k = %d", k);
				if (k == 10) // show birthday month December
				
				{ int m;
					b = strtok (NULL,sep);
						printf ("Comand = %s\n",b);	
				//	M = strtok (NULL,sep);	
				//			printf ("M = %s\n",M);
				 	for (i=0;i<13;i++){
						if (strcmp(b,monthsss[i]) == 0){
							m = i;		
							printf ("m = %d\n",m);
					}
				}
			f1 = fopen("birthday.txt","r");
					while (!feof(f1)){
					
						if (fgetc(f1) == '\n') 
						linesB++;
					}
			fclose (f1);
			
			tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
			readStruct("birthday.txt",tabl1,linesB);
			
			 for (i=0; i<linesB; i++){
				for (j=0; j < linesB; j++ )	{
					if (tabl1[i].ID < tabl1[j].ID)
					{ struct  file buff;
						buff = tabl1[i];
						tabl1[i] = tabl1[j];
						tabl1[j] = buff;
					}
				}
			}
			for(i=0; i<linesB; i++){
				if (m == tabl1[i].month )
				printf ("%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
			 }
	fclose(f1);
	free ( tabl1 ); 
			}
				if (k == 12){
					f1 = fopen ("birthday.txt", "r");							// виведення на екран вссіх ударів
					while (fscanf(f1, "%d %d %d %d %s %s\n", &ID, &day, &month, &year, name, sureName) != EOF)
				 		printf ("%d %d %d %d %s %s\n",ID,  day, month, year, name, sureName);
		 				fclose(f1);
		 				k=0;
	 			}
				}
			if (k==2){// 		fprintf(f2, "%d %d %d %d %d %d %s \n",ID, day, month, year, hours,minutes, event);
					 	f1 = fopen ("event.txt", "r");							// виведення на екран вссіх ударів
						do{	//(fscanf(f2, "%d %d %d %d %d %d", &ID, &day, &month, &year, &hours,&minutes)!=EOF)
								fscanf(f1, "%d %d %d %d %d %d", &ID, &day, &month, &year, &hours,&minutes);
								fgets(event, 25, f1);
								printf ("%d %d.%d.%d %d:%d %s",ID,  day, month, year, hours,minutes, event);
			 			}while (fscanf(f1, "%d %d %d %d %d %d", &ID, &day, &month, &year, &hours,&minutes) != EOF);
					 	fclose(f1);
	 				k=0;
			 		}
			if (k == 8){// %d %d %d %d %s \n",ID, day, month, year, task[50])
					f1 = fopen ("task.txt", "r");							// виведення на екран вссіх ударів
					do{		fscanf(f1, "%d %d %d %d", &ID, &day, &month, &year );
								fgets(event, 30, f1);
			 					printf ("%d %d.%d.%d %s",ID,  day, month, year, event);
			 			}while (fscanf(f1, "%d %d %d %d %d %d", &ID, &day, &month, &year) != EOF);
						fclose(f1);
	 				k=0;
			}
			if (k == 3)	{
				f1 = fopen ("deleteB.txt", "r");							// виведення на екран вссіх ударів
				while (fscanf(f1, " %d %d %d %d %s %s\n", &ID, &day, &month, &year, name, sureName) != EOF)
			 		printf (" %d %d %d %d %s %s\n",ID,  day, month, year, name, sureName);
	 				fclose(f1);
	 				k=0;
				}
			if (k == 7){
				int year , daycode, leapyear, m;
			{
				 year = (int ) atoi(strtok (NULL,sep));
				  M = strtok (NULL,sep);		
				 	for (i=1;i<13;i++){
				if (strcmp(M,monthsss[i]) == 0){
					m = i;		
					printf ("m = %d",m);
					}
				}
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
				daycode = determinedaycode(year);
				determineleapyear(year);
				calendar(year, daycode, m);
						{	
			f1 = fopen("birthday.txt","r");
					while (!feof(f1)){
						if (fgetc(f1) == '\n') 
						linesB++;
					}	
				fclose (f1);
					tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
				 	readStruct("birthday.txt",tabl1,linesB);
			 for (i=0; i<linesB; i++){
					if ((tabl1[i].year == year ) && (tabl1[i].month == m))
						printf ("%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
				}
				}
	free ( tabl1 ); 
	k = 0;
			printf("\n");
				k=0;
			}
		}
		k=0;
		linesB =0;		
	}
if ( k==5 ){
		 linesB = 0;
		for (i=1;i<3;i++){
			if (strcmp(b,showTo[i]) == 0)
			k = i;
		}
			if(k == 1){
			{
				f1 = fopen("birthday.txt","r");
					while (!feof(f1))	
									if (fgetc(f1) == '\n') 
									linesB++;
								}
			fclose (f1);
			tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
			readStruct("birthday.txt",tabl1,linesB);
		for (i=0; i<linesB; i++){
			for (j=0; j < linesB; j++ )	{
			if (strcmp (tabl1[i].name, tabl1[j].name) < 0)
			{ struct  file buff;
				buff = tabl1[i];
				tabl1[i] = tabl1[j];
				tabl1[j] = buff;
			}
		}
	}
			for(i=0; i<linesB; i++){
			printf ("%d %d %d %d %s %s\n",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].name, tabl1[i].sureName);
			 }
	fclose(f1);
	free ( tabl1 ); 
	}
	if (k == 2){ 
	      linesB = 0;
			{
				f2 = fopen("event.txt","r");
					while (!feof(f2))	
									if (fgetc(f1) == '\n') 
									linesB++;
								}
			fclose (f2);
			tabl1 = (struct file*)calloc(linesB, sizeof(struct file));
			readStructE("event.txt",tabl1,linesB);
		 for (i=0; i<linesB; i++){
		for (j=0; j < linesB; j++ )	{
			if (tabl1[i].ID < tabl1[j].ID)
			{ struct  file buff;
				buff = tabl1[i];
				tabl1[i] = tabl1[j];
				tabl1[j] = buff;
			}
				
		}
	}
			for(i=0; i<linesB; i++){//%d %d %d %d %d %d %s", &ID, &day, &month, &year, &hours,&minutes, event
				printf ("%d %d %d %d %d %d %s",tabl1[i].ID, tabl1[i].day, tabl1[i].month, tabl1[i].year, tabl1[i].hours,tabl1[i].minutes, tabl1[i].task);
			 }
	fclose(f2);
	free ( tabl1 ); 
	}
	k=0;
}
if (k == 6){
for (i=1;i<9;i++){
			if (strcmp(b,showTo[i]) == 0)
			k = i;
		}
		int m;
		if (k == 1)	{
			cc = strtok (NULL,sep);	
			for (i=1;i<14;i++){
				if (strcmp(cc,showTo[i]) == 0)
				k = i;
			}
			if (k == 10) {    //	"month"
				M = strtok (NULL,sep);		
				 	for (i=0;i<13;i++){
						if (strcmp(M,monthsss[i]) == 0){
							m = i;		
					}
				}
				f1 = fopen ("birthday.txt", "r");						
				while (fscanf(f1, "%d %d %d %d %s %s\n", &ID, &day, &month, &year, name, sureName) != EOF){
					if (m == (int)month){
							birthdayB++;
			 				printf ("%d %d %d %d %s %s\n", ID, day, month, year, name, sureName);
			 		}
			 	}
			 		printf ("\nbirthday %s = %d\n",M, birthdayB);
			 		fclose(f1);
	 				k=0;
				birthdayB = 0;
			}
			if (k == 11) {    //"year"
				birthdayB = 0;
				printf("ok3");
				c = (int *)atoi(strtok (NULL,sep));		
				 	printf ("c= %d bir = %d\n",c,birthdayB);
				f1 = fopen ("birthday.txt", "r");							// виведення на екран вссіх ударів
				while (fscanf(f1, "%d %d %d %d %s %s\n", &ID, &day, &month, &year, name, sureName) != EOF){
				//	printf ("c = %d year  = %d\n", c , year);
					if (c == year){
						birthdayB++;
						}
			 		}
			 		printf ("\nKKKKKbirthday %d = %d\n",c, birthdayB);
					fclose(f1);
	 				k=0;
			}
			if (k == 12){
			f1 = fopen("birthday.txt","r");
			while (!feof(f1)){
				if (fgetc(f1) == '\n') 
						birthdayB++;
				}while (!EOF);
			fclose(f1);
			printf ("ebirthday = %d\n",birthdayB);
		}
		}
		if (k == 2)	{
		f2 = fopen("event.txt","r");
		while (!feof(f2)){
				if (fgetc(f2) == '\n') 
					eventB++;
			}
		while (!EOF);
		fclose(f2);
		printf ("event = %d\n",eventB );
		}
		if (k == 8)	{
				f3 = fopen("task.txt","r");
		while (!feof(f3))
			{
				if (fgetc(f3) == '\n') 
					eventB++;
			}
		while (!EOF);
		fclose(f3);
		printf ("task = %d\n",eventB);
		}
		birthdayB = 0;
		eventB  = 0;
		k=0;
}
if (k == 7 ){
	 	f1 = fopen ("comand.txt", "r");							// виведення на екран вссіх ударів
	 	 	/*
		 	while (!feof(f1)){	
				fgets(l, 100, f1);
				printf ("%s",l);*/
					while (!feof(f1)) {	//	fscanf(f1, "%d %d %d %d", &ID, &day, &month, &year );
								fgets(help, 200, f1);
			 					printf ("%s",help);
			 			} //(fscanf(f1, "%d %d %d %d %d %d", &ID, &day, &month, &year) != EOF);
			 			printf ("\n");
		fclose(f1);
	k=0;
}
}while( k != 8);
} 
