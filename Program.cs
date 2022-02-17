using System;

public class LargestNumber

{

    int largest, sizeOfArray;

    int[] numbersGivenByUser;


    public LargestNumber()
    {

        largest = 0;
        sizeOfArray = 0;
        numbersGivenByUser = null;
    }

    /////////////// Method to find the largest number from the numbers given by user /////////

    public int largestNumber()

    {

        Console.WriteLine("Enter the number of times you want enter a number : \n ");


        sizeOfArray = Convert.ToInt32(Console.ReadLine());

        numbersGivenByUser = new int[sizeOfArray];

        largest = numbersGivenByUser[0];


        for (int counter = 0; counter < sizeOfArray; counter++)
        {

            Console.WriteLine("Enter Number " + (counter + 1) + ':');

            numbersGivenByUser[counter] = Convert.ToInt32(Console.ReadLine());

        }




        for (int counter = 1; counter < numbersGivenByUser.Length; ++counter)
        {

            if (numbersGivenByUser[counter] > largest)
            {

                largest = numbersGivenByUser[counter];

            }

        }

        return largest;
    }

}

public class ReverseNumber

{
    int userInput;
    int reverse;
    int reminder;


    public ReverseNumber()


    {
        userInput = 0;
        reverse = 0;
        reminder = 0;



    }


    /////////////// Method to reverse the given Number /////////


    public int reverseNumber()
    {
        Console.WriteLine("Please enter a number to reverse : \n");


        userInput = Convert.ToInt32(Console.ReadLine());

        while (userInput != 0)
        {
            reminder = userInput % 10;
            reverse = reverse * 10 + reminder;
            userInput = userInput / 10;
        }

        return reverse;

    }

}

public class LargestDigitNumber
{
    int userInput, largestDigitInTheNumber, reminder;

    public LargestDigitNumber()

    {

        userInput = 0;
        largestDigitInTheNumber = 0;

    }


    /////////////// Method to find  the largest digit in the given Number /////////

    public int largestDigit()

    {
        Console.WriteLine("Please enter a number to find the largest digit in it :  \n");



        userInput = Convert.ToInt32(Console.ReadLine());

        while (userInput > 0)
        {

            reminder = userInput % 10;

            if (largestDigitInTheNumber < reminder)
            {
                largestDigitInTheNumber = reminder;
            }

            userInput = userInput / 10;

        }


        return largestDigitInTheNumber;

    }



}

public class FirstNumberInGivenText
{

    double firstNumber;
    string text;
    char[] characters;
    bool isPrevDigit;

    public FirstNumberInGivenText()
    {

        firstNumber = 0;

    }


    /////////////// Method to find  the first number  in the given Text /////////


    public int firstNumberInGivenText()
    {


        Console.WriteLine("Please Enter a text : ");

        text = Console.ReadLine();


        characters = text.ToCharArray();

        isPrevDigit = false;

        for (int i = 0; i < characters.Length; i++)
        {
            if (isPrevDigit == false)
            {
                if (Char.IsDigit(characters[i]))
                {
                    isPrevDigit = true;

                    firstNumber = Char.GetNumericValue(characters[i]);
                }
            }

            else

            {
                if (Char.IsDigit(characters[i]))
                {
                    firstNumber = (firstNumber * 10) + Char.GetNumericValue(characters[i]);


                }

                else
                {
                    break;
                }



            }
        }

        int firstIntegerNumber=(int ) firstNumber;

        return firstIntegerNumber;
    }



}


public class DigitAnalyzer
{
   

    public int GetLargestDigit()
    {
        LargestDigitNumber instance = new LargestDigitNumber();

        return instance.largestDigit();


    }
}


public class Program
{
    public static void Main()
    {


        Console.WriteLine("  \n");

        Console.WriteLine("                                   ******************************** \n");

        Console.WriteLine("                                   *                              *\n");

        Console.WriteLine("                                   *  Welcome to My application  *\n");

        Console.WriteLine("                                   * Aseel Hamayel                 *\n");

        Console.WriteLine("                                   ******************************** \n");

        Console.WriteLine("  \n");


        Console.WriteLine("Operations : \n ");

        Console.WriteLine("Operation 1 :: Find Largest Number Among given numbers  \n ");

        Console.WriteLine("Operation 2 :: reverse a given number \n ");

        Console.WriteLine("Operation 3 :: find the largest digit of a number \n ");

        Console.WriteLine("Operation 4 :: search for the first int number inside a given text \n ");

        Console.WriteLine("Operation 5 :: End the Program \n ");

        Console.WriteLine("******************************************************************** \n");




        while (true)
        {
            Console.WriteLine("Please enter the required operation number :");

            Console.WriteLine("\n");

            int choice = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("\n");



            switch (choice)
            {

                case 1:
                    {


                        LargestNumber largestNumberInstance1 = new LargestNumber();

                        Console.WriteLine("\n" + "The Largest Number of input Numbers = " + largestNumberInstance1.largestNumber() + "\n");

                        break;
                    }

                case 2:
                    ReverseNumber reverseInstance = new ReverseNumber();

                    Console.WriteLine("\n" + " The reverse of the entered number = " + reverseInstance.reverseNumber() + "\n");
                    Console.WriteLine("******************************************************************** \n");

                    break;

                case 3:

                    DigitAnalyzer digitAnalyzerInstance3 = new DigitAnalyzer();

                    Console.WriteLine("\n" + " The Largest digit of the Entered number = " + digitAnalyzerInstance3.GetLargestDigit() + "\n");
                    Console.WriteLine("******************************************************************** \n");

                    break;

                case 4:
                    FirstNumberInGivenText firstNumberInstance = new FirstNumberInGivenText();
                    Console.WriteLine("******************************************************************** \n");

                    Console.WriteLine("\n" + "The First Number in the entered text = " + firstNumberInstance.firstNumberInGivenText() + "\n");
                    Console.WriteLine("******************************************************************** \n");

                    break;

                case 5:

                    System.Environment.Exit(1);
                    break;

                default:
                    Console.WriteLine(" \n Error operation Number \n ");
                    break;

            }


        }

    }
    }






