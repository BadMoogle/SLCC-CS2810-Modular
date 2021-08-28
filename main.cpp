/* Daniel Harper
 * CS-2430
 * Assignment 3 - Modular Exponentiation
 */

#include <iostream>
#include <vector>

using namespace std;


/* Used to convert a number to another base.
 * Used a vector as the return type since the size of the result varies on the size of the number
 * Using algorithm 1 on page 249 of Discrete Mathmatics and It's Applications by Rosen
 */
vector<int> baseExpansion (int iNumToExpand, int iBase)
{
    vector<int> a;
    int iIterator = 0;
    int q = iNumToExpand;
    while (q != 0)
    {
	a.push_back(q % iBase);
	q /= iBase;
	iIterator++;
    }
    return a;
}


/* Finds the modular exponent of a number (iBase) raised to a power (iPower) mod iModulus
 * Using algorithm 5 on page 254 of Discrete Mathmatics and It's Applications by Rosen
 */
int findModularExponent(int iBase, int iPower, int iModulus)
{
    vector<int> vBinaryEquivOfPower;
    vBinaryEquivOfPower = baseExpansion(iPower, 2);
    int x = 1;
    int p = iBase % iModulus;
    for (int i = 0; i < vBinaryEquivOfPower.size(); i++)
    {
	if(vBinaryEquivOfPower[i] == 1)
	{
	    x = (x * p) % iModulus;
	        
	}
	p = (p * p) % iModulus;
    }
    return x;
}

/* Entry point for the application
 * 
 */
int main(int argc, char **argv) 
{
    // Print the answers
    cout << "The answer to 25 is : " << findModularExponent(7, 644, 645) << endl;
    cout << "The answer to 26 is : " << findModularExponent(11, 644, 645) << endl;
    cout << "The answer to 27 is : " << findModularExponent(3, 2003, 99) << endl;
    cout << "The answer to 28 is : " << findModularExponent(123, 1001, 101) << endl;
    return 0;
}
