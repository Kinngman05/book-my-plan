/*
This is my class 12(XII) project written solely by be.
The project is a ticketing system which uses all the concept of OOP in C++ except inheritance.
The code was made in the TURBOC3 IDE and developed for DOS.
Date of developement: Jan 2016 
*/
//
//PREPROCESSOR
//
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<iomanip.h>
//
//                                                         ENMURATED DATATYPE
//
enum seat_empty_full{empty,full};
//
//                                                         GLOBAL VARIABLE
//
char password[20];
char password_to_delete[]="kingsmen";
//
//                                                         FUNCTION PROTOTYPE
//
void open_page();//The first page of the program
void movie();
void concert();
void sports();
void GET_INFO();
seat_empty_full check(int,int,char []);
seat_empty_full check(char,char,char []);
void write(char,char,char []);
void close_page();
void line();
void clear_all_data();
//
//                                                                  STRUCTURE
//
struct day //Structure to store data of date,month and year
{
 int date;
 int month;
 int year;
};
//
//                                                                      CLASS
//
class TICKETING
{
 private:
	   char name[20];
	   int number_of_booking;
	   char email_id[30];
	   int price;
	   char phone_number[11];
	   int total;
	   char login[10];
	   char bank_name[20];
	   day d,date_of_booking;
	   int hour;
	   char movie_theatre_choice[20];
	   char seat_number[10][2];
	   char movie_booked[15];
	   double card_number;
	   char cvv[10];
	   char otp[10];
	   char expiry_date[10];
	   char text_file[20];
 public:
	   char select_page();//To display and take choice of kind of booking
	   void choice_window_page();//To print the table and take choice
	   void input_data();//To input data of timings and place of movie
	   void display_outlay_of_theatre();//Display look of theatre
	   void payment_of_bill();//To ask mode of payment of bill
	   void payment_by_creditcard();//To pay by creditcard
	   void payment_by_netbanking();//To pay by netbanking
	   void payment_by_vipsmoney();//To pay by VIP money
	   void store_data();//To store the data in a .DAT file
	   void output_data();//To display all the datails of this object
	   void read_data();//To read the data from a .DAT file
	   void delete_current_record(int);
};
class SPORTS
{
 private:
	   day date_of_booking;
	   char sport_booked[20];
	   int price;
	   int total;
	   char name[20];
	   char email_id[30];
	   char phone_number[11];
	   char login[10];
	   char bank_name[20];
	   int number_of_booking;
	   char block;
	   int seat_number;
	   double card_number;
	   char cvv[10];
	   char otp[10];
	   char expiry_date[10];
 public:
	   void choice_window_page();
	   void input_data();
	   void payment_of_bill();
	   void payment_by_creditcard();//To pay by creditcard
	   void payment_by_netbanking();//To pay by netbanking
	   void payment_by_vipsmoney();//To pay by VIP money
	   void store_data();
	   void output_data();//To display the details
	   void read_data();//To read the data from a .DAT file
	   void delete_current_record(int n);
};
class CONCERT
{
 private:
	   day date_of_booking;
	   int price;
	   int total;
	   char name[20];
	   char email_id[30];
	   char phone_number[11];
	   char login[10];
	   char bank_name[20];
	   int number_of_booking;
	   char block;
	   int seat_number;
	   char concert_choice[15];
	   int total_amount;
	   double card_number;
	   char cvv[10];
	   char otp[10];
	   char expiry_date[10];
 public:
	   void choice_window_page();
	   void input_data();
	   void payment_of_bill();
	   void payment_by_creditcard();//To pay by creditcard
	   void payment_by_netbanking();//To pay by netbanking
	   void payment_by_vipsmoney();//To pay by VIP money
	   void store_data();
	   void output_data();//To display the details
	   void read_data();//To read the data from a .DAT file
	   void delete_current_record(int n);
};
//
//                                                   CREATING OBJECT OF CLASS
//
TICKETING t;
SPORTS sp;
CONCERT c;
//
//                                                        FUNCTION DEFINITION
//
void concert()
{
 c.choice_window_page();
 c.input_data();
 c.payment_of_bill();
}
void sports()
{
 sp.choice_window_page();
 sp.input_data();
 sp.payment_of_bill();
}
void movies()
{
 t.choice_window_page();
 t.input_data();
 t.display_outlay_of_theatre();
 t.payment_of_bill();
}
void GET_INFO()
{
 clrscr();
 gotoxy(20,12);
 cout<<" Enter the password: ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 if(strcmp(password,password_to_delete)==0)
 {
  char choice;
  do
  {
   clrscr();
   cout<<"\n            ";
   cout<<"\n 1-> SPORTS ";
   cout<<"\n 2-> MOVIE  ";
   cout<<"\n 3-> CONCERT";
   cout<<"\n Enter your choice: ";
   cin>>choice;
   if(choice=='1')
    sp.read_data();
   else if(choice=='2')
    t.read_data();
   else if(choice=='3')
    c.read_data();
   else if(choice=='9')
    clear_all_data();
   getch();
  }while(choice==1||choice==2||choice==3);
 }
}
void open_page()
{
 /* request auto detection */
 int gdriver = DETECT, gmode, errorcode;
 int style, midx, midy;
 int size = 5;

 /* initialize graphics and local variables */
 initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

 /* read result of initialization */
 errorcode = graphresult();
 if (errorcode != grOk)  /* if true means an error occurred */
 {
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error code */
 }

 midx = getmaxx() / 2; // Gets half of maximum x co-ordinate
 midy = getmaxy() / 4; // Gets half of maximum y co-ordinate

 setbkcolor(RED); // Sets the background color
 setcolor(BLUE);  // Stes the text color
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 cleardevice();   // Clears the screen in graphics mode

 settextstyle(DEFAULT_FONT, HORIZ_DIR, size+2); // Sets text style

 outtextxy(1.1*midx, midy," WELCOME  "); // Output a message
 outtextxy(midx, 2*midy," TO THE ");
 settextstyle(DEFAULT_FONT, HORIZ_DIR, size);
 /* output a message */
 outtextxy(midx, 3*midy," VIP TICKETING");

 delay(3000);
 /* clean up */
 closegraph();
}
seat_empty_full check(int i,int j,char file[])
{
 char bc[3],var[3];
 i++;
 itoa(i,var,10);
 if(j==0)       strcat(var,"A");
 else if(j==1)  strcat(var,"B");
 else if(j==2)  strcat(var,"C");
 else if(j==3)  strcat(var,"D");
 else if(j==4)  strcat(var,"E");
 else if(j==5)  strcat(var,"F");
 else if(j==6)  strcat(var,"G");
 else if(j==7)  strcat(var,"H");
 else if(j==8)  strcat(var,"I");
 else if(j==9)  strcat(var,"J");
 else if(j==10) strcat(var,"K");
 else if(j==11) strcat(var,"L");
 else if(j==12) strcat(var,"M");
 else if(j==13) strcat(var,"N");
 else if(j==14) strcat(var,"O");
 else if(j==15) strcat(var,"P");
 else if(j==16) strcat(var,"Q");
 else if(j==17) strcat(var,"R");
 else if(j==18) strcat(var,"S");
 else if(j==19) strcat(var,"T");
 else if(j==20) strcat(var,"U");
 else if(j==21) strcat(var,"V");
 else if(j==22) strcat(var,"W");
 else if(j==23) strcat(var,"X");
 else if(j==24) strcat(var,"Y");
 else if(j==25) strcat(var,"Z");
 ifstream in(file,ios::in);
 while(!in.eof())
 {
  in.getline(bc,3,'\n');
  if(strcmp(var,bc)==0)
  {
   return full;
  }
 }
 in.close();
 return empty;
}
seat_empty_full check(char a,char b,char file[])
{
 char bc[3],var[3];
 var[0]=a;
 var[1]=b;
 var[2]='\0';
 ifstream in(file,ios::in);
 while(!in.eof())
 {
  in.getline(bc,3,'\n');
  if(strcmp(var,bc)==0)
  {
   return full;
  }
 }
 in.close();
 return empty;
}
void write(char a,char b,char name[])
{
 ofstream file_out(name,ios::out|ios::app);
 if(!file_out)
 {
  cout<<"\n The file "<<name<<" was unable to open.";
 }
 else
 {
  file_out<<a<<b<<endl;
 }
 file_out.close();
}
void close_page()
{
 /* request auto detection */
 int gdriver = DETECT, gmode, errorcode;
 int style, midx, midy;
 int size = 5;

 /* initialize graphics and local variables */
 initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

 /* read result of initialization */
 errorcode = graphresult();
 if (errorcode != grOk)  /* if true means an error occurred */
 {
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error code */
 }

 midx = getmaxx() / 2; // Gets half of maximum x co-ordinate
 midy = getmaxy() / 4; // Gets half of maximum y co-ordinate

 setbkcolor(CYAN); // Sets the background color
 setcolor(BLUE);  // Stes the text color
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 cleardevice();   // Clears the screen in graphics mode

 settextstyle(DEFAULT_FONT, HORIZ_DIR, size); // Sets text style

 outtextxy(1.1*midx, midy," THANK YOU  "); // Output a message
 outtextxy(midx, 2*midy,"FOR BOOKING VIA");
 settextstyle(DEFAULT_FONT, HORIZ_DIR, size);
 /* output a message */
 outtextxy(midx, 3*midy,"VIP TICKETING!");

 delay(2000);
 /* clean up */
 closegraph();
}
void line()
{
 const char asterisk='*';
 for(int i=0;i<80;i++)
  cout<<asterisk;
}
void clear_all_data()
{
 clrscr();
 gotoxy(20,12);
 cout<<" Enter the password: ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 if(strcmp(password,password_to_delete)==0)
 {
  ofstream out("VIPMVE.DAT",ios::trunc);
  out.close();
  out.open("VIPCNCRT.DAT",ios::trunc);
  out.close();
  out.open("VIPSPRT.DAT",ios::trunc);
  out.close();
  out.open("MVE11.TXT",ios::trunc);
  out.close();
  out.open("MVE12.TXT",ios::trunc);
  out.close();
  out.open("MVE13.TXT",ios::trunc);
  out.close();
  out.open("MVE14.TXT",ios::trunc);
  out.close();
  out.open("MVE21.TXT",ios::trunc);
  out.close();
  out.open("MVE22.TXT",ios::trunc);
  out.close();
  out.open("MVE23.TXT",ios::trunc);
  out.close();
  out.open("MVE24.TXT",ios::trunc);
  out.close();
  out.open("MVE31.TXT",ios::trunc);
  out.close();
  out.open("MVE32.TXT",ios::trunc);
  out.close();
  out.open("MVE33.TXT",ios::trunc);
  out.close();
  out.open("MVE34.TXT",ios::trunc);
  out.close();
  out.open("MVE41.TXT",ios::trunc);
  out.close();
  out.open("MVE42.TXT",ios::trunc);
  out.close();
  out.open("MVE43.TXT",ios::trunc);
  out.close();
  out.open("MVE44.TXT",ios::trunc);
  out.close();
 }
 else
 {
  gotoxy(20,13);
  cout<<" The entered password is wrong!";
 }
}

