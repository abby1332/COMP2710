/* 
* Abby Miller
* Project 4 
* Jackson gave me the idea to do listLen instead of a
* global count variable. Caleb gave me the idea to assert
* using return variables. Kelvin helped me with general debug.
* fix bugs and errors.
*/ 
//Libary imports. 
#include <iostream>
#include <assert.h>
using namespace std; 
 
 
//Structure for creating a linked list that holds a trivia question,answer and point 
//amount. 
struct triva_node { 
    string question; 
    string answer; 
    int point; 
    triva_node *next; 
 
}; 
//Global variable
int total_points = 0;
//creates a pointer to triva_node. 
typedef triva_node* ptr_node; 
 
//Prototypes 
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);
void Unit_Test(void);
int listLen(ptr_node& q_list);
 
 
//creates two versions. 
#define UNIT_TESTING 
//#define triva_quiz 
 
int main() { 
    //Unit_test(); 
    ptr_node node_list = new triva_node;
    init_question_list(node_list); 
    string cont;
    //Creates a new trivia game / 
    //Sets up three original  questions/ 
    //Sets up loop for user to input his or her own questions. 
    //Quiz questions are stored in linked list. 
 #ifdef triva_quiz 
    init_question_list(node_list); 
 
  cout << "*** Welcome to Abby Miller's trivia quiz game ***\n"; 


  do {
    add_question(node_list); 
    cout << "Continue? (Yes/No): "; 
    getline(cin, cont);
  }while (cont == "Yes");
 

 //This is start of Trivia quiz game. 
 int count = listLen(node_list);
 ask_question(node_list, count); 
 cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***"; 
 return 0; 

#endif 
//Method for testing 
 
#ifdef UNIT_TESTING 
 
    Unit_Test(); 
    return 0; 

#endif 
 
}
 
//initializes the quiz to have these three questions inputted into the linked list. 
void init_question_list(ptr_node& q_list) {  
    ptr_node cur_ptr = new triva_node;

    cur_ptr->question = "How long was the shortest war on record?"; 
    cur_ptr->answer = "38"; 
    cur_ptr->point = 100;
    cur_ptr->next = new triva_node;
    q_list = cur_ptr;

    cur_ptr = cur_ptr ->next;
    cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)? "; 
    cur_ptr->answer = "Bank of Germany"; 
    cur_ptr->point = 50;
    cur_ptr->next = new triva_node;
    
    cur_ptr = cur_ptr->next; 
    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?"; 
    cur_ptr->answer = "Wii sports"; 
    cur_ptr->point = 20;
    cur_ptr->next = NULL;
    
} 

//gives user the option to add a question to the linked list. 
//question is added to the front of the linked list. 
void add_question(ptr_node& q_list) { 

    //Add to head
    ptr_node new_ptr = new triva_node;
    new_ptr->next = q_list;
    q_list = new_ptr;
    string point;
    int point_int;

    cout << "Enter a new question: "; 
    getline(cin, new_ptr->question); 
    cout << "Enter an answer: "; 
    getline(cin, new_ptr->answer); 
    cout << "Enter award points: "; 
    getline(cin, point);
    point_int = stoi(point);
    new_ptr->point = point_int;
} 

//Checks for null value 
//Ask the user trivia questions and starts the game 
int ask_question(ptr_node q_list, int num_ask) { 
    ptr_node cur_ptr = new triva_node;
    cur_ptr = q_list; 
    int count = listLen(q_list);

    string user_answer;
    if (q_list == NULL) 
        return 0; 
    if(num_ask < 1) { 
        cout << "\nWarning - the number of trivia to be asked must equal to or be" << 
        "larger than 1."; 
        return 0;
    } 
    else if(count < num_ask) { 
        cout << "\nWarning - There is only " << count << " trivia in the" <<
        "list."; 
        return 0;
    }   
    else { 
        for(int x = 0; x < num_ask; x++) { 
            cout << "\nQuestion: " << cur_ptr->question << endl; 
             cout << "Answer: "; 
             getline(cin, user_answer); 

            if (user_answer.compare(cur_ptr->answer) == 0) {//correct_answer) { 
                total_points += cur_ptr->point;
                cout << "Your answer is correct. You recieve " << cur_ptr->point << " points." << endl;
             } 
            else { 
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
            }
            cout << "Your total points: " << total_points << endl;
            cur_ptr = cur_ptr->next; 
  
        } 
    } 
 
 return 1; 
 
} 
 
 int listLen(ptr_node& q_list) {
    int count = 0;
    ptr_node a = q_list;
    if(q_list == NULL) {
        return 0;
    }
    while(a != NULL) {
        count++;
        a = a->next;
    }
    return count;
 }
 
//Test cases to check whether the methods work. 
void Unit_Test() { 
    total_points = 0;
    ptr_node node_list = new triva_node; 
    init_question_list(node_list); 

    cout << "Unit Test Case 1: Ask no question. The program should give a warning" <<
      "  message."; 
    assert(ask_question(node_list, 0) == 0); 
    cout << "\nCase 1 Passed\n\n"; 
 
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters" <<
       " an incorrect answer."; 
    assert(ask_question(node_list, 1) == 1);
    assert(total_points == 0);
    cout << "\nCase 2.1 Passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list."
        << " The tester enters a correct answer.";
    assert(ask_question(node_list, 1) == 1);
    assert(total_points == 100);
    cout << "\nCase 2.2 Passed\n\n";

    total_points = 0;
    cout<<"Unit Test Case 3.1: Ask all questions in the linked list."
        << " The tester answers correctly.";
    assert(ask_question(node_list, 3) == 1);
    assert(total_points == 170);
    cout << "\nCase 3.1 Passed\n\n";

    total_points = 0;
    cout << "Unit Test Case 3.2: Ask all questions in the linked list."
        << " The tester answers incorrectly.";
    assert(ask_question(node_list, 3) == 1);
    assert(total_points == 0);
    cout << "\nCase 3.2 Passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in linked list.";
    assert(ask_question(node_list, 5) == 0);
    cout << "\nCase 4 Passed\n\n";
 
 cout << "\n\n*** End of the Debugging Version ***"; 
} 
 
 
 
 
 