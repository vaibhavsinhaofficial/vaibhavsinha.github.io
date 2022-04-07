#include<stdio.h>
#include<conio.h>
void addstudent();
void studentrecord();
void searchstudent();
void deletestudent();

	struct student
	{
		char name[20];
		int roll_no;
		char course[15];
		float percentage;
	};

	void main()
	{
		int choice;
		clrscr();
		while(choice!=5)
		{
			printf("1.add student record\n");
			printf("2.student record\n");
			printf("3.search student\n");
			printf("4.delete record\n");
			printf("5.exit\n");
			printf("\n ENTER OPERATION YOU WANT TO PERFORM: ");
			scanf("%d", &choice);

			switch(choice)
			{
			 case 1:
				clrscr();
				addstudent();
				clrscr();
				break;

			 case 2:
				clrscr();
				studentrecord();
				printf("press any key to exit\n");
				getch();
				clrscr();
				break;

			 case 3:
				clrscr();
				searchstudent();
				printf("\n press any key to exit\n");
				getch();
				clrscr();
				break;

			 case 4:
				clrscr();
				deletestudent();
				printf("\n press any key to exit\n");
				getch();
				clrscr();
				break;

			 default:
				clrscr();
				getch();
				printf("enter a valid number");
				printf("press any key to continue");
				getch();
				clrscr();
				break;
			}
		}
   }

   void addstudent()
   {
	char another;
	FILE *fp;
	struct student info;
	do
	{
		clrscr();
		printf("add student info \n ");
		fp=fopen("student info","a");
		printf("\n Enter Name: ");
		scanf("%s", &info.name);
		printf("\n enter roll number: ");
		scanf("%d", &info.roll_no);
		printf("\n enter course\n ");
		scanf("%s", &info.course);
		printf("\n enter percentage");
		scanf("%f", &info.percentage);

		if(fp==NULL)
		{
			fprintf(stderr, "\n can't open the file");
		}
		else
		{
			printf("\n record stored successfully ");
		}
		fwrite(&info, sizeof (struct student),1,fp);
		fclose(fp);
		printf("\n do you want to add another record (y\n): ");
		scanf("%s", &another);
		}while (another=='y' || another == 'Y');
   }
   void studentrecord()
   {
	FILE *fp;
	struct student info;
	fp=fopen("STUDENT INFO", "r");
	printf("student records\n\n");
	if(fp==NULL)
	{  fprintf(stderr, "can't open the file");
	}
	else
	{
	printf("records\n ");
	printf("-------------------\n \n ");
	}
	while (fread(&info,sizeof(struct student),1,fp))
	{
		printf("\n student name : %s", info.name);
		printf("\n roll number: %d", info.roll_no);
		printf("\n course : %s", info.course);
		printf("\n percentage : %f", info.percentage);
		printf("\n ---------------------------");
	 }
	 fclose (fp);
	 getch();
   }
   void searchstudent()
   {
   FILE *fp;
   struct student info;
   int roll_no, found = 0;
   fp=fopen("student info", "r");
   printf("\n search student \n \n");
   printf("enter roll number: ");
   scanf("%d", &roll_no);

   while(fread(&info,sizeof(struct student),1,fp))
   {
   found=1;
   printf("\n student name : %s", info.name);
   printf("\n roll number: %d" , info.roll_no);
   printf("\n course : %s", info.course);
   printf("\n percentage: %f", info.percentage);
   }
  if (!found)
	{
	printf("\n record not found");
	}
	fclose(fp);
	getch();
	}

	void deletestudent()
	{
		FILE *fp, *fp1;
		struct student info;
		int roll_no, found=0;
		printf("delete student \n\n");
		fp=fopen("student info", "r");
		fp1=fopen("temp.text", "w");
		printf("Enter roll no: ");
		scanf("%d", &roll_no);
		if(fp==NULL)
		{
			fprintf(stderr, "can't open file\n");
		}
		while (fread(&info, sizeof(struct student),1,fp))
		{
		if(info.roll_no == roll_no)
		{
		found = 1;
		}
		else
		{
		fwrite(&info, sizeof(struct student),1,fp1);
		}
	 }
	 fclose(fp);
	 fclose(fp1);
	 if(found)
	 {
		remove("studentinfo");
		rename("temp.text", "studentinfo");
		printf("record deleted successfully");

	  }
	  if(!found)
	  {
	  printf("record not found");
	  }
	  getch();
	  }