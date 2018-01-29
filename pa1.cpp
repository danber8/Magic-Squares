#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

void magicsquare(int size){     //This is where I create the magicsquare and rotate it
	int magicSquare[size][size];
	for (int i = 0; i < size; i++){         //I used an array to cycle through the array to initialize every value to be 0
		for (int j = 0; j < size; j++){
			magicSquare[i][j] = 0;
		}
	}

	int a = size/2;             //The value 1 will be placed at this position in the array
	int b = size-1;             //The first integer, 1 , will be placed in the middle row in the farthest column on the right

	for (int value = 1; value <= size*size; ++value){
		if (a== -1 && b == size)       //If the elements is to be placed in the diagonal above the top right element, move it one spot to the left
		{
			b = size-1-1;
			a = 0;
		}
		else
		{
			if (b == size){
				b = 0;      //If the element is to be placed to the right of the matrix and not the very top right, move it all the way to the left.
			}
			if (a < 0){     //If the element is to be placed above the matrix, place it on the very bottom row
				a=size-1;
			}
		}
		if (magicSquare[a][b]){ //If the box is already full, place the element one spot to the left
			b = b-2;
			a++;
		}
		magicSquare[a][b] = value; //actually place the incremented value in the array
		b++;  a--;                  //increment the counters to keep the magicsquare going
	}                           //I used this source to create the first magic square: http://www.geeksforgeeks.org/magic-square/

	int sumDiag = 0;                    //initialize the sum of the forward diagonal as 0
	int sum1Diag = 0;                   //initialize the sum of the rear diagonal as 0
    string sumDiagString;               //I change my ints to a string, and this is the string that will store those values
	for(int i = 0; i< size; i++){
        sumDiag += magicSquare[i][i];   //This sums up the forward diagonals
    }

    for (int i = size-1; i>=0; i--){    //This sums up the rear diagonals
        sum1Diag += magicSquare[i][i];
    }                                       //These values will be used throughout because diagonals don't change

    ostringstream convert2;                 //This converts an int into a sting so that i can output all the sums
    convert2 << sumDiag<<" " << sum1Diag;
    sumDiagString = convert2.str();

    string sum1RowsString;      //Create the string to hold the sum of ints in the rows
    string sum1ColsString;      //This creates the string to hold the sum of ints in the columns

    int sum1Rows = 0;       //initialize the sum of rows as 0
    int sum1Cols = 0;       //initialize the sum of columns as 0

    int counter1 = 0;
	cout<<"Magic Square #1 is: " << "\n";           //prints out the first magic square form above
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			cout << magicSquare[i][j] << "\t";
            sum1Rows += magicSquare[i][j];          //sums up the rows
            sum1Cols += magicSquare[j][i];          //sums up the columns

		}

		ostringstream convert;                      //converts the rows ints into stirngs
		convert << sum1Rows/(i+1)<<" ";
		sum1RowsString += convert.str();

		//convert<< sum1Cols/(i+1) << " ";
		ostringstream convert1;
		convert1 << sum1Rows/(i+1)<<" ";            //converts the columns ints into stirngs
		sum1ColsString += convert1.str();


        //cout<<sum1/(i+1);
		cout <<"\n";
	}
    cout<<"\n";
	cout<<"Checking the sums of every row: "<<sum1RowsString <<"\n";        //outputs the values to match the example
	cout<<"Checking the sums of every column: " << sum1ColsString<< "\n";
	cout<<"Checking the sums of every diagonal: " << sumDiagString<<"\n";
	cout<<"\n";

                                    //I do the exact same thing here except I rotate the array first
	string sum2RowsString;
    string sum2ColsString;      //These are all strings to hold the ints once I change them to a string
    string sum2DiagString;
    int sum2Rows = 0;
    int sum2Cols = 0;           //initialize rows, columns, diagonals
    int sum2Diag = 0;
    int sum22Diag = 0;
	cout<<"Magic Square #2 is: " << "\n";
		for(int j = size-1; j >=0; j--){
            for(int i = 0; i<size; i++){
                cout<<magicSquare[i][j] << "\t";
                sum2Rows += (magicSquare[i][j]);        //sums up the rows
                sum2Cols += (magicSquare[j][i]);        //sums up the columns
        }
        cout<<"\n";

        ostringstream convert;              //converts the rows ints to strings
		convert << sum2Rows<<" ";
		sum2RowsString += convert.str();

		//convert<< sum1Cols/(i+1) << " ";
		ostringstream convert1;                 //converts the columns ints to strings
		convert1 << sum2Cols<<" ";
		sum2ColsString += convert1.str();


	}
    cout<<"Checking the sums of every row: "<<sum1RowsString <<"\n";
	cout<<"Checking the sums of every column: " << sum1ColsString<< "\n";       //output which matches the example output
	cout<<"Checking the sums of every diagonal: " << sumDiagString<<"\n";
	cout<<"\n";


    string sum3RowsString;              //declare strings to hold the ints once they are converted
    string sum3ColsString;
    string sum3DiagString;
    int sum3Rows = 0;
    int sum3Cols = 0;                   //initialize sums of rows, columns and diagonals
    int sum3Diag = 0;
    int sum34Diag = 0;
    cout<<"Magic Square #3 is: " << "\n";
	for(int i = 0; i< size; i++){
        for(int j = size-1; j>=0; j--){             //rotate the array once more
            cout << magicSquare[j][i] << "\t";
            sum3Rows += magicSquare[i][j];            //sum up the rows
            sum3Cols += magicSquare[j][i];          //sum up the columns
        }
		ostringstream convert;                      //convert the rows int into a string
		convert << sum3Rows/(i+1)<<" ";
		sum3RowsString += convert.str();

		//convert<< sum1Cols/(i+1) << " ";
		ostringstream convert1;                     //converts the columns int into a string
		convert1 << sum3Cols/(i+1)<<" ";
		sum3ColsString += convert1.str();

        cout <<"\n";
	}
	cout<<"\n";
	cout<<"Checking the sums of every row: "<<sum3RowsString <<"\n";
	cout<<"Checking the sums of every column: " << sum3ColsString<< "\n";           //displays the wanted output
	cout<<"Checking the sums of every diagonal: " << sumDiagString<<"\n"<<"\n";


    string sum4RowsString;          //rinse and repeat one more time
    string sum4ColsString;
    string sum4DiagString;
    int sum4Rows = 0;
    int sum4Cols = 0;           //initialize, rows, columns, and diagonals
    int sum4Diag = 0;
    int sum41Diag = 0;

	cout<<"Magic Square #4 is: " << "\n";
	for(int j = size-1; j>= 0; j--){            //rotate the array once more
        for(int i = 0; i<size; i++){
            cout << magicSquare[i][j] << "\t";
                sum4Rows += (magicSquare[i][j]);        //sum the rows
                sum4Cols += (magicSquare[j][i]);        //sum the columns
        }
        cout <<"\n";
	}
	cout<<"\n";
	cout<<"Checking the sums of every row: "<<sum1RowsString <<"\n";            //output the necessary values
	cout<<"Checking the sums of every column: " << sum1ColsString<< "\n";
	cout<<"Checking the sums of every diagonal: " << sumDiagString<<"\n"<<"\n";

}

int main(){
    while(true){            //This creates an infinite loop unless the user selects exit
		int number;
		bool x = true;
		while(x == true){           //This creates another loop to ensure that the user enters a valid size for the array matrix. The user will be
		cout<<"Enter the size of a magic square: ";     //promoted again and again until he/she selects a valid value
		cin>> number;
		cout<<"\n";
            if(number % 2 !=0 && number >= 3 && number <= 15){      //The value has to be odd and greater than 2 and less than 16
            x = false;      //The user entered a successful value, and the program may proceed
            }
            else{
                cout<<"You entered an incorrect value"<<"\n";       //stay int the loop
            }
		}
		magicsquare(number);        //calls the function that creates the magic square and rotates it
		cout<<"Press 1 if you wish to exit, otherwise press any other key: ";
		int exit;       //Gives the user the option to exit the program
		cin>>exit;
		if(exit == 1){
            return 0;       //If they select exit, the program will return 0 and thus endth the program
		}
	}
	return 0;
}