union REGS in,out;
int callmouse()
{
 in.x.ax=1;
 int86(51,&in,&out);
 return 1;
}
void mouseposi(int &xpos,int &ypos,int &click)
{
 in.x.ax=3;
 int86(51,&in,&out);
 click=out.x.bx;
 xpos=out.x.cx;
 ypos=out.x.dx;
}
int mousehide()
{
 in.x.ax=2;
 int86(51,&in,&out);
 return 1;
}
void setposi(int &xpos,int &ypos)
{
 in.x.ax=4;
 in.x.cx=xpos;
 in.x.dx=ypos;
 int86(51,&in,&out);
}


//
//                                                  CLASS FUNCTION DEFINITION
//
char TICKETING::select_page()
{
 int choice;
 int gdriver = DETECT, gmode, errorcode;
 /* initialize graphics and local variables */
 initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

 /* read result of initialization */
 errorcode = graphresult();
 if (errorcode != grOk)  /* if true means an error occurred */
 {
   cout<<"Graphics error: "<<grapherrormsg(errorcode);
   cout<<"Press any key to halt:";
   getch();
   exit(0); /* terminate with an error code */
 }
 clearviewport();//Clears the screen in graphics mode
 settextstyle(10,HORIZ_DIR,3);//Sets the style of the text,size and direction
 setbkcolor(CYAN);//Sets the background color
 rectangle(10,10,630,470);//Draws a rectangle
 outtextxy(200,15," MAIN MENU ");//Display a text in graphics mode
 outtextxy(20,50," WHAT DO YOU WANT TO BOOK ");
 outtextxy(180,95," TICKETS FOR? ");
 settextstyle(SANS_SERIF_FONT,0,3);
 outtextxy(250,150,"1 . SPORTS");
 outtextxy(250,200,"2 . MOVIE");
 outtextxy(250,250,"3 . CONCERT");
 outtextxy(250,300,"4 . TO EXIT");
 settextstyle(7,0,5);
 rectangle(240,150,400,340);
 line(215,62,415,62);//To draw a line
 outtextxy(20,360, "ENTER YOUR CHOICE:");
 gotoxy(64,25);
 choice=getche();
// getch();
 while((choice>=5&&choice<=0)&&(choice!=59))
 {
  settextstyle(1,0,2);
  outtextxy(475,410,"INVALID CHOICE!");
  outtextxy(475,430,"RETYPE INPUT");
  gotoxy(64,25);
  //clreol();
  cin>>choice;
 }
 clearviewport();//Clears the screen in graphics mode
 closegraph();//Closes the graphics mode
 return choice;
}
void TICKETING::choice_window_page()
{
 int x,y,cl=0,a,b;
 int g=DETECT,m;
 initgraph(&g,&m,"c:\\turboc3\\bgi");
 a=100;
 b=400;
 setposi(a,b);
 callmouse();

 clrscr();
 cleardevice();
 int i,j,k;
 struct event
 {
  char wd[12];
 }word[24];
 ifstream in("MOVIE.TXT");
 if(!in)
 {
  cout<<"\n An error occured.";
 }
 else
 {
  char line[50];
  for(i=0;!in.eof();i++)
  {
   in.getline(line,50,'\n');
   strcpy(word[i].wd,line);
  }
 }
 in.close();
 cout<<" The following are the available movies\n";
 cout<<endl;
 //TABLE
 //Printing border of the table
 cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(5)<<"+"<<setw(17)<<"-"<<setw(1)<<"+";
 cout<<setfill(' ')<<setw(1)<<"|"<<setw(12)<<" ENGLISH"<<setw(7)<<"|"<<setw(12)<<" HINDI"<<setw(7)<<"|"<<setw(15)<<"KANNADA"<<setw(8)<<"|"<<setw(12)<<"TAMIL"<<setw(6)<<"|";
 cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(5)<<"+"<<setw(17)<<"-"<<setw(1)<<"+";
 for(i=1;i<19;i++)
 {
  if(i%3==0)
  {
   cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(5)<<"+"<<setw(17)<<"-"<<setw(1)<<"+";
   continue;
  }
  cout<<setfill(' ')<<setw(1)<<"|"<<setw(19)<<"|"<<setw(19)<<"|"<<setw(23)<<"|"<<setw(18)<<"|";
 }
 //END OF TABLE
 k=0;
 for(j=0;j<4;j++)
 {
  for(i=0;i<6;i++)
  {
   gotoxy(5+(j*20),6+(3*i));
   cout<<word[k].wd;
   k++;
  }
 }
 do
 {
  mouseposi(x,y,cl);
  gotoxy(10,9);
 }while(cl!=1);
 clrscr();
 cleardevice();
      if((x>=5&&y>=72)&&(x>=5&&y<=119)&&(x<=154&&y>=72)&&(x<=154&&y<=119))
 {
  strcpy(movie_booked,word[0].wd);
  strcpy(text_file,"MVE11.txt");
 }
 else if((x>=5&&y>=120)&&(x>=5&&y<=166)&&(x<=154&&y>=120)&&(x<=154&&y<=166))
 {
  strcpy(movie_booked,word[1].wd);
  strcpy(text_file,"MVE21.txt");
 }
 else if((x>=5&&y>=168)&&(x>=5&&y<=214)&&(x<=154&&y>=168)&&(x<=154&&y<=214))
 {
  strcpy(movie_booked,word[2].wd);
  strcpy(text_file,"MVE31.txt");
 }
 else if((x>=5&&y>=216)&&(x>=5&&y<=262)&&(x<=154&&y>=216)&&(x<=154&&y<=262))
 {
  strcpy(movie_booked,word[3].wd);
  strcpy(text_file,"MVE41.txt");
 }
 else if((x>=5&&y>=264)&&(x>=5&&y<=310)&&(x<=154&&y>=264)&&(x<=154&&y<=310))
 {
  strcpy(movie_booked,word[4].wd);
  strcpy(text_file,"MVE51.txt");
 }
 else if((x>=5&&y>=312)&&(x>=5&&y<=358)&&(x<=154&&y>=312)&&(x<=154&&y<=358))
 {
  strcpy(movie_booked,word[5].wd);
  strcpy(text_file,"MVE61.txt");
 }
 else if((x>=157&&y>=72)&&(x>=157&&y<=119)&&(x<=306&&y>=72)&&(x<=306&&y<=119))
 {
  strcpy(movie_booked,word[6].wd);
  strcpy(text_file,"MVE12.txt");
 }
 else if((x>=157&&y>=120)&&(x>=157&&y<=166)&&(x<=306&&y>=120)&&(x<=306&&y<=166))
 {
  strcpy(movie_booked,word[7].wd);
  strcpy(text_file,"MVE22.txt");
 }
 else if((x>=157&&y>=168)&&(x>=157&&y<=214)&&(x<=306&&y>=168)&&(x<=306&&y<=214))
 {
  strcpy(movie_booked,word[8].wd);
  strcpy(text_file,"MVE32.txt");
 }
 else if((x>=157&&y>=216)&&(x>=157&&y<=262)&&(x<=306&&y>=216)&&(x<=306&&y<=262))
 {
  strcpy(movie_booked,word[9].wd);
  strcpy(text_file,"MVE42.txt");
 }
 else if((x>=157&&y>=264)&&(x>=157&&y<=310)&&(x<=306&&y>=264)&&(x<=306&&y<=310))
 {
  strcpy(movie_booked,word[10].wd);
  strcpy(text_file,"MVE52.txt");
 }
 else if((x>=157&&y>=312)&&(x>=157&&y<=358)&&(x<=306&&y>=312)&&(x<=306&&y<=358))
 {
  strcpy(movie_booked,word[11].wd);
  strcpy(text_file,"MVE62.txt");
 }
 else if((x>=309&&y>=72)&&(x>=309&&y<=119)&&(x<=490&&y>=72)&&(x<=490&&y<=119))
 {
  strcpy(movie_booked,word[12].wd);
  strcpy(text_file,"MVE13.txt");
 }
 else if((x>=309&&y>=120)&&(x>=309&&y<=166)&&(x<=490&&y>=120)&&(x<=490&&y<=166))
 {
  strcpy(movie_booked,word[13].wd);
  strcpy(text_file,"MVE23.txt");
 }
 else if((x>=309&&y>=168)&&(x>=309&&y<=214)&&(x<=490&&y>=168)&&(x<=490&&y<=214))
 {
  strcpy(movie_booked,word[14].wd);
  strcpy(text_file,"MVE33.txt");
 }
 else if((x>=309&&y>=216)&&(x>=309&&y<=262)&&(x<=490&&y>=216)&&(x<=490&&y<=262))
 {
  strcpy(movie_booked,word[15].wd);
  strcpy(text_file,"MVE43.txt");
 }
 else if((x>=309&&y>=264)&&(x>=309&&y<=310)&&(x<=490&&y>=264)&&(x<=490&&y<=310))
 {
  strcpy(movie_booked,word[16].wd);
  strcpy(text_file,"MVE53.txt");
 }
 else if((x>=309&&y>=312)&&(x>=309&&y<=358)&&(x<=490&&y>=312)&&(x<=490&&y<=358))
 {
  strcpy(movie_booked,word[17].wd);
  strcpy(text_file,"MVE63.txt");
 }
 else if((x>=493&&y>=72)&&(x>=493&&y<=119)&&(x<=634&&y>=72)&&(x<=634&&y<=119))
 {
  strcpy(movie_booked,word[18].wd);
  strcpy(text_file,"MVE14.txt");
 }
 else if((x>=493&&y>=120)&&(x>=493&&y<=166)&&(x<=634&&y>=120)&&(x<=634&&y<=166))
 {
  strcpy(movie_booked,word[19].wd);
  strcpy(text_file,"MVE24.txt");
 }
 else if((x>=493&&y>=168)&&(x>=493&&y<=214)&&(x<=634&&y>=168)&&(x<=634&&y<=214))
 {
  strcpy(movie_booked,word[20].wd);
  strcpy(text_file,"MVE34.txt");
 }
 else if((x>=493&&y>=216)&&(x>=493&&y<=262)&&(x<=634&&y>=216)&&(x<=634&&y<=262))
 {
  strcpy(movie_booked,word[21].wd);
  strcpy(text_file,"MVE44.txt");
 }
 else if((x>=493&&y>=264)&&(x>=493&&y<=310)&&(x<=634&&y>=264)&&(x<=634&&y<=310))
 {
  strcpy(movie_booked,word[22].wd);
  strcpy(text_file,"MVE54.txt");
 }
 else if((x>=493&&y>=312)&&(x>=493&&y<=358)&&(x<=634&&y>=312)&&(x<=634&&y<=358))
 {
  strcpy(movie_booked,word[23].wd);
  strcpy(text_file,"MVE64.txt");
 }
 mousehide();
 cleardevice();
 closegraph();
}
void TICKETING::input_data()
{
 struct date d1;
 getdate(&d1);
 date_of_booking.date = d1.da_day ;
 date_of_booking.month = d1.da_mon ;
 date_of_booking.year = d1.da_year ;
 clrscr();
 cout<<"\n Enter necessary Date(Earliest booking is four days prior)\n";
 cout<<" Date: ";
 cin>>d.date;
 while(d.date>31||d.date<1)
 {
  gotoxy(8,3);
  clreol();
  gotoxy(10,3);
  cout<<"INVALID";
  gotoxy(8,3);
  cin>>d.date;
 }
 gotoxy(10,3);
 cout<<" Month: ";
 cin>>d.month;
 while((d.month>12||d.month<1)||(d.month==1&&date_of_booking.month==12))
 {
  gotoxy(18,3);
  clreol();
  gotoxy(21,3);
  cout<<"INVALID";
  gotoxy(18,3);
  cin>>d.month;
 }
 gotoxy(21,3);
 cout<<" Year: ";
 cin>>d.year;
 while((d.year<date_of_booking.year))
 {
  gotoxy(28,3);
  clreol();
  gotoxy(32,3);
  cout<<"INVALID";
  gotoxy(28,3);
  cin>>d.year;
  gotoxy(32,3);
  clreol();
 }
 gotoxy(1,4);
 cout<<" Hour(in 24 hour format): ";
 retype_hour:
 cin>>hour;
 if((hour<9 && hour>=0) || hour>22 )
 {
  cout<<" The show timings are from 9:00 to 22:00.";
  delay(2000);//To pause the execution
  change_timings:
  gotoxy(26,4);
  clreol();
  for(int i=0;i<10;i++)
  {
   clreol();
   cout<<endl;
  }
  gotoxy(27,4);
  goto retype_hour;
 }
 else if(hour>=9 && hour<=10)
 {
  cout<<" Nearest timings to your input 9:00 to 12:00.";
  hour=9;
 }
 else if(hour>=11 && hour<=13)
 {
  cout<<" Nearest timings to your input 12:00 to 15:00.";
  hour=12;
 }
 else if(hour>=14 && hour<=16)
 {
  cout<<" Nearest timings to your input 15:00 to 18:00.";
  hour=15;
 }
 else if(hour>=17 && hour<=19)
 {
  cout<<" Nearest timings to your input 18:00 to 21:00.";
  hour=18;
 }
 else if(hour>=20 && hour<=22)
 {
  cout<<" Nearest timings to your input 21:00 to 24:00.";
  hour=21;
 }
 char ch;
 cout<<"\n Do you want to change your timings(y/n)?";
 ch=getche();
 if(ch=='y' || ch=='Y')
 {
  goto change_timings;
 }
 gotoxy(1,8);
 line();
 gotoxy(32,9);
 cout<<" MOVIE THEATRE \n";
 line();
 char m_choice;
 cout<<"\n Please choose from the following theatre:\n";
 cout<<"\n 1 --> V.I.P THEATRE        Rs.180/head";
 cout<<"\n 2 --> P.V.R-ORION          Rs.200/head";
 cout<<"\n 3 --> INOX-MANTRI SQUARE   Rs.250/head";
 cout<<"\n 4 --> CINEPOLIS-ETA MALL   Rs.120/head";
 cout<<"\n Enter the movie choice: ";
 gotoxy(25,18);
 m_choice=getche();
 retype_m_choice:
 gotoxy(25,18);
 if(m_choice=='1')
 {
  cout<<"V.I.P THEATRE";
  strcpy(movie_theatre_choice,"V.I.P THEATRE");
  price=180;
 }
 else if(m_choice=='2')
 {
  cout<<"P.V.R-ORION";
  strcpy(movie_theatre_choice,"P.V.R-ORION");
  price=200;
 }
 else if(m_choice=='3')
 {
  cout<<"INOX-MANTRI SQUARE";
  strcpy(movie_theatre_choice,"INOX-MANTRI SQUARE");
  price=250;
 }
 else if(m_choice=='4')
 {
  cout<<"CINEPOLIS-ETA MALL";
  strcpy(movie_theatre_choice,"CINEPOLIS-ETA MALL");
  price=120;
 }
 else
 {
  gotoxy(25,18);
  cout<<"   ";
  gotoxy(25,18);
  cin>>m_choice;
  goto retype_m_choice;
 }
 cout<<"\n\n\t\t\t Press ENTER to proceed.";
 getch();
}
void TICKETING::display_outlay_of_theatre()
{
 clrscr();
 const int x=65;
 cout<<"   ";
 for(int i=0;i<26;i++)                      //Printitng column name
 cout<<char(x+i)<<"  ";
 cout<<"\n\n";
 for(i=0;i<9;i++)                          //Printing row name
  cout<<i+1<<"\n\n";
 const char blocked='X';
 const unsigned char avilable='\xB2';
 gotoxy(4,4);
 for(i=0;i<9;i++)                         //To print all the seats
 {
  gotoxy(4,4+(2*i));
  for(int j=0;j<26;j++)
  {
   if(check(i,j,text_file)==full)
    cout<<blocked<<"  ";
   else
    cout<<avilable<<"  ";
  }
 }
 cout<<"KEY: "<<blocked<<"--> Seat is blocked\n";
 cout<<"      "<<avilable<<"--> Seat is avilable for booking";
 gotoxy(41,23);
 cout<<"ENTER THE NUMBER OF BOOKINGS: ";
 cin>>number_of_booking;
 for(i=0;i<number_of_booking;i++)
 {
  int j=0;
  gotoxy(30,24);
  cout<<"Person: "<<i+1;
  gotoxy(41,24);
  cout<<"ENTER THE ROW: ";
  cin>>seat_number[i][j];
  j++;
  gotoxy(58,24);
  cout<<" COLUMN: ";
  cin>>seat_number[i][j];
  seat_number[i][j]=toupper(seat_number[i][j]);
  if(check(seat_number[i][j-1],seat_number[i][j],text_file)==full)
  {
   i--;
   j--;
   gotoxy(55,24);
   cout<<"The seat is blocked";
   delay(1000);
  }
  if(i!=number_of_booking-1)
  {
   gotoxy(54,24);
   clreol();
  }
 }
 total=number_of_booking*price;
 getch();
}
void TICKETING::payment_of_bill()
{
 clrscr();
 cout<<movie_booked<<" movie at "<<hour<<":00 on "<<d.date<<"/"<<d.month<<"/"<<d.year<<" at ";
 cout<<movie_theatre_choice<<" for "<<number_of_booking<<" persons at the cost of "<<price<<" total cost: "<<total;
 cout<<"\n Seat numbers: ";
 for(int i=0;i<number_of_booking;i++)
 {
  int j=0;
  cout<<seat_number[i][j];
  j++;
  cout<<seat_number[i][j];
  if(i!=number_of_booking-1)
   cout<<",";
 }
 char ch;
 cout<<"\n Proceed to payment(y/n)?";
 ch=getche();
 if(ch=='y' || ch=='Y')
 {
  cout<<"\n\t                         PAYMENT\n";
  cout<<" What is your mode of payment?";
  cout<<"\n 1 --> CREDIT CARD";
  cout<<"\n 2 --> NET BANKING";
  cout<<"\n 3 --> V.I.P MONEY";
  int choice_of_payment;
  cout<<"\n You're choice is: ";
  cin>>choice_of_payment;
  if(choice_of_payment==1)
  {
   payment_by_creditcard();
  }
  else if(choice_of_payment==2)
  {
   payment_by_netbanking();
  }
  else if(choice_of_payment==3)
  {
   payment_by_vipsmoney();
  }
 }
}
void TICKETING::payment_by_creditcard()
{
 clrscr();
 cout<<"\n You have chosen to pay by credit card.\n";
 cout<<"\n\t\t Name        : ";
 gets(name);
 cout<<"\n\t\t Email ID    : ";
 gets(email_id);
 cout<<"\n\t\t Phone number: ";
 gets(phone_number);
 cout<<"\n\t\t Card number : ";
 cin>>card_number;
 cout<<"\n\t\t C.V.V       : ";
 gets(cvv);
 cout<<"\n\t\t Expiry Date : ";
 gets(expiry_date);
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void TICKETING::payment_by_netbanking()
{
 clrscr();
 cout<<"\n You have chosen to pay by net banking.\n";
 cout<<"\n\t\t Name     : ";
 gets(name);
 cout<<"\n\t\t Email ID : ";
 gets(email_id);
 cout<<"\n\t\t Ph number: ";
 gets(phone_number);
 cout<<"\n\t\t Bank name: ";
 gets(bank_name);
 cout<<"\n\t\t Otp    : ";
 gets(otp);
 cout<<"\n\t\t Password : ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void TICKETING::payment_by_vipsmoney()
{
 clrscr();
 cout<<"\n You have chosen to pay by credit card.\n";
 cout<<"\n\t\t Name        : ";
 gets(name);
 cout<<"\n\t\t Email ID    : ";
 gets(email_id);
 cout<<"\n\t\t Phone number: ";
 gets(phone_number);
 cout<<"\n\t\t Login       : ";
 gets(login);
 cout<<"\n\t\t Password    : ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void TICKETING::store_data()
{
 ofstream file_out;
 file_out.open("VIPMVE.DAT",ios::binary|ios::app);
 if(!file_out)
 {
  cout<<"\n The file VIPMVE.DAT was not able to open due to an error.";
 }
 else
 {
  file_out.write((char*)&t,sizeof(TICKETING));
  for(int i=0;i<number_of_booking;i++)
  {
   int j=0;
   j++;
   write(seat_number[i][j-1],seat_number[i][j],text_file);
  }
  cout<<"\n\t\t THANK YOU FOR BOOKING VIA VIP TICKETING";
 }
 file_out.close();
}
void TICKETING::read_data()
{
 ifstream file_in;
 file_in.open("VIPMVE.DAT",ios::binary);
 if(!file_in)
 {
  cout<<"\n The file VIPMVE.DAT was not able to open due to an error.";
 }
 else
 {
  char yn,a;
  int n,number_of_record;
  file_in.seekg(0,ios::end);
  cout<<"\n The file \"VIPMVE.DAT\" contains "<<file_in.tellg()/sizeof(TICKETING)<<" record's";
  number_of_record=file_in.tellg()/sizeof(TICKETING);
  do
  {
   cout<<"\n Enter the record number: ";
   cin>>n;
   while((n>number_of_record||n<1)&&(number_of_record!=0&&n!=0))
   {
    cout<<" Re-enter the record number: ";
    cin>>n;
   }
   if(number_of_record!=0&&n!=0)
   {
    file_in.seekg((n-1)*sizeof(TICKETING));
    file_in.read((char*)&t,sizeof(TICKETING));
    output_data();
    cout<<"\n Do you want to delete the current record?(y/n)";
    yn=getche();
    if(yn=='y'||yn=='Y')
    {
     gotoxy(50,15);
     cout<<" Are you sure(y/n)?";
     a=getche();
     if(a=='y'||a=='Y')
     {
      delete_current_record(n-1);
      break;
     }
    }
    gotoxy(1,25);
    cout<<" Do you want to read another record?(y/n)";
    yn=getche();
   }
  }while(yn=='y'||yn=='Y');
 }
 file_in.close();
}
void TICKETING::output_data()
{
 cout<<"\n Name                  : "<<name;
 cout<<"\n Phone Number          : "<<phone_number;
 cout<<"\n Movie Booked          : "<<movie_booked;
 cout<<"\n Date of booking       : "<<date_of_booking.date<<"\\"<<date_of_booking.month<<"\\"<<date_of_booking.year;
 cout<<"\n Number of seats Booked: "<<number_of_booking;
 cout<<"\n Seat number's booked  : ";
 for(int i=0;i<number_of_booking;i++)
 {
  int j=0;
  cout<<seat_number[i][j];
  j++;
  cout<<seat_number[i][j];
  if(i!=number_of_booking-1)
   cout<<",";
 }
 cout<<"\n Day and time of movie : "<<hour<<":00 on "<<d.date<<"/"<<d.month<<"/"<<d.year;
 cout<<"\n Movie theatre         : "<<movie_theatre_choice;
 cout<<"\n Total cost of booking : "<<total;
 cout<<"\n Email I.D             : "<<email_id;
 cout<<"\n Bank name             : "<<bank_name;
}
void TICKETING::delete_current_record(int n)
{
 clrscr();
 int count=0,no_of_booking,number_of_bookings_to_pass_by=0,p=0;
 ifstream file_in("VIPMVE.DAT",ios::binary);
 ofstream file_out("TEMP.DAT",ios::binary);
 if(!file_in)
 {
  cout<<"\n Error in opening \"VIPMVE.DAT\".";
 }
 else
 {
  while(file_in.read((char*)&t,sizeof(TICKETING)))
  {
   if(count!=n)
   {
    file_out.write((char*)&t,sizeof(TICKETING));
    if(p==0)
     number_of_bookings_to_pass_by+=number_of_booking;
   }
   else
   {
    no_of_booking=number_of_booking;
    p=1;
   }
   count++;
  }
 }
 file_in.close();
 file_out.close();
 remove("VIPMVE.DAT");
 rename("TEMP.DAT","VIPMVE.DAT");
 file_in.open(text_file);
 file_out.open("TEMP.TXT");
 if(!file_in)
  cout<<"\n Unable to open "<<text_file<<".";
 else
 {
  int count=1;
  char ch[5];
  while(!file_in.eof())
  {
   file_in.getline(ch,5);
   if(count>number_of_bookings_to_pass_by&&count<=(number_of_bookings_to_pass_by+no_of_booking))
   {
    count++;
    continue;
   }
   else
   {
    file_out<<ch<<endl;
   }
   count++;
  }
 }
 file_in.close();
 file_out.close();
 remove(text_file);
 rename("TEMP.TXT",text_file);
}
//
//                                                            SPORTS
//
void SPORTS::choice_window_page()
{
 int x,y,cl=0,a,b;
 int g=DETECT,m;
 initgraph(&g,&m,"c:\\turboc3\\bgi");
 a=100;
 b=400;
 setposi(a,b);
 callmouse();

 clrscr();
 cleardevice();
 int i,j,k;
 struct event
 {
  char wd[12];
 }word[24];
 struct time
 {
  char ttm[16];
 }t[24];
 ifstream in("CRICKET.TXT");
 ifstream in_1("TIME.txt");
 if(!in || !in_1)
 {
  cout<<"\n An error occured.";
 }
 else
 {
  char line[50];
  char line_1[50];
  for(i=0;!in.eof() || !in_1.eof();i++)
  {
   in.getline(line,50,'\n');
   strcpy(word[i].wd,line);
   in_1.getline(line_1,50,'\n');
   strcpy(t[i].ttm,line_1);
  }
 }
 in.close();
 in_1.close();
 cout<<" The following are the available sports\n";
 cout<<endl;
 //TABLE
 //Printing border of the table
 cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(5)<<"+"<<setw(17)<<"-"<<setw(1)<<"+";
 cout<<setfill(' ')<<setw(1)<<"|"<<setw(12)<<" CRICKET"<<setw(7)<<"|"<<setw(12)<<" TENNIS"<<setw(7)<<"|"<<setw(15)<<"FOOTBALL"<<setw(8)<<"|"<<setw(12)<<"HOCKEY"<<setw(6)<<"|";
 cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(5)<<"+"<<setw(17)<<"-"<<setw(1)<<"+";
 j=0;
 for(i=1;i<19;i++)
 {
  if(i%3==0)
  {
   cout<<setfill('-')<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(1)<<"+"<<setw(18)<<"-"<<setw(5)<<"+"<<setw(17)<<"-"<<setw(1)<<"+";
   continue;
  }
  cout<<setfill(' ')<<setw(1)<<"|"<<setw(19)<<"|"<<setw(19)<<"|"<<setw(23)<<"|"<<setw(18)<<"|";
  j++;
 }
 //END OF TABLE
 k=0;
 for(j=0;j<4;j++)
 {
  for(i=0;i<6;i++)
  {
   gotoxy(4+(j*20),6+(3*i));
   cout<<word[k].wd;
   gotoxy(4+(j*20),7+(3*i));
   cout<<t[k].ttm;
   k++;
  }
 }
 do
 {
  mouseposi(x,y,cl);
  gotoxy(10,9);
 }while(cl!=1);
 clrscr();
 cleardevice();
      if((x>=5&&y>=72)&&(x>=5&&y<=119)&&(x<=154&&y>=72)&&(x<=154&&y<=119))
  strcpy(sport_booked,word[0].wd);
 else if((x>=5&&y>=120)&&(x>=5&&y<=166)&&(x<=154&&y>=120)&&(x<=154&&y<=166))
  strcpy(sport_booked,word[1].wd);
 else if((x>=5&&y>=168)&&(x>=5&&y<=214)&&(x<=154&&y>=168)&&(x<=154&&y<=214))
  strcpy(sport_booked,word[2].wd);
 else if((x>=5&&y>=216)&&(x>=5&&y<=262)&&(x<=154&&y>=216)&&(x<=154&&y<=262))
  strcpy(sport_booked,word[3].wd);
 else if((x>=5&&y>=264)&&(x>=5&&y<=310)&&(x<=154&&y>=264)&&(x<=154&&y<=310))
  strcpy(sport_booked,word[4].wd);
 else if((x>=5&&y>=312)&&(x>=5&&y<=358)&&(x<=154&&y>=312)&&(x<=154&&y<=358))
  strcpy(sport_booked,word[5].wd);
 else if((x>=157&&y>=72)&&(x>=157&&y<=119)&&(x<=306&&y>=72)&&(x<=306&&y<=119))
  strcpy(sport_booked,word[6].wd);
 else if((x>=157&&y>=120)&&(x>=157&&y<=166)&&(x<=306&&y>=120)&&(x<=306&&y<=166))
  strcpy(sport_booked,word[7].wd);
 else if((x>=157&&y>=168)&&(x>=157&&y<=214)&&(x<=306&&y>=168)&&(x<=306&&y<=214))
  strcpy(sport_booked,word[8].wd);
 else if((x>=157&&y>=216)&&(x>=157&&y<=262)&&(x<=306&&y>=216)&&(x<=306&&y<=262))
  strcpy(sport_booked,word[9].wd);
 else if((x>=157&&y>=264)&&(x>=157&&y<=310)&&(x<=306&&y>=264)&&(x<=306&&y<=310))
  strcpy(sport_booked,word[10].wd);
 else if((x>=157&&y>=312)&&(x>=157&&y<=358)&&(x<=306&&y>=312)&&(x<=306&&y<=358))
  strcpy(sport_booked,word[11].wd);
 else if((x>=309&&y>=72)&&(x>=309&&y<=119)&&(x<=490&&y>=72)&&(x<=490&&y<=119))
  strcpy(sport_booked,word[12].wd);
 else if((x>=309&&y>=120)&&(x>=309&&y<=166)&&(x<=490&&y>=120)&&(x<=490&&y<=166))
  strcpy(sport_booked,word[13].wd);
 else if((x>=309&&y>=168)&&(x>=309&&y<=214)&&(x<=490&&y>=168)&&(x<=490&&y<=214))
  strcpy(sport_booked,word[14].wd);
 else if((x>=309&&y>=216)&&(x>=309&&y<=262)&&(x<=490&&y>=216)&&(x<=490&&y<=262))
  strcpy(sport_booked,word[15].wd);
 else if((x>=309&&y>=264)&&(x>=309&&y<=310)&&(x<=490&&y>=264)&&(x<=490&&y<=310))
  strcpy(sport_booked,word[16].wd);
 else if((x>=309&&y>=312)&&(x>=309&&y<=358)&&(x<=490&&y>=312)&&(x<=490&&y<=358))
  strcpy(sport_booked,word[17].wd);
 else if((x>=493&&y>=72)&&(x>=493&&y<=119)&&(x<=634&&y>=72)&&(x<=634&&y<=119))
  strcpy(sport_booked,word[18].wd);
 else if((x>=493&&y>=120)&&(x>=493&&y<=166)&&(x<=634&&y>=120)&&(x<=634&&y<=166))
  strcpy(sport_booked,word[19].wd);
 else if((x>=493&&y>=168)&&(x>=493&&y<=214)&&(x<=634&&y>=168)&&(x<=634&&y<=214))
  strcpy(sport_booked,word[20].wd);
 else if((x>=493&&y>=216)&&(x>=493&&y<=262)&&(x<=634&&y>=216)&&(x<=634&&y<=262))
  strcpy(sport_booked,word[21].wd);
 else if((x>=493&&y>=264)&&(x>=493&&y<=310)&&(x<=634&&y>=264)&&(x<=634&&y<=310))
  strcpy(sport_booked,word[22].wd);
 else if((x>=493&&y>=312)&&(x>=493&&y<=358)&&(x<=634&&y>=312)&&(x<=634&&y<=358))
  strcpy(sport_booked,word[23].wd);
 mousehide();
 cleardevice();
 closegraph();
}
void SPORTS::input_data()
{
 clrscr();
 cout<<"\n Enter the number of bookings: ";
 cin>>number_of_booking;
 while(number_of_booking>10||number_of_booking==0)
 {
  cout<<"\n The maximum number of booking per person is 10.";
  cout<<"\n The minimum number of booking per person is 1.";
  delay(1500);
  gotoxy(32,2);
  for(int i=0;i<4;i++)
  {
   clreol();
   cout<<endl;
  }
  gotoxy(32,2);
  cin>>number_of_booking;
 }
 randomize();
 int r=random(700);
 int c=65+random(27);
 block=char(c);
 seat_number=r;
 cout<<"\n The seat numbers are: ";
 for(int i=0;i<number_of_booking;i++)
 {
  cout<<char(c)<<r+i;
  if(i!=number_of_booking-1)
   cout<<",";
 }
 cout<<"\n\n\t\t\t Press ENTER to proceed.";
 struct date d1;
 getdate(&d1);
 date_of_booking.date = d1.da_day ;
 date_of_booking.month = d1.da_mon ;
 date_of_booking.year = d1.da_year ;
 getch();
}
void SPORTS::payment_of_bill()
{
 char ch;
 cout<<endl;
 line();
 cout<<"\t\t\t\t PAYMENT\n";
 line();
 cout<<"\n Proceed to payment(y/n)?";
 ch=getche();
 if(ch=='y' || ch=='Y')
 {
  cout<<"\n\t                         PAYMENT\n";
  cout<<" What is your mode of payment?";
  cout<<"\n 1 --> CREDIT CARD";
  cout<<"\n 2 --> NET BANKING";
  cout<<"\n 3 --> V.I.P MONEY";
  int choice_of_payment;
  cout<<"\n Youre choice is: ";
  cin>>choice_of_payment;
  while(choice_of_payment>3||choice_of_payment<1)
  {
  cout<<"\n\t INVALID CHOICE!";
  delay(1500);
  gotoxy(20,12);
  clreol();
  cin>>choice_of_payment;
  }
  if(choice_of_payment==1)
  {
   payment_by_creditcard();
  }
  else if(choice_of_payment==2)
  {
   payment_by_netbanking();
  }
  else if(choice_of_payment==3)
  {
   payment_by_vipsmoney();
  }
 }
}
void SPORTS::payment_by_creditcard()
{
 clrscr();
 cout<<"\n You have chosen to pay by credit card.\n";
 cout<<"\n\t\t Name        : ";
 gets(name);
 cout<<"\n\t\t Email ID    : ";
 gets(email_id);
 cout<<"\n\t\t Phone number: ";
 gets(phone_number);
 cout<<"\n\t\t Card number : ";
 cin>>card_number;
 cout<<"\n\t\t C.V.V       : ";
 gets(cvv);
 cout<<"\n\t\t Expiry Date : ";
 gets(expiry_date);
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void SPORTS::payment_by_netbanking()
{
 clrscr();
 cout<<"\n You have chosen to pay by net banking.\n";
 cout<<"\n\t\t Name     : ";
 gets(name);
 cout<<"\n\t\t Email ID : ";
 gets(email_id);
 cout<<"\n\t\t Ph number: ";
 gets(phone_number);
 cout<<"\n\t\t Bank name: ";
 gets(bank_name);
 cout<<"\n\t\t Otp    : ";
 gets(otp);
 cout<<"\n\t\t Password : ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void SPORTS::payment_by_vipsmoney()
{
 clrscr();
 cout<<"\n You have chosen to pay by credit card.\n";
 cout<<"\n\t\t Name        : ";
 gets(name);
 cout<<"\n\t\t Email ID    : ";
 gets(email_id);
 cout<<"\n\t\t Phone number: ";
 gets(phone_number);
 cout<<"\n\t\t Login       : ";
 gets(login);
 cout<<"\n\t\t Password    : ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void SPORTS::store_data()
{
 ofstream file_out;
 file_out.open("VIPSPRT.DAT",ios::binary|ios::app);
 if(!file_out)
 {
  cout<<"\n The file VIPSPRT.DAT was not able to open due to an error.";
 }
 else
 {
  file_out.write((char*)&sp,sizeof(SPORTS));
  cout<<"\n\n\t\t THANK YOU FOR BOOKING VIA VIP TICKETING";
 }
 file_out.close();
}
void SPORTS::read_data()
{
 ifstream file_in;
 file_in.open("VIPSPRT.DAT",ios::binary);
 if(!file_in)
 {
  cout<<"\n The file VIPSPRT.DAT was not able to open due to an error.";
 }
 else
 {
  char yn='n',a;
  int n,number_of_record;
  file_in.seekg(0,ios::end);
  cout<<"\n The file \"VIPSPRT.DAT\" contains "<<file_in.tellg()/sizeof(SPORTS)<<" record's";
  number_of_record=file_in.tellg()/sizeof(SPORTS);
  do
  {
   cout<<"\n Enter the record number: ";
   cin>>n;
   while((n>number_of_record||n<1)&&(number_of_record!=0&&n!=0))
   {
    cout<<" Re-enter the record number: ";
    cin>>n;
   }
   if(number_of_record!=0&&n!=0)
   {
    file_in.seekg((n-1)*sizeof(SPORTS));
    file_in.read((char*)&sp,sizeof(SPORTS));
    output_data();
    cout<<"\n Do you want to delete the current record?(y/n)";
    yn=getche();
    if(yn=='y'||yn=='Y')
    {
     gotoxy(50,15);
     cout<<" Are you sure(y/n)?";
     a=getche();
     if(a=='y'||a=='Y')
     {
      delete_current_record(n-1);
      break;
     }
    }
    gotoxy(1,25);
    cout<<"\n Do you want to read another record?";
    yn=getche();
   }
  }while(yn=='y'||yn=='Y');
 }
 file_in.close();
}
void SPORTS::output_data()
{
 cout<<"\n Name                  : "<<name;
 cout<<"\n Phone Number          : "<<phone_number;
 cout<<"\n Date of booking       : "<<date_of_booking.date<<"\\"<<date_of_booking.month<<"\\"<<date_of_booking.year;
 cout<<"\n Number of seats Booked: "<<number_of_booking;
 cout<<"\n Sport booked          : "<<sport_booked;
 cout<<"\n Total cost of booking : "<<total;
 cout<<"\n Email I.D             : "<<email_id;
 cout<<"\n Bank name             : "<<bank_name;
}
void SPORTS::delete_current_record(int n)
{
 clrscr();
 int count=0;
 ifstream file_in("VIPSPRT.DAT",ios::binary);
 ofstream file_out("TEMP.DAT",ios::binary);
 if(!file_in)
 {
  cout<<"\n Error in opening \"VIPSPRT.DAT\".";
 }
 else
 {
  while(file_in.read((char*)&sp,sizeof(SPORTS)))
  {
   if(count!=n)
   {
    file_out.write((char*)&sp,sizeof(SPORTS));
   }
   count++;
  }
 }
 file_in.close();
 file_out.close();
 remove("VIPSPRT.DAT");
 rename("TEMP.DAT","VIPSPRT.DAT");
}
//
//CONCERT
//
void CONCERT::choice_window_page()
{
 char choice;
 cout<<"\n\t\t THE FOLLWOING ARE THE CONCERTS GOING TO BE HELD";
 cout<<endl<<endl;
 cout<<"\n\t\t\t 1 -> Sunburn  \t Rs.6000\n";
 cout<<"\n\t\t\t 2 -> Sunburn 1\t Rs.10000\n";
 cout<<"\n\t\t\t 3 -> Sunburn 2\t Rs.15000\n";
 cout<<"\n\t\t\t Select your choice: ";
 choice=getche();
      if(choice=='1')
 {
  strcpy(concert_choice,"Sunburn");
  price=6000;
 }
 else if(choice=='2')
 {
  strcpy(concert_choice,"Sunburn 1");
  price=10000;
 }
 else if(choice=='3')
 {
  strcpy(concert_choice,"Sunburn 2");
  price=15000;
 }
 getch();
}
void CONCERT::input_data()
{
 cout<<"\n\n Enter the number of bookings: ";
 cin>>number_of_booking;
 total_amount=price*number_of_booking;
 while(number_of_booking>10||number_of_booking==0)
 {
  cout<<"\n The maximum number of booking per person is 10.";
  cout<<"\n The minimum number of booking per person is 1.";
  delay(1500);
  gotoxy(32,13);
  for(int i=0;i<4;i++)
  {
   clreol();
   cout<<endl;
  }
  gotoxy(32,13);
  cin>>number_of_booking;
 }
 randomize();
 int r=random(700);
 int c=65+random(27);
 block=char(c);
 seat_number=r;
 cout<<" The seat numbers are: ";
 for(int i=0;i<number_of_booking;i++)
 {
  cout<<char(c)<<r+i;
  if(i!=number_of_booking-1)
   cout<<",";
 }
 struct date d1;
 getdate(&d1);
 date_of_booking.date = d1.da_day ;
 date_of_booking.month = d1.da_mon ;
 date_of_booking.year = d1.da_year ;
 getch();
}
void CONCERT::payment_of_bill()
{
 char ch;
 cout<<"\n Proceed to payment(y/n)?";
 ch=getche();
 if(ch=='y' || ch=='Y')
 {
  cout<<endl;
  line();
  cout<<"\t                         PAYMENT\n";
  line();
  cout<<" What is your mode of payment?";
  cout<<"\n 1 --> CREDIT CARD";
  cout<<"\n 2 --> NET BANKING";
  cout<<"\n 3 --> V.I.P MONEY";
  int choice_of_payment;
  cout<<"\n Your choice is: ";
  cin>>choice_of_payment;
  while(choice_of_payment>3||choice_of_payment<1)
  {
  cout<<"\n\t INVALID CHOICE!";
  delay(1500);
  gotoxy(20,9);
  clreol();
  cin>>choice_of_payment;
  }
  if(choice_of_payment==1)
  {
   payment_by_creditcard();
  }
  else if(choice_of_payment==2)
  {
   payment_by_netbanking();
  }
  else if(choice_of_payment==3)
  {
   payment_by_vipsmoney();
  }
 }
}
void CONCERT::payment_by_creditcard()
{
 clrscr();
 cout<<"\n You have chosen to pay by credit card.\n";
 cout<<"\n\t\t Name        : ";
 gets(name);
 cout<<"\n\t\t Email ID    : ";
 gets(email_id);
 cout<<"\n\t\t Phone number: ";
 gets(phone_number);
 cout<<"\n\t\t Card number : ";
 cin>>card_number;
 cout<<"\n\t\t C.V.V       : ";
 gets(cvv);
 cout<<"\n\t\t Expiry Date : ";
 gets(expiry_date);
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void CONCERT::payment_by_netbanking()
{
 clrscr();
 cout<<"\n You have chosen to pay by net banking.\n";
 cout<<"\n\t\t Name     : ";
 gets(name);
 cout<<"\n\t\t Email ID : ";
 gets(email_id);
 cout<<"\n\t\t Ph number: ";
 gets(phone_number);
 cout<<"\n\t\t Bank name: ";
 gets(bank_name);
 cout<<"\n\t\t Otp    : ";
 gets(otp);
 cout<<"\n\t\t Password : ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void CONCERT::payment_by_vipsmoney()
{
 clrscr();
 cout<<"\n You have chosen to pay by credit card.\n";
 cout<<"\n\t\t Name        : ";
 gets(name);
 cout<<"\n\t\t Email ID    : ";
 gets(email_id);
 cout<<"\n\t\t Phone number: ";
 gets(phone_number);
 cout<<"\n\t\t Login       : ";
 gets(login);
 cout<<"\n\t\t Password    : ";
 for(int i=0;;i++)
 {
  password[i]=getch();
  if((int)(password[i])==13)
  {
   password[i]='\0';
   break;
  }
  cout<<"*";
 }
 cout<<"\n ARE YOU SURE YOU WANT TO COMPLETE THE BOOKING?(y/n)";
 char ch;
 ch=getche();
 if(ch=='y'||ch=='Y')
  store_data();
}
void CONCERT::store_data()
{
 ofstream file_out;
 file_out.open("VIPCNCRT.DAT",ios::binary|ios::app);
 if(!file_out)
 {
  cout<<"\n The file VIPCNCRT.DAT was not able to open due to an error.";
 }
 else
 {
  file_out.write((char*)&c,sizeof(CONCERT));
  cout<<"\n\n\t\t THANK YOU FOR BOOKING VIA VIP TICKETING";
 }
 file_out.close();
}
void CONCERT::read_data()
{
 ifstream file_in;
 file_in.open("VIPCNCRT.DAT",ios::binary);
 if(!file_in)
 {
  cout<<"\n The file VIPCNCRT.DAT was not able to open due to an error.";
 }
 else
 {
  char yn='n',a;
  int n,number_of_record;
  file_in.seekg(0,ios::end);
  cout<<"\n The file \"VIPCNCRT.DAT\" contains "<<file_in.tellg()/sizeof(CONCERT)<<" record's";
  number_of_record=file_in.tellg()/sizeof(CONCERT);
  do
  {
   cout<<"\n Enter the record number: ";
   cin>>n;
   while((n>number_of_record||n<1)&&(number_of_record!=0&&n!=0))
   {
    cout<<" Re-enter the record number: ";
    cin>>n;
   }
   if(number_of_record!=0&&n!=0)
   {
    file_in.seekg((n-1)*sizeof(CONCERT));
    file_in.read((char*)&c,sizeof(CONCERT));
    output_data();
    cout<<"\n Do you want to delete the current record?(y/n)";
    yn=getche();
    if(yn=='y'||yn=='Y')
    {
     gotoxy(50,15);
     cout<<" Are you sure(y/n)?";
     a=getche();
     if(a=='y'||a=='Y')
     {
      delete_current_record(n-1);
      break;
     }
    }
    cout<<"\n Do you want to read another record?";
    yn=getche();
   }
  }while(yn=='y'||yn=='Y');
 }
 file_in.close();
}
void CONCERT::output_data()
{
 cout<<"\n Name                  : "<<name;
 cout<<"\n Phone Number          : "<<phone_number;
 cout<<"\n Number of seats Booked: "<<number_of_booking;
 cout<<"\n Date of booking       : "<<date_of_booking.date<<"\\"<<date_of_booking.month<<"\\"<<date_of_booking.year;
 cout<<"\n Total cost of booking : "<<total;
 cout<<"\n Email I.D             : "<<email_id;
 cout<<"\n Bank name             : "<<bank_name;
}
void CONCERT::delete_current_record(int n)
{
 clrscr();
 int count=0;
 ifstream file_in("VIPCNCRT.DAT",ios::binary);
 ofstream file_out("TEMP.DAT",ios::binary);
 if(!file_in)
 {
  cout<<"\n Error in opening \"VIPCNCRT.DAT\".";
 }
 else
 {
  while(file_in.read((char*)&c,sizeof(CONCERT)))
  {
   if(count!=n)
   {
    file_out.write((char*)&c,sizeof(CONCERT));
   }
   count++;
  }
 }
 file_in.close();
 file_out.close();
 remove("VIPCNCRT.DAT");
 rename("TEMP.DAT","VIPCNCRT.DAT");
}
//
//                                                              MAIN FUNCTION
//
void main()
{
 char choice;
 open_page();
 while(1)
 {
  choice=t.select_page();
  if(choice=='1')
   sports();
  else if(choice=='2')
   movies();
  else if(choice=='3')
   concert();
  else if(choice=='4')
   goto exit;
  else if(choice=='5')
   clear_all_data();
  else if(choice=='9')
   GET_INFO();
  else
   continue;
  getch();
 }
exit:
 close_page();
}
