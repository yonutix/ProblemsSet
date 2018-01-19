#include <iostream> //for std::cin, std::cout etc
#include <fstream> //for std:: fstream
#include <string> //for std::string
#include <math.h> //pow

//Mihai incearcă să creeze un joc nou pentru tabletă care sa îi amestece nişte bile de loto. Îşi propune mai intai sa
//realizeze o aplicatie mai simpla. In joc pot fi doua bile de loto cu acelasi numar dar numerele de pe bile sunt doar
//cifre. Astfel el creaza pentru inceput doua butoane: unul de "start" care apăsat sa îi afiseze un număr de bile la
//intamplare. El mai creaza un buton "move" ce poate fi folosit doar pentru a muta ultima bila imediat dupa prima bila.
//Cerinta
//
//Dandu-se un numar n, format din cifrele ce apar pe bile dupa apasarea butonului de start, aflati:
//a) care este cifra scrisa pe prima bila
//b) cate bile i-au aparut lui Mihai
//c) Daca Mihai apasa de k ori pe butonul move, ce numar se va forma cu cifrele bilelor in noua configuratie.
//
//Date de intrare
//
//Fişierul de intrare lotokids.in va contine pe prima linie numarul n si numarul k.
//
//Date de ieşire
//
//În fişierul de ieşire lotokids.out se va afisa pe prima linie, cifra de pe prima bila si numarul de bile, iar pe a doua linie numarul ce se obtine dupa apasarea butonului move de k ori.
//Restricţii
//
//    0 ≤ k ≤ 1.000.000.000
//    n va fi un numar natural nenul ce va avea cel mult 9 cifre

unsigned int getFirstDigitOfTheFirstBall(long long n)
{
    while (n > 9)
    {
        n = n / 10;
    }
    return n;
}

unsigned int getNumberOfDigits(long long n)
{
    unsigned int count = 0;

    while (n > 0)
    {
        count++;
        n = n / 10;
    }

    return count;
}

long long rotateFromSecond(long long n)
{
    unsigned int digitsCount = getNumberOfDigits(n);

    long long firstNumberOfN = n/pow(10, digitsCount-1);

    long long nExceptFirstDigit = n % ((long long)pow(10, digitsCount-1));

    long long lastDigitOfN = n % 10;

    long long newN = (firstNumberOfN *10 + lastDigitOfN) * ((long long)pow(10, digitsCount-1)) + nExceptFirstDigit;

    newN = newN / 10;

    return newN;
}






int main()
{

    long long n = 0;
    unsigned int k = 0;

    // This section reads the file
    //START SECTION
    std::fstream inputFile ("lotokids.in");

    if (inputFile.is_open())
    {
        inputFile>>n>>k;


        inputFile.close();
    }

    else
    {
        std::cout << "Unable to open file, The file might not exists or might not have the\
            right permissions";
    }
    //END SECTION


    long long result = n;

    for(unsigned int i = 0; i < k; ++i)
    {
        result = rotateFromSecond(result);
    }



    //This section writes the file
    //START SECTION


    std::ofstream outputFile ("lotokids.out");
    if (outputFile.is_open())
    {
        outputFile<<getFirstDigitOfTheFirstBall(n)<<" "<<getNumberOfDigits(n)<<std::endl<<result<<std::endl;
        outputFile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
    //END SECTION



    return 0;
}