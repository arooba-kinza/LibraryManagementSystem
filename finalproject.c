#include <stdio.h>

//====== DEFINE CONSTANTS ======
#define MAX_STUDENTS 200
#define MAX_BOOKS 10
#define LATE_FINE 50
#define DAMAGE_FINE 200
#define CARD_FEE 500

//====== GLOBAL ARRAYS ======
int studentIDs[MAX_STUDENTS];
int issuedBooks[MAX_STUDENTS];
int studentFines[MAX_STUDENTS];
int memberTypes[MAX_STUDENTS];
int totalStudents = 0;
int nextNewID = 251100;

//====== FUNCTION PROTOTYPES ======
int getPositiveInput();
void showRules();
void showMenu();
int checkCard(int id);
int issueCard();
void getMembership(int index);
void issueBook();
void returnBook();
void showStudentInfo(int index);
void showMembership(int index);
void bonusAward();
void showSummary();
void exitMessage();

// ====== MAIN FUNCTION ======
int main() 
{
    int choice;
    printf("*************************************\n");
    printf("DIGITAL LIBRARY SYSTEM\n");
    printf("*************************************\n");
    
    showRules();
    do 
    {
        showMenu();
        printf("\nEnter your choice: ");
        choice = getPositiveInput();
        
        switch(choice) 
        {
            case 1: issueBook(); break;
            case 2: returnBook(); break;
            case 3: bonusAward(); break;
            case 4: showSummary(); break;
            case 5: exitMessage(); break;
            default: printf("Invalid choice! Please choose (1-5)\n");
        }
    } while (choice != 5);
    
    return 0;
}

// ====== INPUT VALIDATION ======
int getPositiveInput() 
{
    int num;
    while(scanf("%d", &num) != 1 || num < 0) 
    {
        printf("Invalid input! Enter a positive number: ");
        while(getchar() != '\n'); // clear input buffer
    }
    return num;
}

// ====== LIBRARY RULES ======
void showRules() 
{
    printf("\n********** LIBRARY RULES *********\n");
    printf("1. Maximum %d books can be issued\n", MAX_BOOKS);
    printf("2. Keep books for 15 days maximum\n");
    printf("3. Late fine: Rs %d per day after 15 days\n", LATE_FINE);
    printf("4. Damage fine: Rs %d per book\n", DAMAGE_FINE);
    printf("5. Existing card IDs: 251000 to 251099\n");
    printf("6. Membership gives discount on all services\n");
    printf("************************************\n");
}

// ====== MAIN MENU ======
void showMenu() 
{
    printf("\n********* MAIN MENU ********\n");
    printf("1. Issue Books\n");
    printf("2. Return Book\n");
    printf("3. Reading Bonus Award\n");
    printf("4. Student Summary Report\n");
    printf("5. Exit System\n");
    printf("*******************************\n");
}

// ====== CHECK CARD FUNCTION ======
int checkCard(int id) 
{
    // Checks if student ID exists and returns index
    int i;
    for(i = 0; i < totalStudents; i++) 
    {
        if (studentIDs[i] == id) return i;
    }
    
    // For old range IDs (251000-251099) register if not found
    if (id >= 251000 && id <= 251099) 
    {
        studentIDs[totalStudents] = id;
        issuedBooks[totalStudents] = 0;
        studentFines[totalStudents] = 0;
        memberTypes[totalStudents] = 0;
        printf("\nNew ID %d added to system\n", id);
        printf("Please select membership.\n");
        int index = totalStudents;
        totalStudents++;
        return index;
    }
    
    // New IDs not found
    return -1;
}

// ====== ISSUE NEW CARD ======
int issueCard() 
{
    studentIDs[totalStudents] = nextNewID;
    issuedBooks[totalStudents] = 0;
    studentFines[totalStudents] = 0;
    memberTypes[totalStudents] = 0;
    printf("\nNew card issued successfully! Your ID: %d\n", nextNewID);
    printf("Card fee: Rs %d\n", CARD_FEE);
    int index = totalStudents;
    totalStudents++;
    nextNewID++;
    return index;
}

// ====== SELECT MEMBERSHIP ======
void getMembership(int index) 
{
    printf("\n=== SELECT MEMBERSHIP TYPE ===\n");
    printf("1. Student Membership - 25%% discount\n");
    printf("2. Regular Membership - 15%% discount\n");
    printf("3. Premium Membership - 35%% discount\n");
    printf("4. No Membership - 0%% discount\n");
    printf("Enter your choice (1-4): ");
    int choice = getPositiveInput();
    
    if (choice >= 1 && choice <= 4) 
    {
        memberTypes[index] = choice;
        showMembership(index);
    } 
    else 
    {
        printf("Invalid choice! No membership selected.\n");
        memberTypes[index] = 0;
    }
}

// ====== PRINT MEMBERSHIP ======
void showMembership(int index) 
{
    if (memberTypes[index] == 1)
        printf("Student Membership activated! (25%% discount)\n");
    else if (memberTypes[index] == 2)
        printf("Regular Membership activated! (15%% discount)\n");
    else if (memberTypes[index] == 3)
        printf("Premium Membership activated! (35%% discount)\n");
    else
        printf("No membership selected.\n");
}

// ====== SHOW STUDENT INFO ======
void showStudentInfo(int index) 
{
    printf("\nStudent Information:\n");
    printf("Student ID: %d\n", studentIDs[index]);
    printf("Books currently issued: %d/%d\n", issuedBooks[index], MAX_BOOKS);
    printf("Membership Type: ");
    showMembership(index);
}

