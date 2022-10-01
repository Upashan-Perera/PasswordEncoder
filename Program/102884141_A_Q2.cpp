#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// function prototype (reference pass)
int SwapNumbers( int &value );
int* replace( int &value);

int main()
{
    //declaring variables
    int value , choice , i , *temp; 
    int *p ;
    bool extraprotection = false ;
    
    //getting the input
    cout << "\nEnter the integer here: ";
    cin >> value; // read value from user
    
    //checking whether the input value digits are in between 2 and 8
    if(value < 10 || value > 99999999 ) {
        cout << "\n Invalide input, enter again : ";
        exit(0);
    }
    
    //getting the number of each digits in the input value
    int digits = (int)log10(value);
    int digits2 = (int)log10(value);
    
    //checking whether the input value is equal to 2 digits
    if(value < 99 )
    {
        //calling the SwapNumbers function to swap the two digits
        value = SwapNumbers( value) ;
        //displaying the integer after swapping
        cout << "\nvalue after encoding = " << value << endl;
    }
    //checking whether the input value is equal to 3 digits
    else if(99 < value && value < 999 )
    {
        //calling the SwapNumbers function to swap the first digits and the last digit
        value = SwapNumbers( value) ;
        //displaying the integer after swapping
        cout << "\nvalue after encoding = " << value << endl;
    }
    //input value is greater than or equal to 4 digitss but less than 8 digits
    else 
    {
        //calling the replace function 
        p = replace( value);
                    
        cout << "\nvalue after encoding = " ;
        
        //using a for-loop to print the sorted array
        for ( i = 0 ; i < digits+1 ; i++ ) 
        {
            cout << *(p + i);
        }

        cout << endl ;
    }
    
    //creating an infinite loop
    while(1)
    {
        //displaying the program menu
        cout << "\n1. Stage two (extra protection)";
        cout << "\n2. Stage three (decoding)";
        
        //getting the user input
        cout << "\nEnter your choice here: ";
        // read choice from user
        cin >> choice; 
        
        //creating a switch statement to each case
        switch(choice)
        {
            case 1 :
                        
                    //checking whether the user input digits are equal to 8
                    if(digits == 7)
                    {
                        //redeclaring the extraprotection boolean as a true value
                        extraprotection = true ;
                        
                        //creating a for-loop to to swap the two integers
                        for( i = 0 ; i < 4 ; i++)
                        {
                            swap(*(p + digits),*(p + i)) ;
                                
                            digits = digits - 1 ;
                        }
                            
                        //printing the sorted array 
                        for ( i = 0 ; i <  8 ; i++ ) 
                        {
                            cout << *(p + i);
                        }
                            
                        cout << endl ;
                    }
                    else
                    {
                        cout << "\n Sorry this mode is not accessbile for digits less than 8" << endl;
                    }
     
                    break;
                        
            case 2 :
                    //checking the input values digits are qualt to 2
                    if(digits2+1 == 2 )
                    {
                        //calling the SwapNumbers function again to de-encrypt the value by swaping the two digits
                        value = SwapNumbers(value) ;
                        cout << "\nvalue after decoding = " << value << endl;
                    }
                    //checking the input values digits are qualt to 3
                    else if(digits2+1 == 3 )
                    {
                        //calling the SwapNumbers function again to de-encrypt the value by swapping the first and last digits
                        value = SwapNumbers(value) ;
                        cout << "\nvalue after decoding = " << value << endl;
                    }
                    //checking the input values digits are greater than or equal to 4
                    else if(digits2+1 >= 4)
                    {
                        for ( i = 0 ; i <  digits2+1 ; i++ ) 
                        { 
                            // This variable is used to store the encoded number which was calculated in encoding process
                            int encodedNumber ;
                                
                            // If the digit is divisible by 3, no changes are made to the digit
                            if (*(p + i) % 3 == 0)
                            {
                                encodedNumber = *(p + i) ;
                            }
                            // If the digit is 2 or 5 or 8, add 10 to the digit add 10
                            else if (*(p + i) == 2 || *(p + i) == 5 || *(p + i)== 8)
                            {
                                encodedNumber = *(p + i) + 10;
                            }
                            // Else if digit is equal to 1 , 4 , 7 , 10 add 20 to the digit
                            else
                            {
                                encodedNumber = *(p + i) + 20;
                            }

                            // de-encrypting the digit by reversing the expression "(n*3)%10"
                            *(p + i) = (encodedNumber / 3);
                        }
                        
                        //checking whether the input value is extra protected
                        if (extraprotection == true)
                        {
                            //re-swaping the elements in the array which is decodes
                            for( i = 0 ; i < 4 ; i++)
                            {
                                swap(*(p + i),*(p + digits2)) ;
                                digits2 = digits2 - 1 ;
                            }
                            
                            cout << "\n value after decoding = " ;
                            
                            //printing the extraprotected decoded sorted array
                            for ( i = 0 ; i <  8 ; i++ ) 
                            {
                                cout << *(p + i);
                            }
                                
                            cout << endl ;
                                
                            exit(0);
                        }
                        
                        cout << "\n value after decoding = " ;
                        
                        //printing the decoded sorted array
                        for ( i = 0 ; i < digits2+1 ; i++ ) 
                        {
                            cout << *(p + i);
                        }
                            
                        cout << endl ;
                    }
                        
                    //end the program
                    cout << "\nEnd of the program" ;
                    exit(0);
                        
            default :
                    //giving the message to user to enter a valid choice
                    cout << "\nInvalide Choice enter again: " << endl ;
                    break;
                        
        }
    }
    
    return 0 ;
    
} // end main

//declaring the SwapNumbers function to swap digits in the user input
int SwapNumbers( int &value)
{
    int first , last , a  , b , nn , digits ;
    
    digits = (int)log10(value);
    first = value / pow(10,digits);
    last = value % 10;
    a = first * (pow(10,digits));
    b = value % a;
    value = b / 10;
    nn = last * (pow(10, digits)) + (value * 10 + first);
    
    //returning the swaped integer 
    return(nn);
}

/*declaring the replace function to get the 
remainder of each digit when you multiply by 3 and divide by 10*/
int* replace( int &value)
{
    int result = 0, multiply = 1 , num , modified , i = 0  ;

    //get the number of digits of the user input
    int digits = (int)log10(value);
    i = digits ;
    
    //intializing an array to store the modified values
    static int array[10];
    
    //creating a while loop until the last digit is modified
	while (value > 0)
	{
	    //removing the last digit
		num = value%10;
		
		//modifying the digit
		modified = (num*3)%10 ;
		
		//input value without the last digit
		value = value/10 ;
		
		//storing the modified digit as the first element in the array
		array[i] = modified ; 
		i = i - 1 ;
	}
	
	return array ;
}