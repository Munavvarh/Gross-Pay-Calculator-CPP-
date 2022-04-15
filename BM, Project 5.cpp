
 /* 
 name: Munavvarh Bunglawala
 date: 04/27/2021
 project name: sorting and searching (project # 5)
 Purpose: The purpose of this programme is to use arrays of structure,
 pointers, bubblesort,selection sort and binary search for 
 given data. calculate gross pay by using pointers arethmetic. 
 */






#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;






//Structure:

typedef struct data
{
	
	int id;
	string name;
	int workedHours;
	float rate; 
	double grossPay;
	
} *dataptr;



typedef data dataarray [20];


//prototype of functions
void setdata(dataptr);

void bubbleSort(dataptr);
template <class newtype>
void swaps (newtype &, newtype &);
void outBubsort (const dataptr);

void ifGross (const dataptr); 

void sortSelection (dataptr, int &);
void outSsort(const dataptr,const int );

int binarySearch(dataptr, int & );
void outbinSearch(const dataptr, const int );


int main ()
{   
    //declared variables:
     int counter = 0;
	 int target = 0;
	 int position;
	dataarray employees;
	dataptr datal = employees; 
	
	//Function Calls
	
    setdata(employees);
    bubbleSort(employees);
    outBubsort (employees);
    ifGross(employees);
    sortSelection (employees, counter);
    outSsort(employees, counter); 
    
    position = binarySearch(employees, target );
    outbinSearch(employees, position);
    
    
    

	
	return 0;	
	
	
}

/*
  function: setdata.
  type: void
  parameter: dataptr datal: discription:function reads data from file, by using ponter perameter 
  and calculate the gross pay. parameter counter counts total number 
 of data and referance back to the main.
 */

void setdata (dataptr datal)
{

ifstream Fin ("pr2data.txt");

	
	if (!Fin)
	{
		cout<<"Error! File dosen't exist";
		exit(EXIT_FAILURE);
		
		
	
	}
	 
	else {
	
		 for(int i = 0; i < 20;i++)
		 {
	 		Fin >> datal->id;
	 		Fin.ignore();
			getline(Fin, datal -> name);
			Fin >> datal->workedHours >> datal->rate;
			Fin.ignore();
			
			datal -> grossPay = datal->workedHours * datal->rate;
			datal++;
		 }
		 
	}
	
	Fin.close();
	
}






/*

function: bubblesort.
type: void
 parameter: dataptr datal.
 discription:function will use bubble sort method to sort the
 data in asscending order of Gross pay. functio will call
 the swaps function to swaps the values of array. 



*/


void bubbleSort (dataptr datal)

{
	
 for (int i = 0; i < 20;i++)
	for (int j = 0; j < 20-1; j++)
 		 if ((datal+j)->grossPay > ((datal+j)+1)->grossPay)
		{ 
			swaps((datal+j)->id,((datal+j)+1)->id);
 			swaps((datal+j)->name,((datal+j)+1)->name);
 			swaps((datal+j)->workedHours,((datal+j)+1)->workedHours);
 			swaps((datal+j)->rate,((datal+j)+1)->rate);
 			swaps((datal+j)->grossPay,((datal+j)+1)->grossPay);
 		 } 
	
}

/*
function: swaps.
 type: void
parameter: newType,newType.
discription:function will use templates in order to swaps
any types of data, and refrence back the data to calling 
  function */

template <class newtype>

void swaps (newtype & x, newtype & y)
{
	
	newtype temp = x;
	x = y;
	y = temp; 
}


 /*
 function: outBubsort
 type: void
 parameter: dataptr datal.
 discription: function will accept the sorted data 
 and print them to a file */

void outBubsort (const dataptr datal)

{
	ofstream sortData("Bubble sort (Gross).txt");
 
	 sortData <<fixed<<showpoint<<setprecision(2);
	 sortData<<" Sorted Data in ascending according to Grosspay: " 
	 <<endl;
	 sortData<<"____________________________________________________________________"
	 <<"_______________________________________________"<<endl;
	 sortData
	 << left << setw(10) << "ind"
	 << left << setw(15) << "ID"
	 << right << setw(20) << "Name"
	 << right << setw(29) << "Worked hours"
	 << right << setw(20) << "Pay rate"
	 << right << setw(20) << "Gross pay"
	 << endl;
	 sortData<<"========================================================================"
	 <<"==========================================="<<endl;
	 
	 for(int i = 1,j = 1; i <20; i++,j++)
	 
	 {
 
	 sortData
	 	<< left << setw(10) << j
	 	<< left << setw(15) << (datal+i)->id
	 	<< right << setw(25) << (datal+i)->name
	 	<< right << setw(22) <<(datal+i)->workedHours
	 	<< right << setw(15) <<"$"<< (datal+i)->rate
	 	<< right << setw(15) <<"$"<< (datal+i)->grossPay
	 	<<endl; 
	}
	
}

 /*
 function: ifGross
 type: void
 parameter:dataptr datal.
 discription: function will accept the sorted data 
 and, print the data to a file only if their Gross 
 is more than $500.00.
 */


void ifGross (const dataptr datal)

