/* FILE NAME: project2_Miller_amm0257.cpp 
* AUTHOR: Abby Miller
* Referenced hint page
* Studied with Kelvin and Caleb Skelton
*/ 
 
#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 

using namespace std; 
/* 
* Input: A_alive indicates Aaron is alive true for alive, false for dead 
*   B_alive indicates Bob is alive 
*   C_alive indicates Charlie is alive 
* Return: true if at least two are alive otherwise return false 
*/ 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
 
/* 
* Call by reference 
* Strategy 1: Everyone shoots to kill the highest accuracy player alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed
* A -> B -> C->
*/ 
void Aaron_shoots1(bool& B_alive, bool& C_alive);
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  C_alive indicates Charlie is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Bob_shoots(bool& A_alive, bool& C_alive);
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  B_alive indicates Bob is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change B_alive into false if Bob is killed 
*/ 
void Charlie_shoots(bool& A_alive, bool& B_alive);
 
/* 
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots2(bool& B_alive, bool& C_alive);
 
//Simple method to implement pause function in linux 
void Press_any_key(void);
 
//TEST PROTOTYPES 
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void); 
void test_Bob_shoots(void); 
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void); 
 
//VARIABLES 
bool A_alive = true;
bool B_alive = true;
bool C_alive = true;

int A_accuracy = 33;
int B_accuracy = 50;
int C_accuracy = 100;
 
int main() { 
 //Initializes Random number generator's seed and calls test functions 
 cout << "*** Welcome to Abby's Duel Simulator ***\n"; 
 //srand(time(0)); 
 test_at_least_two_alive(); 
 Press_any_key(); 

 test_Aaron_shoots1();
 Press_any_key(); 
 test_Bob_shoots(); 
 Press_any_key(); 
 test_Charlie_shoots(); 
 Press_any_key(); 
 test_Aaron_shoots2(); 
 Press_any_key(); 
  
 //Starts strategy 1 and runs 10,000 times 

 cout << "Ready to test strategy 1 (run 10000 times):\n"; 
 int aaronWins1 = 0;
 int bobWins = 0;
 int charlieWins = 0;
 int TOTAL_RUNS = 10000;
 bool aaronAlive = true; bool bobAlive = true; bool charlieAlive = true;
 Press_any_key(); 

 for (int i = 0; i < TOTAL_RUNS; i++){ 
    aaronAlive = true; bobAlive = true; charlieAlive = true;
  while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
    if (aaronAlive) Aaron_shoots1(bobAlive, charlieAlive);

    if (bobAlive)  Bob_shoots(aaronAlive, charlieAlive);

    if (charlieAlive)  Charlie_shoots(aaronAlive, bobAlive);
   } 

  if (aaronAlive)  aaronWins1++;

  if (bobAlive)  bobWins++;

  if (charlieAlive)  charlieWins++;
  } 

 cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / 
 TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
 * 100 << "%\n" 
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
 TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  
 //Reinitializes variables and starts strategy 2 to run 10,000 times 
 int aaronWins2 = 0;
 bobWins = 0;
 charlieWins = 0;
 TOTAL_RUNS = 10000;
 cout << "Ready to test strategy 2 (run 10000 times):\n"; 
 Press_any_key(); 
 for (int i = 0; i < TOTAL_RUNS; i++ ){ 
    aaronAlive = true; bobAlive = true; charlieAlive = true;
  while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
    if (aaronAlive)  Aaron_shoots2(bobAlive, charlieAlive);

    if (bobAlive)  Bob_shoots(aaronAlive, charlieAlive);

    if (charlieAlive)  Charlie_shoots(aaronAlive, bobAlive);
   } 

  if (aaronAlive) aaronWins2++;

  if (bobAlive)  bobWins++;

  if (charlieAlive)  charlieWins++;
 } 

 cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / 
 TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
 * 100 << "%\n" 
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
 TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  
 if (aaronWins1 > aaronWins2) { 
  cout << "Strategy 1 is better than strategy 2.\n"; 
 } 
 else { 
  cout << "Strategy 2 is better than strategy 1.\n"; 
 } 

 return 0; 
} 
 
//Implementation of functions. Look above for documentation of them. 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    return A_alive && (B_alive || C_alive) || (B_alive && C_alive);
} 
 
void test_at_least_two_alive(void) { 
 cout << "Unit Testing 1: Function - at_least_two_alive()\n"; 
  
 cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n"; 
    bool aaron_a = true; bool bob_a = true; bool charlie_a = true;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == true); 
 cout << "\tCase passed ...\n"; 
  
 cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n"; 
        aaron_a = false; bob_a = true; charlie_a = true;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == true); 
 cout << "\tCase passed ...\n";
 
 cout << "\tCase 3: Aaron dead, Bob dead, Charlie alive\n";
        aaron_a = false; bob_a = false; charlie_a = true;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == false); 
 cout << "\tCase passed ...\n";
 
 cout << "\tCase 3: Aaron dead, Bob alive, Charlie dead\n"; 
     aaron_a = false; bob_a = true; charlie_a = false;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == false); 
 cout << "\tCase passed ...\n";

 cout << "\tCase 4: Aaron alive, Bob dead, Charlie alive\n"; 
        aaron_a = true; bob_a = false; charlie_a = true;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == true); 
 cout << "\tCase passed ...\n";

 cout << "\tCase 5: Aaron alive, Bob alive, Charlie dead\n"; 
        bob_a = true; bob_a = true; charlie_a = false;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == true); 
 cout << "\tCase passed ...\n";

 cout << "\tCase 6: Aaron alive, Bob dead, Charlie dead\n"; 
        aaron_a = true; bob_a = false; charlie_a = false;
 assert(at_least_two_alive(aaron_a, bob_a, charlie_a) == false); 
 cout << "\tCase passed ...\n";
} 
 
void Aaron_shoots1(bool& B_alive, bool& C_alive) { 
 assert(B_alive || C_alive); 
 int shootResult = rand() % 100; 
 if (shootResult <= A_accuracy) { 
    if (C_alive) { 
        //shoot charlie
        C_alive = false;
    } 
    else { 
     //shoot bob
        B_alive = false;
    } 
 }
 //missed
} 
 
void test_Aaron_shoots1(void) { 
 cout << "Unit Test 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	bool bob_alive;
	bool charlie_alive;
    int aaronShot = 0;
	
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	cout << "\t\tAaron is shooting at Charlie\n";
	//Aaron aims for charlie. Run 20 times to see if he gets him
    for(int i = 0; i < 20; i++) {
        bob_alive = true; 
	    charlie_alive = true;
        Aaron_shoots1(bob_alive, charlie_alive);
        if (charlie_alive) {
		//miss
	}
	else {
		//hit
        aaronShot++;
	}
    assert(true == bob_alive);
    }
    cout << "\tAaron shot charlie " << aaronShot << " times out of 20.\n";

	cout << "\tCase 2: Bob dead, Charlie alive\n";
	cout << "\t\tAaron is shooting at Charlie\n";
    aaronShot = 0;
	//Aaron aims for charlie. Run 20 times to see if he gets him
    for(int i = 0; i < 20; i++) {
        bob_alive = false; 
	    charlie_alive = true;
        Aaron_shoots1(bob_alive, charlie_alive);
        if (charlie_alive) {
		//miss
	}
	else {
		//hit
        aaronShot++;
	}
    assert(false == bob_alive);
    }
    cout << "\tAaron shot charlie " << aaronShot << " times out of 20.\n";

	cout << "\tCase 3: Bob alive, Charlie dead\n";
	cout << "\t\tAaron is shooting at Bob\n";
    aaronShot = 0;
	//Aaron aims for Bob. Run 20 times to see if he gets him
    for(int i = 0; i < 20; i++) {
        bob_alive = true; 
	    charlie_alive = false;
        Aaron_shoots1(bob_alive, charlie_alive);
        if (bob_alive) {
		//miss
	}
	else {
		//hit
        aaronShot++;
	}
    assert(false == charlie_alive);
    }
    cout << "\tAaron shot Bob " << aaronShot << " times out of 20.\n";
}
 
void Bob_shoots(bool& A_alive, bool& C_alive) { 
    assert(A_alive || C_alive);
    int shootResult = rand() % 100; 
    if (shootResult <= B_accuracy) { 
        if (C_alive == true) {
                //Bob shoots Charlie
                C_alive = false;
            }
        else if(A_alive == true) {
                //Charlie dead so bob shoots aaron
                A_alive = false;
            }
    } 
    //missed
 }
 
void test_Bob_shoots(void) { 
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n"; 
    bool aaron_a; bool charlie_a;
    int bobShoots = 0;
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    for(int i = 0; i < 20; i++) {
        aaron_a = true; charlie_a = true;
        Bob_shoots(aaron_a, charlie_a);
        if (charlie_a == false) {
            bobShoots++;
        }
        assert (aaron_a == true);
    }
    cout << "\tBob shot Charlie " << bobShoots << " times out of 20.\n";

    cout << "\tCase 2: Aaron alive, Charlie dead\n";
    cout << "\t\tBob is shooting at Aaron\n";
    bobShoots = 0;
    for(int i = 0; i < 20; i++) {
        aaron_a = true; charlie_a = false;
        Bob_shoots(aaron_a, charlie_a);
        if (aaron_a == false) {
            bobShoots++;
        }
        assert (charlie_a == false);
    }
    cout << "\tBob shot Aaron " << bobShoots << " times out of 20.\n";

    cout << "\tCase 3: Aaron dead, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    bobShoots = 0;
    for(int i = 0; i < 20; i++) {
        aaron_a = false; charlie_a = true;
        Bob_shoots(aaron_a, charlie_a);
        if (charlie_a == false) {
            bobShoots++;
        }
        assert (aaron_a == false);
    }
    cout << "\tBob shot Charlie " << bobShoots << " times out of 20.\n";
} 
  
void Charlie_shoots(bool& A_alive, bool& B_alive) { 
    assert(A_alive || B_alive);
    if (B_alive == true) {
        //Charlie shoots Bob
        B_alive = false;
    }
    else if (A_alive == true) {
        //Bob dead so Charlie shoots aaron
        A_alive = false;
    }
} 
 
void test_Charlie_shoots(void) { 
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n"; 
    bool aaron_a = true; bool bob_a = true; bool charlie_a = true;
     cout << "\tCase 1: bob alive, aaron alive\n";
     Charlie_shoots(aaron_a, bob_a);
     assert(bob_a == false);
     cout << "\tCase passed ...\n";

     cout << "\tCase 2: bob dead, aaron alive\n";
     bob_a = false; aaron_a = true;
     Charlie_shoots(aaron_a, bob_a);
     assert(aaron_a == false);
     cout << "\tCase passed ...\n";

     cout << "\tCase 3: bob alive, aaron dead\n";
     bob_a = true; aaron_a = false;
     Charlie_shoots(aaron_a, bob_a);
     assert(bob_a == false);
     cout << "\tCase passed ...\n";
    } 
 
 void Aaron_shoots2(bool& B_alive, bool& C_alive) { 
    assert(B_alive || C_alive);
    if(B_alive == true && C_alive == true) {
        //Aaron doesn't shoot
    }
    else {
        Aaron_shoots1(B_alive, C_alive);
    }
} 
 
void test_Aaron_shoots2(void) { 
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n"; 
    cout << "\tCase 1: Bob alive, Charlie alive, first round.";
    bool charlie_a = true; bool bob_a = true;
    Aaron_shoots2(bob_a, charlie_a);
    assert(charlie_a == true && bob_a == true);
    cout << "\tCase passed ...\n";
} 
 
void Press_any_key(void) { 
 cout << "Press any key to continue..."; 
 cin.get();  
} 