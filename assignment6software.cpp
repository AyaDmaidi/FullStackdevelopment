#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<windows.h>

#pragma warning(disable : 4996)


const int NOTE_SIZE = 50;
const int DISPLACEMENT = 4;
const int MAX_MONTH = 12;
const int MIN_MONTH = 1;
const int MIN_YEAR = 1600;
const int NUMBER_OF_DAYS = 7;

struct Date {
    int      day,year,month;
    
}date;


struct Remainder {
    int     noteDay, noteMonth;
    char     note[NOTE_SIZE];
}reminder;


COORD   location = { 0, 0 };
WORD    fontColor;
HANDLE  handleConsoleOutput= GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO      consoleScreenBufferInfo;
DWORD   counterOfCharsNotUsed;

void GoToLocation(int xCoordinate, int yCoordinate)
{
    // X and Y coordinates
    location.X = xCoordinate;
    location.Y = yCoordinate; 
    SetConsoleCursorPosition(handleConsoleOutput, location);
}


void SetConsoleWindowColor(int ForgC)
{
    
    if (GetConsoleScreenBufferInfo(handleConsoleOutput, &consoleScreenBufferInfo))
    {
        fontColor = (consoleScreenBufferInfo.wAttributes & 0xF0) + (ForgC & 0x0F);

        SetConsoleTextAttribute(handleConsoleOutput, fontColor);
    }
    return;
}


void SetColorAndBackground(int ForgC, int BackC)
{
    fontColor = ((BackC & 0x0F) << DISPLACEMENT) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(handleConsoleOutput, fontColor);
    return;
}


void ClearConsoleToColors(int ForgC, int BackC)
{
    
    fontColor = ((BackC & 0x0F) << DISPLACEMENT) + (ForgC & 0x0F);

    SetConsoleTextAttribute(handleConsoleOutput, fontColor);
    if (GetConsoleScreenBufferInfo(handleConsoleOutput, &consoleScreenBufferInfo))
    {
        FillConsoleOutputCharacter(handleConsoleOutput, (TCHAR)32, consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y, location, &counterOfCharsNotUsed);
        FillConsoleOutputAttribute(handleConsoleOutput, consoleScreenBufferInfo.wAttributes, consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y, location, &counterOfCharsNotUsed);
        SetConsoleCursorPosition(handleConsoleOutput, location);
    }
    return;
}



int LeapYear(int year) { //checks whether the year passed is leap year or not
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 1;
    return 0;
}



void IncreaseMonth(int* monthToIncrease, int* year) { //increase the month by one
    ++* monthToIncrease;
    if (*monthToIncrease > MAX_MONTH) {
        ++* year;
        *monthToIncrease = *monthToIncrease - MAX_MONTH;
    }
}


void DecreaseMonth(int* monthToDecrease, int* year) { //decrease the month by one
    --* monthToDecrease;
    if (*monthToDecrease < 1) {
        --* year;
        if (*year < MIN_YEAR) {
            printf("No record available");
            return;
        }
        *monthToDecrease = *monthToDecrease + MAX_MONTH;
    }
}




int GetNumberOfDays(int month, int year) { 

    switch (month) {                          
    case 1:
        return(31);
        break;

    case 2:
        if (LeapYear(year) == 1){
            return(29);
        }else{

            return(28);
        }
        break;

  
    case 3:
        return(31);
        break;

    case 4:
        return(30);
        break;

    case 5:
        return(31);
        break;

    case 6:
        return(30);
        break;

    case 7: 
        return(31);
        break;

    case 8: 
        return(31);
        break;

    case 9:
        return(30);
        break;

    case 10:
        return(31);
        break;

    case 11:
        return(30);
        break;

    case 12:
        return(31);
        break;

    default:
        return(-1);
        break;
    }
}


const char* DayName(int day) { 
    switch (day) {
    case 0:
        return("Sunday");
        break;

    case 1:
        return("Monday");
        break;

    case 2:
        return("Tuesday");
        break;

    case 3:
        return("Wednesday");
        break;
    case 4:
        return("Thursday");
        break;

    case 5:
        return("Friday");
        break;
    case 6:
        return("Saturday");
        break;
    default:
        return("Error in getName() module.Invalid argument passed");
        break;
    }
}

int GetResult(int year,int dayNumber,int month,int day) {
    int monthValue, t2;
    while (year >= 100) {
        dayNumber = dayNumber + 5;
        year = year - 100;
    }


    dayNumber = (dayNumber % NUMBER_OF_DAYS);
    monthValue = ((year - 1) / 4);
    t2 = (year - 1) - monthValue;
    monthValue = (monthValue * 2) + t2;
    monthValue = (monthValue % NUMBER_OF_DAYS);
    dayNumber = dayNumber + monthValue;
    dayNumber = dayNumber % NUMBER_OF_DAYS;
    t2 = 0;
    for (monthValue = 1; monthValue < month; monthValue++) {
        t2 += GetNumberOfDays(monthValue, year);

    }
    t2 = t2 + day;
    t2 = t2 % NUMBER_OF_DAYS;
    dayNumber = dayNumber + t2;
    dayNumber = dayNumber % NUMBER_OF_DAYS;
    if (year > 2000)
        dayNumber = dayNumber + 1;
    dayNumber = dayNumber % NUMBER_OF_DAYS;
    return dayNumber;
    
}



