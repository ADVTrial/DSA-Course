/*
Chandrika is gifted a game by her aunt. She opens it and finds many rings of different sizes and 3 cones of colors red, blue and pink. Red and Blue stay together whereas Pink cone is kept as a temporary one. Since Chandrika is too young, her aunt sits down and teaches her how to play the game since this game requires some logical thinking.



Each time the game is played, the number of rings to be used is chosen and placed in the Red cone in the ascending order of the ring size i.e., the largest ring is placed at the bottom and the smallest ring at the top. Now these rings have to be moved to the Blue cone and placed in the same order. There is a restriction to the game that only ring has to be moved at a time and during the movement process a larger ring cannot be placed over a smaller one. However, the player can use the temporary Pink cone during the movement process.



A programmer who is watching this from a distant point takes this as a challenge and decides to implement the process using the concept of stacks to arrive at the solution using his skills so that he can use it in his gaming portal.

 Input Format 
Single line input which has the number of rings.

 Output Format 
Output displays the step-by-step procedure of movement as shown in sample test case( a new line feed in added at the end of the output).

 Sample Input  
3
Sample Output 
Shift 1 from Red to Blue
Shift 2 from Red to Pink
Shift 1 from Blue to Pink
Shift 3 from Red to Blue
Shift 1 from Pink to Red
Shift 2 from Pink to Blue
Shift 1 from Red to Blue
*/

/*Tower of HANOI using Recursion*/
#include <iostream>
using namespace std;
void TOH(int n, string Sour, string Aux, string Des)
{
    if (n == 1) 
    {
        cout << "Shift " << n << " from " << Sour << " to " << Des << endl;
        return;
    }
    TOH(n - 1, Sour, Des, Aux);
    cout << "Shift " << n << " from " << Sour << " to " << Des << endl;
    TOH(n - 1, Aux, Sour, Des);
}
int main()
{
    int n;
    cin >> n;
    TOH(n, "Red", "Pink", "Blue");
    return 0;
}