// ====== ISSUE BOOK ======
void issueBook() 
{
    int id, index, booksToIssue;
    printf("\n**** ISSUE BOOK ****\n");
    printf("Enter your Student ID: ");
    id = getPositiveInput();
    index = checkCard(id);
    
    if (index == -1) 
    {
        printf("ID not found! Would you like a new library card? (1=Yes, 0=No): ");
        int choice = getPositiveInput();
        if (choice == 1) index = issueCard();
        else return;
    }
    
    if (memberTypes[index] == 0) 
    {
        printf("You don't have membership. Select now? (1=Yes, 0=No): ");
        int memChoice = getPositiveInput();
        if (memChoice == 1) getMembership(index);
    }
    
    showStudentInfo(index);
    
    if (issuedBooks[index] >= MAX_BOOKS) 
    {
        printf("\nBOOK LIMIT REACHED! Return some books first\n");
        return;
    }
    
    printf("\nHow many books to issue? (Max %d): ", MAX_BOOKS - issuedBooks[index]);
    booksToIssue = getPositiveInput();
    
    if (booksToIssue <= 0 || issuedBooks[index] + booksToIssue > MAX_BOOKS) 
    {
        printf("Invalid number of books!\n");
        return;
    }
    
    issuedBooks[index] += booksToIssue;
    printf("\nBOOKS ISSUED SUCCESSFULLY! Total books now: %d/%d\n", issuedBooks[index], MAX_BOOKS);
}

// ====== RETURN BOOK ======
void returnBook() 
{
    int id, index, booksToReturn, i;
    float fine = 0, lateFine = 0, damageFine = 0;
    
    printf("\n**** RETURN BOOK ****\n");
    printf("Enter Student ID: ");
    id = getPositiveInput();
    index = checkCard(id);
    
    if (index == -1) 
    {
        printf("ID not found!\n"); 
        return;
    }
    
    showStudentInfo(index);
    
    if (issuedBooks[index] == 0) 
    { 
        printf("No books to return.\n"); 
        return; 
    }
    
    printf("How many books to return? ");
    booksToReturn = getPositiveInput();
    
    if (booksToReturn <= 0 || booksToReturn > issuedBooks[index]) 
    {
        printf("Invalid number!\n"); 
        return;
    }
    
    // Fine calculation
    for(i = 1; i <= booksToReturn; i++) 
    {
        int days, damaged;
        printf("\nBook %d - days kept: ", i);
        days = getPositiveInput();
        
        if (days > 15) 
        {
            lateFine += (days - 15) * LATE_FINE;
        }
        
        printf("Is the book damaged? (1=Yes, 0=No): ");
        damaged = getPositiveInput();
        if (damaged == 1) damageFine += DAMAGE_FINE;
    }
    
    fine = lateFine + damageFine;
    issuedBooks[index] -= booksToReturn;
    studentFines[index] += fine;
    
    printf("\nReturn complete! Fine for this return: Rs %.2f\n", fine);
}

// ====== BONUS AWARD ======
void bonusAward() 
{
    int id, index, booksRead;
    printf("\n*** READING BONUS AWARD ***\n");
    printf("Enter Student ID: "); 
    id = getPositiveInput();
    index = checkCard(id);
    
    if (index == -1) 
    { 
        printf("ID not found!\n"); 
        return; 
    }
    
    printf("How many books completed in last 15 days? ");
    booksRead = getPositiveInput();
    
    if (booksRead >= 3) 
    {
        printf(" BONUS UNLOCKED! Free online course awarded.\n");
        printf("You completed %d books in 15 days.\n", booksRead);
        printf("\n-- BONUS DETAILS --\n");
        printf("Course: E-Commerce Basics\n");
        printf("Duration: 4 Weeks\n");
        printf("Certificate: Yes\n");
        printf("Mode: Online\n");
        printf("Value: Rs 5000 (FREE)\n");
        printf("Enrollment Code: LIB-%d-ECOM\n", studentIDs[index]);
    } 
    else 
    {
        printf("Read %d books. Goal: 3 books for next bonus.\n", booksRead);
    }
}

// ====== SUMMARY ======
void showSummary() 
{
    int id, index;
    float discount = 0, totalPay = 0;
    
    printf("\n========== FINAL SUMMARY ==========\n");
    printf("Enter Student ID: ");
    id = getPositiveInput();
    index = checkCard(id);
    
    if (index == -1) 
    {
        printf("ID not found!\n");
        return;
    }
    
    printf("\nStudent ID: %d\n", studentIDs[index]);
    printf("Books Issued: %d/%d\n", issuedBooks[index], MAX_BOOKS);
    printf("Membership: ");
    
    if (memberTypes[index] == 1) 
    { 
        printf("Student (25%%)\n"); 
        discount = studentFines[index] * 0.25; 
    } 
    else if (memberTypes[index] == 2) 
    {
        printf("Regular (15%%)\n"); 
        discount = studentFines[index] * 0.15; 
    } 
    else if (memberTypes[index] == 3) 
    {
        printf("Premium (35%%)\n"); 
        discount = studentFines[index] * 0.35;
    } 
    else 
    {
        printf("None\n");
    }
    
    printf("Total Fine: Rs %.2f\n", (float)studentFines[index]);
    printf("Discount: Rs %.2f\n", discount);
    totalPay = studentFines[index] - discount;
    
    if (studentIDs[index] >= 251100) 
    {
        printf("Card Fee: Rs %d\n", CARD_FEE);
        totalPay += CARD_FEE;
    }
    
    printf("------------------------------\n");
    printf("TOTAL PAYABLE: Rs %.2f\n", totalPay);
    printf("==============================\n");
}

// ====== EXIT MESSAGE ======
void exitMessage() 
{
    printf("\nSystem closed successfully. All library rules enforced properly.\n");
}