int DayNumber(int day, int month, int year) { 

    int     dayNumber = 0;
    int     monthValue, dayNumberInc;
    int     currentYear = year;
    year = year - MIN_YEAR;
    while (year >= 100) {
        dayNumber = dayNumber + 5;
        year = year - 100;
    }
    dayNumber = (dayNumber % NUMBER_OF_DAYS);
    monthValue = ((year - 1) / 4);
    dayNumberInc = (year - 1) - monthValue;
    monthValue = (monthValue * 2) + dayNumberInc;
    monthValue = (monthValue % NUMBER_OF_DAYS);
    dayNumber = dayNumber + monthValue;
    dayNumber = dayNumber % NUMBER_OF_DAYS;
    dayNumberInc = 0;
    for (monthValue = 1; monthValue < month; monthValue++) {
        dayNumberInc += GetNumberOfDays(monthValue, currentYear);
    }
    dayNumberInc = dayNumberInc + day;
    dayNumberInc = dayNumberInc % NUMBER_OF_DAYS;
    dayNumber = dayNumber + dayNumberInc;
    dayNumber = dayNumber % NUMBER_OF_DAYS;
    if (currentYear > 2000)
        dayNumber = dayNumber + 1;
    dayNumber = dayNumber % NUMBER_OF_DAYS;
    return dayNumber;
}

 



const char* GetDay(int day, int month, int year) {
   
    if (!(month >= MIN_MONTH && month <= MAX_MONTH)) {

        return("Invalid month value");

    }else if(!(day >= 1 && day <= GetNumberOfDays(month, year))){

        return("Invalid date");

    }else if(year >= MIN_YEAR){

        day = DayNumber(day, month, year);
        day = day % NUMBER_OF_DAYS;
        return(DayName(day));

    }else {

        return("Please give year more than 1600");
        
    }
}


