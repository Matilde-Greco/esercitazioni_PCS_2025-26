# include <iostream>

int main()
{
    // array statitici di più elementi
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    //variabile intera e una floating point
    int x = 1;
    float y = 1.1;

    // assegno 0 alla posizione 1 di questo ipotetico array
    (&y)[1] = 0; 
    //all'indirizzo di y 1 metti 0, perchè vede y come un array

    //il problema sta nel fatto che vede y come un array quando non lo è
    //e sovrascrive a x il secondo elemento di y, ossia riscrive x=0
    std::cout << x << "\n";

    //faccio qualche prova sugli indirizzi
    std::cout << &x << "\n"; //0x7ffe2ecb6da0
    
    std::cout << &y << "\n"; //0x7ffe2ecb6d9c
    return 0;   
    //0x identifica un numero in base 16
    // in base 16 ho le cifre da 0 a 9 e da A a F, ossia fino a 15
    //ognuno rappresentato da  bit
    //0xC7=1100 0111 in binario
}