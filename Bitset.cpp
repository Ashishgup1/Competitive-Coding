const int SZ = 2001;

void functions()
{
	bitset<SZ> bit;
	bit.all(); //checks whether all bits are set or not
	bit.any(); //checks whether >= 1 bit is on
	bit.none(); //checks if all bits are off
	bit.count(); //counts no of set bits
	bit.flip(); //flips all bits
	bit.flip(1); //flips 1st bit
	bit.reset(); //resets all bits to 0
	bit.reset(1); //resets 1st bit
	bit.set(); //sets all bits to 1
	bit.set(1); //sets 1st bit to 1
	bit.size(); //return size of bitset
	bit.test(1); //check if 1st bit is on or not
	cout << bit.to_string(); //converts to string
}

//Problem 1 (DP): https://www.spoj.com/problems/ADACOINS/

//Problem 2 (Circular BIT with Bitset): https://www.codechef.com/CROS2020/problems/COCR107
//Code: https://www.codechef.com/viewsolution/34639511