{
	ofstream grossabove("Gross Above (500).txt");
 
	 grossabove <<fixed<<showpoint<<setprecision(2);
	 grossabove<<" Sorted Data in ascending according to Grosspay Above $500: " 
	 <<endl;
	 grossabove<<"____________________________________________________________________"
	 <<"_______________________________________________"<<endl;
	 grossabove
	 << left << setw(15) << "ID"
	 << right << setw(20) << "Name"
	 << right << setw(27) << "Gross pay"
	 << endl;
	 grossabove<<"========================================================================"
	 <<"==========================================="<<endl;
	 

	
	for(int i = 0; i <20; i++)
	
		if ((datal+i)->grossPay > 500)
		
    {
 
	grossabove
	<< left << setw(15) << (datal+i)->id
	<< right << setw(25) << (datal+i)->name
	<< right << setw(15) <<"$"<< (datal+i)->grossPay
	<<endl; 
	
   }
		
}

 /*
 function: sortSelection.
 type: void
 parameter: dataptr datal and counter (int).
 discription:function will use selction sort method to
 sort the data in asscending order of Id's. functio will 
 call the swaps function to swaps the values of array. 
 */

void sortSelection (dataptr datal, int &counter)

{

	  for (int i = 0; i < 20;i++)
	for (int j = 0; j < 20-1; j++)
 		 if ((datal+j)->id > ((datal+j)+1)->id)
		{ 
			swaps((datal+j)->id,((datal+j)+1)->id);
 			swaps((datal+j)->name,((datal+j)+1)->name);
 			swaps((datal+j)->workedHours,((datal+j)+1)->workedHours);
 			swaps((datal+j)->rate,((datal+j)+1)->rate);
 			swaps((datal+j)->grossPay,((datal+j)+1)->grossPay);
 			counter++;
 		 } 
	 
	 

	
}

 /*
 function: outSsort
 type: void
 parameter: dataptr datal and int counter;
 discription: function will accept the sorted data 
 and print them to a file */


void outSsort(const dataptr datal, const int counter)
   {
	 ofstream outData("selection sort (Id's).txt");
 
	 outData <<fixed<<showpoint<<setprecision(2);
	 outData<<" Sorted Data in ascending according to Id's': " 
	 <<endl;
	 outData<<" Function took "<<counter<<" swaps, before sort the Data." <<endl;
	 outData<<"____________________________________________________________________"
	 <<"_________________________________"<<endl;
	 outData
	 << left << setw(10) << "ind"
	 << left << setw(15) << "ID"
	 << right << setw(15) << "Gross pay"
	 << endl;
	 outData<<"========================================================================"
	 <<"============================="<<endl;
	 for(int i = 0,j = 1; i <20-1; i++,j++)
	 {
	 outData
	 << left << setw(10) << j
	 << left << setw(15) << (datal+i)->id
	 << right << setw(8) <<"$"<< (datal+i)->grossPay
	 <<endl; 
 
	 } 
}

 /*
 function: binarySearch
 type: void
 parameter: dataptr datal, and target (int).
 discription: function ask the user to provide ID #. store user's
 response in target variable and refrence back to the main. in order
 to search user's given Id # function will accept the sorted data, and
 use binary search. if Id is found function will return to its subscript,
 or return to -1.
 */

 int binarySearch(dataptr datal, int &target)
 {
	 cout<<"Enter the ID# : ";
	 cin>>target;
	 int first = 0;
	 int last = 20 - 1;
	 int position = -1;
	 bool found = false;
	 while (!found && first <= last)
	 {
	 int middle = (first + last)/2;
	 if ((datal+middle)->id == target)
	 {
	 found = true;
	 position = middle;
	 }
	 else if ((datal+middle)->id < target)
	 first = middle +1;
	 else if ((datal+middle)->id > target)
	 last = middle - 1;
	 }
	 return position; 
	 } 
	 
/*
 function: outbinSearch
 type: void
 parameter: dataptr datal, and position(int).
 discription: function will accept the user's given Id's subscript
as a position. function will print a data to a file if Id is found,
 or ask to provide correct id num. 
 */	 
	 
	 
void outbinSearch(const dataptr datal, const int position)
	 {
	 ofstream outBin("Binary search.txt");
 
	 if (position == -1)
	 {
	 cout<<" Id is incorrect. Please provide correct Id #."<<endl;
	 }
	 else
	 {
	 outBin
	 << left << setw(15) << "ID"
	 << right << setw(15) << "Name"
	 << right << setw(22) << "Worked hours"
	 << right << setw(20) << "Pay rate"
	 << right << setw(15) << "Gross pay"
	 << endl;
	 outBin
	 << left << setw(15) << (datal+position)->id
	 << right << setw(20) << (datal+position)->name
	 << right << setw(15) <<(datal+position)->workedHours
	 << right << setw(15) <<"$"<< (datal+position)->rate
	 << right << setw(15) <<"$"<< (datal+position)->grossPay
	 <<endl; 
	 }
	 
	 }
	 
	 

/*

sample output if you enter wrong id number to search

Enter the ID# : 1432
 Id is incorrect. Please provide correct Id #.

--------------------------------
Process exited after 3.995 seconds with return value 0
Press any key to continue . . .
*/  