int CheckNote(int day, int month) {

    FILE* file;
    file = fopen("note.dat", "rb");
    if (file == NULL) {
        printf("Error in Opening the file");
    }
    while (fread(&reminder, sizeof(reminder), 1, file) == 1) {

        if (reminder.noteDay == day && reminder.noteMonth == month) {

            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void MonthChecker(int month,int year) {
if (!(month >= MIN_MONTH && month <= MAX_MONTH)) {
        printf("INVALID MONTH");
        _getch();
        return;
    }else if (!(year >= MIN_YEAR)){
        printf("INVALID YEAR");
        _getch();
        return;
    }
}


void PrintDays(int day,int xCoordinate,int counter) {
    switch (day) { //locates the starting day in calender
    case 0:
        xCoordinate = xCoordinate;
        counter = 1;
        break;
    case 1:
        xCoordinate = xCoordinate + 4;
        counter = 2;
        break;
    case 2:
        xCoordinate = xCoordinate + 8;
        counter = 3;
        break;
    case 3:
        xCoordinate = xCoordinate + 12;
        counter = 4;
        break;
    case 4:
        xCoordinate = xCoordinate + 16;
        counter = 5;
        break;
    case 5:
        xCoordinate = xCoordinate + 20;
        counter = 6;
        break;
    case 6:
        xCoordinate = xCoordinate + 24;
        counter = 7;
        break;
    default:
        printf("INVALID DATA FROM THE getOddNumber()MODULE");
        return;
    }
}

void PrintMonths(int month) {
    switch (month) {
    case 1:
        printf("January");
        break;

    case 2:
        printf("February");
        break;

    case 3:
        printf("March");
        break;

    case 4:
        printf("April");
        break;

    case 5:
        printf("May");
        break;

    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;

    case 8:
        printf("August");
        break;

    case 9:
        printf("September");
        break;

    case 10:
        printf("October");
        break;

    case 11:
        printf("November");
        break;

    case 12:
        printf("December");
        break;
    }
}


void CounterCheck(int counter,int day,int month) {
    if (counter == 1) {
        SetConsoleWindowColor(12);
    }
    else {

        SetConsoleWindowColor(15);
    }

    if (CheckNote(day, month) == 1) {
        SetColorAndBackground(15, 12);
    }

}


void PrintMonthWithDays(int month, int year, int xCoordinate, int yCoordinate) { //prints the month with all days
    int     numberOfDays, day;
    int     counter=0;
    int     dayInYear = 1;
    int     currentValueOfX = xCoordinate;
    int     currentValueOfY = yCoordinate;
    int     isNote = 0;

    MonthChecker(month, year);

    GoToLocation(20, yCoordinate);
     
    printf("---------------------------\n");

    GoToLocation(25, 6);

    PrintMonths(month);

    printf(" , %d", year);

    GoToLocation(20, 7);
    printf("---------------------------");
    yCoordinate += 3;
    GoToLocation(xCoordinate, yCoordinate);
    printf("S   M   T   W   T   F   S   ");
    yCoordinate++;

    numberOfDays = GetNumberOfDays(month, year);
    day = DayNumber(dayInYear, month, year);
    
    PrintDays(day, xCoordinate, counter);

    GoToLocation(xCoordinate, yCoordinate);

   
    printf("%02d", dayInYear);

    SetColorAndBackground(15, 1);

    for (dayInYear = 2; dayInYear <= numberOfDays; dayInYear++) {

        if (counter % 7 == 0) {
            yCoordinate++;
            counter = 0;
            xCoordinate = currentValueOfX - 4;
        }

        xCoordinate = xCoordinate + 4;
        counter++;
        GoToLocation(xCoordinate, yCoordinate);

        CounterCheck(counter, dayInYear, month);

        printf("%02d", dayInYear);
        SetColorAndBackground(15, 1);
    }
    GoToLocation(8, yCoordinate + 2);

    SetConsoleWindowColor(14);

    printf("Press 'n'  to Next, Press 'p' to Previous and 'q' to Quit");
    GoToLocation(8, yCoordinate + 3);
    printf("Red Background indicates the NOTE, Press 's' to see note: ");
    
    SetConsoleWindowColor(15);
}





void Checker(FILE* file) {
    if (fwrite(&reminder, sizeof(reminder), 1, file)) {
        GoToLocation(5, 12);
        puts("Note is saved sucessfully");
        fclose(file);
    }
    else {
        GoToLocation(5, 12);
        SetConsoleWindowColor(12);
        puts("\aFail to save!!\a");
        SetConsoleWindowColor(15);
    }
}

void AddNote() {
    FILE* file;
    file = fopen("note.dat", "ab+");
    system("cls");
    GoToLocation(5, 7);
    printf("Enter the date(Day Month): ");
    scanf_s("%d %d", &reminder.noteDay, &reminder.noteMonth);
    GoToLocation(5, 8);
    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    scanf(" %[^\n]", reminder.note);
    
    Checker(file);

    GoToLocation(5, 15);

    printf("Press any key............");

    _getch();

    fclose(file);
}

void IncrementcheckFound(int month,FILE*file,int incrementVariable,int isNoteFound) {
while (fread(&reminder, sizeof(reminder), 1, file) == 1) {
        if (reminder.noteMonth == month) {
            GoToLocation(10, 5 + incrementVariable);
            printf("Note %d Day = %d: %s", incrementVariable + 1, reminder.noteDay, reminder.note);
            isNoteFound = 1;
            incrementVariable++;
        }
    }

    if (isNoteFound == 0) {
        GoToLocation(10, 5);
        printf("This Month contains no note");
    }
}

void ShowNote(int month) {
    FILE*    file;
    int      incrementVariable = 0;
    int      isNoteFound = 0;
    system("cls");
    file = fopen("note.dat", "rb");
    if (file == NULL) {
        printf("Error in opening the file");
    }
    IncrementcheckFound(month, file, incrementVariable, isNoteFound);
    GoToLocation(10, 7 + incrementVariable);
    printf("Press any key to back.......");
    _getch();
}


int main() {
    ClearConsoleToColors(15, 1);
    SetConsoleTitleA("Calender Project - Programming-technique.blogspot.com");
    int choice;
    char userInput = 'a';

    while (1) {
        system("cls");
        printf("1. Find Out the Day\n");
        printf("2. Print all the day of month\n");
        printf("3. Add Note\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf_s("%d", &choice);
        system("cls");

        switch (choice) {

        case 1:
            printf("Enter date (Day Month Year) : ");
            scanf_s("%d %d %d", &date.day, &date.month, &date.year);
            printf("Day is : %s", GetDay(date.day, date.month, date.year));
            printf("\nPress any key to continue......");
            getch();
            break;

        case 2:
            printf("Enter month and year (Month Year) : ");
            scanf_s("%d %d", &date.month, &date.year);
            system("cls");

            while (userInput != 'q') {
                PrintMonthWithDays(date.month, date.year, 20, 5);
                userInput = _getch();

                if (userInput == 'n') {
                    IncreaseMonth(&date.month, &date.year);
                    system("cls");
                    PrintMonthWithDays(date.month, date.year, 20, 5);

                }else if (userInput == 'p'){
                 DecreaseMonth(&date.month, &date.year);
                 system("cls");
                 PrintMonthWithDays(date.month, date.year, 20, 5);

                } else if (userInput == 's') {
                  ShowNote(date.month);
                  system("cls");
                }
            }

            break;

        case 3:
            AddNote();
            break;

        case 4:
            exit(0);
        }
    }

    return 0;
}