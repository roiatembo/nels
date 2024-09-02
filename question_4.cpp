#include <iostream>
#include <fstream>

using namespace std;

void encodeLetter() {
    ifstream inputFile("letter.txt");
    ofstream outputFile("encode.txt");

    if (!inputFile) {
        cout << "Error opening input file!" << endl;
        return;
    }

    if (!outputFile) {
        cout << "Error opening output file!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        switch (ch) {
            case 't': case 'T':
                outputFile << "1Y";
                break;
            case 'h': case 'H':
                outputFile << "1O";
                break;
            case 'j': case 'J':
                outputFile << "1X";
                break;
            case 'd': case 'D':
                outputFile << "1B";
                break;
            case 'a': case 'A':
                outputFile << "1S";
                break;
            case 'p': case 'P':
                outputFile << "1M";
                break;
            case 'I': case 'i':
                outputFile << "1Q";
                break;
            default:
                outputFile << ch;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "The letter has been encoded and saved to encode.txt." << endl;
}

int main() {
    encodeLetter();
    return 0;
}
/*
Input letter

Dear Julia,
You are the most beautiful girl that I have ever seen. I was wondering
if you would like to come and visit me. My mother will make us
pancakes with ice cream. My dog, Bella, just had three beautiful puppies.
Mom says I may only keep one of them. I would like you to help me
choose one, because they are all so cute and adorable. And just
because you are my special friend, you may also have one if you want.
Your friend,
Hector.

Output

1BS1B 1X1Q1S,
Yo1Q 1S1O 1Y1O 1Y1S 1QOS1Qf1UL g1O1Q 1Y1O1Y 1B1QS1Uf1UQ. 1Q w1S1Y wo1Q1BOQ1Qf1U1X
1Qf yo1M wo1UL li1Y1Q 1S co1MQ 1S1Q visi1Y m1Q. M1Q mo1Y1O1Q w1LL m1MQ 1Us
m1N1MS1S1B1SY wi1Y ic1Q c1QS1M. M1Q 1B1Og, B1LL1S, 1X1U1S1Y h1S 1Y1OQ1Q 1BS1Uf1UL 1M1MM1QS1S.
Mo1M s1YS 1Q m1Y o1nLQ k11Q 1on1Q 1of 1Y1O1M. 1Q wo1UL li1Y1Q yo1M 1Y1O h1Q1LP m1Q
cho1oS1Q 1on1Q, 1B1QS1US1Q 1Y1OQ 1S1Q 1SLL so c1Y1O 1S1Q 1S1B1QS1S1BLQ. 1Sn1B 1X1US1Y
b1QS1US1Q yo1M 1S1Q m1Q s1M1CQ1SL f1Q1Qn1B, yo1M m1Y 1SLS1O h1Q1LP 1on1Q 1Qf yo1M w1S1Y1Y.
Yo1M1Q f1Q1Qn1B,
H1Q1XY1O1B.



*/