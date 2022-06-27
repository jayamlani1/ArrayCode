//1010. Pairs of Songs With Total Durations Divisible by 60

int numPairsDivisibleBy60(int* time, int timeSize)
{
    int hash[60] = {0};
    int count = 0;
    for(int i = 0; i<timeSize ; i++)
    {
        // x stores the remainder for current value 
        
        int x = time[i] % 60;
        
        int y = (60 - x) % 60;
        // y stores the value that is required to add with x to get a number
        // which is multiple of sixty.
        // the only issue I found was when x is zero y would be 60. Hence I
        // have put the code to modulo 60 again.
        
        count = count + hash[y];
        
        hash[x]++;
    }
    return count;
}
